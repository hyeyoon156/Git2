#pragma once
#include "SDLGameObject.h"
#include "LoaderParams.h"

class Fire : public SDLGameObject
{
public:
	//void load(int x, int y, int width, int height,
	//	std::string textureID);
	Fire(const LoaderParams* pParams);
	bool alive;
	/*void draw(SDL_Renderer* pRenderer);*/
	virtual void draw();
	virtual void update();
	virtual void clean();
	void handleInput();

};