#pragma once
#include <SDL.h>
namespace particles {




	class Screen {
	private:

		SDL_Event m_event;
		SDL_Renderer* m_renderer;
		SDL_Window* m_window;
		SDL_Texture* m_texture;

		Uint32* m_buffer;
		Uint32* m_bufferUpdated;

	public:

		const static int SCREEN_WIDTH = 1024;
		const static int SCREEN_HEIGHT = 768;

	public:


		Screen();
		bool Init();
		bool ProcessEvents();
		void SetPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
		void Update();
		void BoxBlur();
		void Clear();
		void Close();


	};
}
