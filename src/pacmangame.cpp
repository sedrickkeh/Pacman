#include "pacmangame.h"


PacmanGame::PacmanGame()
{
    game_window = new GameWindow(nullptr, this);
}

PacmanGame::~PacmanGame(){}

void PacmanGame::startGraphicUI() {
    game_window->show();
}

GameWindow* PacmanGame::get_game_window() const {return game_window;}

void PacmanGame::process_user_input() {}
