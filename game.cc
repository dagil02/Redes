#include "game.h"

Game::Game(): m_left_paddle(Paddle::Type::LEFT, 0, (400 / 2) - 50), m_right_paddle(Paddle::Type::RIGHT, 400 - 25, (400 / 2) - 50)
{
    SDL_CreateWindowAndRenderer(680, 480, SDL_WINDOW_RESIZABLE, &m_game_window, &m_game_window_renderer);

    SDL_RenderSetLogicalSize(m_game_window_renderer, 400, 400);
	
	m_ball.init(m_game_window_renderer, (400 / 2) - 12, (400 / 2) - 12);
}

void Game::run()
{
    bool keep_running = true;
    while(keep_running)
    {
		while(SDL_PollEvent(&m_game_window_event) > 0)
		{
			switch(m_game_window_event.type)
			{
			case SDL_QUIT:
				keep_running = false;
			}

			m_left_paddle.handle_input(m_game_window_event);
			m_right_paddle.handle_input(m_game_window_event);
		}

		update(1.0/60.0);
		render();
    }
}

void Game::update(double delta_time)
{
	m_left_paddle.update(delta_time);
	m_right_paddle.update(delta_time);
	m_ball.update(delta_time);
}

void Game::render()
{
    SDL_RenderClear(m_game_window_renderer);

	m_left_paddle.render(m_game_window_renderer);
	m_right_paddle.render(m_game_window_renderer);
	m_ball.render(m_game_window_renderer);
	
    SDL_RenderPresent(m_game_window_renderer);
}


