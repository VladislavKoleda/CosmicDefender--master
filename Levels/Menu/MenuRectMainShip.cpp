#include "MenuRectMainShip.h"
#include "../../Program.h"

using namespace SFML::Graphics;

namespace ComicDefender
{

	MenuRectMainShip::MenuRectMainShip()
	{
		SpriteShip = Program::content->GetShip1();
		SpriteShip->Position = SFML::System::Vector2f(640, 360);
	}
}
