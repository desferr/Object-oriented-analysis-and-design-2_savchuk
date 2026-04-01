#pragma once

#include <QVector>
#include <memory>
#include "Canvas.h"
#include "Symbol.h"

class TextVisualizer
{

public:
	TextVisualizer(int rows, int columns, int cellWidth = 8, int cellHeight = 8);
	~TextVisualizer();
	void parseText(const QString& text, const QColor& defaultColor = Qt::black);
	void drawAll(QPainter* painter) const;
	int getRows() { return m_rows; }
	int getColumns() { return m_columns; }
	void removeSymbol(int row, int column, const QColor& color);
	int findLastCharColumn(int row);
	void setSymbol(int row, int column, QChar ch, const QColor& color = Qt::black);
	static bool isAllowedChar(QChar ch);
	bool isLastSymbolInRow(int row, int column);
	const QVector<QVector<std::shared_ptr<Symbol>>>& getMatrix() const { return m_matrix; }
	void setSymbolColor(int row, int column, const QColor& color);
	void changeLeftNullToSpace(int row, int column, const QColor& color);
	int getNonEmptyCount() const;
	int getUniqueCharCount() const;

private:
	QVector<QVector<std::shared_ptr<Symbol>>> m_matrix;
	int m_rows;
	int m_columns;
	int m_cellWidth;
	int m_cellHeight;
};