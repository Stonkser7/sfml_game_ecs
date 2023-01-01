#include "SystemOnDraw.h"

SystemOnDraw::SystemOnDraw(ECSManager& manager, sf::RenderWindow& window) : m_ecs_manager{ manager }, m_window{ window } {};