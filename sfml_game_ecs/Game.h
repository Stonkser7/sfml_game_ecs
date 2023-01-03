#pragma once

#include <SFML/Graphics.hpp>
#include "ECSManager.h"

class Game
{
public:
	Game(Game&) = delete;
	
	Game();
	void run();
private:
	sf::RenderWindow m_window;
	ECSManager m_ecs_manager;

	void update();
	void render();
};

