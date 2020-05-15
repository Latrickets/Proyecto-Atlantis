#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

#include "Torretas.h"
#include "Enemigo.h"
#include "Ciudad.h"
#include "Bala.h"
using namespace std;
void SetColor(int ForgC) 
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
void Color(int Background, int Text){ // Función para cambiar el color del fondo y/o pantalla

 HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE); // Tomamos la consola.

 // Para cambiar el color, se utilizan números desde el 0 hasta el 255.
 // Pero, para convertir los colores a un valor adecuado, se realiza el siguiente cálculo.
 int    New_Color= Text + (Background * 16);

 SetConsoleTextAttribute(Console, New_Color); // Guardamos los cambios en la Consola.
}
void OcultarCursor (){
HANDLE hCon;
hCon = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO cci;
cci.dwSize = 2;
cci.bVisible = false;

SetConsoleCursorInfo(hCon, &cci);

}

void gotoxy(int x, int y){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}

void titulo(int textos){
	if (textos == 1){
    gotoxy(9,0);SetColor(4);cout<<" _______ _________ _        _______  _       __________________ _______ \n";
	gotoxy(9,1);SetColor(4);cout<<"(  ___  )\\__   __/( \\      (  ___  )( (    /|\\__   __/\\__   __/(  ____ \\\n";
	gotoxy(9,2);SetColor(12);cout<<"| (   ) |   ) (   | (      | (   ) ||  \\  ( |   ) (      ) (   | (    \\/\n";
    gotoxy(9,3);SetColor(12);cout<<"| (___) |   | |   | |      | (___) ||   \\ | |   | |      | |   | (_____ \n";
    gotoxy(9,4);SetColor(14);cout<<"|  ___  |   | |   | |      |  ___  || (\\ \\) |   | |      | |   (_____  )\n";
    gotoxy(9,5);SetColor(2);cout<<"| (   ) |   | |   | |      | (   ) || | \\   |   | |      | |         ) |\n";
    gotoxy(9,6);SetColor(1);cout<<"| )   ( |   | |   | (____/\\| )   ( || )  \\  |   | |   ___) (___/\\____) |\n";
    gotoxy(9,7);SetColor(5);cout<<"|/     \\|   )_(   (_______/|/     \\||/    )_)   )_(   \\_______/\\_______)\n";
    gotoxy(9,8);cout<<"                                                                        "<<endl;
    SetColor(15);
    
    }else if(textos == 2){
    	gotoxy(35,0);cout<<"Instrucciones";
    	gotoxy(8,2);cout<<"Destruye todas las naves enemigas antes de que destruyan la ciudad.";
    	gotoxy(8,3);cout<<"Disparo nave central:";
    	gotoxy(8,4);cout<<"Presionando la tecla espacio.";
    	gotoxy(8,5);cout<<"Disparo nave lateral izquierda:";
    	gotoxy(8,6);cout<<"Presiona la tecla izquierda.";
    	gotoxy(8,7);cout<<"Disparo nave lateral derecha:";
    	gotoxy(8,8);cout<<"Presiona la tecla derecha y espacio.";
	}else if(textos == 3){
		gotoxy(37,0);cout<<"Creditos";
		gotoxy(8,3);cout<<"Creado por: ";
		gotoxy(8,4);SetColor(1);cout<<"Evelyn Gonzalez Aragon";
		gotoxy(8,5);SetColor(5);cout<<"Angel Duarte Amador";
		SetColor(15);
	}
}


int menu(string opc[100],int cant_opc,int textos){
	OcultarCursor();
	//Funcion para saber en que opci?n estamos
	bool escape = true;
	int tecla;
	int opc_sel = 1;
	do{
		system("cls");
		titulo(textos);
		//posicion de nuestro seleccionador
		gotoxy(34,11+opc_sel);cout<<"->";
		//Mostrar las opciones al jugador
		for (int i = 0; i < cant_opc; i++){
			gotoxy(37,12+i);cout<<i+1<<". "<<opc[i];
		}
		
		//Recibir la tecla arriba, abajo y enter
		do{
			tecla = getch();
		}while(tecla != 72 && tecla !=80 && tecla != 13);
		
		switch(tecla){
			case 72:
				opc_sel--;
				if (opc_sel < 1){
					opc_sel = cant_opc;
				}
				break;
			case 80:
				opc_sel++;
				if (opc_sel > cant_opc){
					opc_sel = 1;
				}
				break;
			case 13:
				escape = false;
				break;
		}
	}while(escape);
	return opc_sel;
}
void creditos(){
	string opcs[100] = {"Volver"};
	int seleccion,tecla;
	bool escape= true;
	int cant_opc = 1,textos = 3;
	do{
		seleccion = menu(opcs,cant_opc,textos);
		switch(seleccion){
			case 1:
				escape = false;
				break;
		}
	}while(escape);
}
void instrucciones(){
	string opcs[100] = {"Volver"};
	int seleccion,tecla;
	bool escape= true;
	int cant_opc = 1,textos = 2;
	do{
		seleccion = menu(opcs,cant_opc,textos);
		switch(seleccion){
			case 1:
				escape = false;
				break;
		}
	}while(escape);
}
void menu_general(){
	string opcs[100] = {"Jugar", "Instrucciones", "Creditos", "Salir"};
	int seleccion;
	bool escape = true;
	int cant_opc = 4,textos = 1;
	do{
		seleccion = menu(opcs,cant_opc,textos);
		switch(seleccion){
			case 1:
				break;
			case 2:
				instrucciones();
				break;
			case 3:
				creditos();
				break;
			case 4:
				escape=false;
				break;
		}
	}while(escape);
}

void escenario(){
	
	//piso abajo
	SetColor(8);
	for (int i = 0; i < 88; i++){
		gotoxy(i, 24); printf("%c", 219);
		gotoxy(i, 25); printf("%c", 219);
		gotoxy(i, 26); printf("%c", 219);
		gotoxy(i, 27); printf("%c", 219);
		gotoxy(i, 28); printf("%c", 219);
		gotoxy(i, 29); printf("%c", 219);
	}
	//piso del escenario
	SetColor(2);
	for(int i = 0; i < 88; i++){
		gotoxy(i, 23);printf("%c",219);
	}
	//estructura torreta 1
	for(int i = 0; i < 5; i++){
		gotoxy(i,18);printf("%c",219);
	}
	for(int i = 0; i < 6; i++){
		gotoxy(i,19);printf("%c",219);
		gotoxy(i,20);printf("%c",219);
		gotoxy(i,21);printf("%c",219);
		gotoxy(i,22);printf("%c",219);
	}
	for(int i = 6; i < 8; i++){
		gotoxy(i,21);printf("%c",219);
		gotoxy(i,22);printf("%c",219);
	}
	//estructura torreta 2
	for(int i = 42; i <46; i++){
		gotoxy(i,16);printf("%c",219);
		gotoxy(i,17);printf("%c",219);
	}
	for(int i = 40; i <50; i++){	
		gotoxy(i,18);printf("%c",219);
		gotoxy(i,19);printf("%c",219);
		gotoxy(i,20);printf("%c",219);
		gotoxy(i,21);printf("%c",219);
		gotoxy(i,22);printf("%c",219);
	}
	for(int i = 36; i < 40; i++){
		gotoxy(i,20);printf("%c",219);
		gotoxy(i,21);printf("%c",219);
		gotoxy(i,22);printf("%c",219);
	}
	//estructura cupula 1
	for(int i = 18; i < 33; i++){
		gotoxy(i,21);printf("%c",219);
		gotoxy(i,22);printf("%c",219);
	}
	for(int i = 16; i < 18; i++){
		gotoxy(i,22);printf("%c",219);
	}
	//estructura cupula 2
	for(int i = 50; i < 52; i++){
		gotoxy(i,20);printf("%c",219);
		gotoxy(i,21);printf("%c",219);
		gotoxy(i,22);printf("%c",219);
	}
	for(int i = 52; i < 54; i++){
		gotoxy(i,21);printf("%c",219);
		gotoxy(i,22);printf("%c",219);
	}
	for(int i = 62; i < 64; i++){
		gotoxy(i,21);printf("%c",219);
		gotoxy(i,22);printf("%c",219);
	}
	for(int i = 64; i < 73; i++){
		gotoxy(i,20);printf("%c",219);
		gotoxy(i,21);printf("%c",219);
		gotoxy(i,22);printf("%c",219);
	}
	//estructura torreta 3
	for(int i = 73; i < 75; i++){
		gotoxy(i,21);printf("%c",219);
		gotoxy(i,22);printf("%c",219);
	}
	for(int i = 75; i < 79; i++){
		gotoxy(i,19);printf("%c",219);
		gotoxy(i,20);printf("%c",219);
		gotoxy(i,21);printf("%c",219);
		gotoxy(i,22);printf("%c",219);
	}
	for(int i = 79; i < 83; i++){
		gotoxy(i,18);printf("%c",219);
		gotoxy(i,19);printf("%c",219);
		gotoxy(i,20);printf("%c",219);
		gotoxy(i,21);printf("%c",219);
		gotoxy(i,22);printf("%c",219);
	}
	for(int i = 83; i < 84; i++){
		gotoxy(i,17);printf("%c",219);
		gotoxy(i,18);printf("%c",219);
		gotoxy(i,19);printf("%c",219);
		gotoxy(i,20);printf("%c",219);
		gotoxy(i,21);printf("%c",219);
		gotoxy(i,22);printf("%c",219);
	}
	for(int i = 84; i < 88; i++){
		gotoxy(i,16);printf("%c",219);
		gotoxy(i,17);printf("%c",219);
		gotoxy(i,18);printf("%c",219);
		gotoxy(i,19);printf("%c",219);
		gotoxy(i,20);printf("%c",219);
		gotoxy(i,21);printf("%c",219);
		gotoxy(i,22);printf("%c",219);
	}
	
	SetColor(15);
}

void fondo(){
	Color(3,3);
	for (int i = 0; i < 88; i++){
		gotoxy(i,17);printf(" ");
		gotoxy(i,18);printf(" ");
		gotoxy(i,19);printf(" ");
		gotoxy(i,20);printf(" ");
		gotoxy(i,21);printf(" ");
		gotoxy(i,22);printf(" ");
	}
	Color(0,15);
}
int main() {
	menu_general();
	system("cls");
	OcultarCursor();
	fondo();
	escenario();
	//Juego.
	/*char soundfile[] = "Sounds/disparo1.wav";
	cout<<PlaySound((LPCSTR)soundfile, NULL, SND_FILENAME | SND_ASYNC );
	*/
	//variables en general
	int opc;
	int nivel = 1;
	bool on = true;
	int tecla,disparo=0;
	//Declarar objetos a usar
	Torretas torreta_I(2,15,1,2), torreta_M(43,13,1,1),torreta_D(85,13,1,3);
	Ciudad ciudad_1(9,22,1,1), ciudad_2(22,19,1,2), ciudad_3(37,19,1,3), ciudad_4(47,17,1,4), ciudad_5(55,20,1,5),ciudad_6(81,17,1,6);
	Enemigo enemigo_1(84,3,1,1);
	Bala bala_T(torreta_M.X(),torreta_M.Y()-1);
//---------------------------------------------------------------------
	torreta_I.pintar();
	torreta_M.pintar();
	torreta_D.pintar();
	ciudad_1.pintar();
	ciudad_2.pintar();
	ciudad_3.pintar();
	ciudad_4.pintar();
	ciudad_5.pintar();
	ciudad_6.pintar();
	enemigo_1.pintar();
	while(on){
		if(nivel == 1){
			escenario();
			Sleep(20);
			enemigo_1.destruir();
			if(kbhit()){
				tecla = getch();
				if(tecla == 32){
					disparo = 1;
					tecla = -1;
				}
		    }
		    bala_T.borrar();
		    if(disparo == 1){
		    	bala_T.movimiento();
		    	bala_T.pintar();
		    	if(bala_T.ybala() == 0){
		    		disparo = 0;
				}
			}
		    enemigo_1.movimiento();
		    enemigo_1.pintar();
		}
	}
	return 0;
}


