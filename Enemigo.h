

#ifndef UNTITLED_ENEMIGO_H
#define UNTITLED_ENEMIGO_H
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

using namespace std;

class Enemigo {
	private:
		int x;
		int y;
		int vida;
		int numE;
		int dir;
		int dx;
		int ini_x, ini_y;
	public:
		Enemigo();
		void crear(int, int, int, int, int);
		void pintar();
		void destruir();
		void movimiento();
		int xEne();
		int yEne();
		int Vidas();
		int sVidas(int);
		void destruct();
};


#endif //UNTITLED_ENEMIGO_H
