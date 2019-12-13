#pragma once

#define _USE_MATH_DEFINES
#include "Entity.h"
#include <string>
#include <cmath>

//C# TO C++ CONVERTER NOTE: Forward class declarations:
namespace ComicDefender { class Animation; }

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
using namespace sf;

namespace ComicDefender
{
	class Boss : public Entity
	{
	protected:
		Vector2f location = Vector2f(0, 0);
		Vector2f velocity = Vector2f(0, 0);
		Vector2f velocity2 = Vector2f(0, 0);
		Vector2f direction = Vector2f(0, 0);
		Vector2f Rotate = Vector2f(0, 0);
	private:
		static float rotat;
		Vector2f RotateShoot = Vector2f(0, 0);
		Clock *bullet_clock = new Clock();
		//
	public:
		int shooting_ready = 0;
		int CountGuns = 0;
	private:
		int BulletToShip = 0; //Длина от корабля до спавна пули
	protected:
		float VectorSpeed = 0; //Максимальная Cкорость корабля
		float bullet_cooldown_max = 0.5f; //Скоростельность
		float bullet_cooldown_max_miniBoss = 2.0f;
	private:
		float bullet_cooldown = 0;
	public:
		Animation *animEnemy;

		virtual ~Boss()
		{
			delete bullet_clock;
			delete animEnemy;
		}

		Boss();

		Boss(Sprite *_sprite, Animation *_animation, float _X, float _Y, int damage, float speed, float shoot_speed, int health, int countguns, const std::wstring &name);

		Boss(Sprite *_sprite, float _X, float _Y, int damage, float speed, float shoot_speed, int health, int countguns, const std::wstring &name);



		void Update(float time) override;


	private:
		Vector2f Normalization(Vector2f vec, float X, float Y);



	};
}
