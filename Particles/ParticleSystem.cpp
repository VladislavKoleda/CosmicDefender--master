#include "ParticleSystem.h"
#include "Particle.h"

using namespace SFML::Graphics;
using namespace SFML::System;

namespace ComicDefender
{

const std::wstring ParticleSystem::CONTENT_DIRICTORY = L"..\\Content\\Textures\\";

	ParticleSystem::ParticleSystem(unsigned int count)
	{
		_count = static_cast<int>(count);
		m_particles = std::vector<Particle*>(static_cast<int>(count));
		m_vertices = new VertexArray(PrimitiveType::Points);
		for (int i = 0; i < count; i++)
		{
			float Angle = R->Next(1, 360);
			// float _speed = R.Next(0, 1000);
			float _speed = R->Next(1, 20) / 100.0f;
			float deltaX = static_cast<float>(std::cos(M_PI * (Angle - 90) / 180.0f)) * _speed;
			float deltaY = static_cast<float>(std::sin(M_PI * (Angle - 90) / 180.0f)) * _speed;
			float X = R->Next(1, 1280);
			float Y = R->Next(1, 720);
			float Q = ((R->Next(1, 4)) / 10.0f);
			int flag = R->Next(0, 1);
			Particle tempVar(Angle, _speed, deltaX, deltaY, X, Y, Q, flag);
			m_particles.push_back(&tempVar);
			m_vertices->Append(Vertex(Vector2f(X, Y), Color::White));
		}
	}

	void ParticleSystem::Draw(RenderTarget *target, RenderStates states)
	{
		states.Texture = nullptr;
		states.Transform *= getTransform();
		target->Draw(m_vertices, states);
	}

	void ParticleSystem::Update()
	{
		for (int i = 0; i != m_particles.size()(); i++)
		{

			auto temp = m_vertices[static_cast<unsigned int>(i)];

			m_particles[i]->X += m_particles[i]->DX;
			m_particles[i]->Y += m_particles[i]->DY;


			temp.Position = Vector2f(m_particles[i]->X, m_particles[i]->Y);

			if (m_particles[i]->q < 0.4 && m_particles[i]->flag == 1)
			{
				m_particles[i]->q += 0.001f;
				m_particles[i]->flag = 1;
			}
			else
			{
				m_particles[i]->flag = 0;
			}
			if (m_particles[i]->q > 0.1 && m_particles[i]->flag == 0)
			{
				m_particles[i]->q -= 0.001f;
			}
			else
			{
				m_particles[i]->flag = 1;
			}

			temp.Color.A = static_cast<unsigned char>(m_particles[i]->q * 255);
			m_vertices[static_cast<unsigned int>(i)] = temp;

		}
	}
}
