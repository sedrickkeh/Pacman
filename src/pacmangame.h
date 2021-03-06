#ifndef PACMANGAME_H
#define PACMANGAME_H

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <algorithm>
#include <QObject>

#include "Character.h"
#include "wall.h"
#include "food.h"
#include "pacman.h"
#include "ghost.h"
#include "direction.h"

#include "gamewindow.h"
#include "square.h"
#include <string>
#include <QTimer>

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
    void init_block(int row, int col, char c);
    void load_high_score();

    bool game_over();
    bool is_level_finished();
    bool exists_ghost_in_box();

    void move_pacman(int r, int c);
    void move_ghost(int r, int c, Ghost* g);
    void update_score();
    void update_map();
    void back_to_starting_pos();

    QTimer *timer;


private slots:
    void process_user_input();
    void refresh_frame();

};

#endif // PACMANGAME_H
