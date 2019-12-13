#pragma once

#include "MenuRectShips.h"
#include <string>

using namespace SFML::Graphics;
using namespace SFML::System;

namespace ComicDefender
{
	class MenuRectLevels : public MenuRectShips
	{
	public:
		Sprite *Background;

		virtual ~MenuRectLevels()
		{
			delete Background;
		}

		MenuRectLevels(Sprite *_SpriteRect, const std::wstring &_Name, Vector2f _Position);

		MenuRectLevels(Sprite *_SpriteRect, const std::wstring &_Name, Vector2f _Position, Sprite *_Background);

	};
}
