#include "gameobject.h"
#ifndef bullet_h
#define bullet_h
class bullet : public gameobject
{
protected:
	void reset_bullet(int px, int py);
	bool hit;
	bool active;

public:
	bullet(int px, int py);

	void explode();
	// rende il proiettile dello stesso colore della strada
	
	void logic(int px, int py, bool& boom, CHAR_INFO buffer[]);
	// inserisce il proiettile nel buffer, lo sposta due volte (così è più veloce) e controlla che non sia arrivato al bordo superiore 
	// dello schermo

	void update_pos(int px, int py);
	// aggiorna la posizione del proiettile

	void deactivate();
	// active diventa true
	
	void activate();
	// active diventa false

	bool get_hit();

	bool get_active();

	int get_posx();

	int get_posy();
};

#endif