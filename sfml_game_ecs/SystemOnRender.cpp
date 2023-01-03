#include "SystemOnRender.h"

SystemOnRender::SystemOnRender(ECSManager& manager, sf::RenderWindow& window) : m_ecs_manager{ manager }, m_window{ window } {}