#pragma once
#define _USE_MATH_DEFINES
#include "Entity.h"
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace sf;

namespace ComicDefender
{
	class Ship : public Entity
	{
	protected:
		static Vector2f location;
		Vector2f velocity = Vector2f(0, 0);
		Vector2f velocity2 = Vector2f(0, 0);
		Vector2f direction = Vector2f(0, 0);
		Vector2f Rotate = Vector2f(0, 0);
	private:
		static float rotat;
		Clock *bullet_clock = new Clock();
		//
	public:
		int shooting_ready = 0;
		int CountGuns = 0;
		float VectorSpeed = 0; //Максимальная Cкорость корабля
		float bullet_cooldown_max = 0; //Скоростельность (была .2f)
		float bullet_cooldown = 0;
		int dmg = 0;
		float Shoot_Speed = 20.0f;

		virtual ~Ship()
		{
			delete bullet_clock;
		}

		Ship();

		Ship(Sprite *_sprite, float _X, float _Y, int damage, float speed, float shoot_speed, int health, int countguns);
		void Settings(Sprite *_sprite, float _X, float _Y, int damage, float speed, float shoot_speed, int health, int countguns);



		void Update(float time) override;

	private:
		Vector2f Normalization(Vector2f vec, float X, float Y);
	public:
		static float GetX();
		static float GetY();
		static float GetRotation();

		int GetDamage();
	};
}
