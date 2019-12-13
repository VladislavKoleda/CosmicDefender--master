#include "Game.h"
#include "../Entities/Entity.h"
#include "../Entities/Ship.h"
#include "../Program.h"
#include "../Animation/Animation.h"
#include "../Entities/Bonus.h"
#include "../Entities/Asteroid.h"
#include "../Entities/Boss.h"
#include "../Entities/EnemyShip.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
using namespace sf;

namespace ComicDefender
{

int Game::CountAsteroids = 0;
int Game::CountEnemies = 0;
bool Game::isBoss = false;

	void Game::Update(Ship *ship, std::vector<Entity*> &entities)
	{
		float time = clock->getElapsedTime.AsMicroseconds();
		clock->restart();
		time = time / 10000;

		for (auto entity : entities.ToList())
		{

			entity->Update(time);

			if (entity->animation != nullptr)
			{
				if (entity->GetName() == L"Explosion")
				{
					entity->animation->update();
					entity->animation->Draw();
					if (entity->animation->isEnd())
					{
						entity->SetHealth(0);
					}
				}
			   // entity.animation.update();
			   // entity.animation.Draw();
			}

			entity->Draw();

			if (entity->GetName() == L"PlayerShip" && entity->GetHealth() <= 0)
			{
				Ship *Ship = new Ship(Program::menu->MainShip->SpriteShip, 500, 500, Program::menu->MainShip->Damage, Program::menu->MainShip->Speed, Program::menu->MainShip->Shoot_speed, Program::menu->MainShip->Health, Program::menu->MainShip->CountGuns);
				//Ship Ship = new Ship(Program.menu.MainShip.SpriteShip, 500, 500, 25, 1.5f, .2f, 100);                  //Загружаем корабль

				entities.push_back(Ship);

//C# TO C++ CONVERTER TODO TASK: A 'delete Ship' statement was not added since Ship was passed to a method or constructor. Handle memory management manually.
			}


			if (entity->GetHealth() <= 0)
			{
				entities.Remove(entity);
			}
		}

		for (int i = 0; i < entities.size(); i++)
		{
			for (int j = 0; j < entities.size(); j++)
			{
				if (entities[j]->GetName() == L"Bullet" && (entities[i]->GetName() == L"Asteroid" || entities[i]->GetName() == L"ShootShip" || entities[i]->GetName() == L"Bomber" || entities[i]->GetName() == L"PlayerShip" || entities[i]->GetName() == L"MiniBoss" || entities[i]->GetName()->find(L"Boss") != std::wstring::npos)) //Найден косяк, урон для пули общий - урон нашего корабля.
				{
																																																				   //Если потом добавлять других врагов с уроном побольше, чем у обычных, то произойдёт бан

					//if(entities.Global)


					if (IsCollide(entities[i]->sprite, entities[j]->sprite))
					{
						Animation *AnimationExplosive1 = new Animation(Program::content->GetsExplosion(), 0, 0, 192, 192, 64, 2.0f);
						Entity *e = new Entity();
						e->Settings(AnimationExplosive1, L"Explosion", entities[j]->GetX(), entities[j]->GetY(), 0, 0.15F, 0.15f);
						entities.push_back(e);

						//Новый астероид
						//
						//

						entities[i]->damage(Program::Ship->GetDamage());
						entities[j]->SetHealth(0);

						//Выпадение бонуса
						if (entities[i]->GetName() == L"Asteroid" && entities[i]->GetHealth() == 0)
						{
							int b = rnd->Next(1, 100);
							if (b >= 1 && b <= 10)
							{
								Bonus *a = new Bonus(Program::content->GetsB_Health(), entities[j]->GetX(), entities[j]->GetY(), L"B_Health");
								entities.push_back(a);

//C# TO C++ CONVERTER TODO TASK: A 'delete a' statement was not added since a was passed to a method or constructor. Handle memory management manually.
							}

						}

						if (entities[i]->GetHealth() <= 0)
						{
							Animation *AnimationExplosive2 = new Animation(Program::content->GetsExplosion(), 0, 0, 192, 192, 64, 0.8f);
							Entity *q = new Entity();

							if (entities[i]->GetName()->find(L"Boss") != std::wstring::npos)
							{
								q->Settings(AnimationExplosive2, L"Explosion", entities[i]->GetX(), entities[i]->GetY(), 0, 1.0f, 0.15f);
							}
							else
							{
								q->Settings(AnimationExplosive2, L"Explosion", entities[i]->GetX(), entities[i]->GetY(), 0, 0.4F, 0.15f);
							}
							entities.push_back(q);

//C# TO C++ CONVERTER TODO TASK: A 'delete q' statement was not added since q was passed to a method or constructor. Handle memory management manually.
//C# TO C++ CONVERTER TODO TASK: A 'delete AnimationExplosive2' statement was not added since AnimationExplosive2 was passed to a method or constructor. Handle memory management manually.
						}

//C# TO C++ CONVERTER TODO TASK: A 'delete e' statement was not added since e was passed to a method or constructor. Handle memory management manually.
//C# TO C++ CONVERTER TODO TASK: A 'delete AnimationExplosive1' statement was not added since AnimationExplosive1 was passed to a method or constructor. Handle memory management manually.
					}
				}
				if (entities[i]->GetName() == L"PlayerShip" && (entities[j]->GetName() == L"ShootShip" || entities[j]->GetName() == L"Asteroid" || entities[j]->GetName() == L"Bomber" || entities[j]->GetName() == L"MiniBoss" || entities[j]->GetName()->find(L"Boss") != std::wstring::npos))
				{
					if (IsCollide(entities[i]->sprite, entities[j]->sprite))
					{
						Animation *AnimationExplosive1 = new Animation(Program::content->GetsExplosion(), 0, 0, 192, 192, 64, 0.8f);
						Entity *e = new Entity();
						e->Settings(AnimationExplosive1, L"Explosion", entities[i]->GetX(), entities[i]->GetY(), 0, 0.4F, 0.15f);
						entities.push_back(e);

						if (entities[j]->GetName() == L"ShootShip" || entities[j]->GetName() == L"Asteroid")
						{
							entities[i]->damage(50);
							entities[j]->SetHealth(0);

							//Выпадение бонуса
							if (entities[j]->GetName() == L"Asteroid")
							{
								int b = rnd->Next(1, 100);
								if (b >= 1 && b <= 10)
								{
									Bonus *a = new Bonus(Program::content->GetsB_Health(), entities[j]->GetX(), entities[j]->GetY(), L"B_Health");
									entities.push_back(a);

//C# TO C++ CONVERTER TODO TASK: A 'delete a' statement was not added since a was passed to a method or constructor. Handle memory management manually.
								}
							}
						} //Урон при столкновении нашему кораблю 50!!!!!! Можно изменить

						if (entities[j]->GetName() == L"Bomber")
						{
							entities[i]->damage(100);
							entities[j]->SetHealth(0);
						}

						if (entities[j]->GetName() == L"MiniBoss")
						{
							entities[i]->damage(100);
							entities[j]->damage(70);
						}
						if (entities[j]->GetName()->find(L"Boss") != std::wstring::npos)
						{
							entities[i]->damage(300);
						}

//C# TO C++ CONVERTER TODO TASK: A 'delete e' statement was not added since e was passed to a method or constructor. Handle memory management manually.
//C# TO C++ CONVERTER TODO TASK: A 'delete AnimationExplosive1' statement was not added since AnimationExplosive1 was passed to a method or constructor. Handle memory management manually.
					}
				}
				//Поднятие бонуса
				if (entities[i]->GetName() == L"PlayerShip" && (entities[j]->GetName() == L"B_Health"))
				{
					if (IsCollide(entities[i]->sprite, entities[j]->sprite))
					{
						if (entities[j]->GetName() == L"B_Health")
						{
							entities[i]->SetHealth(100); //max HP ????????
						}

						entities[j]->SetHealth(0);
					}
				}
			}
		}
	}

	bool Game::IsCollide(Sprite *first, Sprite *second)
	{
		Vector2f firstRect = Vector2f(first->getTextureRect.Width, first->getTextureRect.Width);
		firstRect.x *= first->Scale.X;
		firstRect.y *= first->Scale.Y;

		Vector2f secondRect = Vector2f(second->TextureRect.Width, second->TextureRect.Width);
		secondRect.X *= second->Scale.X;
		secondRect.Y *= second->Scale.Y;

		float r1 = (firstRect.X + firstRect.Y) / 4;
		float r2 = (secondRect.X + secondRect.Y) / 4;
		float xd = first->Position.X - second->Position.X;
		float yd = first->Position.Y - second->Position.Y;

		return (std::sqrt(xd * xd + yd * yd) <= r1 + r2);
	}

	void Game::CreateAsteroid(std::vector<Entity*> &entities, int count)
	{
		int b = rnd2->Next(1, 100);
		if (b == 1)
		{
			if (CountAsteroids != count)
			{
				Asteroid *a = new Asteroid();
				entities.push_back(a);

				CountAsteroids++;

//C# TO C++ CONVERTER TODO TASK: A 'delete a' statement was not added since a was passed to a method or constructor. Handle memory management manually.
			}
		}
	}

	void Game::Enemy(std::vector<Entity*> &entities, int count, Boss *boss)
	{
		int b = rnd->Next(1, 100);
		if (b == 1)
		{
			int Choose1, Choose2, a1, a2;
			Choose1 = rnd->Next(0, 2);

//====================================================================================================
//End of the allowed output for the Free Edition of C# to C++ Converter.

//To subscribe to the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-csharp-to-cplus.html
//====================================================================================================