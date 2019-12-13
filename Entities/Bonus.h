#pragma once

#include "Entity.h"
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
using namespace sf;

namespace ComicDefender
{
	class Bonus : public Entity
	{
	protected:
		int armour = 0;
		static Vector2f location;

	public:
		Bonus();

		Bonus(Sprite *_sprite, float _X, float _Y, const std::wstring &name);
		void Update(float time) override;

	};
}
