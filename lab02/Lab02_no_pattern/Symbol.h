#pragma once

#include <memory>
#include <QColor>
#include <QPainter>
#include <QChar>

class Symbol
{

public:
	Symbol(QChar ch, int row, int column, const QColor& color) : m_char(ch), m_row(row), m_column(column), m_color(color)
	{
		m_mask = getMaskForChar(ch);
	}
	void draw(QPainter* painter, int width = 8, int height = 8) const
	{
		for (int row_iter = 0; row_iter < height; row_iter++)
		{
			for (int column_iter = 0; column_iter < width; column_iter++)
			{
				int bitIndex = row_iter * width + column_iter;
				if (m_mask & (1ULL << bitIndex))
				{
					painter->fillRect(width * m_column + column_iter, (height + 2) * m_row + row_iter, 1, 1, m_color);
				}
			}
		}
	}
	void setColor(const QColor& color) { m_color = color; }
	QChar getChar() const { return m_char; }
	QColor getColor() const { return m_color; }

private:
	QChar m_char;
	int m_row;
	int m_column;
	QColor m_color;
	uint64_t m_mask;
	//////////////////////////////////////////////////////////////////////////
	QString demoWeight = "DEMO WEIGHT";
	//////////////////////////////////////////////////////////////////////////

public:
	static uint64_t getMaskForChar(QChar ch)
	{
		uint64_t mask = 0;
		if (ch == QChar(0x0410)) // À
		{
			mask |= (1ULL << 3);
			mask |= (1ULL << 4);
			mask |= (1ULL << 10);
			mask |= (1ULL << 13);
			mask |= (1ULL << 18);
			mask |= (1ULL << 21);
			mask |= (1ULL << 26);
			mask |= (1ULL << 29);
			mask |= (1ULL << 34);
			mask |= (1ULL << 35);
			mask |= (1ULL << 36);
			mask |= (1ULL << 37);
			mask |= (1ULL << 42);
			mask |= (1ULL << 45);
			mask |= (1ULL << 50);
			mask |= (1ULL << 53);
			mask |= (1ULL << 58);
			mask |= (1ULL << 61);
		}
		else if (ch == QChar(0x0411)) // Á
		{
			mask |= (1ULL << 2);
			mask |= (1ULL << 3);
			mask |= (1ULL << 4);
			mask |= (1ULL << 5);
			mask |= (1ULL << 6);
			mask |= (1ULL << 10);
			mask |= (1ULL << 18);
			mask |= (1ULL << 26);
			mask |= (1ULL << 27);
			mask |= (1ULL << 28);
			mask |= (1ULL << 29);
			mask |= (1ULL << 34);
			mask |= (1ULL << 38);
			mask |= (1ULL << 42);
			mask |= (1ULL << 46);
			mask |= (1ULL << 50);
			mask |= (1ULL << 54);
			mask |= (1ULL << 58);
			mask |= (1ULL << 59);
			mask |= (1ULL << 60);
			mask |= (1ULL << 61);
		}
		else if (ch == QChar(0x0412)) // Â
		{
			mask |= (1ULL << 2);
			mask |= (1ULL << 3);
			mask |= (1ULL << 4);
			mask |= (1ULL << 10);
			mask |= (1ULL << 13);
			mask |= (1ULL << 18);
			mask |= (1ULL << 21);
			mask |= (1ULL << 26);
			mask |= (1ULL << 27);
			mask |= (1ULL << 28);
			mask |= (1ULL << 34);
			mask |= (1ULL << 37);
			mask |= (1ULL << 42);
			mask |= (1ULL << 45);
			mask |= (1ULL << 50);
			mask |= (1ULL << 53);
			mask |= (1ULL << 58);
			mask |= (1ULL << 59);
			mask |= (1ULL << 60);
		}
		else if (ch == QChar(0x0413)) // Ã
		{
			mask |= (1ULL << 2);
			mask |= (1ULL << 3);
			mask |= (1ULL << 4);
			mask |= (1ULL << 5);
			mask |= (1ULL << 10);
			mask |= (1ULL << 18);
			mask |= (1ULL << 26);
			mask |= (1ULL << 34);
			mask |= (1ULL << 42);
			mask |= (1ULL << 50);
			mask |= (1ULL << 58);
		}
		else if (ch == QChar(0x0414)) // Ä
		{
			mask |= (1ULL << 3);
			mask |= (1ULL << 4);
			mask |= (1ULL << 10);
			mask |= (1ULL << 13);
			mask |= (1ULL << 18);
			mask |= (1ULL << 21);
			mask |= (1ULL << 26);
			mask |= (1ULL << 29);
			mask |= (1ULL << 34);
			mask |= (1ULL << 37);
			mask |= (1ULL << 41);
			mask |= (1ULL << 42);
			mask |= (1ULL << 43);
			mask |= (1ULL << 44);
			mask |= (1ULL << 45);
			mask |= (1ULL << 46);
			mask |= (1ULL << 49);
			mask |= (1ULL << 54);
			mask |= (1ULL << 57);
			mask |= (1ULL << 62);
		}
		else if (ch == QChar(0x0415)) // Å
		{
			mask |= (1ULL << 2);
			mask |= (1ULL << 3);
			mask |= (1ULL << 4);
			mask |= (1ULL << 5);
			mask |= (1ULL << 10);
			mask |= (1ULL << 18);
			mask |= (1ULL << 26);
			mask |= (1ULL << 34);
			mask |= (1ULL << 35);
			mask |= (1ULL << 36);
			mask |= (1ULL << 37);
			mask |= (1ULL << 42);
			mask |= (1ULL << 50);
			mask |= (1ULL << 58);
			mask |= (1ULL << 59);
			mask |= (1ULL << 60);
			mask |= (1ULL << 61);
		}
		else if (ch == QChar(0x0401)) // ¨
		{
			mask |= (1ULL << 2);
			mask |= (1ULL << 5);
			mask |= (1ULL << 18);
			mask |= (1ULL << 19);
			mask |= (1ULL << 20);
			mask |= (1ULL << 21);
			mask |= (1ULL << 26);
			mask |= (1ULL << 34);
			mask |= (1ULL << 42);
			mask |= (1ULL << 43);
			mask |= (1ULL << 44);
			mask |= (1ULL << 45);
			mask |= (1ULL << 50);
			mask |= (1ULL << 58);
			mask |= (1ULL << 59);
			mask |= (1ULL << 60);
			mask |= (1ULL << 61);
		}
		else if (ch == QChar(0x0416)) // Æ
		{
			mask |= (1ULL << 1);
			mask |= (1ULL << 3);
			mask |= (1ULL << 5);
			mask |= (1ULL << 9);
			mask |= (1ULL << 11);
			mask |= (1ULL << 13);
			mask |= (1ULL << 17);
			mask |= (1ULL << 19);
			mask |= (1ULL << 21);
			mask |= (1ULL << 26);
			mask |= (1ULL << 27);
			mask |= (1ULL << 28);
			mask |= (1ULL << 33);
			mask |= (1ULL << 35);
			mask |= (1ULL << 37);
			mask |= (1ULL << 41);
			mask |= (1ULL << 43);
			mask |= (1ULL << 45);
			mask |= (1ULL << 49);
			mask |= (1ULL << 51);
			mask |= (1ULL << 53);
			mask |= (1ULL << 57);
			mask |= (1ULL << 59);
			mask |= (1ULL << 61);
		}
		else if (ch == QChar(0x0417)) // Ç
		{
			mask |= (1ULL << 2);
			mask |= (1ULL << 3);
			mask |= (1ULL << 4);
			mask |= (1ULL << 13);
			mask |= (1ULL << 21);
			mask |= (1ULL << 26);
			mask |= (1ULL << 27);
			mask |= (1ULL << 28);
			mask |= (1ULL << 37);
			mask |= (1ULL << 45);
			mask |= (1ULL << 53);
			mask |= (1ULL << 58);
			mask |= (1ULL << 59);
			mask |= (1ULL << 60);
		}
		else if (ch == QChar(0x0418)) // È
		{
			mask |= (1ULL << 2);
			mask |= (1ULL << 6);
			mask |= (1ULL << 10);
			mask |= (1ULL << 13);
			mask |= (1ULL << 14);
			mask |= (1ULL << 18);
			mask |= (1ULL << 21);
			mask |= (1ULL << 22);
			mask |= (1ULL << 26);
			mask |= (1ULL << 28);
			mask |= (1ULL << 30);
			mask |= (1ULL << 34);
			mask |= (1ULL << 36);
			mask |= (1ULL << 38);
			mask |= (1ULL << 42);
			mask |= (1ULL << 43);
			mask |= (1ULL << 46);
			mask |= (1ULL << 50);
			mask |= (1ULL << 51);
			mask |= (1ULL << 54);
			mask |= (1ULL << 58);
			mask |= (1ULL << 62);
		}
		else if (ch == QChar(0x0419)) // É
		{
			mask |= (1ULL << 2);
			mask |= (1ULL << 5);
			mask |= (1ULL << 11);
			mask |= (1ULL << 12);
			mask |= (1ULL << 26);
			mask |= (1ULL << 29);
			mask |= (1ULL << 34);
			mask |= (1ULL << 37);
			mask |= (1ULL << 42);
			mask |= (1ULL << 44);
			mask |= (1ULL << 45);
			mask |= (1ULL << 50);
			mask |= (1ULL << 51);
			mask |= (1ULL << 53);
			mask |= (1ULL << 58);
			mask |= (1ULL << 61);
		}
		else if (ch == QChar(0x041A)) // Ê
		{
			mask |= (1ULL << 2);
			mask |= (1ULL << 5);
			mask |= (1ULL << 10);
			mask |= (1ULL << 13);
			mask |= (1ULL << 18);
			mask |= (1ULL << 20);
			mask |= (1ULL << 26);
			mask |= (1ULL << 27);
			mask |= (1ULL << 34);
			mask |= (1ULL << 36);
			mask |= (1ULL << 42);
			mask |= (1ULL << 45);
			mask |= (1ULL << 50);
			mask |= (1ULL << 53);
			mask |= (1ULL << 58);
			mask |= (1ULL << 61);
		}
		else if (ch == QChar(0x041B)) // Ë
		{
			mask |= (1ULL << 3);
			mask |= (1ULL << 4);
			mask |= (1ULL << 10);
			mask |= (1ULL << 13);
			mask |= (1ULL << 18);
			mask |= (1ULL << 21);
			mask |= (1ULL << 26);
			mask |= (1ULL << 29);
			mask |= (1ULL << 34);
			mask |= (1ULL << 37);
			mask |= (1ULL << 42);
			mask |= (1ULL << 45);
			mask |= (1ULL << 50);
			mask |= (1ULL << 53);
			mask |= (1ULL << 57);
			mask |= (1ULL << 61);
		}
		else if (ch == QChar(0x041C)) // Ì
		{
			mask |= (1ULL << 2);
			mask |= (1ULL << 6);
			mask |= (1ULL << 10);
			mask |= (1ULL << 11);
			mask |= (1ULL << 13);
			mask |= (1ULL << 14);
			mask |= (1ULL << 18);
			mask |= (1ULL << 20);
			mask |= (1ULL << 22);
			mask |= (1ULL << 26);
			mask |= (1ULL << 30);
			mask |= (1ULL << 34);
			mask |= (1ULL << 38);
			mask |= (1ULL << 42);
			mask |= (1ULL << 46);
			mask |= (1ULL << 50);
			mask |= (1ULL << 54);
			mask |= (1ULL << 58);
			mask |= (1ULL << 62);
		}
		else if (ch == QChar(0x041D)) // Í
		{
			mask |= (1ULL << 2);
			mask |= (1ULL << 5);
			mask |= (1ULL << 10);
			mask |= (1ULL << 13);
			mask |= (1ULL << 18);
			mask |= (1ULL << 21);
			mask |= (1ULL << 26);
			mask |= (1ULL << 29);
			mask |= (1ULL << 34);
			mask |= (1ULL << 35);
			mask |= (1ULL << 36);
			mask |= (1ULL << 37);
			mask |= (1ULL << 42);
			mask |= (1ULL << 45);
			mask |= (1ULL << 50);
			mask |= (1ULL << 53);
			mask |= (1ULL << 58);
			mask |= (1ULL << 61);
		}
		else if (ch == QChar(0x041E)) // Î
		{
			mask |= (1ULL << 3);
			mask |= (1ULL << 4);
			mask |= (1ULL << 10);
			mask |= (1ULL << 13);
			mask |= (1ULL << 18);
			mask |= (1ULL << 21);
			mask |= (1ULL << 26);
			mask |= (1ULL << 29);
			mask |= (1ULL << 34);
			mask |= (1ULL << 37);
			mask |= (1ULL << 42);
			mask |= (1ULL << 45);
			mask |= (1ULL << 50);
			mask |= (1ULL << 53);
			mask |= (1ULL << 59);
			mask |= (1ULL << 60);
		}
		else if (ch == QChar(0x041F)) // Ï
		{
			mask |= (1ULL << 2);
			mask |= (1ULL << 3);
			mask |= (1ULL << 4);
			mask |= (1ULL << 5);
			mask |= (1ULL << 10);
			mask |= (1ULL << 13);
			mask |= (1ULL << 18);
			mask |= (1ULL << 21);
			mask |= (1ULL << 26);
			mask |= (1ULL << 29);
			mask |= (1ULL << 34);
			mask |= (1ULL << 37);
			mask |= (1ULL << 42);
			mask |= (1ULL << 45);
			mask |= (1ULL << 50);
			mask |= (1ULL << 53);
			mask |= (1ULL << 58);
			mask |= (1ULL << 61);
		}
		else if (ch == QChar(0x0420)) // Ð
		{
			mask |= (1ULL << 2);
			mask |= (1ULL << 3);
			mask |= (1ULL << 4);
			mask |= (1ULL << 10);
			mask |= (1ULL << 13);
			mask |= (1ULL << 18);
			mask |= (1ULL << 21);
			mask |= (1ULL << 26);
			mask |= (1ULL << 27);
			mask |= (1ULL << 28);
			mask |= (1ULL << 34);
			mask |= (1ULL << 42);
			mask |= (1ULL << 50);
			mask |= (1ULL << 58);
		}
		else if (ch == QChar(0x0421)) // Ñ
		{
			mask |= (1ULL << 3);
			mask |= (1ULL << 4);
			mask |= (1ULL << 5);
			mask |= (1ULL << 10);
			mask |= (1ULL << 18);
			mask |= (1ULL << 26);
			mask |= (1ULL << 34);
			mask |= (1ULL << 42);
			mask |= (1ULL << 50);
			mask |= (1ULL << 59);
			mask |= (1ULL << 60);
			mask |= (1ULL << 61);
		}
		else if (ch == QChar(0x0422)) // Ò
		{
			mask |= (1ULL << 2);
			mask |= (1ULL << 3);
			mask |= (1ULL << 4);
			mask |= (1ULL << 5);
			mask |= (1ULL << 6);
			mask |= (1ULL << 12);
			mask |= (1ULL << 20);
			mask |= (1ULL << 28);
			mask |= (1ULL << 36);
			mask |= (1ULL << 44);
			mask |= (1ULL << 52);
			mask |= (1ULL << 60);
		}
		else if (ch == QChar(0x0423)) // Ó
		{
			mask |= (1ULL << 2);
			mask |= (1ULL << 5);
			mask |= (1ULL << 10);
			mask |= (1ULL << 13);
			mask |= (1ULL << 18);
			mask |= (1ULL << 21);
			mask |= (1ULL << 27);
			mask |= (1ULL << 29);
			mask |= (1ULL << 36);
			mask |= (1ULL << 44);
			mask |= (1ULL << 51);
			mask |= (1ULL << 58);
		}
		else if (ch == QChar(0x0424)) // Ô
		{
			mask |= (1ULL << 4);
			mask |= (1ULL << 11);
			mask |= (1ULL << 12);
			mask |= (1ULL << 13);
			mask |= (1ULL << 18);
			mask |= (1ULL << 20);
			mask |= (1ULL << 22);
			mask |= (1ULL << 26);
			mask |= (1ULL << 28);
			mask |= (1ULL << 30);
			mask |= (1ULL << 34);
			mask |= (1ULL << 36);
			mask |= (1ULL << 38);
			mask |= (1ULL << 42);
			mask |= (1ULL << 44);
			mask |= (1ULL << 46);
			mask |= (1ULL << 51);
			mask |= (1ULL << 52);
			mask |= (1ULL << 53);
			mask |= (1ULL << 60);
		}
		else if (ch == QChar(0x0425)) // Õ
		{
			mask |= (1ULL << 1);
			mask |= (1ULL << 5);
			mask |= (1ULL << 9);
			mask |= (1ULL << 13);
			mask |= (1ULL << 18);
			mask |= (1ULL << 20);
			mask |= (1ULL << 27);
			mask |= (1ULL << 34);
			mask |= (1ULL << 36);
			mask |= (1ULL << 42);
			mask |= (1ULL << 44);
			mask |= (1ULL << 49);
			mask |= (1ULL << 53);
			mask |= (1ULL << 57);
			mask |= (1ULL << 61);
		}
		else if (ch == QChar(0x0426)) // Ö
		{
			mask |= (1ULL << 2);
			mask |= (1ULL << 5);
			mask |= (1ULL << 10);
			mask |= (1ULL << 13);
			mask |= (1ULL << 18);
			mask |= (1ULL << 21);
			mask |= (1ULL << 26);
			mask |= (1ULL << 29);
			mask |= (1ULL << 34);
			mask |= (1ULL << 37);
			mask |= (1ULL << 42);
			mask |= (1ULL << 45);
			mask |= (1ULL << 50);
			mask |= (1ULL << 51);
			mask |= (1ULL << 52);
			mask |= (1ULL << 53);
			mask |= (1ULL << 54);
			mask |= (1ULL << 62);
		}
		else if (ch == QChar(0x0427)) // ×
		{
			mask |= (1ULL << 2);
			mask |= (1ULL << 5);
			mask |= (1ULL << 10);
			mask |= (1ULL << 13);
			mask |= (1ULL << 18);
			mask |= (1ULL << 21);
			mask |= (1ULL << 26);
			mask |= (1ULL << 29);
			mask |= (1ULL << 35);
			mask |= (1ULL << 36);
			mask |= (1ULL << 37);
			mask |= (1ULL << 45);
			mask |= (1ULL << 53);
			mask |= (1ULL << 61);
		}
		else if (ch == QChar(0x0428)) // Ø
		{
			mask |= (1ULL << 2);
			mask |= (1ULL << 4);
			mask |= (1ULL << 6);
			mask |= (1ULL << 10);
			mask |= (1ULL << 12);
			mask |= (1ULL << 14);
			mask |= (1ULL << 18);
			mask |= (1ULL << 20);
			mask |= (1ULL << 22);
			mask |= (1ULL << 26);
			mask |= (1ULL << 28);
			mask |= (1ULL << 30);
			mask |= (1ULL << 34);
			mask |= (1ULL << 36);
			mask |= (1ULL << 38);
			mask |= (1ULL << 42);
			mask |= (1ULL << 44);
			mask |= (1ULL << 46);
			mask |= (1ULL << 50);
			mask |= (1ULL << 52);
			mask |= (1ULL << 54);
			mask |= (1ULL << 58);
			mask |= (1ULL << 59);
			mask |= (1ULL << 60);
			mask |= (1ULL << 61);
			mask |= (1ULL << 62);
		}
		else if (ch == QChar(0x0429)) // Ù
		{
			mask |= (1ULL << 2);
			mask |= (1ULL << 4);
			mask |= (1ULL << 6);
			mask |= (1ULL << 10);
			mask |= (1ULL << 12);
			mask |= (1ULL << 14);
			mask |= (1ULL << 18);
			mask |= (1ULL << 20);
			mask |= (1ULL << 22);
			mask |= (1ULL << 26);
			mask |= (1ULL << 28);
			mask |= (1ULL << 30);
			mask |= (1ULL << 34);
			mask |= (1ULL << 36);
			mask |= (1ULL << 38);
			mask |= (1ULL << 42);
			mask |= (1ULL << 44);
			mask |= (1ULL << 46);
			mask |= (1ULL << 50);
			mask |= (1ULL << 51);
			mask |= (1ULL << 52);
			mask |= (1ULL << 53);
			mask |= (1ULL << 54);
			mask |= (1ULL << 55);
			mask |= (1ULL << 63);
		}
		else if (ch == QChar(0x042A)) // Ú
		{
			mask |= (1ULL << 2);
			mask |= (1ULL << 3);
			mask |= (1ULL << 11);
			mask |= (1ULL << 19);
			mask |= (1ULL << 27);
			mask |= (1ULL << 35);
			mask |= (1ULL << 36);
			mask |= (1ULL << 37);
			mask |= (1ULL << 43);
			mask |= (1ULL << 46);
			mask |= (1ULL << 51);
			mask |= (1ULL << 54);
			mask |= (1ULL << 59);
			mask |= (1ULL << 60);
			mask |= (1ULL << 61);
		}
		else if (ch == QChar(0x042B)) // Û
		{
			mask |= (1ULL << 1);
			mask |= (1ULL << 6);
			mask |= (1ULL << 9);
			mask |= (1ULL << 14);
			mask |= (1ULL << 17);
			mask |= (1ULL << 22);
			mask |= (1ULL << 25);
			mask |= (1ULL << 30);
			mask |= (1ULL << 33);
			mask |= (1ULL << 34);
			mask |= (1ULL << 35);
			mask |= (1ULL << 38);
			mask |= (1ULL << 41);
			mask |= (1ULL << 44);
			mask |= (1ULL << 46);
			mask |= (1ULL << 49);
			mask |= (1ULL << 52);
			mask |= (1ULL << 54);
			mask |= (1ULL << 57);
			mask |= (1ULL << 58);
			mask |= (1ULL << 59);
			mask |= (1ULL << 62);
		}
		else if (ch == QChar(0x042C)) // Ü
		{
			mask |= (1ULL << 2);
			mask |= (1ULL << 10);
			mask |= (1ULL << 18);
			mask |= (1ULL << 26);
			mask |= (1ULL << 34);
			mask |= (1ULL << 35);
			mask |= (1ULL << 36);
			mask |= (1ULL << 42);
			mask |= (1ULL << 45);
			mask |= (1ULL << 50);
			mask |= (1ULL << 53);
			mask |= (1ULL << 58);
			mask |= (1ULL << 59);
			mask |= (1ULL << 60);
		}
		else if (ch == QChar(0x042D)) // Ý
		{
			mask |= (1ULL << 2);
			mask |= (1ULL << 3);
			mask |= (1ULL << 4);
			mask |= (1ULL << 13);
			mask |= (1ULL << 21);
			mask |= (1ULL << 26);
			mask |= (1ULL << 27);
			mask |= (1ULL << 28);
			mask |= (1ULL << 29);
			mask |= (1ULL << 37);
			mask |= (1ULL << 45);
			mask |= (1ULL << 53);
			mask |= (1ULL << 58);
			mask |= (1ULL << 59);
			mask |= (1ULL << 60);
		}
		else if (ch == QChar(0x042E)) // Þ
		{
			mask |= (1ULL << 1);
			mask |= (1ULL << 4);
			mask |= (1ULL << 5);
			mask |= (1ULL << 9);
			mask |= (1ULL << 11);
			mask |= (1ULL << 14);
			mask |= (1ULL << 17);
			mask |= (1ULL << 19);
			mask |= (1ULL << 22);
			mask |= (1ULL << 25);
			mask |= (1ULL << 26);
			mask |= (1ULL << 27);
			mask |= (1ULL << 30);
			mask |= (1ULL << 33);
			mask |= (1ULL << 35);
			mask |= (1ULL << 38);
			mask |= (1ULL << 41);
			mask |= (1ULL << 43);
			mask |= (1ULL << 46);
			mask |= (1ULL << 49);
			mask |= (1ULL << 51);
			mask |= (1ULL << 54);
			mask |= (1ULL << 57);
			mask |= (1ULL << 60);
			mask |= (1ULL << 61);
		}
		else if (ch == QChar(0x042F)) // ß
		{
			mask |= (1ULL << 3);
			mask |= (1ULL << 4);
			mask |= (1ULL << 5);
			mask |= (1ULL << 10);
			mask |= (1ULL << 13);
			mask |= (1ULL << 18);
			mask |= (1ULL << 21);
			mask |= (1ULL << 27);
			mask |= (1ULL << 28);
			mask |= (1ULL << 29);
			mask |= (1ULL << 36);
			mask |= (1ULL << 37);
			mask |= (1ULL << 43);
			mask |= (1ULL << 45);
			mask |= (1ULL << 50);
			mask |= (1ULL << 53);
			mask |= (1ULL << 58);
			mask |= (1ULL << 61);
		}
		else if (ch == QChar(0x0430)) // à
		{
			mask |= (1ULL << 26);
			mask |= (1ULL << 27);
			mask |= (1ULL << 36);
			mask |= (1ULL << 43);
			mask |= (1ULL << 44);
			mask |= (1ULL << 50);
			mask |= (1ULL << 52);
			mask |= (1ULL << 59);
			mask |= (1ULL << 60);
			mask |= (1ULL << 61);
		}
		else if (ch == QChar(0x0431)) // á
		{
			mask |= (1ULL << 11);
			mask |= (1ULL << 12);
			mask |= (1ULL << 18);
			mask |= (1ULL << 26);
			mask |= (1ULL << 34);
			mask |= (1ULL << 35);
			mask |= (1ULL << 42);
			mask |= (1ULL << 44);
			mask |= (1ULL << 50);
			mask |= (1ULL << 52);
			mask |= (1ULL << 58);
			mask |= (1ULL << 59);
		}
		else if (ch == QChar(0x0432)) // â
		{
			mask |= (1ULL << 18);
			mask |= (1ULL << 19);
			mask |= (1ULL << 26);
			mask |= (1ULL << 28);
			mask |= (1ULL << 34);
			mask |= (1ULL << 35);
			mask |= (1ULL << 42);
			mask |= (1ULL << 44);
			mask |= (1ULL << 50);
			mask |= (1ULL << 52);
			mask |= (1ULL << 58);
			mask |= (1ULL << 59);
		}
		else if (ch == QChar(0x0433)) // ã
		{
			mask |= (1ULL << 34);
			mask |= (1ULL << 35);
			mask |= (1ULL << 36);
			mask |= (1ULL << 42);
			mask |= (1ULL << 50);
			mask |= (1ULL << 58);
		}
		else if (ch == QChar(0x0434)) // ä
		{
			mask |= (1ULL << 28);
			mask |= (1ULL << 35);
			mask |= (1ULL << 37);
			mask |= (1ULL << 43);
			mask |= (1ULL << 45);
			mask |= (1ULL << 50);
			mask |= (1ULL << 51);
			mask |= (1ULL << 52);
			mask |= (1ULL << 53);
			mask |= (1ULL << 54);
			mask |= (1ULL << 62);
			mask |= (1ULL << 58);
		}
		else if (ch == QChar(0x0435)) // å
		{
			mask |= (1ULL << 27);
			mask |= (1ULL << 34);
			mask |= (1ULL << 36);
			mask |= (1ULL << 42);
			mask |= (1ULL << 43);
			mask |= (1ULL << 44);
			mask |= (1ULL << 50);
			mask |= (1ULL << 59);
			mask |= (1ULL << 60);
		}
		else if (ch == QChar(0x0451)) // ¸
		{
			mask |= (1ULL << 10);
			mask |= (1ULL << 12);
			mask |= (1ULL << 27);
			mask |= (1ULL << 34);
			mask |= (1ULL << 36);
			mask |= (1ULL << 42);
			mask |= (1ULL << 43);
			mask |= (1ULL << 44);
			mask |= (1ULL << 50);
			mask |= (1ULL << 59);
			mask |= (1ULL << 60);
		}
		else if (ch == QChar(0x0436)) // æ
		{
			mask |= (1ULL << 25);
			mask |= (1ULL << 27);
			mask |= (1ULL << 29);
			mask |= (1ULL << 33);
			mask |= (1ULL << 35);
			mask |= (1ULL << 37);
			mask |= (1ULL << 42);
			mask |= (1ULL << 43);
			mask |= (1ULL << 44);
			mask |= (1ULL << 49);
			mask |= (1ULL << 51);
			mask |= (1ULL << 53);
			mask |= (1ULL << 57);
			mask |= (1ULL << 59);
			mask |= (1ULL << 61);
		}
		else if (ch == QChar(0x0437)) // ç
		{
			mask |= (1ULL << 26);
			mask |= (1ULL << 27);
			mask |= (1ULL << 36);
			mask |= (1ULL << 42);
			mask |= (1ULL << 43);
			mask |= (1ULL << 52);
			mask |= (1ULL << 58);
			mask |= (1ULL << 59);
		}
		else if (ch == QChar(0x0438)) // è
		{
			mask |= (1ULL << 26);
			mask |= (1ULL << 29);
			mask |= (1ULL << 34);
			mask |= (1ULL << 37);
			mask |= (1ULL << 42);
			mask |= (1ULL << 44);
			mask |= (1ULL << 45);
			mask |= (1ULL << 50);
			mask |= (1ULL << 51);
			mask |= (1ULL << 53);
			mask |= (1ULL << 58);
			mask |= (1ULL << 61);
		}
		else if (ch == QChar(0x0439)) // é
		{
			mask |= (1ULL << 11);
			mask |= (1ULL << 12);
			mask |= (1ULL << 26);
			mask |= (1ULL << 29);
			mask |= (1ULL << 34);
			mask |= (1ULL << 37);
			mask |= (1ULL << 42);
			mask |= (1ULL << 44);
			mask |= (1ULL << 45);
			mask |= (1ULL << 50);
			mask |= (1ULL << 51);
			mask |= (1ULL << 53);
			mask |= (1ULL << 58);
			mask |= (1ULL << 61);
		}
		else if (ch == QChar(0x043A)) // ê
		{
			mask |= (1ULL << 26);
			mask |= (1ULL << 28);
			mask |= (1ULL << 34);
			mask |= (1ULL << 36);
			mask |= (1ULL << 42);
			mask |= (1ULL << 43);
			mask |= (1ULL << 50);
			mask |= (1ULL << 52);
			mask |= (1ULL << 58);
			mask |= (1ULL << 60);
		}
		else if (ch == QChar(0x043B)) // ë
		{
			mask |= (1ULL << 35);
			mask |= (1ULL << 36);
			mask |= (1ULL << 42);
			mask |= (1ULL << 44);
			mask |= (1ULL << 50);
			mask |= (1ULL << 52);
			mask |= (1ULL << 58);
			mask |= (1ULL << 60);
		}
		else if (ch == QChar(0x043C)) // ì
		{
			mask |= (1ULL << 25);
			mask |= (1ULL << 29);
			mask |= (1ULL << 33);
			mask |= (1ULL << 34);
			mask |= (1ULL << 36);
			mask |= (1ULL << 37);
			mask |= (1ULL << 41);
			mask |= (1ULL << 43);
			mask |= (1ULL << 45);
			mask |= (1ULL << 49);
			mask |= (1ULL << 53);
			mask |= (1ULL << 57);
			mask |= (1ULL << 61);
		}
		else if (ch == QChar(0x043D)) // í
		{
			mask |= (1ULL << 26);
			mask |= (1ULL << 28);
			mask |= (1ULL << 34);
			mask |= (1ULL << 36);
			mask |= (1ULL << 42);
			mask |= (1ULL << 43);
			mask |= (1ULL << 44);
			mask |= (1ULL << 50);
			mask |= (1ULL << 52);
			mask |= (1ULL << 58);
			mask |= (1ULL << 60);
		}
		else if (ch == QChar(0x043E)) // î
		{
			mask |= (1ULL << 27);
			mask |= (1ULL << 28);
			mask |= (1ULL << 34);
			mask |= (1ULL << 37);
			mask |= (1ULL << 42);
			mask |= (1ULL << 45);
			mask |= (1ULL << 50);
			mask |= (1ULL << 53);
			mask |= (1ULL << 59);
			mask |= (1ULL << 60);
		}
		else if (ch == QChar(0x043F)) // ï
		{
			mask |= (1ULL << 26);
			mask |= (1ULL << 27);
			mask |= (1ULL << 28);
			mask |= (1ULL << 29);
			mask |= (1ULL << 34);
			mask |= (1ULL << 37);
			mask |= (1ULL << 42);
			mask |= (1ULL << 45);
			mask |= (1ULL << 50);
			mask |= (1ULL << 53);
			mask |= (1ULL << 58);
			mask |= (1ULL << 61);
		}
		else if (ch == QChar(0x0440)) // ð
		{
			mask |= (1ULL << 26);
			mask |= (1ULL << 27);
			mask |= (1ULL << 28);
			mask |= (1ULL << 34);
			mask |= (1ULL << 36);
			mask |= (1ULL << 42);
			mask |= (1ULL << 43);
			mask |= (1ULL << 44);
			mask |= (1ULL << 50);
			mask |= (1ULL << 58);
		}
		else if (ch == QChar(0x0441)) // ñ
		{
			mask |= (1ULL << 26);
			mask |= (1ULL << 27);
			mask |= (1ULL << 28);
			mask |= (1ULL << 34);
			mask |= (1ULL << 42);
			mask |= (1ULL << 50);
			mask |= (1ULL << 58);
			mask |= (1ULL << 59);
			mask |= (1ULL << 60);
		}
		else if (ch == QChar(0x0442)) // ò
		{
			mask |= (1ULL << 26);
			mask |= (1ULL << 27);
			mask |= (1ULL << 28);
			mask |= (1ULL << 35);
			mask |= (1ULL << 43);
			mask |= (1ULL << 51);
			mask |= (1ULL << 59);
		}
		else if (ch == QChar(0x0443)) // ó
		{
			mask |= (1ULL << 26);
			mask |= (1ULL << 28);
			mask |= (1ULL << 34);
			mask |= (1ULL << 36);
			mask |= (1ULL << 43);
			mask |= (1ULL << 44);
			mask |= (1ULL << 52);
			mask |= (1ULL << 58);
			mask |= (1ULL << 59);
		}
		else if (ch == QChar(0x0444)) // ô
		{
			mask |= (1ULL << 19);
			mask |= (1ULL << 26);
			mask |= (1ULL << 27);
			mask |= (1ULL << 28);
			mask |= (1ULL << 33);
			mask |= (1ULL << 35);
			mask |= (1ULL << 37);
			mask |= (1ULL << 42);
			mask |= (1ULL << 43);
			mask |= (1ULL << 44);
			mask |= (1ULL << 51);
			mask |= (1ULL << 59);
		}
		else if (ch == QChar(0x0445)) // õ
		{
			mask |= (1ULL << 26);
			mask |= (1ULL << 28);
			mask |= (1ULL << 34);
			mask |= (1ULL << 36);
			mask |= (1ULL << 43);
			mask |= (1ULL << 50);
			mask |= (1ULL << 52);
			mask |= (1ULL << 58);
			mask |= (1ULL << 60);
		}
		else if (ch == QChar(0x0446)) // ö
		{
			mask |= (1ULL << 26);
			mask |= (1ULL << 28);
			mask |= (1ULL << 34);
			mask |= (1ULL << 36);
			mask |= (1ULL << 42);
			mask |= (1ULL << 44);
			mask |= (1ULL << 50);
			mask |= (1ULL << 51);
			mask |= (1ULL << 52);
			mask |= (1ULL << 53);
			mask |= (1ULL << 61);
		}
		else if (ch == QChar(0x0447)) // ÷
		{
			mask |= (1ULL << 27);
			mask |= (1ULL << 29);
			mask |= (1ULL << 35);
			mask |= (1ULL << 37);
			mask |= (1ULL << 43);
			mask |= (1ULL << 44);
			mask |= (1ULL << 45);
			mask |= (1ULL << 53);
			mask |= (1ULL << 61);
		}
		else if (ch == QChar(0x0448)) // ø
		{
			mask |= (1ULL << 26);
			mask |= (1ULL << 28);
			mask |= (1ULL << 30);
			mask |= (1ULL << 34);
			mask |= (1ULL << 36);
			mask |= (1ULL << 38);
			mask |= (1ULL << 42);
			mask |= (1ULL << 44);
			mask |= (1ULL << 46);
			mask |= (1ULL << 50);
			mask |= (1ULL << 52);
			mask |= (1ULL << 54);
			mask |= (1ULL << 58);
			mask |= (1ULL << 59);
			mask |= (1ULL << 60);
			mask |= (1ULL << 61);
			mask |= (1ULL << 62);
		}
		else if (ch == QChar(0x0449)) // ù
		{
			mask |= (1ULL << 26);
			mask |= (1ULL << 28);
			mask |= (1ULL << 30);
			mask |= (1ULL << 34);
			mask |= (1ULL << 36);
			mask |= (1ULL << 38);
			mask |= (1ULL << 42);
			mask |= (1ULL << 44);
			mask |= (1ULL << 46);
			mask |= (1ULL << 50);
			mask |= (1ULL << 51);
			mask |= (1ULL << 52);
			mask |= (1ULL << 53);
			mask |= (1ULL << 54);
			mask |= (1ULL << 55);
			mask |= (1ULL << 63);
		}
		else if (ch == QChar(0x044A)) // ú
		{
			mask |= (1ULL << 26);
			mask |= (1ULL << 27);
			mask |= (1ULL << 35);
			mask |= (1ULL << 43);
			mask |= (1ULL << 44);
			mask |= (1ULL << 51);
			mask |= (1ULL << 53);
			mask |= (1ULL << 59);
			mask |= (1ULL << 60);
		}
		else if (ch == QChar(0x044B)) // û
		{
			mask |= (1ULL << 26);
			mask |= (1ULL << 30);
			mask |= (1ULL << 34);
			mask |= (1ULL << 38);
			mask |= (1ULL << 42);
			mask |= (1ULL << 43);
			mask |= (1ULL << 46);
			mask |= (1ULL << 50);
			mask |= (1ULL << 52);
			mask |= (1ULL << 54);
			mask |= (1ULL << 58);
			mask |= (1ULL << 59);
			mask |= (1ULL << 62);
		}
		else if (ch == QChar(0x044C)) // ü
		{
			mask |= (1ULL << 26);
			mask |= (1ULL << 34);
			mask |= (1ULL << 42);
			mask |= (1ULL << 43);
			mask |= (1ULL << 50);
			mask |= (1ULL << 52);
			mask |= (1ULL << 58);
			mask |= (1ULL << 59);
		}
		else if (ch == QChar(0x044D)) // ý
		{
			mask |= (1ULL << 26);
			mask |= (1ULL << 27);
			mask |= (1ULL << 36);
			mask |= (1ULL << 42);
			mask |= (1ULL << 43);
			mask |= (1ULL << 44);
			mask |= (1ULL << 52);
			mask |= (1ULL << 58);
			mask |= (1ULL << 59);
		}
		else if (ch == QChar(0x044E)) // þ
		{
			mask |= (1ULL << 26);
			mask |= (1ULL << 29);
			mask |= (1ULL << 34);
			mask |= (1ULL << 36);
			mask |= (1ULL << 38);
			mask |= (1ULL << 42);
			mask |= (1ULL << 43);
			mask |= (1ULL << 44);
			mask |= (1ULL << 46);
			mask |= (1ULL << 50);
			mask |= (1ULL << 52);
			mask |= (1ULL << 54);
			mask |= (1ULL << 58);
			mask |= (1ULL << 61);
		}
		else if (ch == QChar(0x044F)) // ÿ
		{
			mask |= (1ULL << 27);
			mask |= (1ULL << 28);
			mask |= (1ULL << 34);
			mask |= (1ULL << 36);
			mask |= (1ULL << 43);
			mask |= (1ULL << 44);
			mask |= (1ULL << 50);
			mask |= (1ULL << 52);
			mask |= (1ULL << 58);
			mask |= (1ULL << 60);
		}
		else if (ch == '.')
		{
			mask |= (1ULL << 59);
		}
		else if (ch == ',')
		{
			mask |= (1ULL << 52);
			mask |= (1ULL << 59);
		}
		else if (ch == ';')
		{
			mask |= (1ULL << 28);
			mask |= (1ULL << 52);
			mask |= (1ULL << 59);
		}
		else if (ch == ':')
		{
			mask |= (1ULL << 28);
			mask |= (1ULL << 60);
		}
		else if (ch == '!')
		{
			mask |= (1ULL << 28);
			mask |= (1ULL << 36);
			mask |= (1ULL << 44);
			mask |= (1ULL << 60);
		}
		else if (ch == '?')
		{
			mask |= (1ULL << 20);
			mask |= (1ULL << 21);
			mask |= (1ULL << 29);
			mask |= (1ULL << 36);
			mask |= (1ULL << 37);
			mask |= (1ULL << 44);
			mask |= (1ULL << 60);
		}
		else if (ch == '-')
		{
			mask |= (1ULL << 44);
			mask |= (1ULL << 45);
		}
		else if (ch == '(')
		{
			mask |= (1ULL << 27);
			mask |= (1ULL << 28);
			mask |= (1ULL << 34);
			mask |= (1ULL << 42);
			mask |= (1ULL << 50);
			mask |= (1ULL << 59);
			mask |= (1ULL << 60);
		}
		else if (ch == ')')
		{
			mask |= (1ULL << 27);
			mask |= (1ULL << 28);
			mask |= (1ULL << 37);
			mask |= (1ULL << 45);
			mask |= (1ULL << 53);
			mask |= (1ULL << 59);
			mask |= (1ULL << 60);
		}
		else if (ch == '[')
		{
			mask |= (1ULL << 26);
			mask |= (1ULL << 27);
			mask |= (1ULL << 28);
			mask |= (1ULL << 34);
			mask |= (1ULL << 42);
			mask |= (1ULL << 50);
			mask |= (1ULL << 58);
			mask |= (1ULL << 59);
			mask |= (1ULL << 60);
		}
		else if (ch == ']')
		{

			mask |= (1ULL << 27);
			mask |= (1ULL << 28);
			mask |= (1ULL << 29);
			mask |= (1ULL << 37);
			mask |= (1ULL << 45);
			mask |= (1ULL << 53);
			mask |= (1ULL << 59);
			mask |= (1ULL << 60);
			mask |= (1ULL << 61);
		}
		else if (ch == ' ')
		{

		}
		else if (ch == '0')
		{
			mask |= (1ULL << 19);
			mask |= (1ULL << 20);
			mask |= (1ULL << 26);
			mask |= (1ULL << 29);
			mask |= (1ULL << 34);
			mask |= (1ULL << 37);
			mask |= (1ULL << 42);
			mask |= (1ULL << 45);
			mask |= (1ULL << 50);
			mask |= (1ULL << 53);
			mask |= (1ULL << 59);
			mask |= (1ULL << 60);
		}
		else if (ch == '1')
		{
			mask |= (1ULL << 19);
			mask |= (1ULL << 26);
			mask |= (1ULL << 27);
			mask |= (1ULL << 35);
			mask |= (1ULL << 43);
			mask |= (1ULL << 51);
			mask |= (1ULL << 58);
			mask |= (1ULL << 59);
			mask |= (1ULL << 60);
		}
		else if (ch == '2')
		{
			mask |= (1ULL << 18);
			mask |= (1ULL << 19);
			mask |= (1ULL << 28);
			mask |= (1ULL << 36);
			mask |= (1ULL << 42);
			mask |= (1ULL << 43);
			mask |= (1ULL << 50);
			mask |= (1ULL << 58);
			mask |= (1ULL << 59);
			mask |= (1ULL << 60);
		}
		else if (ch == '3')
		{
			mask |= (1ULL << 18);
			mask |= (1ULL << 19);
			mask |= (1ULL << 28);
			mask |= (1ULL << 34);
			mask |= (1ULL << 35);
			mask |= (1ULL << 44);
			mask |= (1ULL << 52);
			mask |= (1ULL << 58);
			mask |= (1ULL << 59);
		}
		else if (ch == '4')
		{
			mask |= (1ULL << 18);
			mask |= (1ULL << 20);
			mask |= (1ULL << 26);
			mask |= (1ULL << 28);
			mask |= (1ULL << 34);
			mask |= (1ULL << 35);
			mask |= (1ULL << 36);
			mask |= (1ULL << 44);
			mask |= (1ULL << 52);
			mask |= (1ULL << 60);
		}
		else if (ch == '5')
		{
			mask |= (1ULL << 18);
			mask |= (1ULL << 19);
			mask |= (1ULL << 20);
			mask |= (1ULL << 26);
			mask |= (1ULL << 34);
			mask |= (1ULL << 35);
			mask |= (1ULL << 44);
			mask |= (1ULL << 52);
			mask |= (1ULL << 58);
			mask |= (1ULL << 59);
		}
		else if (ch == '6')
		{
			mask |= (1ULL << 19);
			mask |= (1ULL << 20);
			mask |= (1ULL << 26);
			mask |= (1ULL << 34);
			mask |= (1ULL << 35);
			mask |= (1ULL << 42);
			mask |= (1ULL << 44);
			mask |= (1ULL << 50);
			mask |= (1ULL << 52);
			mask |= (1ULL << 58);
			mask |= (1ULL << 59);
		}
		else if (ch == '7')
		{
			mask |= (1ULL << 18);
			mask |= (1ULL << 19);
			mask |= (1ULL << 20);
			mask |= (1ULL << 28);
			mask |= (1ULL << 36);
			mask |= (1ULL << 43);
			mask |= (1ULL << 51);
			mask |= (1ULL << 59);
		}
		else if (ch == '8')
		{
			mask |= (1ULL << 19);
			mask |= (1ULL << 26);
			mask |= (1ULL << 28);
			mask |= (1ULL << 35);
			mask |= (1ULL << 42);
			mask |= (1ULL << 44);
			mask |= (1ULL << 50);
			mask |= (1ULL << 52);
			mask |= (1ULL << 58);
			mask |= (1ULL << 59);
			mask |= (1ULL << 60);
		}
		else if (ch == '9')
		{
			mask |= (1ULL << 18);
			mask |= (1ULL << 19);
			mask |= (1ULL << 26);
			mask |= (1ULL << 28);
			mask |= (1ULL << 34);
			mask |= (1ULL << 35);
			mask |= (1ULL << 36);
			mask |= (1ULL << 44);
			mask |= (1ULL << 52);
			mask |= (1ULL << 58);
			mask |= (1ULL << 59);
		}
		return mask;
	}
};