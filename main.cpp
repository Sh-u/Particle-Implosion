#define SDL_MAIN_HANDLED

#include <iostream>
#include <SDL.h>
#include <memory>
#include "Screen.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Particle.h"
#include "Swarm.h"
using namespace particles;


int main() {
	SDL_SetMainReady();

	srand(time(nullptr));

	Screen screen;

	Swarm swarm;



	if (!screen.Init()) {
		std::cout << "Init failed" << std::endl;
		return 1;
	}


	const int HALF_WIDTH = Screen::SCREEN_WIDTH / 2;
	const int HALF_HEIGHT = Screen::SCREEN_HEIGHT / 2;

	while (true) {

		swarm.UpdateSwarm(SDL_GetTicks());

		double red = (1 + sin(SDL_GetTicks() * 0.0001)) * 128;
		double green = (1 + sin(SDL_GetTicks() * 0.001)) * 128;
		double blue = (1 + sin(SDL_GetTicks() * 0.001)) * 128;

		if (red > 255) { red = 255; }
		if (green > 255) { green = 255; }
		if (blue > 255) { blue = 255; }


		const Particle* const pParticles = swarm.getParticle();

		for (int i = 0; i < swarm.MAX_PARTICLES; i++) {
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * HALF_WIDTH;
			int y = particle.m_y * HALF_WIDTH + HALF_HEIGHT;


			screen.SetPixel(x, y, red, green, blue);

		}

		screen.BoxBlur();

		screen.Update();

		if (!screen.ProcessEvents()) {
			break;
		}



	}

	screen.Close();

	return 0;

}

