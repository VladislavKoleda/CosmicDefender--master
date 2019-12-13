#include "Boss.h"
#include "../Animation/Animation.h"
#include "Ship.h"
#include "../Program.h"

using namespace SFML::Graphics;
using namespace SFML::System;
using namespace SFML::Window;

namespace ComicDefender
{

float Boss::rotat = 0;

	Boss::Boss()
	{

	}

	Boss::Boss(Sprite *_sprite, Animation *_animation, float _X, float _Y, int damage, float speed, float shoot_speed, int health, int countguns, const std::wstring &name)
	{
		sprite = new Sprite(_sprite);
		location = Vector2f(_X, _Y);
		sprite->Position = location;
		sprite->Scale = Vector2f(0.4F, 0.4F);
		SetHealth(health);
		VectorSpeed = speed;
		Name = name; //  $$$$
		X = _X;
		Y = _Y;
		CountGuns = countguns;
		animEnemy = _animation;
		Settings(_animation, L"Boss1", 0, 100, 100, 1.0f, 0.3f);
	}

	Boss::Boss(Sprite *_sprite, float _X, float _Y, int damage, float speed, float shoot_speed, int health, int countguns, const std::wstring &name)
	{
		sprite = new Sprite(_sprite);
		location = Vector2f(_X, _Y);
		sprite->Position = location;
		sprite->Scale = Vector2f(0.4F, 0.4F);
		SetHealth(health);
		VectorSpeed = speed;
		Name = name; //  $$$$
		X = _X;
		Y = _Y;
		CountGuns = countguns;
	}

	void Boss::Update(float time)
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

		if (animEnemy != nullptr)
		{
			sprite = animEnemy->sprite;
			animEnemy->update();
		}
		Program::Window->Draw(sprite);

		delete rnd;
	}

	Vector2f Boss::Normalization(Vector2f vec, float X, float Y)
	{
		float d = static_cast<float>(std::sqrt((vec.X) * (vec.X) + (vec.Y) * (vec.Y)));
		vec = vec / (10 * d);
		return vec;
	}
}
