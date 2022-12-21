#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H

#include <unordered_map>
#include <memory>

#include "Entity.h"
#include "Component.h"
#include "ComponentArray.h"
#include "IComponentArray.h"

using ComponentName = std::string;

class ComponentManager
{
public:
	template <typename T>
	void RegisterComponent(); 

	template <typename T>
	T& getComponent(EntityID entity);

private:
	template <typename T>
	std::shared_ptr<ComponentArray<T>> getComponentArray();


	std::unordered_map<ComponentName, std::shared_ptr<IComponentArray>> m_components;
};



template<typename T>
inline void ComponentManager::RegisterComponent()
{
	assert(m_components.find(typeid(T).name()) == m_components.end() && "attempt to register existent component");

	m_components.insert({ typeid(T).name(), std::make_shared<ComponentArray<T>>()});

}

template<typename T>
inline T& ComponentManager::getComponent(EntityID entity)
{
	getComponentArray()->getData(entity);
}

template<typename T>
inline std::shared_ptr<ComponentArray<T>> ComponentManager::getComponentArray()
{
	assert(m_components.find(typeid(T).name()) != m_components.end() && "attempt to get non-existent component array");

	return static_pointer_cast<ComponentArray<T>>(m_components[typeid(T).name()]);
}

#endif