#include "Entity.h"
#include "../Animation/Animation.h"

using namespace SFML::Graphics;
using namespace SFML::System;

namespace ComicDefender
{

const std::wstring Entity::CONTENT_DIRICTORY = L"..\\Content\\Textures\\";

	Entity::Entity()
	{
		Health = 100;
	}

	Entity::Entity(int _health)
	{
		Health = _health;
	}

	void Entity::Settings(Sprite *_sprite, const std::wstring &_name, float x, float y, float rotation, float size, float _speed)
	{
		sprite = new Sprite(_sprite);
		sprite->Scale = Vector2f(size, size);
		sprite->Origin = Vector2f(sprite->Texture->Size.X / 2, sprite->Texture->Size.Y / 2);
		Name = _name;
		X = x;
		Y = y;
		Rotation = rotation;
		Size = size;
		Speed = _speed;
		float deltaX = static_cast<float>(std::cos(M_PI * (rotation - 90) / 180.0f)) * -1 * _speed;
		float deltaY = static_cast<float>(std::sin(M_PI * (rotation - 90) / 180.0f)) * -1 * _speed;
		Dx = deltaX;
		Dy = deltaY;
		X += Dx / 3;
		Y += Dy / 3;
	}

	void Entity::Settings(Animation *a, const std::wstring &_name, float x, float y, float rotation, float size, float _speed)
	{
		a->sprite->Scale = Vector2f(size, size);
		Name = _name;
		animation = a;
		X = x;
		Y = y;
		animation->X = x;
		animation->Y = y;
		animation->sprite->Rotation = rotation;
		Size = size;
		Speed = _speed;
		float deltaX = static_cast<float>(std::cos(M_PI * (rotation - 90) / 180.0f)) * -1 * _speed;
		float deltaY = static_cast<float>(std::sin(M_PI * (rotation - 90) / 180.0f)) * -1 * _speed;
		Dx = deltaX;
		Dy = deltaY;
	  //  X += 3 * Dx;
	   // Y += 3 * Dy;
		animation = a;

	}

	void Entity::damage(int _damage)
	{
		Health -= _damage;
	}

	void Entity::Update(float time)
	{
	}

	void Entity::Draw()
	{
	}

	void Entity::SetX(float x)
	{
		X = x;
	}

	void Entity::SetY(float y)
	{
		Y = y;
	}

	void Entity::SetDx(float dx)
	{
		Dx = dx;
	}

	void Entity::SetDy(float dy)
	{
		Dy = dy;
	}

	float Entity::GetX()
	{
		return X;
	}

	float Entity::GetY()
	{
		return Y;
	}

	float Entity::GetDx()
	{
		return Dx;
	}

	float Entity::GetDy()
	{
		return Dy;
	}

	std::wstring Entity::GetName()
	{
		return Name;
	}

	void Entity::SetName(const std::wstring &name)
	{
		Name = name;
	}

	float Entity::GetRotation()
	{
		return Rotation;
	}

	void Entity::SetRotation(float _Rotation)
	{
		Rotation = _Rotation;
	}

	int Entity::GetHealth()
	{
		return Health;
	}

	void Entity::SetHealth(int _health)
	{
		Health = _health;
	}

	float Entity::GetSize()
	{
		return Size;
	}

	void Entity::SetSize(float _size)
	{
		Size = _size;
	}
}
