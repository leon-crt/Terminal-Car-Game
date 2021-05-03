#include "BufferStuff.h"
BufferStuff::BufferStuff()
{
	CharacterBufferSize = { WIDTH, HEIGHT };
	CharacterPosition = { 0, 0 };

	// BUFFER INITIALIZATION
	for (int y = 0; y < HEIGHT; ++y) {
		for (int x = 0; x < WIDTH; ++x) {
			buffer[x + WIDTH * y].Char.AsciiChar = ' ';
			buffer[x + WIDTH * y].Attributes = BACKGROUND_GREEN;
		}
	}

};

void BufferStuff::DrawField()
{
	for (int y = 0; y < HEIGHT; ++y)
	{
		buffer[WIDTH * y].Char.AsciiChar = (unsigned char)' ';
		buffer[WIDTH * y].Attributes = WHITE;

		for (int x = 1; x <= ROAD_W; ++x)
		{
			buffer[x + WIDTH * y].Char.AsciiChar = ' ';
			buffer[x + WIDTH * y].Attributes = 138 | 138 | 138;
			if (x == ROAD_W)
			{
				buffer[x + WIDTH * y].Char.AsciiChar = (unsigned char)' ';
				buffer[x + WIDTH * y].Attributes = WHITE;
			}
		}
	}
};

void BufferStuff::Draw_Road_Lines(int loc)
{

	for (int y = 0; y < 4; y++)
	{
		if ((loc + WIDTH * y) < WIDTH * HEIGHT)
		{
			buffer[loc + WIDTH * y].Char.AsciiChar = ' ';
			buffer[loc + WIDTH * y].Attributes = WHITE;
		}
	}
};

void BufferStuff::output(HANDLE whdl)
{
	WriteConsoleOutputA(whdl, buffer, CharacterBufferSize, CharacterPosition, &console_write_area);
};

//MENU SELECT PLAY
void BufferStuff::select_pause_play()
{
	for (int y = 0; y < HEIGHT; ++y)
	{
		buffer[WIDTH * y].Char.AsciiChar = (unsigned char)' ';
		buffer[WIDTH * y].Attributes = BLACK;

		for (int x = 1; x <= ROAD_W; ++x)
		{
			buffer[x + WIDTH * y].Char.AsciiChar = ' ';
			buffer[x + WIDTH * y].Attributes = 000 | 000 | 000;
			if (x == ROAD_W)
			{
				buffer[x + WIDTH * y].Char.AsciiChar = (unsigned char)' ';
				buffer[x + WIDTH * y].Attributes = BLACK;
			}
		}

	}

	int y = (HEIGHT / 2) - 15;
	//print white lines
	for (int a = 0; a < 2; ++a)
	{
		for (int x = 1; x <= ROAD_W; ++x)
		{
			buffer[x + WIDTH * y].Char.AsciiChar = ' ';
			buffer[x + WIDTH * y].Attributes = WHITE;
		}
		y = y + 2;
	}

	//Menu Items choise
	char msg_choise[] = "Premi la lettera o per confermare la scelta ";
	int cont = 0;
	int lun = sizeof(msg_choise) / sizeof(msg_choise[0]);

	for (int x = 1; x <= ROAD_W; ++x)
	{
		if (cont < lun)
		{
			buffer[x + WIDTH * y].Char.AsciiChar = msg_choise[cont];
			buffer[x + WIDTH * y].Attributes = BLACK | WHITE_TEXT;
			++cont;
		}

		else
		{
			buffer[x + WIDTH * y].Char.AsciiChar = ' ';
			buffer[x + WIDTH * y].Attributes = BLACK;
		}
	}
	//Menu Items Play
	y = y + 2;
	char msg_play[] = "Riprendi il gioco";
	cont = 0;
	lun = sizeof(msg_play) / sizeof(msg_play[0]);

	buffer[1 + WIDTH * y].Char.AsciiChar = ' ';
	buffer[1 + WIDTH * y].Attributes = YELLOW;
	buffer[1 + WIDTH * (y + 1)].Char.AsciiChar = ' ';
	buffer[1 + WIDTH * (y + 1)].Attributes = BLACK;


	for (int x = 3; x <= ROAD_W; ++x)
	{
		if (cont < lun)
		{
			buffer[x + WIDTH * y].Char.AsciiChar = msg_play[cont];
			buffer[x + WIDTH * y].Attributes = BLACK | WHITE_TEXT;
			++cont;
		}

		else
		{
			buffer[x + WIDTH * y].Char.AsciiChar = ' ';
			buffer[x + WIDTH * y].Attributes = BLACK;
		}
	}

	//Menu Items Exit
	y++;
	char msg_exit[] = "Esci dal gioco";
	cont = 0;
	lun = sizeof(msg_exit) / sizeof(msg_exit[0]);

	for (int x = 3; x <= ROAD_W; ++x)
	{
		if (cont < lun)
		{
			buffer[x + WIDTH * y].Char.AsciiChar = msg_exit[cont];
			buffer[x + WIDTH * y].Attributes = BLACK | WHITE_TEXT;
			++cont;
		}

		else
		{
			buffer[x + WIDTH * y].Char.AsciiChar = ' ';
			buffer[x + WIDTH * y].Attributes = BLACK;
		}
	}

	//print white lines
	y = y + 4;
	for (int a = 0; a < 2; ++a)
	{
		for (int x = 1; x <= ROAD_W; ++x)
		{
			buffer[x + WIDTH * y].Char.AsciiChar = ' ';
			buffer[x + WIDTH * y].Attributes = WHITE;
		}
		y = y + 2;
	}
};

//MENU SELECT EXIT
void BufferStuff::select_pause_exit()
{
	for (int y = 0; y < HEIGHT; ++y)
	{
		buffer[WIDTH * y].Char.AsciiChar = (unsigned char)' ';
		buffer[WIDTH * y].Attributes = BLACK;

		for (int x = 1; x <= ROAD_W; ++x)
		{
			buffer[x + WIDTH * y].Char.AsciiChar = ' ';
			buffer[x + WIDTH * y].Attributes = 000 | 000 | 000;
			if (x == ROAD_W)
			{
				buffer[x + WIDTH * y].Char.AsciiChar = (unsigned char)' ';
				buffer[x + WIDTH * y].Attributes = BLACK;
			}
		}

	}

	int y = (HEIGHT / 2) - 15;
	//print white lines
	for (int a = 0; a < 2; ++a)
	{
		for (int x = 1; x <= ROAD_W; ++x)
		{
			buffer[x + WIDTH * y].Char.AsciiChar = ' ';
			buffer[x + WIDTH * y].Attributes = WHITE;
		}
		y = y + 2;
	}

	//Menu Items choise
	char msg_choise[] = "Premi la lettera o per confermare la scelta ";
	int cont = 0;
	int lun = sizeof(msg_choise) / sizeof(msg_choise[0]);

	for (int x = 1; x <= ROAD_W; ++x)
	{
		if (cont < lun)
		{
			buffer[x + WIDTH * y].Char.AsciiChar = msg_choise[cont];
			buffer[x + WIDTH * y].Attributes = BLACK | WHITE_TEXT;
			++cont;
		}

		else
		{
			buffer[x + WIDTH * y].Char.AsciiChar = ' ';
			buffer[x + WIDTH * y].Attributes = BLACK;
		}
	}
	//Menu Items Play
	y = y + 2;
	char msg_play[] = "Riprendi il gioco";
	cont = 0;
	lun = sizeof(msg_play) / sizeof(msg_play[0]);

	buffer[1 + WIDTH * y].Char.AsciiChar = ' ';
	buffer[1 + WIDTH * y].Attributes = BLACK;
	buffer[1 + WIDTH * (y + 1)].Char.AsciiChar = ' ';
	buffer[1 + WIDTH * (y + 1)].Attributes = YELLOW;


	for (int x = 3; x <= ROAD_W; ++x)
	{
		if (cont < lun)
		{
			buffer[x + WIDTH * y].Char.AsciiChar = msg_play[cont];
			buffer[x + WIDTH * y].Attributes = BLACK | WHITE_TEXT;
			++cont;
		}
		else
		{
			buffer[x + WIDTH * y].Char.AsciiChar = ' ';
			buffer[x + WIDTH * y].Attributes = BLACK;
		}
	}

	//Menu Items Exit
	y++;
	char msg_exit[] = "Esci dal gioco";
	cont = 0;
	lun = sizeof(msg_exit) / sizeof(msg_exit[0]);

	for (int x = 3; x <= ROAD_W; ++x)
	{
		if (cont < lun)
		{
			buffer[x + WIDTH * y].Char.AsciiChar = msg_exit[cont];
			buffer[x + WIDTH * y].Attributes = BLACK | WHITE_TEXT;
			++cont;
		}
		else
		{
			buffer[x + WIDTH * y].Char.AsciiChar = ' ';
			buffer[x + WIDTH * y].Attributes = BLACK;
		}
	}

	//print white lines
	y = y + 4;
	for (int a = 0; a < 2; ++a)
	{
		for (int x = 1; x <= ROAD_W; ++x)
		{
			buffer[x + WIDTH * y].Char.AsciiChar = ' ';
			buffer[x + WIDTH * y].Attributes = WHITE;
		}
		y = y + 2;
	}
};

//MENU GAME OVER RESET
void BufferStuff::select_gameover_reset()
{
	for (int y = 0; y < HEIGHT; ++y)
	{
		buffer[WIDTH * y].Char.AsciiChar = (unsigned char)' ';
		buffer[WIDTH * y].Attributes = BLACK;

		for (int x = 1; x <= ROAD_W; ++x)
		{
			buffer[x + WIDTH * y].Char.AsciiChar = ' ';
			buffer[x + WIDTH * y].Attributes = 000 | 000 | 000;
			if (x == ROAD_W)
			{
				buffer[x + WIDTH * y].Char.AsciiChar = (unsigned char)' ';
				buffer[x + WIDTH * y].Attributes = BLACK;
			}
		}

	}

	int y = (HEIGHT / 2) - 15;
	//print white lines
	for (int a = 0; a < 2; ++a)
	{
		for (int x = 1; x <= ROAD_W; ++x)
		{
			buffer[x + WIDTH * y].Char.AsciiChar = ' ';
			buffer[x + WIDTH * y].Attributes = WHITE;
		}
		y = y + 2;
	}

	//Menu Items choise
	char msg_choise[] = "Premi la lettera o per confermare la scelta ";
	int cont = 0;
	int lun = sizeof(msg_choise) / sizeof(msg_choise[0]);

	for (int x = 1; x <= ROAD_W; ++x)
	{
		if (cont < lun)
		{
			buffer[x + WIDTH * y].Char.AsciiChar = msg_choise[cont];
			buffer[x + WIDTH * y].Attributes = BLACK | WHITE_TEXT;
			++cont;
		}

		else
		{
			buffer[x + WIDTH * y].Char.AsciiChar = ' ';
			buffer[x + WIDTH * y].Attributes = BLACK;
		}
	}
	//Menu Items Play
	y = y + 2;
	char msg_play[] = "Rinizia il gioco perche' e' troppo divertente";
	cont = 0;
	lun = sizeof(msg_play) / sizeof(msg_play[0]);

	buffer[1 + WIDTH * y].Char.AsciiChar = ' ';
	buffer[1 + WIDTH * y].Attributes = YELLOW;
	buffer[1 + WIDTH * (y + 1)].Char.AsciiChar = ' ';
	buffer[1 + WIDTH * (y + 1)].Attributes = BLACK;


	for (int x = 3; x <= ROAD_W; ++x)
	{
		if (cont < lun)
		{
			buffer[x + WIDTH * y].Char.AsciiChar = msg_play[cont];
			buffer[x + WIDTH * y].Attributes = BLACK | WHITE_TEXT;
			++cont;
		}

		else
		{
			buffer[x + WIDTH * y].Char.AsciiChar = ' ';
			buffer[x + WIDTH * y].Attributes = BLACK;
		}
	}

	//Menu Items Exit
	y++;
	char msg_exit[] = "Esci dal gioco";
	cont = 0;
	lun = sizeof(msg_exit) / sizeof(msg_exit[0]);

	for (int x = 3; x <= ROAD_W; ++x)
	{
		if (cont < lun)
		{
			buffer[x + WIDTH * y].Char.AsciiChar = msg_exit[cont];
			buffer[x + WIDTH * y].Attributes = BLACK | WHITE_TEXT;
			++cont;
		}

		else
		{
			buffer[x + WIDTH * y].Char.AsciiChar = ' ';
			buffer[x + WIDTH * y].Attributes = BLACK;
		}
	}

	//print white lines
	y = y + 4;
	for (int a = 0; a < 2; ++a)
	{
		for (int x = 1; x <= ROAD_W; ++x)
		{
			buffer[x + WIDTH * y].Char.AsciiChar = ' ';
			buffer[x + WIDTH * y].Attributes = WHITE;
		}
		y = y + 2;
	}

	y++;
	char msg_finalcredit[] = "Lorenzo Bassoli e Leon Pirazzoli";
	cont = 0;
	lun = sizeof(msg_finalcredit) / sizeof(msg_finalcredit[0]);

	for (int x = 10; x <= ROAD_W; ++x)
	{
		if (cont < lun)
		{
			buffer[x + WIDTH * y].Char.AsciiChar = msg_finalcredit[cont];
			buffer[x + WIDTH * y].Attributes = BLACK | WHITE_TEXT;
			++cont;
		}
		else
		{
			buffer[x + WIDTH * y].Char.AsciiChar = ' ';
			buffer[x + WIDTH * y].Attributes = BLACK;
		}
	}

	//print white lines
	y = y + 4;
	for (int a = 0; a < 2; ++a)
	{
		for (int x = 1; x <= ROAD_W; ++x)
		{
			buffer[x + WIDTH * y].Char.AsciiChar = ' ';
			buffer[x + WIDTH * y].Attributes = WHITE;
		}
		y = y + 2;
	}
};


//MENU GAME OVER EXIT
void BufferStuff::select_gameover_exit()
{
	for (int y = 0; y < HEIGHT; ++y)
	{
		buffer[WIDTH * y].Char.AsciiChar = (unsigned char)' ';
		buffer[WIDTH * y].Attributes = BLACK;

		for (int x = 1; x <= ROAD_W; ++x)
		{
			buffer[x + WIDTH * y].Char.AsciiChar = ' ';
			buffer[x + WIDTH * y].Attributes = 000 | 000 | 000;
			if (x == ROAD_W)
			{
				buffer[x + WIDTH * y].Char.AsciiChar = (unsigned char)' ';
				buffer[x + WIDTH * y].Attributes = BLACK;
			}
		}

	}

	int y = (HEIGHT / 2) - 15;
	//print white lines
	for (int a = 0; a < 2; ++a)
	{
		for (int x = 1; x <= ROAD_W; ++x)
		{
			buffer[x + WIDTH * y].Char.AsciiChar = ' ';
			buffer[x + WIDTH * y].Attributes = WHITE;
		}
		y = y + 2;
	}

	//Menu Items choise
	char msg_choise[] = "Premi la lettera o per confermare la scelta ";
	int cont = 0;
	int lun = sizeof(msg_choise) / sizeof(msg_choise[0]);

	for (int x = 1; x <= ROAD_W; ++x)
	{
		if (cont < lun)
		{
			buffer[x + WIDTH * y].Char.AsciiChar = msg_choise[cont];
			buffer[x + WIDTH * y].Attributes = BLACK | WHITE_TEXT;
			++cont;
		}

		else
		{
			buffer[x + WIDTH * y].Char.AsciiChar = ' ';
			buffer[x + WIDTH * y].Attributes = BLACK;
		}
	}
	//Menu Items Play
	y = y + 2;
	char msg_play[] = "Rinizia il gioco perche' e' troppo divertente";
	cont = 0;
	lun = sizeof(msg_play) / sizeof(msg_play[0]);

	buffer[1 + WIDTH * y].Char.AsciiChar = ' ';
	buffer[1 + WIDTH * y].Attributes = BLACK;
	buffer[1 + WIDTH * (y + 1)].Char.AsciiChar = ' ';
	buffer[1 + WIDTH * (y + 1)].Attributes = YELLOW;


	for (int x = 3; x <= ROAD_W; ++x)
	{
		if (cont < lun)
		{
			buffer[x + WIDTH * y].Char.AsciiChar = msg_play[cont];
			buffer[x + WIDTH * y].Attributes = BLACK | WHITE_TEXT;
			++cont;
		}
		else
		{
			buffer[x + WIDTH * y].Char.AsciiChar = ' ';
			buffer[x + WIDTH * y].Attributes = BLACK;
		}
	}

	//Menu Items Exit
	y++;
	char msg_exit[] = "Esci dal gioco";
	cont = 0;
	lun = sizeof(msg_exit) / sizeof(msg_exit[0]);

	for (int x = 3; x <= ROAD_W; ++x)
	{
		if (cont < lun)
		{
			buffer[x + WIDTH * y].Char.AsciiChar = msg_exit[cont];
			buffer[x + WIDTH * y].Attributes = BLACK | WHITE_TEXT;
			++cont;
		}
		else
		{
			buffer[x + WIDTH * y].Char.AsciiChar = ' ';
			buffer[x + WIDTH * y].Attributes = BLACK;
		}
	}

	//print white lines
	y = y + 4;
	for (int a = 0; a < 2; ++a)
	{
		for (int x = 1; x <= ROAD_W; ++x)
		{
			buffer[x + WIDTH * y].Char.AsciiChar = ' ';
			buffer[x + WIDTH * y].Attributes = WHITE;
		}
		y = y + 2;
	}

	y++;
	char msg_finalcredit[] = "Lorenzo Bassoli e Leon Pirazzoli";
	cont = 0;
	lun = sizeof(msg_finalcredit) / sizeof(msg_finalcredit[0]);

	for (int x = 10; x <= ROAD_W; ++x)
	{
		if (cont < lun)
		{
			buffer[x + WIDTH * y].Char.AsciiChar = msg_finalcredit[cont];
			buffer[x + WIDTH * y].Attributes = BLACK | WHITE_TEXT;
			++cont;
		}
		else
		{
			buffer[x + WIDTH * y].Char.AsciiChar = ' ';
			buffer[x + WIDTH * y].Attributes = BLACK;
		}
	}

	//print white lines
	y = y + 4;
	for (int a = 0; a < 2; ++a)
	{
		for (int x = 1; x <= ROAD_W; ++x)
		{
			buffer[x + WIDTH * y].Char.AsciiChar = ' ';
			buffer[x + WIDTH * y].Attributes = WHITE;
		}
		y = y + 2;
	}

};
