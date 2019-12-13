#include "Bullet.h"
#include "../Animation/Animation.h"
#include "../Program.h"
#include "Ship.h"

using namespace SFML::Graphics;
using namespace SFML::System;
using namespace SFML::Window;

namespace ComicDefender
{

	Bullet::Bullet(float _X, float _Y, float _Rotation, float _size, float _speed)
	{
		this->Settings(Program::content->GetBullet(),L"Bullet", _X, _Y, _Rotation, _size, _speed);
		Vector2i pixelPos = Mouse::GetPosition(Program::Window); //забираем коорд курсора
		Vector2f pos = Program::Window->MapPixelToCoords(pixelPos); //переводим их в игровые (уходим от коорд окна
		float dX = pos.X - Ship::GetX(); //вектор , колинеарный прямой, которая пересекает спрайт и курсор
		float dY = pos.Y - Ship::GetY(); //он же, координата y
		float rotation = static_cast<float>(((std::atan2(static_cast<double>(dY), static_cast<double>(dX))) * 180 / M_PI) - 90); //получаем угол в радианах и переводим его в градусы
		sprite->Rotation = _Rotation;
	}

	void Bullet::Update(float time)
	{
		float _x = GetX();
		float _y = GetY();
		_x += GetDx();
		SetX(_x);
		_y += GetDy();
		SetY(_y);

		if (GetX() > Program::WindowWidth || GetX() < 0 || GetY() > Program::WindowHeight || GetY() < 0)
		{
			SetHealth(0);
		}

	}

	void Bullet::Draw()
	{
		sprite->Position = Vector2f(GetX(), GetY());
		Program::Window->Draw(sprite);
	}
}
