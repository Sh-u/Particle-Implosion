#pragma once
#include "Particle.h"


namespace particles {


	class Swarm {
	private:

		Particle* m_Particle;
		int m_lastTime;

	public:
		const static int MAX_PARTICLES = 5000;


	public:
		Swarm();
		~Swarm();
		const Particle* const getParticle() const { return m_Particle; }
		void UpdateSwarm(int elapsed);

	};


}
