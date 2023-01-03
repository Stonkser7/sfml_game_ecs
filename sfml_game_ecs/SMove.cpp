#include "SMove.h"

SMove::SMove(ECSManager& manager) : SystemOnUpdate(manager)
{
	m_signature.set(ComponentID::Position);
	m_signature.set(ComponentID::Speed);
	m_signature.set(ComponentID::Direction);
}

void SMove::update()
{
	for (auto& e : m_entities) {
		CPosition& pos = m_ecs_manager.getComponent<CPosition>(e);
		CSpeed& speed = m_ecs_manager.getComponent<CSpeed>(e);
		CDirection& dir = m_ecs_manager.getComponent<CDirection>(e);

		pos.vector += dir.asVec2f() * speed.value;
	}
}
