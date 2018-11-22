#ifndef GHOST_H
#define GHOST_H

#include "character.h"

class Ghost : public Character
{
public:
    Ghost(int row, int col, Character* (*board)[31][28]);
    const static char IMAGE_PACMAN = 'P';
    virtual char getImage() const override;
    int get_time_in_box();
    void eaten(bool eat);
    void set_color(bool eaten);
    void update_points();
    void move(int row, int col);

private:
    int points = 200;
    int time_in_box = 10;
    bool is_eaten = false;
};

#endif // PACMAN_H
