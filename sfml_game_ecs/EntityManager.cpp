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

	m_signature[newEntity];
	m_availableEntities.pop();

	return newEntity;
}
