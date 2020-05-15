
#ifndef UNTITLED_BALA_H
#define UNTITLED_BALA_H


class Bala {
	private:
		int x;
		int y;
		int ini_x, ini_y;
		int dx;
		int dy;
	public:
		Bala(int, int);
		void pintar();
		void movimiento();
		void borrar();
		int xbala();
		int ybala();
		int setX(int);
		int setY(int);
};


#endif //UNTITLED_CIUDAD_H
