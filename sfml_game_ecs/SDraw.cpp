#include "SDraw.h"

SDraw::SDraw(ECSManager& manager, sf::RenderWindow& window): SystemOnRender(manager, window)
{
	m_signature.set(ComponentID::Position);
	m_signature.set(ComponentID::Sprite);
	m_signature.set(ComponentID::Rotation);
}

void SDraw::render()
{
	for (auto& e : m_entities) {
		CPosition& pos = m_ecs_manager.getComponent<CPosition>(e);
		CSprite& sprite = m_ecs_manager.getComponent<CSprite>(e);
		CRotation& rotation = m_ecs_manager.getComponent<CRotation>(e);

		sprite.value.setPosition(pos.vector);
		sprite.value.setRotation(rotation.angle);
		m_window.draw(sprite.value);
	}
}
