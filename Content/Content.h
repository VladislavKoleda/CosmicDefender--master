#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <string>

using namespace sf;

namespace ComicDefender
{
	class Content : public Transformable
	{
		//Директория к текстурам
	private:
		static const std::wstring CONTENT_DIRICTORY;

		//Название переменных для всех текстур

		static Texture *Texture0_Level1;
		static Texture *Texture0_Asteroid;
		static Texture *Texture0_Cursor;
		static Sprite *sBackground;
		static Sprite *sPlayer;
		static Sprite *cursorSprite;
		static Sprite *sAsteroid;


	public:
		static Sprite *sExplosion;
		static Image *iExplosion;
		static Texture *tExplosion;


		//public static Animation animAsteroid = new Animation("animAsteroid.png", 0, 0, 85, 100, 6, 5, 0.15f);



		// public static Player Ship1;

		//

		//Метод для загрузки текстуры
		static void Load();

		static Sprite *GetTextureLevel1(float a, float b);
		static Sprite *GetTextureShip1();
		static Sprite *GetTextureCursor();
		static Sprite *GetTextureAsteroid();



	};
}
