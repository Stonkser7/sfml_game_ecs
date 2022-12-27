#include "BaseSystem.h"

void BaseSystem::setSignature(const Signature& signature)
{
	m_signature = signature;
}

void BaseSystem::signatureMatchingCheck(EntityID entity, const Signature& signature)
{
	if ((signature & m_signature) == m_signature) {
		assignEntity(entity);
	}
	else {
		removeEntity(entity);
	}
}

void BaseSystem::assignEntity(EntityID entity)
{
	m_entities.insert(entity);
}

void BaseSystem::removeEntity(EntityID entity)
{
	m_entities.erase(entity);
}
