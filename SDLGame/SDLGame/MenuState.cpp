#include "MenuState.h"
#include "MenuButton.h"
#include "PlayState.h"
#include "AnimatedGraphic.h"
#include "Game.h"
#include <iostream>

MenuState* MenuState::s_pInstance = 0;

const std::string MenuState::s_menuID = "MENU";

void MenuState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void MenuState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool MenuState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/Cat.png",
		"catbg", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/button.png",
		"playbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/exit.png",
		"exitbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	//GameObject* button1 = new MenuButton(
	//	new LoaderParams(100, 100, 400, 100, "playbutton"));
	//GameObject* button2 = new MenuButton(
	//	new LoaderParams(100, 300, 400, 100, "exitbutton"));
	GameObject* catBg = new SDLGameObject(
		new  LoaderParams(0, 0, 1280, 720, "catbg"));

	GameObject* button1 = new MenuButton(
		new LoaderParams(100, 100, 400, 100, "playbutton"),
		s_menuToPlay);
	GameObject* button2 = new MenuButton(
		new LoaderParams(100, 250, 400, 100, "exitbutton"),
		s_exitFromMenu);

	m_gameObjects.push_back(catBg);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "entering MenuState\n";
	return true;
}

bool MenuState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()
		->clearFromTextureMap("playbutton");
	TheTextureManager::Instance()
		->clearFromTextureMap("exitbutton");
	std::cout << "exiting MenuState\n";
	return true;
}

void MenuState::s_menuToPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
	std::cout << "Play button clicked\n";

}

void MenuState::s_exitFromMenu()
{
	TheGame::Instance()->quit();
	std::cout << "Exit button clicked\n";

}
