#pragma once

#include <memory>
#include <QColor>
#include "Flyweight.h"
#include "CharFlyweight.h"

class CharContext
{

public:
	CharContext(std::shared_ptr<Flyweight> flyweight, int row, int column, const QColor& color) : m_flyweight(flyweight), m_row(row), m_column(column), m_color(color) {}
	void draw(QPainter* painter) const
	{
		m_flyweight->draw(painter, m_row, m_column, m_color);
	}
	void setColor(const QColor& color) { m_color = color; }
	QChar getChar() const { return m_flyweight->getChar(); }
	QColor getColor() const { return m_color; }

private:
	std::shared_ptr<Flyweight> m_flyweight;
	int m_row;
	int m_column;
	QColor m_color;
};