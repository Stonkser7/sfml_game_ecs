#include "SystemManager.h"

void SystemManager::update()
{
	for (auto& s : m_systems) {
		s->update();
	}
}

void SystemManager::entitySignatureUpdated(EntityID entity, const Signature& signature)
{
	for (auto& s : m_systems) {
		s->checkForMatching(entity, signature);
	}
}

void SystemManager::entityDestroyed(EntityID entity)
{
	for (auto &s : m_systems) {
		s->removeEntity(entity);
	}
}
