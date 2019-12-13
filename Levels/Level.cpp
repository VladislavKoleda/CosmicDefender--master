#include "Level.h"
#include "../Entities/Boss.h"

using namespace SFML::Graphics;

namespace ComicDefender
{

	Level::Level()
	{

	}

	Level::Level(Sprite *_Background, Boss *_boss, const std::wstring &_Name)
	{
		Background = _Background;
		LevelBoss = _boss;
		Name = _Name;
	}

	void Level::Settings(Sprite *_Background, Boss *_boss)
	{
		Background = _Background;
		LevelBoss = _boss;
	}
}
