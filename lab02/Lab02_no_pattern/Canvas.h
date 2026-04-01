#pragma once

#include <QWidget>
#include <QImage>
#include <QColor>
#include <QPoint>

class TextVisualizer;

class Canvas : public QWidget
{
	Q_OBJECT

public:
	Canvas(QWidget *parent = nullptr, int cellWidth = 8, int cellHeihgt = 8);
	void setTextVisualizer(TextVisualizer* visualizer) { m_visualizer = visualizer; }
	void clearSelection() { m_selectedCell = QPoint(-1, -1); emit cellClicked(-1, -1);  update(); }
	void setSelectedCell(int row, int column);

public slots:
	void clear(const QColor &color = Qt::white);
	void drawTextVisualizer(const TextVisualizer& visualizer);

signals: 
	void cellClicked(int row, int col);

protected:
	void paintEvent(QPaintEvent *event) override;
	void mousePressEvent(QMouseEvent *event) override;

private:
	QImage image;
	TextVisualizer* m_visualizer = nullptr;
	QPoint m_selectedCell = QPoint(-1, -1);
	int m_cellWidth;
	int m_cellHeight;
};