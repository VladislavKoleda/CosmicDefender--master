#pragma once
#include "../Entities/Entity.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
using namespace sf;

namespace ComicDefender
{
	class Animation : public Entity

	{
	public:
		float Frame = 0, Speed = 0;
		Sprite *sprite;
		std::vector<IntRect> frames = std::vector<IntRect>();

		virtual ~Animation()
		{
			delete sprite;
		}

	private:
		Animation();

	public:
		Animation(Sprite *_sprite, int x, int y, int w, int h, int countX, int countY, float speed);

		Animation(Sprite *_sprite, int x, int y, int w, int h, int count, float speed);


		void update();

		bool isEnd();

		void Draw() override;
	};
}
