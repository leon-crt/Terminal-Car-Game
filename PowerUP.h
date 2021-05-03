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
#include "car.h"
#include "score_n_level.h"
#ifndef PowerUP_h
#define PowerUP_h
class PowerUP : public gameobject
{
protected:
	void explode(bool& pop);
	
	void resetPU(bool& pop, int random_place);
	
	bool collision_detection(car CAR);

public:
	PowerUP(int px, int py);
	PowerUP();
	void logic(int random_place, car CAR, score_n_level& score, bool& pop, bool& go, CHAR_INFO buffer[]);
	// inserisce il bonus nel buffer, lo sposta, se ha raggiunto il fondo dello schermo lo riporta sul bordo superiore
	// e controlla se ci sono collisioni con la macchina del giocatore, se sì allora lo fa "scomparire" e aumenta il punteggio del 
	// giocatore

};

#endif