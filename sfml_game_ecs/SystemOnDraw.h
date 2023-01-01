#pragma once

#include "BaseSystem.h"
#include <SFML/Graphics.hpp>

class ECSManager;

class SystemOnDraw : public BaseSystem
{
public:
	SystemOnDraw() = delete;
	SystemOnDraw(SystemOnDraw&) = delete;

	virtual void draw() = 0;
protected:
	SystemOnDraw(ECSManager& manager, sf::RenderWindow& window);
private:
	ECSManager& m_ecs_manager;
	sf::RenderWindow& m_window;
};

