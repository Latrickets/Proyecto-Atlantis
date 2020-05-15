#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

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
    gotoxy(22,0);cout<<" _______ _________ _        _______  _       __________________ _______ \n";
	gotoxy(22,1);cout<<"(  ___  )\\__   __/( \\      (  ___  )( (    /|\\__   __/\\__   __/(  ____ \\\n";
	gotoxy(22,2);cout<<"| (   ) |   ) (   | (      | (   ) ||  \\  ( |   ) (      ) (   | (    \\/\n";
    gotoxy(22,3);cout<<"| (___) |   | |   | |      | (___) ||   \\ | |   | |      | |   | (_____ \n";
    gotoxy(22,4);cout<<"|  ___  |   | |   | |      |  ___  || (\\ \\) |   | |      | |   (_____  )\n";
    gotoxy(22,5);cout<<"| (   ) |   | |   | |      | (   ) || | \\   |   | |      | |         ) |\n";
    gotoxy(22,6);cout<<"| )   ( |   | |   | (____/\\| )   ( || )  \\  |   | |   ___) (___/\\____) |\n";
    gotoxy(22,7);cout<<"|/     \\|   )_(   (_______/|/     \\||/    )_)   )_(   \\_______/\\_______)\n";
    gotoxy(22,8);cout<<"                                                                        "<<endl;
    }else if(textos == 2){
    	gotoxy(8,1);cout<<"Destruye todas las naves enemigas antes de que destruyan la ciudad.";
    	gotoxy(8,2);cout<<"Disparo nave central:";
    	gotoxy(8,3);cout<<"Presionando la tecla espacio.";
    	gotoxy(8,5);cout<<"Disparo nave lateral izquierda:";
    	gotoxy(8,6);cout<<"Presiona la tecla izquierda.";
    	gotoxy(8,8);cout<<"Disparo nave lateral derecha:";
    	gotoxy(8,9);cout<<"Presiona la tecla derecha y espacio.";
	}else if(textos == 3){
		gotoxy(8,3);cout<<"Creado por: ";
		gotoxy(8,4);cout<<"Evelyn Gonzalez Aragon";
		gotoxy(8,5);cout<<"Angel Duarte Amador";
	}
}


int menu(string opc[100],int cant_opc,int textos){
	//Funcion para saber en que opción estamos
	bool escape = true;
	int tecla;
	int opc_sel = 1;
	do{
		system("cls");
		titulo(textos);
		//posicion de nuestro seleccionador
		gotoxy(5,9+opc_sel);cout<<"->";
		//Mostrar las opciones al jugador
		for (int i = 0; i < cant_opc; i++){
			gotoxy(10,10+i);cout<<i+1<<". "<<opc[i];
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

int main() {
	menu_general();
	return 0;
}

