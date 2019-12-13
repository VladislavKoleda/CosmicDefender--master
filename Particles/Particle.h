#pragma once

using namespace SFML::System;

namespace ComicDefender
{
	class Particle
	{
	public:
		float DY = 0, DX = 0, X = 0, Y = 0, Speed = 0, Angle = 0;
		float q = 0;
		int flag = 0;
		Particle(float angle, float speed, float dx, float dy, float x, float y, float Q, int Flag);
	};
}
