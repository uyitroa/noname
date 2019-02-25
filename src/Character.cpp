

#include "Character.h"

Character::Character(std::string file_bitmao, int x_default, int y_default) {
	x = x_default;
	y = y_default;
	player = al_load_bitmap("player.png");
}

void Character::move(int x_pixels, int y_pixels) {
	x += x_pixels;
	y += y_pixels;
	if (x_pixels > 0) { // DIRECTION =

	}
}

void Character::render() {

}

//
// Created by yuitora . on 25/02/2019.
//

#include "Character.h"
