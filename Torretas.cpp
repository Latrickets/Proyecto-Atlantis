#include "Torretas.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

using namespace std;
void SetColor2(int ForgC) 
{ 
    WORD wColor; 
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); 
     CONSOLE_SCREEN_BUFFER_INFO csbi; 

         //We use csbi for the wAttributes word. 
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)) 
    { 
       //Mask out all but the background attribute, and add in the forgournd  color 
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F); 
      SetConsoleTextAttribute(hStdOut, wColor); 
    } 
    return; 
} 
void gotoxy2(int x, int y){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}
Torretas::Torretas(int _x, int _y, int _vida, int _numT){
	this->x = _x;
	this->y = _y;
	this->vida = _vida;
	this->numT = _numT;
}
void Torretas::pintar(){
	if(numT == 1){
		gotoxy2(this->x,this->y);printf("%c%c", 124, 124);
		gotoxy2(this->x,this->y+1);cout<<"--";
		SetColor2(13);gotoxy2(this->x,this->y+2);printf("%c%c",219,219);
	}else if(numT == 2){
		gotoxy2(this->x,this->y);printf("%c%c", 47, 47);
		gotoxy2(this->x,this->y+1);cout<<"--";
		SetColor2(13);gotoxy2(this->x,this->y+2);printf("%c%c",219,219);
	}else if(numT == 3){
		gotoxy2(this->x,this->y);printf("%c%c", 92, 92);
		gotoxy2(this->x,this->y+1);cout<<"--";
		SetColor2(13);gotoxy2(this->x,this->y+2);printf("%c%c",219,219);
	}
	SetColor2(15);
}
void Torretas::destruir(){
	gotoxy2(this->x,this->y);cout<<"  ";
	gotoxy2(this->x,this->y+1);cout<<"--";
	gotoxy2(this->x,this->y+2);printf("%c",219);
}
int Torretas::X(){
	return this->x;	
}
int Torretas::Y(){
	return this->y;
}
