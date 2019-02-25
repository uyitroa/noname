#include "stdafx.h"
#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include  <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include <iostream>
using namespace std;

#define width 840
#define height 680

int main()
{
	al_init();
	if (!al_init())
	{
		cout << "Failed to initialize Allegro";
		return -1;
	}
	ALLEGRO_DISPLAY *myDisplay = al_create_display(width, height);
	if (!myDisplay)
	{
		cout << "Failed to display your window";
	}

	//Variables
	enum direction { LEFT, RIGHT, UP, DOWN };
	bool finish = false, draw = true, active = false;
	int directions = DOWN;
	float X = 10, Y = 10, speed = 5, sX = 90, sY = 0, monsX = 64, monsY = 0;
	float FPS = 30;

	//Install
	al_init_primitives_addon();
	al_install_keyboard();
	al_init_image_addon();

	//Events and Queues
	ALLEGRO_KEYBOARD_STATE keyboardstate;
	ALLEGRO_BITMAP *player = al_load_bitmap("player.png");
	ALLEGRO_BITMAP *monster = al_load_bitmap("monster.png");

	ALLEGRO_EVENT_QUEUE *myqueue = al_create_event_queue();
	ALLEGRO_TIMER *mytimer = al_create_timer(1 / FPS);
	al_register_event_source(myqueue, al_get_keyboard_event_source());
	al_register_event_source(myqueue, al_get_timer_event_source(mytimer));
	al_register_event_source(myqueue, al_get_display_event_source(myDisplay));

	al_start_timer(mytimer);

	while (!finish)
	{
		ALLEGRO_EVENT curEvents;
		al_wait_for_event(myqueue, &curEvents);
		al_get_keyboard_state(&keyboardstate);
		if (curEvents.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			finish = true;
		else if (curEvents.type == ALLEGRO_EVENT_TIMER)
		{
			active = true;
			if (al_key_down(&keyboardstate, ALLEGRO_KEY_ESCAPE))
				finish = true;
			if (al_key_down(&keyboardstate, ALLEGRO_KEY_DOWN))
			{
				Y += speed;
				directions = DOWN;
			}
			else if (al_key_down(&keyboardstate, ALLEGRO_KEY_LEFT))
			{
				X -= speed;
				directions = LEFT;
			}
			else if (al_key_down(&keyboardstate, ALLEGRO_KEY_RIGHT))
			{
				X += speed;
				directions = RIGHT;
			}
			else if (al_key_down(&keyboardstate, ALLEGRO_KEY_UP))
			{
				Y -= speed;
				directions = UP;
			}
			else
				active = false;
			if (active)
				sX += al_get_bitmap_width(player) / 5;
			else
				sX = 18; // 90
			if (sX >= al_get_bitmap_width(player))
				sX = 0;
			sY = directions;
			draw = true;

		}
		if (draw)
		{
			draw = false;
			al_draw_bitmap_region(player, sX, sY * al_get_bitmap_height(player) / 4, 90, 90, X, Y, NULL);

			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}
	}
	al_destroy_display(myDisplay);
	al_destroy_timer(mytimer);
	al_destroy_event_queue(myqueue);
	al_destroy_bitmap(player);
	return 0;
}