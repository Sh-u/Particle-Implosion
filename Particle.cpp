#define _USE_MATH_DEFINES

#include "Particle.h"
#include <stdlib.h>
#include <math.h>

namespace particles {




	Particle::Particle() {
		m_x = 0;
		m_y = 0;

		m_direction = (2 * M_PI * rand()) / RAND_MAX;
		m_speed = (0.01 * rand()) / RAND_MAX;

		m_speed *= m_speed;

	}

	void Particle::UpdateParticle(int interval) {

		m_direction += interval * 0.0002;

		double xspeed = m_speed * cos(m_direction);
		double yspeed = m_speed * sin(m_direction);

		m_x += xspeed * interval;
		m_y += yspeed * interval;

	}

	Particle::~Particle() {

	}


}