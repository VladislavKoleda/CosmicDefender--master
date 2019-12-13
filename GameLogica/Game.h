#pragma once

#include "Rand.h"
#include <string>
#include <vector>
#include <cmath>

//C# TO C++ CONVERTER NOTE: Forward class declarations:
namespace ComicDefender { class Entity; }
namespace ComicDefender { class Ship; }
namespace ComicDefender { class Boss; }

using namespace SFML::Graphics;
using namespace SFML::System;
using namespace SFML::Window;

namespace ComicDefender
{
	class Game : public Rand
	{
	private:
		static int CountAsteroids;
		static int CountEnemies;
		static bool isBoss;
		Clock *bullet_clock = new Clock();
		Clock *clock = new Clock();
		//private float bullet_cooldown;
		Random *rnd2 = new Random();

	public:
		virtual ~Game()
		{
			delete bullet_clock;
			delete clock;
			delete rnd2;
		}

		void Update(Ship *ship, std::vector<Entity*> &entities);

	private:
		static bool IsCollide(Sprite *first, Sprite *second);

//		#region Create Objects

//		#region Asteroids

	public:
		void CreateAsteroid(std::vector<Entity*> &entities, int count);

//		#endregion

//		#region Enemies

		void Enemy(std::vector<Entity*> &entities, int count, Boss *boss);

//		#endregion

//		#endregion

		int GetCountEnemies();

	};

}
