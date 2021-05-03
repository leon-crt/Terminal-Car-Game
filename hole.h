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
#include "gameobject.h"
#include "score_n_level.h"
#include "car.h"
#include "bullet.h"
#ifndef hole_h
#define hole_h

class hole :
	public gameobject
{
protected:
	void reset_hole(bool& pop, int random_place);
public:
	hole(int px, int py);
	void logic(int random_place, car CAR, score_n_level& score, bool& pop, bool& go, CHAR_INFO buffer[], bullet& bill);
};

#endif