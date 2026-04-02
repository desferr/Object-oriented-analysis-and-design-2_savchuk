#pragma once

#include <QHash>
#include <memory>
#include "Flyweight.h"
#include "CharFlyweight.h"

class FlyweightFactory
{
private:
	static QHash<QChar, std::shared_ptr<Flyweight>> m_cache;

public:
	static std::shared_ptr<Flyweight> getFlyweight(QChar ch);
	static uint64_t getMaskForChar(QChar ch);
};