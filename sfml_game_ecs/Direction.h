#pragma once

#include <SFML/Graphics.hpp>
#include "Tools.h"


class Direction
{
public:
	Direction();
	Direction(const sf::Vector2f& vec);
	Direction(const Direction& dir);

	sf::Vector2f& operator=(const sf::Vector2f& right);
	Direction& operator=(const Direction& right);

	sf::Vector2f asVec2f() const;

private:
	sf::Vector2f m_dir;
};