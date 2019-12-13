#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


using namespace sf;

//C# TO C++ CONVERTER NOTE: Forward class declarations:
namespace ComicDefender { class Animation; }


namespace ComicDefender
{
	class Asteroid : public Entity
	{
	private:
		Animation *animAsteroid;
		Random *rdn = new Random(DateTime::Now.Millisecond);

	public:
		virtual ~Asteroid()
		{
			delete animAsteroid;
			delete rdn;
		}

		Asteroid();


		void Update(float time) override;
		void Draw() override;
	};
}
