#include "bullet.h"
bullet::bullet(int px, int py)
{
	posx = px+1;
	posy = py;
	color = 138 | YELLOW;
	shape[0] = '|';
	hit = false;
	active = false;
}

void bullet::logic(int px, int py, bool& boom, CHAR_INFO buffer[])
{

	draw_object(buffer, 1, 1);
	move_object(1, 0, 0, 0);
	move_object(1, 0, 0, 0);

	if (posy == 0)
	{
		reset_bullet(px, py);
		boom = false;
	}
}

void bullet::explode()
{
	hit = true;
	shape[0] = ' ';
	color = 138 | 138 | 138;
}

void bullet::reset_bullet(int px, int py)
{
	color = 138 | YELLOW;
	shape[0] = '|';
	posx = px+1;
	posy = py;
	hit = false;
}

void bullet::deactivate()
{
	active = false;
}

void bullet::activate()
{
	active = true;
}

bool bullet::get_hit()
{
	return hit;
}

int bullet::get_posx()
{
	return posx;
}

int bullet::get_posy()
{
	return posy;
}

bool bullet::get_active()
{
	return active;
}

void bullet::update_pos(int px, int py)
{
	posx = px+1;
	posy = py;
}