#include "PlayState.h"
#include "InputHandler.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "AnimatedGraphic.h"
#include "MenuButton.h"
#include "Fire.h"
//#include "GameStateMachine.h"
#include "Game.h"

PlayState* PlayState::s_pInstance = 0;

const std::string PlayState::s_playID = "PLAY";

	int delay = 10;
	int n = rand() % 700;

//void PlayState::update()
//{
//	for (int i = 0; i < m_gameObjects.size(); i++)
//	{
//		m_gameObjects[i]->update();
//	}
//}

//void PlayState::update()
//{
//	if (TheInputHandler::Instance()->isKeyDown(
//		SDL_SCANCODE_ESCAPE))
//	{
//		TheGame::Instance()->getStateMachine()->changeState(
//			new	PauseState());
//	}
//	for (int i = 0; i < m_gameObjects.size(); i++)
//	{
//		m_gameObjects[i]->update();
//	}
//}
void PlayState::update()
{
	int x = 3;

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->changeState(
			new PauseState());
	}
	else if (checkCollision(
		dynamic_cast<SDLGameObject*>(m_gameObjects[2]),
		dynamic_cast<SDLGameObject*>(m_gameObjects[x++])))
	{
		TheGame::Instance()->getStateMachine()->changeState(
			new GameOverState());
	}
	//else if (checkCollision(
	//	dynamic_cast<SDLGameObject*>(m_gameObjects[2]),
	//	dynamic_cast<SDLGameObject*>(m_gameObjects[4])))
	//{
	//	TheGame::Instance()->getStateMachine()->changeState(
	//		new GameOverState());
	//}
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}

	if (!delay--)
	{
		m_gameObjects.push_back(new Fire(new LoaderParams(1280, n, 120, 60, "meteor")));
		delay = 4;
	}

}

void PlayState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

//bool PlayState::onEnter()
//{
//	if (!TheTextureManager::Instance()->load(
//		"assets/helicopter.png", "helicopter",
//		TheGame::Instance()->getRenderer()))
//	{
//		return false;
//	}
//
//	GameObject* player = new Player(
//		new LoaderParams(100, 100, 128, 55, "helicopter"));
//
//	m_gameObjects.push_back(player);
//	std::cout << "entering PlayState\n";
//
//	return true;
//}

bool PlayState::onEnter()
{
	int n = rand() % 700;

	if (!TheTextureManager::Instance()->load("assets/ingame.png",
		"gamebg", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/pause6.png",
		"pausebutton", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/catPlayer3.png",
		"catPlayer", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/helicopter2.png",
		"helicopter2", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/meteor1.png",
		"meteor", TheGame::Instance()->getRenderer())) {
		return false;
	}

	GameObject* gameBg = new AnimatedGraphic(
		new  LoaderParams(0, 0, 1280, 720, "gamebg"),2);
	GameObject* button1 = new MenuButton(new
		LoaderParams(20, 20, 72, 72, "pausebutton"), s_pause);
	GameObject* player = new Player(
		new LoaderParams(500, 100, 150, 60, "catPlayer"));
	GameObject* enemy = new Enemy(
		new LoaderParams(100, 100, 128, 55, "helicopter2"));
	GameObject* Meteor = new Fire(
		new LoaderParams(1280, n, 120, 60, "meteor"));

	m_gameObjects.push_back(gameBg);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(player);
	m_gameObjects.push_back(enemy);
	m_gameObjects.push_back(Meteor);
	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}


	TheTextureManager::Instance()->clearFromTextureMap("helicopter");
	
	m_gameObjects.clear();
	std::cout << "exiting PlayState\n";
	return true;
}

bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();

	//Calculate the sides of rect B
	leftB = p2->getPosition().getX();
	rightB = p2->getPosition().getX() + p2->getWidth();
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();

	//If any of the sides from A are outside of B
	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }
	return true;
}

void PlayState::s_pause()
{
	TheGame::Instance()->getStateMachine()->changeState(
		new PauseState());
}