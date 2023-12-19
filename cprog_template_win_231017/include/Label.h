#ifndef LABEL_H
#define LABEL_H

#include "Component.h"
#include <SDL2/SDL.h>

namespace engine
{
	class Label : public Component
	{
	public:
		static std::shared_ptr<Label> getInstance(int x, int y, int w, int h, std::string txt);
		std::string getText() const;
		void setText(std::string newText);
		void draw() const override;
		void tick() override;
		~Label() override;
		int getscribble();
	protected:
		Label(int x, int y, int w, int h, std::string txt);

	private:
		std::string text;
		SDL_Texture *texture;
	};
}
#endif