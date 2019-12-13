//====================================================================================================
//The Free Edition of C# to C++ Converter limits conversion output to 100 lines per file.

//To subscribe to the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-csharp-to-cplus.html
//====================================================================================================

#include "Content2.h"
#include "../Animation/Animation.h"
#include "../Levels/Menu/MenuRectButtons.h"
#include "../Program.h"
#include "../Levels/Menu/MenuRectShips.h"
#include "../Levels/Menu/MenuRectLevels.h"

using namespace SFML::Graphics;
using namespace SFML::System;

namespace ComicDefender
{

const std::wstring Content2::CONTENT_DIRICTORY = L"..\\Content\\Textures\\";

	void Content2::Load()
	{
	//			#region Font

		font = new Font(LR"(..\Content\Textures\Font\eng.ttf)");

	//			#endregion

	//			#region Animation Asteroid1

		iAnimAsteroid1 = new Image(CONTENT_DIRICTORY + L"Animation\\AnimAsteroid.png");
		tAnimAsteroid1 = new Texture(iAnimAsteroid1);
		tAnimAsteroid1->Smooth = true;
		sAnimAsteroid1 = new Sprite(tAnimAsteroid1);
		sAnimAsteroid1->Origin = Vector2f(iAnimAsteroid1->Size.X / 2, iAnimAsteroid1->Size.Y / 2);

	//			#endregion

	//			#region Bosses

	//			#region Animation Boss1

		iBoss1 = new Image(CONTENT_DIRICTORY + L"Bosses\\Boss1_Shield.png");
		tBoss1 = new Texture(iBoss1);
		tBoss1->Smooth = true;
		sBoss1 = new Sprite(tBoss1);
		sBoss1->Origin = Vector2f(iBoss1->Size.X / 2, iBoss1->Size.Y / 2);

	//			#endregion

	//			#region Boss2

		iBoss2 = new Image(CONTENT_DIRICTORY + L"Bosses\\Boss2.png");
		tBoss2 = new Texture(iBoss2);
		tBoss2->Smooth = true;
		sBoss2 = new Sprite(tBoss2);
		sBoss2->Origin = Vector2f(iBoss2->Size.X / 2, iBoss2->Size.Y / 2);

	//			#endregion

	//			#region Boss3

		iBoss3 = new Image(CONTENT_DIRICTORY + L"Bosses\\Boss3.png");
		tBoss3 = new Texture(iBoss3);
		tBoss3->Smooth = true;
		sBoss3 = new Sprite(tBoss3);
		sBoss3->Origin = Vector2f(iBoss3->Size.X / 2, iBoss3->Size.Y / 2);

	//			#endregion



	//			#endregion

	//			#region Animation Explosive Asteroid

		iExplosion = new Image(CONTENT_DIRICTORY + L"Explosive\\type_B.png");
		tExplosion = new Texture(iExplosion);
		tExplosion->Smooth = true;
		sExplosion = new Sprite(tExplosion);
		sExplosion->Origin = Vector2f(iExplosion->Size.X / 2, iExplosion->Size.Y / 2);

	//			#endregion

	//			#region Enemy Ship
		iShootShip = new Image(CONTENT_DIRICTORY + L"Enemy\\EnemyShip1_green.png");
		tShootShip = new Texture(iShootShip);
		tShootShip->Smooth = true;
		sShootShip = new Sprite(tShootShip);
		sShootShip->Origin = Vector2f(iShootShip->Size.X / 2, iShootShip->Size.Y / 2);
	//			#endregion

	//			#region Bomber Ship
		iBomber = new Image(CONTENT_DIRICTORY + L"Enemy\\playerShip3_red.png");
		tBomber = new Texture(iBomber);
		tBomber->Smooth = true;
		sBomber = new Sprite(tBomber);
		sBomber->Origin = Vector2f(iBomber->Size.X / 2, iBomber->Size.Y / 2);
	//			#endregion

	//			#region Bonus_Health
		iB_Health = new Image(CONTENT_DIRICTORY + L"Bonuses\\HP_Bonus.png");
		tB_Health = new Texture(iB_Health);
		tB_Health->Smooth = true;
		sB_Health = new Sprite(tB_Health);
		sB_Health->Origin = Vector2f(iB_Health->Size.X / 2, iB_Health->Size.Y / 2);
	//			#endregion

	//			#region Mini Boss Ship
		iMiniBoss = new Image(CONTENT_DIRICTORY + L"Enemy\\miniBoss.png");
		tMiniBoss = new Texture(iMiniBoss);
		tMiniBoss->Smooth = true;
		sMiniBoss = new Sprite(tMiniBoss);
		sMiniBoss->Origin = Vector2f(iMiniBoss->Size.X / 2, iMiniBoss->Size.Y / 2);
	//			#endregion

	//			#region Asteroid1
		iAsteroid1 = new Image(CONTENT_DIRICTORY + L"Animation\\animAsteroid.png");
		tAsteroid1 = new Texture(iAsteroid1);
		tAsteroid1->Smooth = true;
		sAsteroid1 = new Sprite(tAsteroid1);
	//			#endregion

	//			#region Asteroid2
		iAsteroid2 = new Image(CONTENT_DIRICTORY + L"animAsteroid2.png");
		tAsteroid2 = new Texture(iAsteroid2);
		tAsteroid2->Smooth = true;
		sAsteroid2 = new Sprite(tAsteroid2);
	//			#endregion

	//			#region Shield

		iShield = new Image(CONTENT_DIRICTORY + L"Upgrade\\Shield.png");
		tShield = new Texture(iShield);
		tShield->Smooth = true;
		sShield = new Sprite(tShield);

	//			#endregion

	//			#region Bullet

		iBullet = new Image(CONTENT_DIRICTORY + L"Bullet.png");
		tBullet = new Texture(iBullet);
		tBullet->Smooth = true;
		sBullet = new Sprite(tBullet);

	//			#endregion

	//			#region TypeA
		iTypeA = new Image(CONTENT_DIRICTORY + L"Explosive\\type_A.png");
		tTypeA = new Texture(iTypeA);
		tTypeA->Smooth = true;
		sTypeA = new Sprite(tTypeA);

	//			#endregion

	//			#region TypeB
		iTypeB = new Image(CONTENT_DIRICTORY + L"Explosive\\type_B.png");
		tTypeB = new Texture(iTypeB);
		tTypeB->Smooth = true;
		sTypeB = new Sprite(tTypeB);

	//			#endregion

	//			#region TypeC
		iTypeC = new Image(CONTENT_DIRICTORY + L"Explosive\\type_C.png");
		tTypeC = new Texture(iTypeC);
		tTypeC->Smooth = true;
		sTypeC = new Sprite(tTypeC);

	//			#endregion

	//			#region Ship1

		iShip1 = new Image(CONTENT_DIRICTORY + L"Ships\\Ship1.png");
		tShip1 = new Texture(iShip1);
		tShip1->Smooth = true;
		sShip1 = new Sprite(tShip1);

	//			#endregion

	//			#region Ship2

		iShip2 = new Image(CONTENT_DIRICTORY + L"Ships\\Ship2.png");
		tShip2 = new Texture(iShip2);
		tShip2->Smooth = true;
		sShip2 = new Sprite(tShip2);

	//			#endregion

	//			#region Ship3

		iShip3 = new Image(CONTENT_DIRICTORY + L"Ships\\Ship3.png");
		tShip3 = new Texture(iShip3);
		tShip3->Smooth = true;
		sShip3 = new Sprite(tShip3);

	//			#endregion

	//			#region Ship4

		iShip4 = new Image(CONTENT_DIRICTORY + L"Ships\\Ship4.png");
		tShip4 = new Texture(iShip4);
		tShip4->Smooth = true;
		sShip4 = new Sprite(tShip4);

	//			#endregion

	//			#region Ship5

		iShip5 = new Image(CONTENT_DIRICTORY + L"Ships\\Ship5.png");
		tShip5 = new Texture(iShip5);
		tShip5->Smooth = true;
		sShip5 = new Sprite(tShip5);

	//			#endregion

	//			#region Ship6

		iShip6 = new Image(CONTENT_DIRICTORY + L"Ships\\Ship6.png");

//====================================================================================================
//End of the allowed output for the Free Edition of C# to C++ Converter.

//To subscribe to the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-csharp-to-cplus.html
//====================================================================================================
