#pragma once
#include <vector>
#include "SDL.h"
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include "GameStateMachine.h"

class Game
{
private:
	Game() {};
	static Game* s_pInstance;

public:
	~Game() {}
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }
	void quit() { m_bRunning = false; }

	SDL_Renderer* getRenderer() const { return m_pRenderer; }

	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}

private:
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
	int m_currentFrame;

	std::vector<GameObject*> m_gameObjects;

	GameStateMachine* m_pGameStateMachine;
};

typedef Game TheGame;

//class Game
//{
//public:
//	static Game* Instance()
//	{
//		if (s_pInstance == 0)
//		{
//			s_pInstance = new Game();
//			return s_pInstance;
//		}
//		return s_pInstance;
//	}
//	SDL_Renderer* getRenderer() const { return m_pRenderer; }
//
//	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
//	void render();
//	void update();
//	void handleEvents();
//	void clean();
//	void quit() { std::cout << "quit" << std::endl; m_bRunning = false; };
//	bool running() { return m_bRunning; }
//private:
//
//	std::vector<GameObject*> m_gameObjects;
//
//	~Game() {}
//	Game() {};
//	static Game* s_pInstance;
//
//	SDL_Window * m_pWindow;
//	SDL_Renderer* m_pRenderer;
//	bool m_bRunning;
//
//	int m_currentFrame;
//	TextureManager m_textureManager;
//
//	GameObject* m_go;
//	GameObject* m_player;
//	GameObject* m_enemy;
//};
//
//typedef Game TheGame;
