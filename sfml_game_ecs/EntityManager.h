#pragma once

#include <unordered_map>
#include <queue>

#include "Entity.h"
#include "Component.h"
#include "Signature.h"

#include <cassert>

const size_t MAX_ENTITIES = 30;

class EntityManager
{
public:
	EntityManager();
	
	EntityManager(const EntityManager&) = delete;
	EntityManager(EntityManager&&) = delete;


	EntityID createEntity();

	void destroyEntity(EntityID entity);

	bool assignComponent(EntityID entity, ComponentID component);

	bool removeComponent(EntityID entity, ComponentID component);

	Signature& getSignature(EntityID entity);
private:
	std::unordered_map<EntityID, Signature> m_usedEntities;

	std::queue<EntityID> m_availableEntities;
};