#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include "Bala.h"

using namespace std;
void gotoxy5(int x, int y){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}
Bala::Bala(){}
void Bala::crear(int _x, int _y, int _id){
	this->x = _x;this->ini_x = _x;
	this->y = _y;this->ini_y = _y;
	this->id = _id;
	if (id == 0 || id == 1 || id == 2){ // disparo hacia arriba
		this->dy = -1;
	}else if(id == 3){ // disparo hacia abajo
		this->dy = 1;
	}
	if(id == 1){ // movimiento diagonal derecho
		this->dx = 3;
	}else if (id == 2){ //movimiento diagonal izquierdo
		this->dx = -3;
	}
	
}
void Bala::pintar(){
	gotoxy5(x,y);printf("*");
}
void Bala::movimiento(){
	if(id == 0){ //mover hacia arriba
		if(this->y != 0){ //regresa a posici?n inicial
			this->y += this->dy;
		}else{
			this->y = this->ini_y;
		}
	}else if(id == 1 || id == 2){ //mover en diagonales 
		if(this->y != 0){ //regresa a posici?n inicial
			this->y += this->dy;
			this->x += this->dx; 
		}else{
			this->y = this->ini_y;
			this->x = this->ini_x;
		}
	}else if(id == 3){ //mover hacia abajo
			this->y += this->dy;
	}
}
void Bala::borrar(){
	gotoxy5(x,y);printf(" ");
}
int Bala::xbala(){
	return this->x;
}
int Bala::ybala(){
	return this->y;
}
int Bala::setX(int _newX){
	this->x = _newX;
}
int Bala::setY(int _newY){
	this->y = _newY;
}

