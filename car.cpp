#include "car.h"
#include "score_n_level.h"
void car::explode(bool& bang)
{
	for (int i = 0; i < 16; ++i)
		shape[i] = ' ';
	color = 138 | 138 | 138;
	bang = true;
};

void car::reset_car(int random_num, int random_col, bool& bang)
{
	posy = 0;
	posx = random_num;
	color = random_col;
	bang = false;
	for (int i = 0; i < 16; ++i)
	{
		if (i == 0)
			shape[i] = '*';
		if (i == 1 || i == 2)
			shape[i] = '|';
		if (i == 3)
			shape[i] = '*';
		if (i == 4)
			shape[i] = '(';
		if (i == 5 || i == 6)
			shape[i] = ' ';
		if (i == 7)
			shape[i] = ')';
		if (i > 7 && i < 14)
			shape[i] = '_';
	}
};

bool car::collision_detection(car obst)
{
	for (int a = 0; a < 3; ++a)
	{
		for (int b = 0; b < 4; ++b)
		{
			for (int y = 0; y < 3; ++y)
				for (int x = 0; x < 4; ++x)
				{
					if ((posx + x) + WIDTH * (posy + y) == (obst.posx + b) + WIDTH * (obst.posy + a))
						return true;
				}
		}
	}
	return false;
};

car::car(int px, int py, WORD col)
{
	posx = px;
	posy = py;
	color = col;
};

void car::draw_object(CHAR_INFO buffer[])
{
	for (int y = 0; y < 3; ++y)
		for (int x = 0; x < 4; ++x) {
			if ((posx + x) + WIDTH * (posy + y) < HEIGHT * WIDTH)
			{
				buffer[(posx + x) + WIDTH * (posy + y)].Char.AsciiChar = shape[x + 4 * y];
				buffer[(posx + x) + WIDTH * (posy + y)].Attributes = color | WHITE_TEXT;
			}
		}
};

void car::color_change(WORD col, bullet bill)
{
	if (bill.get_active() == true)
	{
		color = col;
	}
	else
		color = RED;
}

bool car::collision_detection(bullet bill)
{
	for (int y = 0; y < 3; ++y)
		for (int x = 0; x < 4; ++x)
		{
			if ((posx + x) + WIDTH * (posy + y) == (bill.get_posx()) + WIDTH * (bill.get_posy()))
				return true;
		}

	return false;
}

void car::logic(int random_place, int random_col, car CAR, score_n_level& score, bool& bang, CHAR_INFO buffer[], bullet& bill)
{
	draw_object(buffer);
	move_object(0, 1, 0, 0);

	if (posy == HEIGHT)
	{
		random_place = rand() % 52 + 1;
		int random_col1 = rand() % 129 - 1;
		int random_col2 = rand() % 100 + 146;
		random_col = rand() % 2;
		if (random_col <= 1)
			random_col = random_col1;
		else
			random_col = random_col2;
		reset_car(random_place, random_col, bang);
	}

	if (collision_detection(CAR) && bang == false)
	{
		explode(bang);
		score.score_dec();
		if (bill.get_active() == true)
			bill.deactivate();
	}

	if (collision_detection(bill) && bang == false && bill.get_hit() == false)
	{
		bill.explode();
		explode(bang);
		score.score_inc(5);
	}

};
