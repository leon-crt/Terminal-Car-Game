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

class BufferStuff
{
protected:
	COORD CharacterBufferSize;
	COORD CharacterPosition;
	SMALL_RECT console_write_area = { 0, 0, WIDTH - 1, HEIGHT - 1 };

public:
	CHAR_INFO buffer[WIDTH * HEIGHT];

	BufferStuff();

	void DrawField();
	// inserisce la strada nel buffer

	void Draw_Road_Lines(int loc);
	// inserisce le linee di mezzeria nel buffer

	void output(HANDLE whdl);
	// stampa il buffer sulla console

	void select_pause_play();

	void select_pause_exit();

	void select_gameover_reset();

	void select_gameover_exit();
};
