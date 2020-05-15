#include "Ciudad.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

using namespace std;
void Color2(int Background, int Text){ // Función para cambiar el color del fondo y/o pantalla

 HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE); // Tomamos la consola.

 // Para cambiar el color, se utilizan números desde el 0 hasta el 255.
 // Pero, para convertir los colores a un valor adecuado, se realiza el siguiente cálculo.
 int    New_Color= Text + (Background * 16);

 SetConsoleTextAttribute(Console, New_Color); // Guardamos los cambios en la Consola.
}
void SetColor3(int ForgC) 
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
void gotoxy3(int x, int y){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}
Ciudad::Ciudad(int _x, int _y, int _vida, int _c){
	this->x = _x;
	this->y = _y;
	this->vida = _vida;
	this->numC = _c;
}

void Ciudad::pintar(){
	if (numC == 1){
		gotoxy3(x,y);
		Color2(3,12);printf("%c",220);
		Color2(3,6);printf("%c",219);
		Color2(3,14);printf("%c%c",220,220);
		Color2(3,7);printf("%c",219);
		Color2(3,12);printf("%c",220);
	}else if (numC == 2){
		
		gotoxy3(x,y+1);Color2(3,1);printf("%c",47);
		gotoxy3(x+1,y);Color2(3,14);printf("%c%c%c%c%c",95,95,95,95,95);
		gotoxy3(x+2,y+1);Color2(3,5);printf("%c",220);
		gotoxy3(x+3,y+1);Color2(3,14);printf("%c",219);
		gotoxy3(x+4,y+1);Color2(3,4);printf("%c",220);
		gotoxy3(x+6,y+1);Color2(3,1);printf("%c",92);
	}else if (numC == 3){
		gotoxy3(x,y);Color2(3,0);printf("%c%c",185,204);
	}else if (numC == 4){
		gotoxy3(x,y);Color2(3,4);printf("%c%c",178,178);
	}else if (numC == 5){
		gotoxy3(x,y);Color2(3,5);printf("%c%c%c%c%c",47,197, 219, 197,92);
	}else if (numC == 6){
		gotoxy3(x,y);Color2(3,14);printf("%c",219);
	}
	SetColor3(15);
}
