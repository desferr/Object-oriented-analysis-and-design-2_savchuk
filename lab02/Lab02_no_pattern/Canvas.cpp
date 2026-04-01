#include "Canvas.h"
#include <QPainter>
#include <QMouseEvent>
#include "TextVisualizer.h"

Canvas::Canvas(QWidget* parent, int cellWidth, int cellHeight) : QWidget(parent)
{
	m_cellWidth = cellWidth;
	m_cellHeight = cellHeight;
	setFixedSize(600, 700);
	image = QImage(size(), QImage::Format_ARGB32_Premultiplied);
	image.fill(Qt::white);
	setFocusPolicy(Qt::StrongFocus);
}

void Canvas::clear(const QColor& color)
{
	image.fill(color);
	update();
}

void Canvas::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.drawImage(0, 0, image);
	if (m_selectedCell.x() >= 0 && m_selectedCell.y() >= 0 && m_visualizer)
	{
		int x = m_selectedCell.y() * m_cellWidth;
		int y = m_selectedCell.x() * (m_cellHeight + 2) + 9;
		painter.setPen(QPen(Qt::red, 1));
		painter.drawLine(x, y, x + m_cellWidth, y);
	}
}

void Canvas::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton && m_visualizer)
	{
		QPoint pos = event->pos();
		int column = pos.x() / m_cellWidth;
		int row = pos.y() / (m_cellHeight + 2);
		if (row >= 0 && row < m_visualizer->getRows() && column >= 0 && column < m_visualizer->getColumns())
		{
			m_selectedCell = QPoint(row, column);
			emit cellClicked(row, column);
			setFocus();
			update();
		}
		else
		{
			clearSelection();
		}
	}
}

void Canvas::drawTextVisualizer(const TextVisualizer& visualizer)
{
	clear();
	QPainter painter(&image);
	painter.setRenderHint(QPainter::Antialiasing, false);
	visualizer.drawAll(&painter);
	update();
}

void Canvas::setSelectedCell(int row, int column)
{
	m_selectedCell = QPoint(row, column);
	update();
}