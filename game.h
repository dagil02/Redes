#pragma once

#include <SDL2/SDL.h>
#include "ball.h"
#include "paddle.h"

class Game
{
public:
    Game();
    ~Game() = default;
    
    void run();
    void update(double delta_time);
    void render();

private:
    SDL_Window   *m_game_window;
    SDL_Event     m_game_window_event;
    SDL_Renderer *m_game_window_renderer;

    Ball          m_ball;
    Paddle        m_left_paddle;
    Paddle        m_right_paddle;
};
