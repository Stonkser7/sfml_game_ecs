#pragma once

#include "SystemOnRender.h"
#include "Component.h"
#include "ECSManager.h"
#include <SFML/Graphics.hpp>

#include "CPosition.h"
#include "CSprite.h"
#include "CRotation.h"

class SDraw : public SystemOnRender
{
public:
	SDraw(ECSManager& manager, sf::RenderWindow& window);
	void render() override;
};

