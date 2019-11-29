#include <iostream>
#include <SDL2/SDL.h>
#include "player.h"


Player::Player() {
    x = 250;
    y = 250;
    x_vel = 0;
    y_vel = 0;
    width = 100;
    height = 100;

    color[0] = 255;
    color[1] = 255;
    color[2] = 255;

    moving_up = false;
    moving_down = false;
    moving_left = false;
    moving_right = false;
}

void Player::up() {
    moving_up = true;
}

void Player::down() {
    moving_down = true;
}

void Player::left() {
    moving_left = true;
}

void Player::right() {
    moving_right = true;
}

void Player::calculate_input() {
    if (moving_right && moving_left) {
        moving_right = false;
        moving_left = false;
    }
    if (moving_right) {
        x_vel += 2;
    } else if (moving_left) {
        x_vel -= 2;
    }
    if (moving_down) {
        y_vel += 1;
    }
    if (moving_up) {
        y_vel -= 1;
    }
}

void Player::move() {
    x += x_vel;
    y += y_vel;
}

void Player::reset_variables() {
    moving_right = false;
    moving_left = false;
    moving_up = false;
    moving_down = false;
}

SDL_Rect Player::get_rect() {
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = width;
    r.h = height;
    return r;
}

void Player::draw(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], 255);

    SDL_Rect rect = get_rect();
    SDL_RenderFillRect(renderer, &rect);

}