#pragma once

#include <vector>
#include <unordered_map>

#include <assert.h>

#include "Entity.h"
#include "IComponentArray.h"

template <typename T>
class ComponentArray : public IComponentArray 
{
public:

	T& getData(EntityID entity);

	void createData(EntityID entity);

	void removeData(EntityID entity);

private:
	std::vector<T> m_components;

	std::unordered_map<EntityID, size_t> m_EntityToIndex;

	std::unordered_map<size_t, EntityID> m_IndexToEntity;
};

template<typename T>
inline T& ComponentArray<T>::getData(EntityID entity)
{
	assert(m_EntityToIndex.find(entity) != m_EntityToIndex.end() && "T& ComponentArray<T>::getData(EntityID entity): attempt to get non-existent component");

	return m_components[m_EntityToIndex[entity]];
}

template<typename T>
inline void ComponentArray<T>::createData(EntityID entity)
{
	assert(m_EntityToIndex.find(entity) == m_EntityToIndex.end() && "void ComponentArray<T>::createData(EntityID entity): entity can't have two same components");

	m_components.push_back(T());
	m_EntityToIndex[entity] = m_components.size() - 1;
	m_IndexToEntity[m_components.size() - 1] = entity;
}

template<typename T>
inline void ComponentArray<T>::removeData(EntityID entity)
{
	assert(m_EntityToIndex.find(entity) != m_EntityToIndex.end() && "void ComponentArray<T>::removeData(EntityID entity): attempt to remove non-existent component");

	size_t last_i = m_components.size() - 1;
	EntityID last_e = m_IndexToEntity[last_i];

	m_components[m_EntityToIndex[entity]] = m_components[last_i];

	m_EntityToIndex[m_IndexToEntity[last_i]] = m_EntityToIndex[entity];
	m_IndexToEntity[m_EntityToIndex[entity]] = last_e;

	m_EntityToIndex.erase(entity);
	m_IndexToEntity.erase(last_i);
	m_components.pop_back();
}