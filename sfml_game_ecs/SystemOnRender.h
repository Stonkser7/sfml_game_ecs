#pragma once

#include "BaseSystem.h"
#include <SFML/Graphics.hpp>

class ECSManager;

class SystemOnRender : public BaseSystem
{
public:
	SystemOnRender() = delete;
	SystemOnRender(SystemOnRender&) = delete;

	virtual void render() = 0;
protected:
	SystemOnRender(ECSManager& manager, sf::RenderWindow& window);
	ECSManager& m_ecs_manager;
	sf::RenderWindow& m_window;
};

