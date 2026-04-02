#pragma once

#include <QChar>
#include "Flyweight.h"

class CharFlyweight : public Flyweight
{

public:
	CharFlyweight(QChar ch, uint64_t mask = 0) : m_char(ch), m_mask(mask) {}
	QChar getChar() const { return m_char; }
	void draw(QPainter* painter, int row, int column, const QColor& color, int width = 8, int height = 8) const override
	{
		for (int row_iter = 0; row_iter < height; row_iter++)
		{
			for (int column_iter = 0; column_iter < width; column_iter++)
			{
				int bitIndex = row_iter * width + column_iter;
				if (m_mask & (1ULL << bitIndex))
				{
					painter->fillRect(width * column + column_iter, (height + 2) * row + row_iter, 1, 1, color);
				}
			}
		}
	}

private:
	QChar m_char;
	uint64_t m_mask;
	//////////////////////////////////////////////////////////////////////////
	QString demoWeight = "DEMO WEIGHT";
	//////////////////////////////////////////////////////////////////////////
};