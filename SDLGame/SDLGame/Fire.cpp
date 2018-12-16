#include <iostream>
#include "Fire.h"
#include "TextureManager.h"
#include "Game.h"
#include "InputHandler.h"
//#include "Barrier.h"

Fire::Fire(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_velocity.setX(4);
	m_velocity.setY(0.001);//0.001
	
}
void Fire::draw()
{
	SDLGameObject::draw();
}
void Fire::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 1));
	if (m_position.getX() <= 1280) {
		m_velocity.setX(-2);
	}
	//else if (m_position.getX()) {
	//	m_velocity.setX(-2);
	//}
	SDLGameObject::update();
}

void Fire::clean()
{
}

void Fire::handleInput()
{

	if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	{
		m_velocity.setY(1);
		Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
		m_velocity = (*vec - m_position) / 100;
		SDLGameObject::update();
	}

}

//std::vector<GameObject*> m_bullet;
//
//bool destro;
//
////void Enemy::update()
////{
////	GameObject::update();
////	m_y += 1;
////	//m_x += 1;
////	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
////}
//
//Fire::Fire(const LoaderParams* pParams) : SDLGameObject(pParams)
//{
//
//}
//
//void Fire::draw()
//{
//	SDLGameObject::draw(); // we now use SDLGameObject
//}
//
//void Fire::update()
//{
//	m_position.setX(m_position.getX()+3);
//	//m_position.setY(m_position.getY());
//
//	m_currentFrame = int(((SDL_GetTicks() / 100)%1));
//
//	handleInput();
//	//GameObject::update();
//
//	//if (m_position.getX() == 500)
//	//{
//	//	for (std::vector<GameObject*>::size_type i = 0;
//	//		i != m_bullet.size(); i++)
//	//	{
//	//		m_bullet[i].alive=0;
//	//	}
//	//}
//}
//
//void Fire::clean()
//{
//}
//
//void Fire::handleInput()
//{
//
//	//if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
//	//{
//	//	m_velocity.setX(1);
//	//	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
//	//	m_velocity = (*vec - m_position) / 100;
//		SDLGameObject::update();
//	//}
//}
