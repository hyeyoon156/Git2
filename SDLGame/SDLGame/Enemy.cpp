#include "Enemy.h"
#include <SDL.h>
#include "InputHandler.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void Enemy::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Enemy::update()
{
	m_position.setX(m_position.getX());
	m_position.setY(m_position.getY());

	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));

	handleInput();
}
void Enemy::clean()
{
}

void Enemy::handleInput()
{

	if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	{
		m_velocity.setX(1);
		Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
		m_velocity = (*vec - m_position) / 100;
		SDLGameObject::update();
	}

}