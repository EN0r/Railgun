#include <iostream>
#include "SDL.h"
#include "window.h"
#include "game.h"

/*
--CREDITS--
CODED BY ERIAH NORWOOD.
NAMED BY MATTHEW BOUSIE.
*/
int main(int argc, char* argv[])
{
	window w;
	SDL_Event windowEvent;
	if (!w.createWindow(800, 600))
		return -1;
	if (!w.createRenderer())
		return -1;
	Start(w.ren);
	while (true)
	{
		if (SDL_PollEvent(&windowEvent))
		{
			if (SDL_QUIT == windowEvent.type)
			{
				return -1;
			}
		}
		SDL_RenderPresent(w.ren);
		Update(w.ren);
	}
	return 0;
}