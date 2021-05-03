#include "PowerUP.h"

PowerUP::PowerUP(int px, int py)
{
	for (int i = 0; i < 2; ++i)
		shape[i] = 219;
	posx = px;
	posy = py;
	color = 90;
}

PowerUP::PowerUP()
{}

void PowerUP::logic(int random_place, car CAR, score_n_level& score, bool& pop, bool& go, CHAR_INFO buffer[])
{
	draw_object(buffer, 1, 2);
	move_object(0, 1, 0, 0);

	if (posy == HEIGHT)
	{
		random_place = rand() % 52 + 1;
		resetPU(pop, random_place);
		go = false;
	}

	if (collision_detection(CAR) && pop == false)
	{
		explode(pop);
		score.score_inc(10); 
	}
}

void PowerUP::explode(bool& pop)
{
	for (int i=0; i<2; ++i)
		shape[i] = 32;
	color = 138 | 138 | 138;
	pop = true;
}

void PowerUP::resetPU(bool& pop, int random_place)
{
	posy = 0;
	posx = random_place;
	color = 90;
	pop = false;
	for (int i = 0; i < 2; ++i)
		shape[i] = 219;
}

bool PowerUP::collision_detection(car CAR)
{
	for (int y = 0; y < 3; ++y)
	{
		for (int x = 0; x < 4; ++x)
		{
			for (int a = 0; a < 2; ++a)
				if (((CAR.gimme_posx() + x) + WIDTH * (CAR.gimme_posy() + y)) == ((posx + a) + (WIDTH * posy)))
					return true;
		}
	}
	return false;
}