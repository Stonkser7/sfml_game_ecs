#include "SystemManager.h"

void SystemManager::update()
{
	for (auto& s : m_systems_on_update) {
		s->update();
	}
}

void SystemManager::render()
{
	for (auto& s : m_systems_on_render) {
		s->render();
	}
}



void SystemManager::entitySignatureUpdated(EntityID entity, const Signature& signature)
{
	for (auto& s : m_systems_on_update) {
		s->checkForMatching(entity, signature);
	}

	for (auto& s : m_systems_on_render) {
		s->checkForMatching(entity, signature);
	}
}

void SystemManager::entityDestroyed(EntityID entity)
{
	for (auto &s : m_systems_on_update) {
		s->removeEntity(entity);
	}

	for (auto& s : m_systems_on_render) {
		s->removeEntity(entity);
	}
}
