#pragma once

#include <string>

//C# TO C++ CONVERTER NOTE: Forward class declarations:
namespace ComicDefender { class Ship; }

using namespace SFML::Graphics;
using namespace SFML::System;

namespace ComicDefender
{
	class MenuRectShips
	{
	public:
		Sprite *SpriteRect;
		Sprite *SpriteShip;
		std::wstring Name;

		int Damage = 0;
		float Speed = 0;
		float Shoot_speed = 0;
		int Health = 0;
		int CountGuns = 0;

		Ship *ship;

		virtual ~MenuRectShips()
		{
			delete SpriteRect;
			delete SpriteShip;
			delete ship;
		}

		MenuRectShips();
		MenuRectShips(Sprite *_SpriteRect, Sprite *_SpriteShip, const std::wstring &_Name, Vector2f _Position, Ship *s);

		MenuRectShips(Sprite *_SpriteRect, const std::wstring &_Name, Vector2f _Position);


	};
}
