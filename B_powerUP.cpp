#include "B_powerUP.h"
B_powerUP::B_powerUP(int px, int py)
{
	posx = px;
	posy = py;
	color = YELLOW;
	for (int i = 0; i < 2; ++i)
		shape[i] = 219;
}

void B_powerUP::logic(int random_place, car CAR, bullet& bill, bool& pop, bool& go, CHAR_INFO buffer[])
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
		bill.activate();
	}
}

void B_powerUP::resetPU(bool& pop, int random_place)
{
	posy = 0;
	posx = random_place;
	color = YELLOW;
	pop = false;
	for (int i = 0; i < 2; ++i)
		shape[i] = 219;
}