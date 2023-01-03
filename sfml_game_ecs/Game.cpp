#include "Game.h"

Game::Game()
{
	m_window.create(sf::VideoMode(1920, 1080), "ECS GAME", sf::Style::Default);
	m_ecs_manager.init();
}

void Game::run()
{

	sf::Clock frame_clock;
	sf::Time lag;
	sf::Time current;
	const float UPDATE_TIME_STEP = 0.0166;
	while (m_window.isOpen()) {
		current = frame_clock.getElapsedTime();

		sf::Event event;
		while (m_window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				m_window.close();
			}
		}

		while (lag >= sf::seconds(UPDATE_TIME_STEP)) {
			update();
		}

		render();

		lag += frame_clock.getElapsedTime() - current;
	}
}

void Game::update()
{
	m_ecs_manager.onUpdate();
}

void Game::render()
{
	m_window.clear();

	m_ecs_manager.onDraw();

	m_window.display();
}
