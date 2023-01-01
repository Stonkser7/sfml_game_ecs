#pragma once


#include "Component.h"
#include "SystemOnUpdate.h"

class ECSManager;

class MoveSystem : public SystemOnUpdate
{
public:
	MoveSystem(ECSManager& manager);
	void update() override;
	void specifySignature() override;
};