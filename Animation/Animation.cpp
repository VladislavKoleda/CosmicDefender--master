#include "Animation.h"
#include "../Program.h"

using namespace SFML::Graphics;
using namespace SFML::System;

namespace ComicDefender
{

	Animation::Animation()
	{
	}

	Animation::Animation(Sprite *_sprite, int x, int y, int w, int h, int countX, int countY, float speed)
	{
		sprite = new Sprite(_sprite);
		sprite->Origin = Vector2f(w / 2, h / 2);
		Frame = 0;
		Speed = speed;
		for (int i = 0; i < countY; i++)
		{
			for (int j = 0; j < countX; j++)
			{
				frames.push_back(IntRect(x + (j * w), y, w, h));
			}
			y += h;
			x = 0;
		}
		sprite->TextureRect = frames[0];
	}

	Animation::Animation(Sprite *_sprite, int x, int y, int w, int h, int count, float speed)
	{
		sprite = new Sprite(_sprite);
		sprite->Origin = Vector2f(w / 2, h / 2);
		Speed = speed;
		Frame = 0;
		for (int i = 0; i < count; i++)
		{
			frames.push_back(IntRect(x + (i * w), y, w, h));
		}
	}

	void Animation::update()
	{
		Frame += Speed;
		int n = frames.size();
		if (Frame >= n)
		{
			Frame -= n;
		}
		if (n > 0)
		{
			sprite->TextureRect = frames[static_cast<int>(Frame)];
		}
	}

	bool Animation::isEnd()
	{
		return Frame + Speed >= frames.size();
	}

	void Animation::Draw()
	{
		sprite->Position = Vector2f(X, Y);
		Program::Window->Draw(sprite);
	}
}
