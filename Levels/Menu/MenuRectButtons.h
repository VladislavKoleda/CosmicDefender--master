#pragma once

#include <string>

using namespace SFML::Graphics;
using namespace SFML::System;

namespace ComicDefender
{
	class MenuRectButtons
	{
	public:
		Sprite *SpriteRect;
		std::wstring Name;

		virtual ~MenuRectButtons()
		{
			delete SpriteRect;
		}

		MenuRectButtons(Sprite *_SpriteRect, const std::wstring &_Name, Vector2f _Position);
	};
}
