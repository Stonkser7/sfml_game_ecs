#include "EntityManager.h"

EntityManager::EntityManager()
{
	for (size_t i = 0; i < MAX_ENTITIES; ++i) {
		m_availableEntities.push(i);
	}
}

EntityID EntityManager::createEntity()
{
	assert(!m_availableEntities.empty() && "number of entities overflowed");

	EntityID newEntity = m_availableEntities.front();

	m_engagedEntities[newEntity];
	m_availableEntities.pop();

	return newEntity;
}

/// <summary>
/// 
/// </summary>
/// <param name="entity"></param>
/// <param name="component"></param>
/// <returns>True if component was assigned</returns>
bool EntityManager::assignComponent(EntityID entity, ComponentID component)
{
	assert(m_engagedEntities.find(entity) != m_engagedEntities.end() && "EntityManager::assignComponent(): Requested entity doesn't available");

	if (m_engagedEntities[entity][component]) return false;	//check if already assigned

	m_engagedEntities[entity][component] = true;
	return true;
}
