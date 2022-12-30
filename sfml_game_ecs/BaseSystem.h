#pragma once

#include "Entity.h"
#include "Signature.h"

#include <unordered_set>

class ECSManager;

class BaseSystem //allows storing objects of generic derived classes in a container using pointers
{
public:
	BaseSystem() = delete;
	explicit BaseSystem(ECSManager* ecs_manager);

	virtual void update() = 0;

	void checkForMatching(EntityID entity, const Signature& signature);
	void removeEntity(EntityID entity);
protected:
	void setSignature(const Signature& signature);

	std::unordered_set<EntityID> m_entities;
	Signature m_signature;	//each derived class must specify it in constructor
	ECSManager* m_ecs_manager;
private:
	void assignEntity(EntityID entity);
};