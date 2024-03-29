﻿#include "Constants.h"
#include "../Entities/Ship.h"
#include "../Animation/Animation.h"
#include "../Entities/Boss.h"
#include "../Program.h"

using namespace SFML::Graphics;
using namespace SFML::System;

namespace ComicDefender
{

	Constants::Constants()
	{
		AnimationBoss1 = new Animation(Program::content->GetBoss1(), 0, 0, 338, 338, 3, 0.02f);
		Boss1 = new Boss(Program::content->GetBoss1(), AnimationBoss1, 0, 0, 0, 0.3f, 0, 10000, 0, L"Boss1");
		Boss2 = new Boss(Program::content->GetBoss2(), 0, 0, 0, 0.3f, 0, 10000, 0, L"Boss2");
		Boss3 = new Boss(Program::content->GetBoss3(), 0, 0, 0, 0.3f, 0, 10000, 0, L"Boss3");


		Ship1 = new Ship(Program::content->GetShip1(), X, Y, 25, 1.5f, .2f, 100, 1);
		Ship2 = new Ship(Program::content->GetShip2(), X, Y, 15, 1.2f, .4f, 100, 2);
		Ship3 = new Ship(Program::content->GetShip3(), X, Y, 40, 1.2f, .15f, 140, 1);
		Ship4 = new Ship(Program::content->GetShip4(), X, Y, 45, 1.4f, .18f, 150, 1);
		Ship5 = new Ship(Program::content->GetShip5(), X, Y, 30, 2.0f, .25f, 110, 1);
		Ship6 = new Ship(Program::content->GetShip6(), X, Y, 25, 2.2f, .5f, 90, 1);
		Ship7 = new Ship(Program::content->GetShip7(), X, Y, 30, 1.1f, .2f, 200, 2);
		Ship8 = new Ship(Program::content->GetShip8(), X, Y, 35, 1.3f, .24f, 310, 2);
		Ship9 = new Ship(Program::content->GetShip9(), X, Y, 40, 2.0f, .3f, 400, 2);

	}
}
