#pragma once

#include <vector>
#include <memory>
#include <cassert>

#include "Entity.h"
#include "Signature.h"
#include "BaseSystem.h"

class SystemManager
{
public:
	void update();

	template <typename T>
	void addSystem();

	void entitySignatureUpdated(EntityID entity, const Signature& signature);
	void entityDestroyed(EntityID entity);
private:
	std::vector<std::shared_ptr<BaseSystem>> m_systems;
};

template<typename T>
inline void SystemManager::addSystem()
{
	m_systems.push_back(std::make_shared<T>());
}
