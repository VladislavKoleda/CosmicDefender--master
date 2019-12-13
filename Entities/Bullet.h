#pragma once

#define _USE_MATH_DEFINES
#include "Entity.h"
#include <cmath>

//C# TO C++ CONVERTER NOTE: Forward class declarations:
namespace ComicDefender { class Animation; }
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
using namespace sf;

namespace ComicDefender
{
	class Bullet : public Entity
	{
	public:
		Animation *animation;
		virtual ~Bullet()
		{
			delete animation;
		}

		Bullet(float _X, float _Y, float _Rotation, float _size, float _speed);

		void Update(float time) override;
		void Draw() override;

	};
}
