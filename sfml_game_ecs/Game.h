#pragma once

#include <SFML/Graphics.hpp>
#include "ECSManager.h"

#include "Component.h"

#include "CPosition.h"
#include "CRotation.h"
#include "CDirection.h"
#include "CAcceleration.h"
#include "CSpeed.h"
#include "CSprite.h"

#include "SMove.h"
#include "SDraw.h"

#include <random>
#include <ctime>

class Game
{
public:
	Game(Game&) = delete;
	
	Game();

	void run();
private:
	sf::RenderWindow m_window;
	ECSManager m_ecs_manager;
	sf::Texture texture_test;

	void update();
	void render();
};

