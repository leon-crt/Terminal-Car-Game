#include "score_n_level.h"
score_n_level::score_n_level()
{
	nscore = 1;
	nlevel = 1;
	damage = 10;
	level_up = false;
	level_down = false;
	speed_reg = 50;
};

void score_n_level::translate()
{
	int i = 11;

	for (int tmp = nscore; tmp > 0 && i >= 6; tmp = tmp / 10)
	{
		score[i] = 48 + (tmp % 10);
		--i;
	}

	while (i > 6)
	{
		score[i] = 48;
		--i;
	}

	i = 11;
	for (int tmp = nlevel; tmp > 0 && i >= 6; tmp = tmp / 10)
	{
		level[i] = 48 + (tmp % 10);
		--i;
	}

	while (i > 6)
	{
		level[i] = 48;
		--i;
	}
};

void score_n_level::display_score(CHAR_INFO buffer[])
{
	translate();
	for (int i = 0; i < 13; ++i)
		buffer[ROAD_W + 5 + i + WIDTH * 5].Char.AsciiChar = score[i];
	for (int i = 0; i < 13; ++i)
		buffer[ROAD_W + 5 + i + WIDTH * 7].Char.AsciiChar = level[i];
};

void score_n_level::score_inc(int x)
{
	for (int i = 0; i < x; i++)
	{
		if (nscore % 100 == 0)
		{
			++nlevel;
			level_up = true;
		}
		nscore = nscore + 1;
	}
};

void score_n_level::score_dec()
{	
	for (int i = 0; i < damage; i++)
	{
		if (nscore % 100 == 0)
		{
			nlevel = nlevel - 1;
			level_down = true;
		}
	
		nscore = nscore - 1;
	}
};

void score_n_level::score_dec(int x)
{
	for (int i = 0; i < x; i++)
	{
		if (nscore % 100 == 0 )
		{
			nlevel = nlevel - 1;
			level_down = true;
		}
		nscore = nscore - 1;
	}
};

int score_n_level::git_gud()
{
	if ((level_up) && (speed_reg > 30))
	{
		damage = damage + 20;
		speed_reg = speed_reg - 10;
		level_up = false;
	}
	return speed_reg;
};

void score_n_level::reset()
{
	nscore = 1;
	nlevel = 1;
	damage = 10;
	level_up = false;
	level_down = false;
	speed_reg = 50;
};

int score_n_level::gimme_nscore()
{
	return nscore;
};

int score_n_level::gimme_nlevel()
{
	return nlevel;
};