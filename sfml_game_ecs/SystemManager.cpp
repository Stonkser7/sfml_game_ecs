#include "SystemManager.h"

void SystemManager::update()
{
	for (auto& s : m_systems) {
		s->update();
	}
}

void SystemManager::entitySignatureChecking(EntityID entity, const Signature& signature)
{
	for (auto& s : m_systems) {
		s->signatureMatchingCheck(entity, signature);
	}
}
