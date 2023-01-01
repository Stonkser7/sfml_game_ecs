#pragma once

#include <memory>
#include <unordered_map>
#include <cassert>

#include "EntityManager.h"
#include "ComponentManager.h"
#include "SystemManager.h"


class ECSManager
{
public:
	ECSManager();

	EntityID createEntity();
	void destroyEntity(EntityID entity);

	template <typename T>
	void registerComponent(ComponentID component_id);

	template <typename T>
	void addSystemOnUpdate();

	template <typename T>
	void addSystemOnDraw(sf::RenderWindow& window);

	template <typename T>
	bool assignComponent(EntityID entity);

	template <typename T>
	bool removeComponent(EntityID entity);

	template <typename T>
	T& getComponent(EntityID entity);

	void onUpdate();
	void onDraw();
private:
	std::unique_ptr<EntityManager> m_entity_manager;
	std::unique_ptr<ComponentManager> m_component_manager;
	std::unique_ptr<SystemManager> m_system_manager;

	std::unordered_map<ComponentName, ComponentID> m_components;
};

template<typename T>
inline void ECSManager::registerComponent(ComponentID component_id)
{
	assert(m_components.find(typeid(T).name()) == m_components.end() && "ECSManager: attempt to register already registered component");

	m_components.insert({ typeid(T).name(), component_id });
	m_component_manager->registerComponent<T>();
}

template<typename T>
inline void ECSManager::addSystemOnUpdate()
{
	m_system_manager->addSystemOnUpdate<T>(*this);
}

template<typename T>
inline void ECSManager::addSystemOnDraw(sf::RenderWindow& window)
{
	m_system_manager->addSystemOnDraw<T>(*this, window);
}

template<typename T>
inline bool ECSManager::assignComponent(EntityID entity)
{
	assert(m_components.find(typeid(T).name()) != m_components.end() && "ECSManager: attempt to assign unregistered component");

	bool assigned = m_entity_manager->assignComponent(entity, m_components[typeid(T).name()]);

	if (assigned) {
		m_component_manager->assignComponent<T>(entity);
		m_system_manager->entitySignatureUpdated(entity, m_entity_manager->getSignature(entity));
	}

	return assigned;
}

template<typename T>
inline bool ECSManager::removeComponent(EntityID entity)
{
	assert(m_components.find(typeid(T).name()) != m_components.end() && "ECSManager: attempt to remove unregistered component");

	bool removed = m_entity_manager->removeComponent(entity, m_components[typeid(T).name()]);

	if (removed) {
		m_component_manager->removeComponent<T>(entity);
		m_system_manager->entitySignatureUpdated(entity, m_entity_manager->getSignature(entity);
	}

	return removed;
}

template<typename T>
inline T& ECSManager::getComponent(EntityID entity)
{
	assert(m_components.find(typeid(T).name()) != m_components.end() && "ECSManager: attempt to get unregistered component");

	return m_component_manager->getComponent<T>(entity);
}
