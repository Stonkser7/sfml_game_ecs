#pragma once

#include "Entity.h"
#include "Signature.h"

#include <unordered_set>

class BaseSystem //allows storing objects of generic derived classes in a container using pointers
{
public:
	virtual void update() = 0;
	void setSignature(const Signature& signature);

	void signatureMatchingCheck(EntityID entity, const Signature& signature);

private:
	void assignEntity(EntityID entity);
	void removeEntity(EntityID entity); 

	std::unordered_set<EntityID> m_entities;
	Signature m_signature;
};