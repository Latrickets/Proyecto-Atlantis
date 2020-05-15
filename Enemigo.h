

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
		int dx;
	public:
		Enemigo(int, int, int, int);
		void pintar();
		void destruir();
		void movimiento();
};


#endif //UNTITLED_ENEMIGO_H
