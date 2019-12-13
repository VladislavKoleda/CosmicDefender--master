#include "MenuRectShips.h"
#include "../../Entities/Ship.h"

using namespace SFML::Graphics;
using namespace SFML::System;

namespace ComicDefender
{

	MenuRectShips::MenuRectShips()
	{

	}

	MenuRectShips::MenuRectShips(Sprite *_SpriteRect, Sprite *_SpriteShip, const std::wstring &_Name, Vector2f _Position, Ship *s)
	{
		SpriteRect = _SpriteRect;
		SpriteShip = _SpriteShip;
		SpriteShip->Origin = Vector2f(_SpriteShip->Texture->Size.X / 2, _SpriteShip->Texture->Size.Y / 2);
		Name = _Name;
		SpriteRect->Position = _Position;
		/*
		Damage = damage;
		Speed = speed;
		Shoot_speed = shoot_speed;
		Health = health;
		CountGuns = countguns;
		*/
		ship = s;

	}

	MenuRectShips::MenuRectShips(Sprite *_SpriteRect, const std::wstring &_Name, Vector2f _Position)
	{
		SpriteRect = _SpriteRect;
		Name = _Name;
		SpriteRect->Position = _Position;
	}
}
