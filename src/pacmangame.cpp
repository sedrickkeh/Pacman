#include "pacmangame.h"
#include <QTimer>
#include <iostream>
using namespace std;

PacmanGame::PacmanGame() :
    pacman(nullptr),
    ghost1(nullptr),
    ghost2(nullptr),
    ghost3(nullptr),
    ghost4(nullptr)
{
    game_window = new GameWindow(nullptr, this);
    for (int k = 0; k < 31; k ++) for (int l = 0; l < 28; l ++) board[k][l] = nullptr;
    load_map();
    update_map();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(refresh_frame()));
    timer -> start(100);
}

PacmanGame::~PacmanGame(){}

void PacmanGame::load_map() {
    QFile file(":/resources/maps/pacman_map.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;
    int rownum = 30;
    while (!file.atEnd()) {
        QString line = file.readLine();
        for (int k = 0; k < line.size()-1; k ++) {
            if (line[k] == 'W') board[rownum][k] = new Wall(rownum, k, &board);
            else if (line[k] == 'P') {
                pacman = new Pacman(rownum, k, &board);
                board[rownum][k] = pacman;
            }
            else if (line[k] == 'G') {
                if (ghost1 == nullptr) {
                    ghost1 = new Ghost(rownum, k, &board, 2);
                    board[rownum][k] = ghost1;
                }
                else if (ghost2 == nullptr) {
                    ghost2 = new Ghost(rownum, k, &board, 4);
                    board[rownum][k] = ghost2;
                }
                else if (ghost3 == nullptr) {
                    ghost3 = new Ghost(rownum, k, &board, 6);
                    board[rownum][k] = ghost3;
                }
                else if (ghost4 == nullptr) {
                    ghost4 = new Ghost(rownum, k, &board, 8);
                    board[rownum][k] = ghost4;
                }
            }
            else if (line[k] == 'F') board[rownum][k] = new Food(rownum, k, &board);
        }
        rownum--;
    }
}

void PacmanGame::init_block(int row, int col, char c) {
    game_window->set_square(row, col, c);
}

void PacmanGame::startGraphicUI() {
    game_window->show();
}

void PacmanGame::refresh_frame() {
    std::cout << "kdasfjl" << std::endl;
    move_pacman();
    update_map();
}

void PacmanGame::move_pacman() {
    int dir = pacman->get_direction();
    int row = pacman->getRow();
    int col = pacman->getCol();
    if (dir == 0) pacman->move(row-1, col);
    else if (dir == 1) pacman->move(row+1, col);
    else if (dir == 2) pacman->move(row, col-1);
    else if (dir == 3) pacman->move(row, col+1);
}

void PacmanGame::update_map() {
    for (int k = 0; k < 31; k ++)
        for (int l = 0; l < 28; l ++) {
            if (board[k][l] != nullptr) init_block(k, l, board[k][l]->getImage());
            else init_block(k, l, 'S');
        }
}

GameWindow* PacmanGame::get_game_window() const {return game_window;}

void PacmanGame::process_user_input() {}
