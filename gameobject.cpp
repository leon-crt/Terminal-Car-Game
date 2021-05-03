#include "gameobject.h"
void gameobject::draw_object(CHAR_INFO buffer[], int a, int b)
{
	for (int y = 0; y < a; ++y)
		for (int x = 0; x < b; ++x) 
		{
			if ((posx + x) + WIDTH * (posy + y) < HEIGHT * WIDTH)
			{
				buffer[(posx + x) + WIDTH * (posy + y)].Char.AsciiChar = shape[x + b * y];
				buffer[(posx + x) + WIDTH * (posy + y)].Attributes = color;
			}
		}
};

void gameobject::move_object(bool UP, bool DOWN, bool LEFT, bool RIGHT)
{
	if (UP && posy > 0)
		--posy;
	if (DOWN && posy < HEIGHT)
		++posy;
	if (LEFT && posx > 0)
		--posx;
	if (RIGHT && posx + 3 < ROAD_W)
		++posx;
};

bool gameobject::collision_detection(gameobject obst, int w, int h)
{
	for (int a = 0; a < h; ++a)
	{
		for (int b = 0; b < w; ++b)
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

int gameobject::gimme_posy()
{
	return posy;
};

int gameobject::gimme_posx()
{
	return posx;
};