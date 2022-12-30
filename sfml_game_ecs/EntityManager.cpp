#include "EntityManager.h"

EntityManager::EntityManager()
{
	for (EntityID id = 0; id < MAX_ENTITIES; ++id) {
		m_availableEntities.push(id);
	}
}

EntityID EntityManager::createEntity()
{
	assert(!m_availableEntities.empty() && "number of entities overflowed");

	EntityID newEntity = m_availableEntities.front();
	m_usedEntities[newEntity];
	m_availableEntities.pop();

	return newEntity;
}

void EntityManager::destroyEntity(EntityID entity)
{
	assert(m_usedEntities.find(entity) != m_usedEntities.end() && "attempt to destroy unused entity");

	m_usedEntities.erase(entity);
	m_availableEntities.push(entity);
}



/// <summary>
/// 
/// </summary>
/// <param name="entity"></param>
/// <param name="component"></param>
/// <returns>False if component is already assigned</returns>
bool EntityManager::assignComponent(EntityID entity, ComponentID component)
{
	assert(m_usedEntities.find(entity) != m_usedEntities.end() && "EntityManager::assignComponent(): Requested entity doesn't used");

	if (m_usedEntities[entity][component]) return false;	//check if already assigned

	m_usedEntities[entity][component] = true;
	return true;
}

/// <summary>
/// 
/// </summary>
/// <param name="entity"></param>
/// <param name="component"></param>
/// <returns>False if nothing to remove</returns>
bool EntityManager::removeComponent(EntityID entity, ComponentID component)
{
	assert(m_usedEntities.find(entity) != m_usedEntities.end() && "EntityManager::removeComponent(): Requested entity doesn't used");

	if (!m_usedEntities[entity][component]) return false;	//check if nothing to remove

	m_usedEntities[entity][component] = false;
	return true;
}

Signature& EntityManager::getSignature(EntityID entity)
{
	assert(m_usedEntities.find(entity) != m_usedEntities.end() && "EntityManager: attempt to get signature of unused entity");

	return m_usedEntities[entity];
}
