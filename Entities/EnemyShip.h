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
	class EnemyShip : public Entity
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
		bool IsAnimation = false;
		//Пустой конструктор для последующей инициализации
		virtual ~EnemyShip()
		{
			delete bullet_clock;
			delete animEnemy;
		}

		EnemyShip();


		EnemyShip(Sprite *_sprite, float _X, float _Y, float MaxSpeed, const std::wstring &name, int countguns, bool _animation, float size); // Параметр Name




		void Update(float time) override;

	private:
		Vector2f Normalization(Vector2f vec, float X, float Y);
	};
}
