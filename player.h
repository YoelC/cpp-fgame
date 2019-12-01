#include <iostream>
#include "physics_cube.h"

class Player: public PhysicsCube {
public:
    double x, y, width, height;
    double x_vel, y_vel;
    bool moving_left, moving_right, moving_up, moving_down;
    int color[3];
    Player();

    void up();
    void down();
    void left();
    void right();

    void calculate_input();

    void move();

    SDL_Rect get_rect();

    void draw(SDL_Renderer *renderer);

    void reset_variables();

    void apply_gravity();
};