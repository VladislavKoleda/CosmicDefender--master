#include "Program.h"
#include "Entities/Entity.h"
#include "Content/Content2.h"
#include "Entities/Ship.h"
#include "Levels/Menu/Menu.h"
#include "Levels/Level.h"
#include "GameLogica/Game.h"
#include "Content/Constants.h"
#include "Particles/ParticleSystem.h"
#include "Content/Content.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

namespace ComicDefender
{

	sf::RenderWindow* Program::Window;
	std::vector<Entity*> Program::entities;
	Content2* Program::content;
	Program::Ship* Ship;
	Menu* Program::menu;
	std::vector<Level*> Program::levels;
	Game* Program::Logic = new Game();
	Program::Constants* Constants;

	void Program::Main(std::vector<std::wstring>& args)
	{
		//			#region Create Window
			//Создание окна
		Window = new sf::RenderWindow(SFML::Window::VideoMode(WindowWidth, WindowHeight), L"CosmicDefender");
		Window->SetVerticalSyncEnabled(true);
		Window->SetFramerateLimit(60);
		//			#endregion

		//			#region События

			//Добавим событие на закрытие окна
		Window->Closed += Window_Closed;
		Window->Resized += Win_Resized;

		//			#endregion

		//			#region Initialization Start Components

		//			#region Content and Menu Load

		content = new Content2();
		menu = new Menu();
		content->Load();
		Constants = new Constants();
		menu->Load();

		//			#endregion

		//			#region Levels

		Level* level1 = new Level(content->GetBackgroundLevel1(), Constants->Boss1, L"Level1");
		levels.push_back(level1);
		Level* level2 = new Level(content->GetBackgroundLevel2(), Constants->Boss2, L"Level2");
		levels.push_back(level2);
		Level* level3 = new Level(content->GetBackgroundLevel3(), Constants->Boss3, L"Level3");
		levels.push_back(level3);



		//level1 = new level(Content2.GetSpriteBoss, harakterist);
		//level1 = new level(Const.Boss1Hp, , harakterist);


	//			#endregion

	//			#region Game Logic and Particles
		Game* Logic = new Game(); //Логика

		ParticleSystem* particles = new ParticleSystem(5000); //ParticleSystem

		Content::Load(); //Content

	//			#endregion


		Ship = new Ship(content->GetShip1(), 500, 500, 25, 1.5f, .2f, 100, 1); //Загружаем корабль(пока что только один корабль с дамагом 25)
		//Ship = new Ship();
		entities.push_back(Ship); //Добавляем его в лист объектов


		Clock* clock = new Clock();

		//			#endregion

		while (Window->IsOpen)
		{
			//				#region Time

			float time = clock->ElapsedTime.AsMicroseconds();
			clock->Restart();
			time = time / 10000;

			//				#endregion

			Window->DispatchEvents(); //Cобираем ивенты
			Window->Clear(); //Чистим экран

	//				#region If Open Menu

			if (menu->IsOpen == true)
			{
				menu->Update();
			}

			//				#endregion


			for (auto level : levels.ToList())
			{
				if (level->IsOpen == true)
				{
					Window->Draw(level->Background);

					//						#region Particles
					particles->Update();
					Window->Draw(particles);
					//						#endregion

					//						#region Logic
					Logic->Update(Ship, entities);
					Logic->CreateAsteroid(entities, 1000);
					Logic->Enemy(entities, 0, level->LevelBoss);
					//						#endregion
				}

			}


			Window->Display(); //Выводит всё на дисплей
		}

		delete clock;
		//C# TO C++ CONVERTER TODO TASK: A 'delete particles' statement was not added since particles was passed to a method or constructor. Handle memory management manually.
		delete Logic;
		//C# TO C++ CONVERTER TODO TASK: A 'delete level3' statement was not added since level3 was passed to a method or constructor. Handle memory management manually.
		//C# TO C++ CONVERTER TODO TASK: A 'delete level2' statement was not added since level2 was passed to a method or constructor. Handle memory management manually.
		//C# TO C++ CONVERTER TODO TASK: A 'delete level1' statement was not added since level1 was passed to a method or constructor. Handle memory management manually.
	}


}
