#include "Game.h"

Game::Game()
{
	m_window.create(sf::VideoMode(1920, 1080), "ECS GAME", sf::Style::Default);
	m_ecs_manager.init();

	m_ecs_manager.registerComponent<CPosition>(ComponentID::Position);
	m_ecs_manager.registerComponent<CRotation>(ComponentID::Rotation);
	m_ecs_manager.registerComponent<CDirection>(ComponentID::Direction);
	m_ecs_manager.registerComponent<CAcceleration>(ComponentID::Acceleration);
	m_ecs_manager.registerComponent<CSpeed>(ComponentID::Speed);
	m_ecs_manager.registerComponent<CSprite>(ComponentID::Sprite);

	m_ecs_manager.addSystemOnUpdate<SMove>();
	m_ecs_manager.addSystemOnRender<SDraw>(m_window);

	texture_test.loadFromFile("Textures/basePlayerTexture.png");

	std::default_random_engine random_engine;
	random_engine.seed(std::time(0));
	std::uniform_real_distribution<float> dist(0, m_window.getSize().y);

	for (int i = 0; i < MAX_ENTITIES; ++i) {
		EntityID e = m_ecs_manager.createEntity();

		m_ecs_manager.assignComponent<CPosition>(e);
		m_ecs_manager.assignComponent<CDirection>(e);
		m_ecs_manager.assignComponent<CSpeed>(e);
		m_ecs_manager.assignComponent<CRotation>(e);
		m_ecs_manager.assignComponent<CSprite>(e);

		CPosition& pos = m_ecs_manager.getComponent<CPosition>(e);
		pos.vector.x = 0;
		pos.vector.y = dist(random_engine);

		m_ecs_manager.getComponent<CDirection>(e) = sf::Vector2f(1, 0);

		m_ecs_manager.getComponent<CSpeed>(e).value = 5;

		m_ecs_manager.getComponent<CRotation>(e).angle = 90;

		CSprite& sprite = m_ecs_manager.getComponent<CSprite>(e);
		sprite.value.setTexture(texture_test);
		sprite.value.setOrigin(texture_test.getSize().x / 2.f, texture_test.getSize().y / 2.f);
	}

	EntityID id = 1;
	m_ecs_manager.removeComponent<CSpeed>(id);
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
			lag -= sf::seconds(UPDATE_TIME_STEP);
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

	m_ecs_manager.onRender();

	m_window.display();
}
