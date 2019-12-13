#pragma once

#include <string>

//C# TO C++ CONVERTER NOTE: Forward class declarations:
namespace ComicDefender { class Boss; }

using namespace SFML::Graphics;

namespace ComicDefender
{
	class Level
	{
	public:
		Sprite *Background;
		std::wstring Name;
		Boss *LevelBoss;

		bool IsOpen = false;

		virtual ~Level()
		{
			delete Background;
			delete LevelBoss;
		}

		Level();

		Level(Sprite *_Background, Boss *_boss, const std::wstring &_Name);

		void Settings(Sprite *_Background, Boss *_boss);

	};
}
