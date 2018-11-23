#include "Pacman.h"

Pacman::Pacman(int row, int col, Character* (*board)[31][28]) :
	Character(row, col, board),
	superpower(-1),
	direction(0),
	has_eaten_piece(false)
{}

int Pacman::get_superpower() {
	return superpower;
}

int Pacman::get_direction() {
	return direction;
}

char Pacman::getImage() const {
    return IMAGE_PACMAN;
}


void Pacman::update_superpower(bool sup) {
	superpower = sup;
}

void Pacman::update_direction(int dir) {
	direction = dir;
}

void Pacman::eats_piece(bool eat) {
	has_eaten_piece = eat;
}

void Pacman::move(int row, int col) {
    if (row < 0 || col < 0 || row >= 31 || col >= 28) return;
    if ((*board)[row][col] -> getImage() == 'W') return;
    else {
        delete ((*board)[row][col]);
        ((*board)[row][col]) = this;
        this->row = row; this->col = col;
    }
}

