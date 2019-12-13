#pragma once

#include "../Level.h"
#include <string>
#include <vector>

//C# TO C++ CONVERTER NOTE: Forward class declarations:
namespace ComicDefender { class MenuRectShips; }
namespace ComicDefender { class MenuRectButtons; }
namespace ComicDefender { class MenuRectMainShip; }

using namespace SFML::Graphics;
using namespace SFML::System;
using namespace SFML::Window;

namespace ComicDefender
{
	class Menu : public Level
	{
		// View view = new View(new FloatRect(0, 0, 1280, 720));
	private:
		Color CopyColor;
	public:
		std::vector<MenuRectShips*> RectShips = std::vector<MenuRectShips*>();
		std::vector<MenuRectShips*> RectLevels = std::vector<MenuRectShips*>();
		std::vector<MenuRectButtons*> RectButtons = std::vector<MenuRectButtons*>();

		MenuRectMainShip *MainShip;
	private:
		int listShips = 0;
		int listLevels = 0;
	public:
		std::wstring CurrentLevel = L"Level1";

		virtual ~Menu()
		{
			delete MainShip;
		}

		Menu();

		void Load();

		void Update();


		bool Contains(Sprite *sprite, int x, int y);
		bool Contains(IntRect this1, int x, int y, Sprite *sprite);



	};
}
