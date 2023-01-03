#pragma once

#include "Entity.h"
#include "Signature.h"

#include <unordered_set>

class BaseSystem {
public:
	BaseSystem(BaseSystem&) = delete;

	void checkForMatching(EntityID entity, const Signature& signature);
	void removeEntity(EntityID entity);
protected:
	BaseSystem() {};

	std::unordered_set<EntityID> m_entities;
	Signature m_signature;						//each system class must specify it
private:
	void assignEntity(EntityID entity);
};