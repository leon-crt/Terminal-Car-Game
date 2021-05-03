#define YELLOW 110 | 110 | 110
#include "PowerUP.h"
#include "bullet.h"
#ifndef b_powerUP_h
#define b_powerUP_h
class B_powerUP : // è come PowerUp ma se viene colpito cambia lo stato del proiettile da non attivo a attivo
	public PowerUP
{
protected:
	void resetPU(bool& pop, int random_place);

public:
	B_powerUP(int px, int py);

	void logic(int random_place, car CAR, bullet& bill, bool& pop, bool& go, CHAR_INFO buffer[]);

	
};

#endif