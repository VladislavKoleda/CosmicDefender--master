//====================================================================================================
//The Free Edition of C# to C++ Converter limits conversion output to 100 lines per file.

//To subscribe to the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-csharp-to-cplus.html
//====================================================================================================

#include "Menu.h"
#include "MenuRectShips.h"
#include "MenuRectButtons.h"
#include "MenuRectMainShip.h"
#include "../../Program.h"

using namespace SFML::Graphics;
using namespace SFML::System;
using namespace SFML::Window;

namespace ComicDefender
{

	Menu::Menu()
	{
		IsOpen = true;
	}

	void Menu::Load()
	{
		MainShip = new MenuRectMainShip();
		listShips = 1;
		listLevels = 1;
		Program::content->LoadListShips1();
		Program::content->BackGround = new Sprite(Program::content->GetBackgroundLevel1());
	}

	void Menu::Update()
	{
		CopyColor = Program::content->GetShip9_lock()->Color;
		Program::Window->Draw(Program::content->BackGround);
		Program::Window->Draw(Program::content->GetMenuLevels());
		Program::Window->Draw(Program::content->GetMenuShips());
		Program::Window->Draw(Program::content->GetMenuTable());
		Program::Window->Draw(Program::content->GetCircle1());
		Program::Window->Draw(Program::content->GetCircle2());
		Program::Window->Draw(Program::content->GetCircle3());
		Program::Window->Draw(Program::content->GetCircle4());
		Program::Window->Draw(Program::content->GetMenuButton());
		Program::Window->Draw(Program::content->GetTextPlay());
		Program::Window->Draw(Program::content->GetListUpButton());
		Program::Window->Draw(Program::content->GetListDownButton());

		if (listShips == 1)
		{
			Program::content->LoadListShips1();
		}

		if (listShips == 2)
		{
			Program::content->LoadListShips2();
		}

		if (listLevels == 1)
		{
			Program::content->LoadListLevels1();
		}

		if (listShips == 1)
		{
			// Program.content.LoadListShips1();
			Program::Window->Draw(Program::content->GetShip1_lock());
			Program::Window->Draw(Program::content->GetShip2_lock());
			Program::Window->Draw(Program::content->GetShip3_lock());
			Program::Window->Draw(Program::content->GetShip4_lock());
			Program::Window->Draw(Program::content->GetShip5_lock());
			Program::Window->Draw(Program::content->GetShip6_lock());

		}
		else
		{
			Program::Window->Draw(Program::content->GetShip7_lock());
			Program::Window->Draw(Program::content->GetShip8_lock());
			Program::Window->Draw(Program::content->GetShip9_lock());
		}

		if (listLevels == 1)
		{
			Program::Window->Draw(Program::content->GetLevel1());
			Program::Window->Draw(Program::content->GetLevel2());
			Program::Window->Draw(Program::content->GetLevel3());
			Program::Window->Draw(Program::content->GetLevel4());
			Program::Window->Draw(Program::content->GetLevel5());
			Program::Window->Draw(Program::content->GetLevel6());
		}


		Program::Window->Draw(Program::menu->MainShip->SpriteShip);


		for (int i = 0; i < 3; i++)
		{
			Program::Window->Draw(Program::content->sMenuRectHp[i]);
			Program::Window->Draw(Program::content->sMenuRectDmg[i]);
			Program::Window->Draw(Program::content->sMenuRectSpd[i]);
		}

	//			#region Colide with Buttons on Menu

		for (auto RectShip : Program::menu->RectShips.ToList())
		{
			if (Contains(RectShip->SpriteRect, Mouse::GetPosition(Program::Window).X, Mouse::GetPosition(Program::Window).Y))
			{
				Program::Window->Draw(RectShip->SpriteRect);

				//RectShip.SpriteRect.Color = new Color(255,0,0,100);

				RectShip->SpriteRect->Scale = Vector2f(1.05f, 1.05f);

				if (Mouse::IsButtonPressed(Mouse::Button::Left))
				{
					MainShip->Damage = RectShip->ship->dmg;
					MainShip->Speed = RectShip->ship->VectorSpeed;
					MainShip->Shoot_speed = RectShip->ship->Shoot_Speed;
					MainShip->Health = RectShip->ship->GetHealth();
					MainShip->CountGuns = RectShip->ship->CountGuns;
					MainShip->SpriteShip = RectShip->ship->sprite;
					MainShip->SpriteShip->Position = Vector2f(640, 360);
					MainShip->SpriteShip->Scale = Vector2f(1.0f, 1.0f);

					Program::Ship->Settings(MainShip->SpriteShip, 500, 500, MainShip->Damage, MainShip->Speed, MainShip->Shoot_speed, MainShip->Health, MainShip->CountGuns);
				}
			}
			else
			{
				//RectShip.SpriteRect.Color = Program.content.GetColorButtonUp().Color;
				RectShip->SpriteRect->Scale = Vector2f(1.0f, 1.0f);

			}
		}

		for (auto RectButtons : Program::menu->RectButtons.ToList())
		{
			if (Contains(RectButtons->SpriteRect, Mouse::GetPosition(Program::Window).X, Mouse::GetPosition(Program::Window).Y))
			{
				Program::Window->Draw(RectButtons->SpriteRect);

				if (RectButtons->Name == L"ButtonUp" || RectButtons->Name == L"ButtonDown")
				{
					RectButtons->SpriteRect->Color = Color::Red;
				}
				else
				{
					RectButtons->SpriteRect->Color = Color(0, 100, 255);
				}


				if (Mouse::IsButtonPressed(Mouse::Button::Left))
				{
					//Событие что нажалось в меню
					//Если нажалось кнопка смены листа то

					if (RectButtons->Name == L"ButtonUp")
					{
						listShips = 1;
					}
					if (RectButtons->Name == L"ButtonDown")
					{
						listShips = 2;
					}
					if (RectButtons->Name == L"ButtonPlay")
					{
						for (auto level : Program::levels.ToList())
						{
							if (level->Name == CurrentLevel)
							{
								level->IsOpen = true;
								Program::menu->IsOpen = false;
							}
						}
					}
				}

			}
			else
			{
				RectButtons->SpriteRect->Color = Program::content->GetColorButtonUp()->Color;
			}
		}

		for (auto RectLevels : Program::menu->RectLevels.ToList())
		{
			if (Contains(RectLevels->SpriteRect, Mouse::GetPosition(Program::Window).X, Mouse::GetPosition(Program::Window).Y))
			{
				RectLevels->SpriteRect->Scale = Vector2f(1.05f, 1.05f);

				Program::Window->Draw(RectLevels->SpriteRect);

				if (Mouse::IsButtonPressed(Mouse::Button::Left))
				{
					if (RectLevels->Name == L"Level1")
					{
						CurrentLevel = L"Level1";
						Program::content->BackGround = new Sprite(RectLevels->Background);
					}
					if (RectLevels->Name == L"Level2")
					{
						CurrentLevel = L"Level2";

//====================================================================================================
//End of the allowed output for the Free Edition of C# to C++ Converter.

//To subscribe to the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-csharp-to-cplus.html
//====================================================================================================
