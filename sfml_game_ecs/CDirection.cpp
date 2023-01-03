#include "CDirection.h"

CDirection::CDirection() :m_dir() {}

CDirection::CDirection(const sf::Vector2f& vec)
{
	m_dir = tool::normalized(vec);
}

CDirection::CDirection(const CDirection& dir)
{
	m_dir = dir.asVec2f();
}

sf::Vector2f& CDirection::operator=(const sf::Vector2f& right)
{
	m_dir = tool::normalized(right);
	return m_dir;
}

CDirection& CDirection::operator=(const CDirection& right)
{
	m_dir = right.asVec2f();
	return *this;
}

void CDirection::setX(float x)
{
	m_dir.x = x;
}

void CDirection::setY(float y)
{
	m_dir.y = y;
}

sf::Vector2f CDirection::asVec2f() const
{
	return m_dir;
}


