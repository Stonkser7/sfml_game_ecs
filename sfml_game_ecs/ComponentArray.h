#ifndef COMPONENT_ARRAY_H
#define COMPONENT_ARRAY_H

#include <vector>
#include <unordered_map>

#include <assert.h>

#include "Entity.h"
#include "Direction.h"

template <typename T>
class ComponentArray
{
public:

	T& getData(EntityID entity);

	void createData(EntityID entity);

private:
	std::vector<T> m_components;

	std::unordered_map<EntityID, size_t> m_EntityToIndex;
};

#endif

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
}
