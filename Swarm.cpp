#include "Swarm.h"
#include <iostream>
namespace particles {

	Swarm::Swarm() {

		m_Particle = new Particle[MAX_PARTICLES];
		m_lastTime = 0;

	}


	Swarm::~Swarm() {
		delete[] m_Particle;
	}

	void Swarm::UpdateSwarm(int elapsed) {

		int interval = elapsed - m_lastTime;

		std::cout << interval << std::endl;

		for (int i = 0; i < MAX_PARTICLES; ++i) {
			m_Particle[i].UpdateParticle(interval);
		}

		m_lastTime = elapsed;

	}



}