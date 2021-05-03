#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <ctime>
#define WIDTH 80
#define ROAD_W 56
#define HEIGHT 35
#define BLACK 0
#define WHITE 255|255|255
#define WHITE_TEXT FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY
#define RED BACKGROUND_RED
#define YELLOW 110 | 110 | 110 
using namespace std;
#ifndef gameobject_h
#define gameobject_h

class gameobject 
{
	protected:
		int posx;
		int posy;
		char shape[10];
		WORD color;

	public:
		void draw_object(CHAR_INFO buffer[], int a, int b);

		void move_object(bool UP, bool DOWN, bool LEFT, bool RIGHT);

		bool collision_detection(gameobject obst, int w, int h);

		int gimme_posy();
		
		int gimme_posx();
};

#endif

