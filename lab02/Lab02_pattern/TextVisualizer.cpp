#include "TextVisualizer.h"
#include "FlyweightFactory.h"
#include <QChar>
#include <QMessageBox>
#include <QSet>

TextVisualizer::TextVisualizer(int rows, int columns, int cellWidth, int cellHeight) : m_rows(rows), m_columns(columns), m_cellWidth(cellWidth), m_cellHeight(cellHeight)
{
	m_matrix.resize(rows);
	for (int i = 0; i < rows; i++) m_matrix[i].resize(columns);
}
TextVisualizer::~TextVisualizer() = default;

void TextVisualizer::parseText(const QString& text, const QColor& defaultColor)
{
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_columns; j++)
		{
			m_matrix[i][j].reset();
		}
	}
	int row = 0;
	int column = 0;
	QColor color = defaultColor;
	bool opt = false;
	for (const QChar& ch : text)
	{
		if (ch == '\n')
		{
			column = 0;
			row++;
			continue;
		}
		if (ch == '<')
		{
			opt = true;
			continue;
		}
		if (ch == '>')
		{
			opt = false;
			continue;
		}
		if (opt == true)
		{
			if (ch == 'k') color = Qt::black;
			else if (ch == 'r') color = Qt::red;
			else if (ch == 'g') color = Qt::green;
			else if (ch == 'b') color = Qt::blue;
			else if (ch == 'y') color = Qt::yellow;
			else color = defaultColor;
			continue;
		}
		if (row >= m_rows)
		{
			break;
		}
		if (column >= m_columns)
		{
			row++;
			column = 0;
			if (row >= m_rows) break;
		}
		auto fly = FlyweightFactory::getFlyweight(ch);
		m_matrix[row][column] = std::make_shared<CharContext>(fly, row, column, color);
		column++;
	}
}

void TextVisualizer::drawAll(QPainter* painter) const
{
	if (!painter) return;
	for (int row = 0; row < m_rows; row++)
	{
		for (int column = 0; column < m_columns; column++)
		{
			const auto& context = m_matrix[row][column];
			if (context)
			{
				context->draw(painter);
			}
		}
	}
}

void TextVisualizer::removeSymbol(int row, int column, const QColor& color)
{
	if (row >= 0 && row < m_rows && column >= 0 && column <= m_columns)
	{
		if (isLastSymbolInRow(row, column)) m_matrix[row][column].reset();
		else m_matrix[row][column] = std::make_shared<CharContext>(FlyweightFactory::getFlyweight(' '), row, column, color);
	}
}

int TextVisualizer::findLastCharColumn(int row)
{
	int column = m_columns - 1;
	for (; column > 0; column--)
	{
		if (m_matrix[row][column] != nullptr) return column + 1;
	}
	return 0;
}

void TextVisualizer::setSymbol(int row, int column, QChar ch, const QColor& color)
{
	if (row < 0 || row >= m_rows || column < 0 || column >= m_columns) return;
	auto fly = FlyweightFactory::getFlyweight(ch);
	m_matrix[row][column] = std::make_shared<CharContext>(fly, row, column, color);
}

bool TextVisualizer::isAllowedChar(QChar ch)
{
	ushort code = ch.unicode();
	static const QString allowedPunct = ".,;:!?-()[] ";
	if ((code >= 0x0410 && code <= 0x042F) || (code >= 0x0430 && code <= 0x044F) || code == 0x0401 || code == 0x0451) return true;
	else if (ch.isDigit()) return true;
	else if (allowedPunct.contains(ch)) return true;
	return false;
}

bool TextVisualizer::isLastSymbolInRow(int row, int column)
{
	column++;
	while (column < m_columns)
	{
		if (m_matrix[row][column] != nullptr) return false;
		column++;
	}
	return true;
}

void TextVisualizer::setSymbolColor(int row, int column, const QColor& color)
{
	if (row >= 0 && row < m_rows && column >= 0 && column < m_columns)
	{
		auto& context = m_matrix[row][column];
		if (context) context->setColor(color);
	}
}

void TextVisualizer::changeLeftNullToSpace(int row, int column, const QColor& color)
{
	if (column == 0 || m_matrix[row][column - 1] != nullptr) return;
	column--;
	while (column >= 0)
	{
		if (m_matrix[row][column] == nullptr) m_matrix[row][column] = std::make_shared<CharContext>(FlyweightFactory::getFlyweight(' '), row, column, color);;
		column--;
	}
	return;
}

int TextVisualizer::getNonEmptyCount() const
{
	int count = 0;
	for (int row = 0; row < m_rows; row++)
	{
		for (int column = 0; column < m_columns; column++)
		{
			if (m_matrix[row][column]) count++;
		}
	}
	return count;
}

int TextVisualizer::getUniqueCharCount() const
{
	QSet<QChar> unique;
	for (int row = 0; row < m_rows; row++)
	{
		for (int column = 0; column < m_columns; column++)
		{
			if (m_matrix[row][column]) unique.insert(m_matrix[row][column]->getChar());
		}
	}
	return unique.size();
}