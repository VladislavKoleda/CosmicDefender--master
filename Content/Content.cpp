#include "Content.h"

using namespace SFML::Graphics;
using namespace SFML::System;

namespace ComicDefender
{

const std::wstring Content::CONTENT_DIRICTORY = L"..\\Content\\Textures\\";
Texture *Content::Texture0_Level1;
Texture *Content::Texture0_Asteroid;
Texture *Content::Texture0_Cursor;
Sprite *Content::sBackground;
Sprite *Content::sPlayer;
Sprite *Content::cursorSprite;
Sprite *Content::sAsteroid;
Sprite *Content::sExplosion;
Image *Content::iExplosion;
Texture *Content::tExplosion;

	void Content::Load()
	{

		Texture0_Level1 = new Texture(CONTENT_DIRICTORY + L"Level1.jpg");
		Texture0_Level1->Smooth = true;
		sBackground = new Sprite(Texture0_Level1);
		cursorSprite = new Sprite(Texture0_Cursor);
		Texture0_Asteroid = new Texture(CONTENT_DIRICTORY + L"Asteroid1.png");
		Texture0_Asteroid->Smooth = true;
		sAsteroid = new Sprite(Texture0_Asteroid);



		iExplosion = new Image(CONTENT_DIRICTORY + L"Explosive\\type_B.png");
		tExplosion = new Texture(iExplosion);
		tExplosion->Smooth = true;
		sExplosion = new Sprite(tExplosion);
		sExplosion->Origin = Vector2f(iExplosion->Size.X / 2, iExplosion->Size.Y / 2);








		//AnimationExplosive1 = new Animation("Explosive\\type_B.png", 0, 0, 192, 192, 64, 0.1f, 0);
	}

	Sprite *Content::GetTextureLevel1(float a, float b)
	{
		sBackground->Scale = Vector2f(a,b);
		return sBackground;
	}

	Sprite *Content::GetTextureShip1()
	{
		return sPlayer;
	}

	Sprite *Content::GetTextureCursor()
	{
		return cursorSprite;
	}

	Sprite *Content::GetTextureAsteroid()
	{
		return sAsteroid;
	}
}
