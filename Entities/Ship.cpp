#include "Ship.h"
#include "../Program.h"
#include "Bullet.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace sf;

namespace ComicDefender
{
	Vector2f Ship::location = Vector2f(0, 0);
	float Ship::rotat = 0;

	Ship::Ship()
	{
	}

	Ship::Ship(Sprite *_sprite, float _X, float _Y, int damage, float speed, float shoot_speed, int health, int countguns)
	{
		Name = L"PlayerShip";
		sprite = new Sprite(*_sprite);
		sprite->setOrigin = Vector2f(sprite->getTexture->Size.X / 2, sprite->getTexture->Size.Y / 2);
		location = Vector2f(_X, _Y);
		sprite->setPosition = location;
		sprite->setScale = Vector2f(0.4F, 0.4F);
		bullet_cooldown_max = shoot_speed;
		VectorSpeed = speed;
		dmg = damage; //изменить попозже ????????????????????????????????????????
		Health = health;
		CountGuns = countguns;
		X = _X;
		Y = _Y;
	}

	void Ship::Settings(sf::Sprite *_sprite, float _X, float _Y, int damage, float speed, float shoot_speed, int health, int countguns)
	{
		Name = L"PlayerShip";
		sprite = new sf::Sprite(*_sprite);
		sprite->setOrigin = Vector2f(sprite->getTexture->Size.X / 2, sprite->getTexture->Size.Y / 2);
		location = Vector2f(_X, _Y);
		sprite->setPosition = location;
		sprite->setScale = Vector2f(0.4F, 0.4F);
		bullet_cooldown_max = shoot_speed;
		VectorSpeed = speed;
		dmg = damage; //изменить попозже ????????????????????????????????????????
		Health = health;
		CountGuns = countguns;
		X = _X;
		Y = _Y;
	}

	void Ship::Update(float time)
	{

		Vector2i pixelPos = Mouse::getPosition(*(Program::Window)); //забираем коорд курсора
		Vector2f pos = Program::Window->mapPixelToCoords(pixelPos); //переводим их в игровые (уходим от коорд окна
		Vector2f Rotate = pos - location;
		Vector2f RotateToGun;
		RotateToGun.y = 1;
		RotateToGun.x = (((-1) * (Rotate.y * RotateToGun.y)) / (Rotate.x));
		RotateToGun = Normalization(RotateToGun, pos.x, pos.y);

		Rotate = Normalization(Rotate, pos.x, pos.y);
		direction = Rotate;
		float v = 0.3f;
		rotat = static_cast<float>((std::atan2(Rotate.y, Rotate.x) * 180 / M_PI) - 90);
		sprite->setRotation = rotat;
		sprite->setPosition = location;
		location += velocity * time; // Где находится корабль

	//			#region MoveShip
		if (Keyboard::isKeyPressed(Keyboard::Key::W))
		{
			velocity += v * direction;
			float constanta = static_cast<float>(std::sqrt((VectorSpeed * VectorSpeed) / (velocity.X * velocity.X + velocity.Y * velocity.Y)));
			velocity2 = velocity * constanta;
			float Dvelocity = static_cast<float>(std::sqrt((velocity.X) * (velocity.X) + (velocity.Y) * (velocity.Y)));
			float Dvelocity2 = static_cast<float>(std::sqrt((velocity2.X) * (velocity2.X) + (velocity2.Y) * (velocity2.Y)));
			if (Dvelocity > Dvelocity2)
			{
				velocity = velocity2;
			}
		}

		if (location.x > 1280)
		{
			location.x = 0;
		}
		if (location.x < 0)
		{
			location.x = 1280;
		}

		if (location.y > 720)
		{
			location.y = 0;
		}
		if (location.y < 0)
		{
			location.y = 720;
		}

		X = location.x;
		Y = location.y;

	//			#endregion

	//			#region Shoot

		bullet_cooldown = bullet_clock->getElapsedTime.AsSeconds();
		shooting_ready = 0;

		if (Mouse::isButtonPressed(Mouse::Button::Left))
		{
			shooting_ready = 1;
		}
		if (shooting_ready == 1 && bullet_cooldown >= .2f)
		{
			bullet_clock->restart();

			if (CountGuns == 1)
			{
				Bullet *b1 = new Bullet(GetX() + sprite->getTexture->Size.X * Rotate.x, GetY() + sprite->getTexture->Size.X * Rotate.y, GetRotation(), 0.2f, Shoot_Speed);
				Program::entities.push_back(b1);

//C# TO C++ CONVERTER TODO TASK: A 'delete b1' statement was not added since b1 was passed to a method or constructor. Handle memory management manually.
			}

			if (CountGuns == 2)
			{
				Bullet *b1 = new Bullet(GetX() + 100 * RotateToGun.x + sprite->getTexture->Size.X * Rotate.x, GetY() + 100 * RotateToGun.y + sprite->getTexture->Size.x * Rotate.y, GetRotation(), 0.2f, Shoot_Speed);
				Program::entities.push_back(b1);

				Bullet *b2 = new Bullet(GetX() + (-100) * RotateToGun.x + sprite->getTexture->Size.X * Rotate.x, GetY() + (-100) * RotateToGun.y + sprite->getTexture->Size.X * Rotate.y, GetRotation(), 0.2f, Shoot_Speed);
				Program::entities.push_back(b2);

//C# TO C++ CONVERTER TODO TASK: A 'delete b2' statement was not added since b2 was passed to a method or constructor. Handle memory management manually.
//C# TO C++ CONVERTER TODO TASK: A 'delete b1' statement was not added since b1 was passed to a method or constructor. Handle memory management manually.
			}
			shooting_ready = 0;
		}

	//			#endregion

		Program::Window->draw(*sprite);
	}

	Vector2f Ship::Normalization(Vector2f vec, float X, float Y)
	{
		float d = static_cast<float>(std::sqrt((vec.x) * (vec.x) + (vec.y) * (vec.y)));
		vec = vec / (10 * d);
		return vec;
	}

	float Ship::GetX()
	{
		return location.x;
	}

	float Ship::GetY()
	{
		return location.y;
	}

	float Ship::GetRotation()
	{
		return rotat;
	}

	int Ship::GetDamage()
	{
		return dmg;
	}
}
