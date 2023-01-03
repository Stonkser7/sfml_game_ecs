#pragma once

#include "Component.h"
#include "SystemOnUpdate.h"
#include "ECSManager.h"

#include "CPosition.h"
#include "CSpeed.h"
#include "CDirection.h"

class SMove : public SystemOnUpdate
{
public:
	SMove(ECSManager& manager);
	void update() override;
};