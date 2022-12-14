#pragma once

#include <unordered_map>
#include <memory>
#include <string>

#include "Entity.h"
#include "Component.h"
#include "ComponentArray.h"
#include "IComponentArray.h"

using ComponentName = std::string;

class ComponentManager
{
public:
	template <typename T>
	void registerComponent();

	template <typename T>
	void assignComponent(EntityID entity);

	template <typename T>
	void removeComponent(EntityID entity);

	void removeAllComponents(EntityID entity);

	template <typename T>
	T& getComponent(EntityID entity);

private:
	template <typename T>
	std::shared_ptr<ComponentArray<T>> getComponentArray();


	std::unordered_map<ComponentName, std::shared_ptr<IComponentArray>> m_components;
};



template<typename T>
inline void ComponentManager::registerComponent()
{
	assert(m_components.find(typeid(T).name()) == m_components.end() && "ComponentManager: attempt to register already registered component");

	m_components.insert({ typeid(T).name(), std::make_shared<ComponentArray<T>>() });
}

template<typename T>
inline void ComponentManager::assignComponent(EntityID entity)
{
	assert(m_components.find(typeid(T).name()) != m_components.end() && "attempt to assign unregistered component");

	getComponentArray<T>()->createData(entity);
}

template<typename T>
inline void ComponentManager::removeComponent(EntityID entity)
{
	assert(m_components.find(typeid(T).name()) != m_components.end() && "attempt to remove unregistered component");

	getComponentArray<T>()->removeData(entity);
}

template<typename T>
inline T& ComponentManager::getComponent(EntityID entity)
{
	assert(m_components.find(typeid(T).name()) != m_components.end() && "attempt to get unregistered component");

	return getComponentArray<T>()->getData(entity);
}

template<typename T>
inline std::shared_ptr<ComponentArray<T>> ComponentManager::getComponentArray()
{
	return static_pointer_cast<ComponentArray<T>>(m_components[typeid(T).name()]);
}