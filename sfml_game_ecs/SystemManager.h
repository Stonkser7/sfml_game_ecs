#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>
#include <cassert>

#include "Entity.h"
#include "Signature.h"
#include "SystemOnUpdate.h"
#include "SystemOnDraw.h"

class ECSManager;

class SystemManager
{
public:
	void update();
	void draw();

	template <typename T>
	void addSystemOnUpdate(ECSManager& manager);

	template <typename T>
	void addSystemOnDraw(ECSManager& manager, sf::RenderWindow& window);

	void entitySignatureUpdated(EntityID entity, const Signature& signature);
	void entityDestroyed(EntityID entity);
private:
	std::vector<std::shared_ptr<SystemOnUpdate>> m_systems_on_update;
	std::vector<std::shared_ptr<SystemOnDraw>> m_systems_on_draw;
};

template<typename T>
inline void SystemManager::addSystemOnUpdate(ECSManager& manager)
{
	m_systems_on_update.push_back(std::make_shared<T>(manager));
}

template<typename T>
inline void SystemManager::addSystemOnDraw(ECSManager& manager, sf::RenderWindow& window)
{
	m_systems_on_draw.push_back(std::make_shared<T>(manager, window));
}
