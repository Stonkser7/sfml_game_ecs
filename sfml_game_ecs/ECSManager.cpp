#include "ECSManager.h"

ECSManager::ECSManager()
{
	m_entity_manager = std::make_unique<EntityManager>();
	m_component_manager = std::make_unique<ComponentManager>();
	m_system_manager = std::make_unique<SystemManager>();
}

EntityID ECSManager::createEntity()
{
	return m_entity_manager->createEntity();
}

void ECSManager::destroyEntity(EntityID entity)
{
	m_entity_manager->destroyEntity(entity);
	m_component_manager->removeAllComponents(entity);
	m_system_manager->entityDestroyed(entity);
}
