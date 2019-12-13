#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
//C# TO C++ CONVERTER NOTE: Forward class declarations:

namespace ComicDefender { class Ship; }
namespace ComicDefender { class Animation; }
namespace ComicDefender { class Boss; }


namespace ComicDefender
{
	class Constants
	{
	private:
		static constexpr int X = 500;
		static constexpr int Y = 500;


	public:
		Ship *Ship1;
		Ship *Ship2;
		Ship *Ship3;
		Ship *Ship4;
		Ship *Ship5;
		Ship *Ship6;
		Ship *Ship7;
		Ship *Ship8;
		Ship *Ship9;


	private:
		Animation *AnimationBoss1;
	public:
		Boss *Boss1;
		Boss *Boss2;
		Boss *Boss3;
		Boss *Boss4;
		Boss *Boss5;
		Boss *Boss6;


		virtual ~Constants()
		{
			delete Ship1;
			delete Ship2;
			delete Ship3;
			delete Ship4;
			delete Ship5;
			delete Ship6;
			delete Ship7;
			delete Ship8;
			delete Ship9;
			delete AnimationBoss1;
			delete Boss1;
			delete Boss2;
			delete Boss3;
			delete Boss4;
			delete Boss5;
			delete Boss6;
		}

		Constants();
	};
}
