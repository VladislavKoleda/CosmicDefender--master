﻿#include "Asteroid.h"
#include "../Animation/Animation.h"
#include "../Program.h"

using namespace SFML::Graphics;
using namespace SFML::System;

namespace ComicDefender
{

	Asteroid::Asteroid()
	{
		animAsteroid = new Animation(Program::content->GetsAnimAsteroid1(), 0, 0, 85, 100, 6, 5, 0.15f);

		int Choose1, Choose2, a1, a2;
		Choose1 = rdn->Next(0, 1);
		if (Choose1 == 1)
		{
			a1 = rdn->Next(1, Program::WindowWidth);
			Choose2 = rdn->Next(0, 1);
			if (Choose2 == 1) //Если 1 то сверху
			{
				a2 = 0;
			}
			else //Если 2 то снизу
			{
				a2 = Program::WindowHeight;
			}
		}
		else
		{
			a2 = rdn->Next(1, Program::WindowHeight);
			Choose2 = rdn->Next(0, 1);
			if (Choose2 == 1) //Если 1 то слева
			{
				a1 = 0;
			}
			else //Если 2 то справа
			{
				a1 = Program::WindowWidth;
			}
		}
		int a3 = rdn->Next(1, 360);
		float speed = (rdn->Next(10,100));
		speed = speed / 100;
		Settings(animAsteroid, L"Asteroid", a1, a2, a3, 0.4F, speed);
	}

	void Asteroid::Update(float time)
	{
		float _x = GetX();
		float _y = GetY();

		_x += GetDx();
		SetX(_x);
		_y += GetDy();
		SetY(_y);

		if (GetX() > Program::WindowWidth)
		{
			SetX(0);
		}
		if (GetX() < 0)
		{
			SetX(Program::WindowWidth);
		}
		if (GetY() > Program::WindowHeight)
		{
			SetY(0);
		}
		if (GetY() < 0)
		{
			SetY(Program::WindowHeight);
		}
		sprite = animAsteroid->sprite;
		animAsteroid->update();

	}

	void Asteroid::Draw()
	{
		animation->sprite->Position = Vector2f(GetX(), GetY());
		Program::Window->Draw(sprite);
	}
}
