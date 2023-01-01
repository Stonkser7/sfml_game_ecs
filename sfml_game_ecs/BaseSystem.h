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
	BaseSystem();
	virtual void specifySignature() = 0;

	std::unordered_set<EntityID> m_entities;
	Signature m_signature;		//each derived class must specify it in constructor
private:
	void assignEntity(EntityID entity);
};