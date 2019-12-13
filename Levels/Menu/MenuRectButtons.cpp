#include "MenuRectButtons.h"

using namespace SFML::Graphics;
using namespace SFML::System;

namespace ComicDefender
{

	MenuRectButtons::MenuRectButtons(Sprite *_SpriteRect, const std::wstring &_Name, Vector2f _Position)
	{
		SpriteRect = _SpriteRect;
		Name = _Name;
		SpriteRect->Position = _Position;
	}
}
