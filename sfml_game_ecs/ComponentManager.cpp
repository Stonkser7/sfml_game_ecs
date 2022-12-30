#include "ComponentManager.h"

void ComponentManager::removeAllComponents(EntityID entity)
{
	for (auto& c : m_components) {
		if (c.second->isAssigned(entity)) {
			c.second->removeData(entity);
		}
	}
}
