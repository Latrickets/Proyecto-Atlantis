#ifndef UNTITLED_TORRETAS_H
#define UNTITLED_TORRETAS_H
#include "Torretas.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

using namespace std;

class Torretas {
	private:
		int x;
		int y;
		int vida;
		int numT;
	public:
		Torretas();
		void crear(int, int, int, int);
		void pintar();
		void destruir();
		int X();
		int Y();
		int setV(int);
		int getV();
};

#endif //UNTITLED_TORRETAS_H

