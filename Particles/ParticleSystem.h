#pragma once

#define _USE_MATH_DEFINES
#include <string>
#include <vector>
#include <cmath>

//C# TO C++ CONVERTER NOTE: Forward class declarations:
namespace ComicDefender { class Particle; }

using namespace SFML::Graphics;
using namespace SFML::System;

namespace ComicDefender
{
	class ParticleSystem : public Transformable, public Drawable
	{
	protected:
		static const std::wstring CONTENT_DIRICTORY;
	public:
		VertexArray *m_vertices;
		std::vector<Particle*> m_particles;
		int _count = 0;
		Random *R = new Random();
		virtual ~ParticleSystem()
		{
			delete m_vertices;
			delete R;
		}

		ParticleSystem(unsigned int count);
		void Draw(RenderTarget *target, RenderStates states) override;

		void Update();
	};

}
