
#ifndef UNTITLED_BALA_H
#define UNTITLED_BALA_H

#include "Enemigo.h"
class Bala {
	private:
		int x;
		int y;
		int id;
		int ini_x, ini_y;
		int dx;
		int dy;
	public:
		Bala();
		void crear(int, int, int);
		void pintar();
		void movimiento();
		void borrar();
		int xbala();
		int ybala();
		int setX(int);
		int setY(int);
};


#endif //UNTITLED_CIUDAD_H

