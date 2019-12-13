#include "Bonus.h"
#include "../Program.h"

using namespace SFML::Graphics;
using namespace SFML::System;
using namespace SFML::Window;

namespace ComicDefender
{

Vector2f Bonus::location = Vector2f(0, 0);

	Bonus::Bonus()
	{
	}

	Bonus::Bonus(Sprite *_sprite, float _X, float _Y, const std::wstring &name)
	{
		Name = name;
		sprite = new Sprite(_sprite);
		sprite->Origin = Vector2f(sprite->Texture->Size.X / 2, sprite->Texture->Size.Y / 2);
		location = Vector2f(_X, _Y);
		sprite->Position = location;
		sprite->Scale = Vector2f(0.1F, 0.1F);
		X = _X;
		Y = _Y;
	}

	void Bonus::Update(float time)
	{
		Program::Window->Draw(sprite);
	}
}
