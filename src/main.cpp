#include <stdafx.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <iostream>
// using namespace std;  don't use namespace std

const int WIDTH = 800;
const int HEIGHT = 600;

int main()
{
  al_init();
  if(!al_init())
  {
    cout << "failed to initialize allegro";
    return -1;
  }

  ALLEGRO_DISPLAY *display = al_create_display(WIDTH, HEIGHT);
  if(!display)
  {
    cout << "Failed to display the display";
    return -1;
  }

  while (true)
  {
    //Almost done dling cya there
  }

  al_destroy_display(display);
  return 0;
}
