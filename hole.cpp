#include "hole.h"

hole::hole(int px, int py)
{
	posx = px;
	posy = py;
	color = 1 | WHITE_TEXT;
	for (int i = 0; i < 6; ++i)
		shape[i] = 176;
}

void hole::logic(int random_place, car CAR, score_n_level& score, bool& pop, bool& go, CHAR_INFO buffer[], bullet &bill)
{
	draw_object(buffer, 2, 3);
	move_object(0, 1, 0, 0);
	move_object(0, 1, 0, 0);

	if (posy == HEIGHT)
	{
		random_place = rand() % 52 + 1;
		reset_hole(pop, random_place);
		go = false;
	}

	if (collision_detection(CAR, 3, 2) && pop == false)
	{
		if (score.gimme_nlevel() == 1)
		{
			score.score_dec(5);
			if(bill.get_active() == true)
				bill.deactivate();
		}
		else if (score.gimme_nlevel() == 2)
		{
			score.score_dec(10);
			if (bill.get_active() == true)
				bill.deactivate();
		}
		else
		{
			score.score_dec(15);
			if (bill.get_active() == true)
				bill.deactivate();
		}
	}
}

void hole::reset_hole(bool& pop, int random_place)
{
	posy = 0;
	posx = random_place;
	pop = false;
}
