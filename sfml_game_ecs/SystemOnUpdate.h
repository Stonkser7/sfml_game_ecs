#pragma once

#include "BaseSystem.h"

class ECSManager;

class SystemOnUpdate : public BaseSystem
{
public:
	SystemOnUpdate() = delete;
	SystemOnUpdate(SystemOnUpdate&) = delete;

	virtual void update() = 0;
protected:
	explicit SystemOnUpdate(ECSManager& manager);
private:
	ECSManager& m_ecs_manager;
};

