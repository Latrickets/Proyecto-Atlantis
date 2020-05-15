
#include "Enemigo.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

using namespace std;
void Color3(int Background, int Text){ // Funci�n para cambiar el color del fondo y/o pantalla

 HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE); // Tomamos la consola.

 // Para cambiar el color, se utilizan n�meros desde el 0 hasta el 255.
 // Pero, para convertir los colores a un valor adecuado, se realiza el siguiente c�lculo.
 int    New_Color= Text + (Background * 16);

 SetConsoleTextAttribute(Console, New_Color); // Guardamos los cambios en la Consola.
}
void SetColor4(int ForgC) 
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
void gotoxy4(int x, int y){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}
Enemigo::Enemigo(int _x, int _y, int _vida, int _numE){
	this->x = _x;
	this->y = _y;
	this->vida = _vida;
	this->numE = _numE;
	this->dx = -1;
}
void Enemigo::pintar(){
	if(numE == 1){
		Color3(0,5);gotoxy4(this->x, this->y);printf("%c",219);Color3(0,7);printf("%c",219);Color3(0,5);printf("%c%c", 219,219);
		Color3(0,8);gotoxy4(this->x+1, this->y+1);printf("%c%c",219,219);
		Color3(0,2);gotoxy4(this->x+2, this->y+2);printf("%c",223);
	}else if(numE == 2){
	}else if(numE == 3){
	}
	Color3(0,15);
}
void Enemigo::destruir(){
	if(numE == 1){
		Color3(0,0);gotoxy4(this->x, this->y);printf("    ");
		Color3(0,0);gotoxy4(this->x+1, this->y+1);printf("  ");
		Color3(0,0);gotoxy4(this->x+2, this->y+2);printf(" ");
	}
	Color3(0,15);
}
void Enemigo::movimiento(){
	if(numE == 1){
		this->x = this->x + dx;
		if(this->x == 0 || this->x == 84){
			dx *= -1;
		}
	}
}
