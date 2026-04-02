#pragma once

#include <QColor>
#include <QPainter>

class Flyweight
{

public:
	virtual ~Flyweight() = default;
	virtual void draw(QPainter* painter, int row, int column, const QColor& color, int width = 8, int height = 8) const = 0;
	virtual QChar getChar() const = 0;
};