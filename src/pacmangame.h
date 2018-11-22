#ifndef PACMANGAME_H
#define PACMANGAME_H

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <algorithm>
#include <QObject>

#include "Character.h"
#include "Wall.h"
#include "Food.h"
#include "Pacman.h"
#include "Ghost.h"

#include "gamewindow.h"
#include "square.h"
#include <string>

class PacmanGame : public QObject {
    Q_OBJECT
public:
    PacmanGame();
    ~PacmanGame();
    void startGraphicUI();
    GameWindow* get_game_window() const;

private:
    GameWindow* game_window;
    Character* board[31][28];
    Pacman* pacman;
    Ghost* ghost1;
    Ghost* ghost2;
    Ghost* ghost3;
    Ghost* ghost4;
    int high_score;
    int lives;
    int level;

    void load_map();
    void load_high_score();
    void refresh_frame();

    bool game_over();
    bool is_level_finished();
    bool exists_ghost_in_box();

    void update_score();
    void update_map();
    void back_to_starting_pos();

private slots:
    void process_user_input();
};

#endif // PACMANGAME_H
