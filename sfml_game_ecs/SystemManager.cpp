#include "SystemManager.h"

void SystemManager::update()
{
	for (auto& s : m_systems_on_update) {
		s->update();
	}
}

void SystemManager::draw()
{
	for (auto& s : m_systems_on_draw) {
		s->draw();
	}
}



void SystemManager::entitySignatureUpdated(EntityID entity, const Signature& signature)
{
	for (auto& s : m_systems_on_update) {
		s->checkForMatching(entity, signature);
	}

	for (auto& s : m_systems_on_draw) {
		s->checkForMatching(entity, signature);
	}
}

void SystemManager::entityDestroyed(EntityID entity)
{
	for (auto &s : m_systems_on_update) {
		s->removeEntity(entity);
	}

	for (auto& s : m_systems_on_draw) {
		s->removeEntity(entity);
	}
}
