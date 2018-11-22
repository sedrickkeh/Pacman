#include "ghost.h"

Ghost::Ghost(int row, int col, Character* (*board)[31][28], int timebox) :
	Charcter(row, col, board),
	points(200),
	time_in_box(timebox),
	is_eaten(false)
{}

int Ghost::get_time_in_box() {
	return time_in_box;
}

char Ghost::getImage() const {
    return IMAGE_GHOST;
}

Ghost::eaten(bool eat) {
	is_eaten = eat;
}

Ghost::set_color(bool eaten) {

}

Ghost::update_points() {

}

Ghost::move(int row, int col) {

}