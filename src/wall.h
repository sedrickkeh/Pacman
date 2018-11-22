#ifndef WALL_H
#define WALL_H

#include "character.h"

class Wall : public Character
{
public:
    const static char IMAGE_WALL = 'W';
    virtual char getImage() const override;
};

#endif // WALL_H
