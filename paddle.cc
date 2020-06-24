#include "paddle.h"

Paddle::Paddle(Type type, int x, int y)
{
    m_position.x = x;
    m_position.y = y;
    m_position.w = 25;
    m_position.h = 75;
    m_y = static_cast<double>(y);
    m_direction = Direction::NONE;
    m_type = type;
}

void Paddle::handle_input(SDL_Event const &event)
{
}

void Paddle::update(double delta_time)
{
    if(m_direction == Direction::UP)
    {
        if(m_y > 0)
        {
            m_y = m_y - 5.0 * delta_time;
            m_position.y = m_y;
        }
    }
    else if(m_direction == Direction::DOWN)
    {
        if(m_y + m_position.h < 400)
        {
            m_y = m_y + 5.0 * delta_time;
            m_position.y = m_y;
        }
    }
}

void Paddle::render(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &m_position);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}






