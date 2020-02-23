#pragma once
#include "SDL.h"
#include <string>
#include "SDL_image.h"

class window
{
protected:
	SDL_Window* wnd; // unitialised
	SDL_Surface* icon;
	std::string windowName = "Railgun v1.0";
public:
	SDL_Renderer* ren;
	~window(); // prevent memory leaks using the destructor.
	SDL_Window* getWindow() { return wnd; }
	SDL_Renderer* getRenderer() { return ren; }
	bool createWindow(int x, int y);
	bool setIcon(std::string path);
	bool createRenderer();
};
window::~window()
{
	SDL_FreeSurface(icon);
	delete wnd;
}
bool window::createWindow(int x, int y)
{
	wnd = SDL_CreateWindow(windowName.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,x,y,NULL);
	if(!wnd)
		return false;
	return true;
}
bool window::setIcon(std::string path)
{
	icon = IMG_Load(path.c_str());
	if (icon == nullptr)
		return false;
	SDL_SetWindowIcon(this->wnd,icon);
	return true;
}
bool window::createRenderer()
{
	ren = SDL_CreateRenderer(this->wnd,-1,NULL);
	if(!ren)
		return false;
	return true;
}


