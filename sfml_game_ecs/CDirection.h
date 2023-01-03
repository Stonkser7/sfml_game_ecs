#pragma once

#include <SFML/Graphics.hpp>
#include "Tools.h"


class CDirection
{
public:
	CDirection();
	CDirection(const sf::Vector2f& vec);
	CDirection(const CDirection& dir);

	sf::Vector2f& operator=(const sf::Vector2f& right);
	CDirection& operator=(const CDirection& right);

	void setX(float x);
	void setY(float y);

	sf::Vector2f asVec2f() const;

private:
	sf::Vector2f m_dir;
};