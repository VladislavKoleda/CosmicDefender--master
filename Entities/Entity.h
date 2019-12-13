#pragma once

#define _USE_MATH_DEFINES
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
	class Entity
	{
		//Константы
	protected:
		static const std::wstring CONTENT_DIRICTORY;
		//
		float X = 0, Y = 0; //Координаты объекта
	private:
		float Dx = 0, Dy = 0; //Скорость объекта
		float Rotation = 0; //Направление объекта
		float Size = 0; //Размер объекта
	protected:
		int Health = 0; //Здоровье
		std::wstring Name; //Имя объекта
	private:
		float Speed = 0; //Скорость объекта
	public:
		Sprite *sprite;
	protected:
		Texture *texture;
		Image *image;
	public:
		Animation *animation;

		virtual ~Entity()
		{
			delete sprite;
			delete texture;
			delete image;
			delete animation;
		}

		Entity();

		Entity(int _health);



		//Настройки объекта
		void Settings(Sprite *_sprite, const std::wstring &_name, float x, float y, float rotation, float size, float _speed);

		void Settings(Animation *a, const std::wstring &_name, float x, float y, float rotation, float size, float _speed);

		//Урон предмету
		void damage(int _damage);


		//Виртуальные функции
		virtual void Update(float time);
		virtual void Draw();

		//Геттеры и Сеттеры
		void SetX(float x);
		void SetY(float y);
		void SetDx(float dx);
		void SetDy(float dy);
		float GetX();
		float GetY();
		float GetDx();
		float GetDy();
		std::wstring GetName();
		void SetName(const std::wstring &name);
		float GetRotation();
		void SetRotation(float _Rotation);
		int GetHealth();
		void SetHealth(int _health);
		float GetSize();
		void SetSize(float _size);
	};
}
