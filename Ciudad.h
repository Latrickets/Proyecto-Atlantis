
#ifndef UNTITLED_CIUDAD_H
#define UNTITLED_CIUDAD_H


class Ciudad {
	private:
		int x;
		int y;
		int vida;
		int numC;
	public:
		Ciudad();
		void crear(int, int, int, int);
		void pintar();
		void borrar();
		int getNC();
		int getX();
		int getY();
		int getV();
		void destruct();
};


#endif //UNTITLED_CIUDAD_H

