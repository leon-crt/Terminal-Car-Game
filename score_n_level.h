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
#ifndef score_n_level_h
#define score_n_level_h
class score_n_level
{
protected:
	int nscore; // int dove viene registrato il punteggio
	int nlevel; // int dove viene registrato il livello
	int damage; // quantità di punti sottratti al giocatore ogni volta che colpisce un ostacolo, aumenta in modo proporzionale al livello ma non diminuisce con esso per mantenere un grado di sfida abbastanza alto da tenere il giocatore impegnato
	char score[13] = { "SCORE 000000" }; // stringa che va inserita nel buffer
	char level[13] = { "LEVEL 000000" };
	bool level_up;
	bool level_down;
	int speed_reg; // numero che regola la velocità del gioco.

public:
	score_n_level();

	void translate();
	// Dato che l'array che costituisce il buffer è di tipo char ogni numero che gli diciamo di scrivere viene interpretato come 
	// un simbolo della tabella ASCII quindi ogni numero va tradotto sommandogli 48 (a 48 sulla tabella ASCII corrisponde lo 0)
	
	void display_score(CHAR_INFO buffer[]);
	// inserisce le stringhe score e level sullo schermo

	void score_inc(int x);
	// incrementa il punteggio di una quantità x 

	void score_dec();
	// decrementa il punteggio di un numero pari al campo int "damage"

	void score_dec(int x);
	// decrementa il punteggio di una quantità x

	void reset();
	// resetta il punteggio in caso di gameover

	int git_gud();
	// ogni volta che si sale di livello aumenta damage e decrementa speed_reg e lo restituisce. Questa funzione è inserita come parametro
	// nella funzione Sleep() all'inizio del game loop nel main

	int gimme_nscore();

	int gimme_nlevel();
};

#endif
