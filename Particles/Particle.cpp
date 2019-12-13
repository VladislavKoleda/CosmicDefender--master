#include "Particle.h"

using namespace SFML::System;

namespace ComicDefender
{

	Particle::Particle(float angle, float speed, float dx, float dy, float x, float y, float Q, int Flag)
	{
		Angle = angle;
		Speed = speed;
		DX = dx;
		DY = dy;
		X = x;
		Y = y;
		q = Q;
		flag = Flag;
	}
}
