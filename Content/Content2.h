#pragma once

//====================================================================================================
//The Free Edition of C# to C++ Converter limits conversion output to 100 lines per file.

//To subscribe to the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-csharp-to-cplus.html
//====================================================================================================

#include <string>
#include <vector>

//C# TO C++ CONVERTER NOTE: Forward class declarations:
namespace ComicDefender { class Animation; }

using namespace SFML::Graphics;
using namespace SFML::System;

namespace ComicDefender
{
	class Content2
	{
	private:
		static const std::wstring CONTENT_DIRICTORY;
		Font *font;
		Text *TextPlay;
		RectangleShape *RectangleHp1;

	public:
		Sprite *BackGround;


//		#region Animation

	private:
		Animation *aAnimAsteroid1;
		Animation *aBoss1;

//		#endregion

//		#region Sprites

		Sprite *sAnimAsteroid1;
		Sprite *sExplosion;
		Sprite *cursorSprite;
		Sprite *sAsteroid1;
		Sprite *sAsteroid2;
		Sprite *sShootShip;
		Sprite *sBomber;
		Sprite *sBullet;
		Sprite *sB_Health;
		Sprite *sShip1;
		Sprite *sShip2;
		Sprite *sShip3;
		Sprite *sShip4;
		Sprite *sShip5;
		Sprite *sShip6;
		Sprite *sShip7;
		Sprite *sShip8;
		Sprite *sShip9;
		Sprite *sTypeA;
		Sprite *sTypeB;
		Sprite *sTypeC;
		Sprite *sMenuLevels;
		Sprite *sMenuShips;
		Sprite *sMenuTable;
		Sprite *sMenuButton;
		Sprite *sCircle1;
		Sprite *sCircle2;
		Sprite *sCircle3;
		Sprite *sCircle4;
	public:
		std::vector<Sprite*> sMenuRectHp = std::vector<Sprite*>(3);
		std::vector<Sprite*> sMenuRectDmg = std::vector<Sprite*>(3);
		std::vector<Sprite*> sMenuRectSpd = std::vector<Sprite*>(3);
	private:
		Sprite *sShip1_lock;
		Sprite *sShip2_lock;
		Sprite *sShip3_lock;
		Sprite *sShip4_lock;
		Sprite *sShip5_lock;
		Sprite *sShip6_lock;
		Sprite *sShip7_lock;
		Sprite *sShip8_lock;
		Sprite *sShip9_lock;
		Sprite *sShip1_unlock;
		Sprite *sShip2_unlock;
		Sprite *sShip3_unlock;
		Sprite *sShip4_unlock;
		Sprite *sShip5_unlock;
		Sprite *sShip6_unlock;
		Sprite *sShip7_unlock;
		Sprite *sShip8_unlock;
		Sprite *sShip9_unlock;
		Sprite *sTestButton;
		Sprite *sListUp;
		Sprite *sListDown;
		Sprite *sMiniBoss;
		Sprite *sBoss1;
		Sprite *sBoss2;
		Sprite *sBoss3;
		Sprite *sBoss4;
		Sprite *sBoss5;
		Sprite *sBoss6;

		Sprite *sShield;

		Sprite *sLevel1;
		Sprite *sLevel2;
		Sprite *sLevel3;
		Sprite *sLevel4;
		Sprite *sLevel5;
		Sprite *sLevel6;

		Sprite *sBackgroundLevel1;
		Sprite *sBackgroundLevel2;
		Sprite *sBackgroundLevel3;
		Sprite *sBackgroundLevel4;
		Sprite *sBackgroundLevel5;
		Sprite *sBackgroundLevel6;


//		#endregion

//		#region Textures
		Texture *tAnimAsteroid1;

		Texture *tExplosion;
		Texture *tLevel1;
		Texture *tAsteroid2;
		Texture *tAsteroid1;
		Texture *tCursor;
		Texture *tShootShip;
		Texture *tBomber;
		Texture *tBullet;
		Texture *tB_Health;

//====================================================================================================
//End of the allowed output for the Free Edition of C# to C++ Converter.

//To subscribe to the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-csharp-to-cplus.html
//====================================================================================================
