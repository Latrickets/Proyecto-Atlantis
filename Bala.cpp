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
Bala::Bala(int _x, int _y){
	this->x = _x;this->ini_x = _x;
	this->y = _y;this->ini_y = _y;
	this->dy = -1;
}
void Bala::pintar(){
	gotoxy5(x,y);printf("*");
}
void Bala::movimiento(){
	
	if(this->y != 0){
		this->y += this->dy;
	}else{
		this->y = this->ini_y;
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
int Bala::setY(int _newY){
	this->y = _newY;
}
