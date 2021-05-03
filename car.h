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
#include "bullet.h"
#ifndef car_h
#define car_h

class car : public gameobject
{
protected:
	char shape[4 * 4] = { "*||*(  )____" };

	void explode(bool& bang);
	// viene chiamata quando una macchina ostacolo viene colpita e la fa "scomparire" cambiandone il colore e 
	// la forma (la stringa shape viene cambiata in tutti spazi per renderla indistinguibile e rendendo il booleano  
	// bang true per non farla più considerare da collision_detection

	void reset_car(int random_num, int random_col, bool& bang);
	// viene chiamata quando la macchina ostacolo raggiunge il fondo dello schermo, la riporta nel bordo superiore cambiandone il colore 
	// e la posizione sull'asse delle x facendola sembrare un ostacolo nuovo. Reimposta il campo shape a quello originale nel caso fosse
	// stata chiamata la funzione explode prima.

	bool collision_detection(car obst);
	// ritorna true se l'oggetto ha almeno una coordinata in comune con il parametro obst di tipo car

	bool collision_detection(bullet bill);
	// ritorna true se l'oggetto ha almeno una coordinata in comune con il parametro bill di tipo bullet

public:
	car(int px, int py, WORD col);

	void draw_object(CHAR_INFO buffer[]);

	void color_change(WORD col, bullet bill);
	// cambia il colore se il bonus proiettile è attivo

	void logic(int random_place, int random_col, car CAR, score_n_level& score, bool& bang, CHAR_INFO buffer[], bullet& bill);
	// inserisce la macchina ostacolo nel buffer, la sposta, se ha raggiunto il fondo dello schermo la riporta sul bordo superiore,
	// controlla se ci sono collisioni con la macchina del giocatore, se sì allora la fa "scomparire" e diminuisce il punteggio del 
	// giocatore e infine controlla se ci sono collisioni con il proiettile, se sì la fa "scomparire" e aumenta il punteggio del giocatore

};

#endif