#include "EnemyShip.h"
#include "../Animation/Animation.h"
#include "Ship.h"
#include "Bullet.h"
#include "../Program.h"

using namespace SFML::Graphics;
using namespace SFML::System;
using namespace SFML::Window;

namespace ComicDefender
{

float EnemyShip::rotat = 0;

	EnemyShip::EnemyShip()
	{

	}

	EnemyShip::EnemyShip(Sprite *_sprite, float _X, float _Y, float MaxSpeed, const std::wstring &name, int countguns, bool _animation, float size)
	{
		if (_animation == true)
		{
			animEnemy = new Animation(_sprite, 0, 0, 338, 338, 3, 0.02f); //ПАРАМЕТРЫ ДЛЯ КАЖДОГО БОССА ?????????????????????????????????????????????
		}

		IsAnimation = _animation;
		sprite = new Sprite(_sprite);
		location = Vector2f(_X, _Y);
		sprite->Position = location;
		sprite->Scale = Vector2f(size, size);
		VectorSpeed = MaxSpeed;
		Name = name; //  $$$$
		X = _X;
		Y = _Y;
		CountGuns = countguns;

		if (_animation == true)
		{
			Settings(animEnemy, L"Boss1", 0, 100, 100, 0.5f, 0.3f);
		}
	}

	void EnemyShip::Update(float time)
	{
		Vector2f pos = Vector2f(Ship::GetX(), Ship::GetY());
		Vector2f Rotate = pos - location;
		RotateShoot = Rotate;

		Vector2f RotateToGun;
		RotateToGun.Y = 1;
		RotateToGun.X = (((-1) * (Rotate.Y * RotateToGun.Y)) / (Rotate.X));
		RotateToGun = Normalization(RotateToGun, pos.X, pos.Y);

		Rotate = Normalization(Rotate, pos.X, pos.Y);
		direction = Rotate;

		float v = 0.3f;
		rotat = static_cast<float>((std::atan2(Rotate.Y, Rotate.X) * 180 / M_PI) + 90);
		sprite->Rotation = rotat;
		sprite->Position = location;
		location += velocity * time; // Где находится корабль
		Random *rnd = new Random();

		velocity += v * direction;
		float constanta = static_cast<float>(std::sqrt((VectorSpeed * VectorSpeed) / (velocity.X * velocity.X + velocity.Y * velocity.Y)));
		velocity2 = velocity * constanta;
		float Dvelocity = static_cast<float>(std::sqrt((velocity.X) * (velocity.X) + (velocity.Y) * (velocity.Y)));
		float Dvelocity2 = static_cast<float>(std::sqrt((velocity2.X) * (velocity2.X) + (velocity2.Y) * (velocity2.Y)));
		if (Dvelocity > Dvelocity2)
		{
			velocity = velocity2;
		}
		X = location.X;
		Y = location.Y;

		if (Name == L"ShootShip") //стрелок стреляет
		{
			if ((std::sqrt(RotateShoot.X * RotateShoot.X + RotateShoot.Y * RotateShoot.Y)) < 500) // ... и это корабль стрелок
			{
				bullet_cooldown = bullet_clock->ElapsedTime.AsSeconds();
				shooting_ready = 1;
				if (shooting_ready == 1 && bullet_cooldown >= bullet_cooldown_max)
				{
					bullet_clock->Restart();
					Bullet *b = new Bullet((location.X + 300 * Rotate.X), (location.Y + 300 * Rotate.Y), rotat + 180, 0.2f, 2.0f);
					Program::entities.push_back(b);
					shooting_ready = 0;

//C# TO C++ CONVERTER TODO TASK: A 'delete b' statement was not added since b was passed to a method or constructor. Handle memory management manually.
				}
			}
			else
			{
				shooting_ready = 0;
			}
		}

		if (Name == L"Bomber") //бомбер не стреляет
		{
		shooting_ready = 0;
		}

		if (Name == L"MiniBoss")
		{
			if ((std::sqrt(RotateShoot.X * RotateShoot.X + RotateShoot.Y * RotateShoot.Y)) < 500)
			{
				bullet_cooldown = bullet_clock->ElapsedTime.AsSeconds();
				shooting_ready = 1;
				if (shooting_ready == 1 && bullet_cooldown >= bullet_cooldown_max_miniBoss)
				{
					bullet_clock->Restart();

					if (CountGuns == 1)
					{
						Bullet *b1 = new Bullet(location.X + sprite->Texture->Size.X * Rotate.X, location.Y + sprite->Texture->Size.X * Rotate.Y, rotat + 180, 0.3f, 1.5f);
						Program::entities.push_back(b1);

//C# TO C++ CONVERTER TODO TASK: A 'delete b1' statement was not added since b1 was passed to a method or constructor. Handle memory management manually.
					}

					if (CountGuns == 4)
					{
						int a = rnd->Next(1,3);

						if (a == 1)
						{
							Bullet *b1 = new Bullet(location.X + 150 * RotateToGun.X + sprite->Texture->Size.X * 2 * Rotate.X, location.Y + 150 * RotateToGun.Y + sprite->Texture->Size.X * 2 * Rotate.Y, rotat + 180, 0.3f, 1.5f);
							Program::entities.push_back(b1);

							Bullet *b2 = new Bullet(location.X + (-150) * RotateToGun.X + sprite->Texture->Size.X * 2 * Rotate.X, location.Y + (-150) * RotateToGun.Y + sprite->Texture->Size.X * 2 * Rotate.Y, rotat + 180, 0.3f, 1.5f);
							Program::entities.push_back(b2);

//C# TO C++ CONVERTER TODO TASK: A 'delete b2' statement was not added since b2 was passed to a method or constructor. Handle memory management manually.
//C# TO C++ CONVERTER TODO TASK: A 'delete b1' statement was not added since b1 was passed to a method or constructor. Handle memory management manually.
						}
						if (a == 2)
						{
							Bullet *b3 = new Bullet(location.X + 300 * RotateToGun.X + sprite->Texture->Size.X * 1.5f * Rotate.X, location.Y + 300 * RotateToGun.Y + sprite->Texture->Size.X * 1.5f * Rotate.Y, rotat + 180, 0.3f, 1.5f);
							Program::entities.push_back(b3);
							Bullet *b4 = new Bullet(location.X + (-300) * RotateToGun.X + sprite->Texture->Size.X * 1.5f * Rotate.X, location.Y + (-300) * RotateToGun.Y + sprite->Texture->Size.X * 1.5f * Rotate.Y, rotat + 180, 0.3f, 1.5f);
							Program::entities.push_back(b4);

//C# TO C++ CONVERTER TODO TASK: A 'delete b4' statement was not added since b4 was passed to a method or constructor. Handle memory management manually.
//C# TO C++ CONVERTER TODO TASK: A 'delete b3' statement was not added since b3 was passed to a method or constructor. Handle memory management manually.
						}
					}
					shooting_ready = 0;
				}
			}
			else
			{
				shooting_ready = 0;
			}
		}


		//Stop
		if (Name == L"ShootShip") //стрелок стреляет
		{
			if ((std::sqrt(RotateShoot.X * RotateShoot.X + RotateShoot.Y * RotateShoot.Y)) < 200) // ... и это корабль стрелок
			{
				velocity = Vector2f(0, 0);
			}
		}

		if (Name == L"MiniBoss") //стрелок стреляет
		{
			if ((std::sqrt(RotateShoot.X * RotateShoot.X + RotateShoot.Y * RotateShoot.Y)) < 300) // ... и это корабль стрелок
			{
				velocity = Vector2f(0, 0);
			}
		}

		if (IsAnimation == true)
		{
			sprite = animEnemy->sprite;
			animEnemy->update();
		}

		Program::Window->Draw(sprite);

		delete rnd;
	}

	Vector2f EnemyShip::Normalization(Vector2f vec, float X, float Y)
	{
		float d = static_cast<float>(std::sqrt((vec.X) * (vec.X) + (vec.Y) * (vec.Y)));
		vec = vec / (10 * d);
		return vec;
	}
}
