#pragma once

namespace particles {


	struct Particle {

		double m_x;
		double m_y;
		double m_speed;
		double m_direction;


		Particle();
		~Particle();


		void UpdateParticle(int interval);

	};

}