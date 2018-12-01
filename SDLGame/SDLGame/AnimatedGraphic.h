#pragma once
#include "SDLGameObject.h"
#include "GameObject.h"

class AnimatedGraphic : public SDLGameObject
{
public:
	AnimatedGraphic(const LoaderParams * pParams, int animSpeed);

	void update();

private:
	/* data */
	int m_animSpeed;
};

