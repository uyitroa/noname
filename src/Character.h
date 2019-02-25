//
// Created by yuitora . on 25/02/2019.
//

#ifndef NONAME_CHARACTER_H
#define NONAME_CHARACTER_H

#include <iostream>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro.h>

class Character {
private:
	int x;
	int y;
	ALLEGRO_BITMAP *player;
public:
	Character(std::string file_bitmao, int x_default, int y_default);
	void move(int x_pixels, int y_pixels);
	void render();
};


#endif //NONAME_CHARACTER_H
