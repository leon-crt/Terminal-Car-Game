#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <ctime>
#include "gameobject.h"
#include "PowerUP.h"
#include "B_powerUP.h"
#include "BufferStuff.h"
#include "score_n_level.h"
#include "car.h"
#include "hole.h"
#include "bullet.h"
#define WIDTH 80
#define ROAD_W 56
#define HEIGHT 35
#define BLACK 0
#define WHITE 255|255|255
#define WHITE_TEXT FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY
#define RED BACKGROUND_RED
#define YELLOW 110 | 110 | 110
using namespace std;

HANDLE whdl;
HANDLE rhdl;

int main() {
	srand(time(NULL));

	// CONSOLE SIZE, HANDLE AND INFO
	SMALL_RECT window_size = { 0, 0, WIDTH-1, HEIGHT-1 };
	whdl = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTitle(L"---RAGE RACER---");
	SetConsoleWindowInfo(whdl, TRUE, &window_size);
	COORD buffer_size = { WIDTH, HEIGHT };
	SetConsoleScreenBufferSize(whdl, buffer_size);
	
	BufferStuff screen;
	
	//PLAYER INFO
	int px, py; // posizione iniziale della macchina del giocatore
	px = ROAD_W / 2;
	py = 25;

	// CAR
	car CAR (px, py, RED); 

	/*
	*||*
	(  )
    ____
	*/	

	// ROAD LINES INITIALIZATION
	int loc = 28; // loc e loc2 sono le posizioni delle strisce bianche in mezzo alla strada
	int loc2 = loc + WIDTH * (HEIGHT / 2);

	// SPEED 
	int rpm = 1; //contatore per amministrare i tempi indipendentemente dal punteggio o dal livello
	int score_clock = 0; //contatore per il punteggio
	int obst_per_rounds = 10; //variabile utile per sfasare leggermente la comparizione degli ostacoli sullo schermo

	// LOGIC
	int random_place[9]; // array di posizioni random che saranno poi date come parametro alla funzione che amministra la logica delle macchine ostacolo
	for (int i = 0; i < 9; ++i)
		random_place[i] = 0;
	int random_col[5]; // array di posizioni random che saranno poi date come parametro alla funzione che amministra la logica delle macchine ostacolo
	for (int i = 0; i < 5; ++i)
		random_col[i] = 0;
	int y = 0;
	bool gameover = false; // booleano che sta nella guardia del game loop e che diventa true (interrompendo il ciclo) se i punti scendono sotto 0

	bool bang[5]; // array di booleani da dare come parametro alle funzioni "logic" degli ostacoli. Diventano true quando un ostacolo è colpito
	for (int i = 0; i < 5; i++)
		bang[i] = false;

	bool pop[4]; // array di booleani da dare come parametro alle funzioni "logic" dei power up. Diventano true quando un power up è colpito
	for (int i = 0; i < 4; i++)
		pop[i] = false;

	bool shot_fired = false; // booleano che regola il bonus proiettile, quando è true vuol dire che un proiettile è stato sparato.

	// OBSTACLES
	car OBST(ROAD_W/3, 0, rand() % 52 + 1); //dichiarazione delle macchine ostacolo
	car OBST2(45, 0, rand() % 52 + 1);
	car OBST3(ROAD_W / 2, 0, rand() % 52 + 1);
	car OBST4(ROAD_W / 2, 0, rand() % 52 + 1);
	car OBST5(ROAD_W / 2, 0,rand() % 52 + 1);
	bool go[8]; // array di booleani che serve per far comparire le macchine un po' alla volta e non tutte insieme
	for (int i = 0; i < 8; ++i)
		go[i] = false;

	// dichiarazione degli ostacoli di tipo buca
	hole HOLE1(45, 0);
	hole HOLE2(70, 0);

	// POWER UPS
	PowerUP up1(15, 0); // dichiarazione dei bonus punti e proiettile e dichiarazione del proiettile stesso
	PowerUP up2(30, 0);
	B_powerUP shmup(40, 0);
	bullet bill(1, 1);

	// KEY INPUT
	bool wasd[6]; // array di booleani che rappresentano i tasti w a s d

	// SCORE INITIALIZATION
	score_n_level SCORE;

	// GAME LOOP
	while (!gameover)
	{
		// DIFFICULTY INCREASE
		Sleep(SCORE.git_gud()); // La velocità del gioco è decisa qui con la funzione git_gud() che restituisce un intero sempre più piccolo mano a mano che si va avanti

		// DRAW FIELD
		screen.DrawField();

		// DRAW CENTER ROAD LINES
		screen.Draw_Road_Lines(loc2);
		loc2 = loc2 + WIDTH * 2;
		if (loc2 > (HEIGHT-1)* WIDTH)
			loc2 = 28;

		screen.Draw_Road_Lines(loc);
		loc = loc + WIDTH * 2;
		if (loc > (HEIGHT-1)* WIDTH)
			loc = 28;

		// DRAW HOLES
		if (rpm % 100 == 0 && (go[5] == false)) // aspetta 100 giri di ciclo while prima di far comparire la buca
			go[5] = true;
		if (go[5] == true)
			HOLE1.logic(random_place[6], CAR, SCORE, pop[0], go[5], screen.buffer, bill);

		// DRAW POWERUPS
		if (rpm % 50 == 0 && (go[4] == false)) // aspetta 50 giri di ciclo while prima di far comparire il power up
			go[4] = true;
		if (go[4] == true)
			up1.logic(random_place[5], CAR, SCORE, pop[1], go[4], screen.buffer);

		if (SCORE.gimme_nlevel() > 2) // il secondo power up e il bonus proiettile iniziano a comparire dal livello 2
		{
			if (rpm % 60 == 0 && (go[7] == false))
				go[7] = true;
			if (go[7] == true)
				up2.logic(random_place[8], CAR, SCORE, pop[3], go[7], screen.buffer);

			if (rpm % 160 == 0 && (go[6] == false))
				go[6] = true;
			if (go[6] == true)
				shmup.logic(random_place[7], CAR, bill, pop[2], go[6], screen.buffer);
		}
			
		// DRAW OBSTACLE CARS AND LOGIC
		// la prima macchina ostacolo appare subito
		OBST.logic(random_place[0], random_col[0], CAR, SCORE, bang[0], screen.buffer, bill);

		if (rpm == obst_per_rounds*2 && !go[0]) //aspetta 20 giri di ciclo while prima di far comparire la seconda macchina ostacolo
			go[0] = true;
		if (go[0] == true)
			OBST2.logic(random_place[1], random_col[1], CAR, SCORE, bang[1], screen.buffer, bill);

		if (rpm == obst_per_rounds*5 && !go[1]) 
			go[1] = true;
		if (go[1] == true)
			OBST3.logic(random_place[2], random_col[2], CAR, SCORE, bang[2], screen.buffer, bill);

		if (SCORE.gimme_nlevel() == 2 && !go[2]) //quando si arriva al livello 2 rende true il booleano a guardia della logica che governa l'ostacolo e quindi fa lo fa comparire sullo schermo
			go[2] = true;
		if (go[2] == true)
			OBST4.logic(random_place[3], random_col[3], CAR, SCORE, bang[3], screen.buffer, bill);

		if (SCORE.gimme_nlevel() == 2 && rpm == obst_per_rounds*20 && !go[3]) //quando si arriva al livello 2 rende true il booleano a guardia della logica che governa l'ostacolo e quindi fa lo fa comparire sullo schermo
			go[3] = true;
		if (go[3] == true)
			OBST5.logic(random_place[4], random_col[4], CAR, SCORE, bang[4], screen.buffer, bill);
			
		// DRAW CAR
		CAR.color_change(YELLOW, bill); //controlla se il bonus proiettile è stato raccolto e in tal caso cambia il colore della macchina
		CAR.draw_object(screen.buffer);

		// CONTROLS
		for (int k = 0; k < 6; k++)								
			wasd[k] = (GetAsyncKeyState("WASDP "[k])); //controlla se viene premuto un tasto, se sì allora il booleano corrispondente diventa true
		if (wasd[0])
			CAR.move_object(1, 0, 0, 0); //muove la macchina in alto se la il primo elemento dell'array è true 
		if (wasd[1])
			CAR.move_object(0, 0, 1, 0); //muove la macchina in basso se la il secondo elemento dell'array è true 
		if (wasd[2] && CAR.gimme_posy() < HEIGHT-3)
			CAR.move_object(0, 1, 0, 0); //muove la macchina a sinistra se il terzo elemento dell'array è true 
		if (wasd[3])
			CAR.move_object(0, 0, 0, 1); //muove la macchina a destra se il quarto elemento dell'array è true 

		if (wasd[5] && bill.get_active() == true && shot_fired == false) //se il quinto elemento dell'array è true e il bonus proiettile è stato raccolto e se non c'è attualmente un proiettile già sparato attiva la funzione logic del proiettile qui sotto
		{
			shot_fired = true;
			bill.update_pos(CAR.gimme_posx(), CAR.gimme_posy());
		}
		if (shot_fired == true)
		{
			bill.logic(CAR.gimme_posx(), CAR.gimme_posy(), shot_fired, screen.buffer);
		}
		
		// GAME PAUSE
		if (wasd[4])
		{
			bool pause = true;

			bool selectedPlay = true;
			screen.select_pause_play();
			screen.output(whdl);

			bool wsp[3];

			while (pause)
			{
				for (int k = 0; k < 3; k++) {
					wsp[k] = (GetAsyncKeyState(("WSO"[k]))) != 0;
				}

				if (wsp[2]) {
					pause = false;
				}
				else if (wsp[0]) {
					selectedPlay = true;
				}
				else if (wsp[1]) {
					selectedPlay = false;
				}

				if (pause) {
					if (selectedPlay) {
						screen.select_pause_play();
					}
					else {
						screen.select_pause_exit();
					}

					screen.output(whdl);
				}

			}

			if (!selectedPlay) {
				gameover = true;

			}

		}

		++rpm; 
		if (rpm == 1000)
			rpm = 0;

		// SCORE STUFF
		++score_clock; 
		if (score_clock == 10) //aumenta il punteggio di uno ogni 10 giri del game loop
		{
			SCORE.score_inc(1);
			score_clock = 0;
		}
		SCORE.display_score(screen.buffer);

		screen.output(whdl); // stampa lo screen buffer sulla console

		// GAMEOVER
		if (SCORE.gimme_nscore() < 0)
		{

			// GAMEOVER MENU
			bool gameovermenu = true;

			bool selectedReset = true;
			screen.select_gameover_reset();
			screen.output(whdl);

			bool wsp[3];

			while (gameovermenu)
			{
				for (int k = 0; k < 3; k++) {
					wsp[k] = (GetAsyncKeyState(("WSO"[k]))) != 0;
				}

				if (wsp[2]) {
					gameovermenu = false;
				}
				else if (wsp[0]) {
					selectedReset = true;
				}
				else if (wsp[1]) {
					selectedReset = false;
				}

				if (gameovermenu)
				{
					if (selectedReset)
					{
						screen.select_gameover_reset();
					}
					else
					{
						screen.select_gameover_exit();
					}

					screen.output(whdl);
				}

			}

			if (!selectedReset)
			{
				gameover = true;
			}
			else
			{
				for (int i = 0; i < 8; ++i)
				{
					go[i] = false;
				}
				SCORE.reset();
			}
		}
		//fine loop
	}
	return (0);
}