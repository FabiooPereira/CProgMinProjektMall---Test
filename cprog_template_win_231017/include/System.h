#ifndef SYSTEM_H
#define SYSTEM_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define FPS 60;

namespace engine
{
	class System
	{
	public:
		System();
		~System();
		SDL_Renderer *get_ren() const;
		const int get_height() const;
		TTF_Font *get_font() const;
		static const int getfps() { return FPS; };

	private:
		SDL_Window *win;
		SDL_Renderer *ren;
		TTF_Font *font;
		const int width = 500;
		const int height = 900;
	};

	extern System sys; // Statiskt globalt objekt (definierad utanför funktioner.)
}
#endif