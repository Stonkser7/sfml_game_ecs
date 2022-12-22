#pragma once

#include <bitset>
#include <unordered_map>
#include <queue>

#include "Entity.h"
#include "Component.h"

#include <cassert>

#include <SFML/Graphics.hpp>

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

private:
	std::unordered_map<EntityID, std::bitset<ComponentID::Count>> m_usedEntities;

	std::queue<EntityID> m_availableEntities;
};