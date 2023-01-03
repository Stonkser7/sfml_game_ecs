#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>
#include <cassert>

#include "Entity.h"
#include "Signature.h"
#include "SystemOnUpdate.h"
#include "SystemOnRender.h"

class ECSManager;

class SystemManager
{
public:
	template <typename T>
	void addSystemOnUpdate(ECSManager& manager);

	template <typename T>
	void addSystemOnRender(ECSManager& manager, sf::RenderWindow& window);

	void entitySignatureUpdated(EntityID entity, const Signature& signature);
	void entityDestroyed(EntityID entity);

	void update();
	void render();
private:
	std::vector<std::shared_ptr<SystemOnUpdate>> m_systems_on_update;
	std::vector<std::shared_ptr<SystemOnRender>> m_systems_on_render;
};

template<typename T>
inline void SystemManager::addSystemOnUpdate(ECSManager& manager)
{
	m_systems_on_update.push_back(std::make_shared<T>(manager));
}

template<typename T>
inline void SystemManager::addSystemOnRender(ECSManager& manager, sf::RenderWindow& window)
{
	m_systems_on_render.push_back(std::make_shared<T>(manager, window));
}
