#pragma once

#include "Entity.h"

class IComponentArray //allows storing objects of generic derived classes in a container using pointers
{
public:
	IComponentArray() = delete;

	virtual void removeData(EntityID entity) = 0;
	virtual bool isAssigned(EntityID entity) = 0;
};