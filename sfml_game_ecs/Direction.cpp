#include "Direction.h"

Direction::Direction() :m_dir() {}

Direction::Direction(const sf::Vector2f& vec)
{
	m_dir = tool::normalized(vec);
}

Direction::Direction(const Direction& dir)
{
	m_dir = dir.asVec2f();
}

sf::Vector2f& Direction::operator=(const sf::Vector2f& right)
{
	m_dir = tool::normalized(right);
	return m_dir;
}

Direction& Direction::operator=(const Direction& right)
{
	m_dir = right.asVec2f();
	return *this;
}

sf::Vector2f Direction::asVec2f() const
{
	return m_dir;
}


