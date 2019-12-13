#include "MenuRectLevels.h"

using namespace SFML::Graphics;
using namespace SFML::System;

namespace ComicDefender
{

	MenuRectLevels::MenuRectLevels(Sprite *_SpriteRect, const std::wstring &_Name, Vector2f _Position)
	{
		SpriteRect = _SpriteRect;
		Name = _Name;
		SpriteRect->Position = _Position;
	}

	MenuRectLevels::MenuRectLevels(Sprite *_SpriteRect, const std::wstring &_Name, Vector2f _Position, Sprite *_Background)
	{
		SpriteRect = _SpriteRect;
		Name = _Name;
		SpriteRect->Position = _Position;
		Background = _Background;
	}
}
