#pragma once

namespace ComicDefender
{
	class Rand
	{
	public:
		Random *rnd = new Random();
		virtual ~Rand()
		{
			delete rnd;
		}

	};
}
