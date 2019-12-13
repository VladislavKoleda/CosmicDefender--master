#pragma once

#include <string>
#include <vector>
#include <any>

//C# TO C++ CONVERTER NOTE: Forward class declarations:
namespace ComicDefender { class Entity; }
namespace ComicDefender { class Content2; }
namespace ComicDefender { class Ship; }
namespace ComicDefender { class Menu; }
namespace ComicDefender { class Level; }
namespace ComicDefender { class Game; }
namespace ComicDefender { class Constants; }

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
using namespace sf;


namespace ComicDefender
{
	class Program
	{

//		#region Vars and Consts
	public:
		static constexpr int WindowWidth = 1280;
		static constexpr int WindowHeight = 720;
		static RenderWindow *Window;
		static std::vector<Entity*> entities;
		static Content2 *content;
		static Ship *Ship;
		static Menu *menu;
		static std::vector<Level*> levels;
	   // public static Level level;
	private:
		static Game *Logic;
	public:
		static Constants *Constants;
//		#endregion

		static void Main(std::vector<std::wstring> &args);


	private:
		static void Win_Resized(std::any sender, SizeEventArgs *e);

		static void Window_Closed(std::any sender, EventArgs *e);


	};
}
