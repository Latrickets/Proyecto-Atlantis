#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <MMSystem.h>
#include <ctime>

#include "Torretas.h"
#include "Enemigo.h"
#include "Ciudad.h"
#include "Bala.h"
using namespace std;
Enemigo enemigos1[3];
Enemigo enemigos2[2], enemigos2_2[2], enemigos2_3[1];
Enemigo enemigos3[3], enemigos3_2[2], enemigos3_3[2];
Enemigo enemigos4[2], enemigos4_2[1];
Bala balas_E1[3];
Bala balas_E2[2], balas_E2_2[2], balas_E2_3[1];
Bala balas_E3[3], balas_E3_2[2], balas_E3_3[2];
Bala balas_E4[2], balas_E4_2[1];
Torretas torres[3];
Ciudad ciudades[6];
Bala balas_T[3];
void menu_general();
//posicion random de las balas enemigos 1
int num_R[3] = {0,0,0};
bool mover_bal[3] = {false,false,false}, disparados[3] = {false,false,false};
//posicion 2
int num_R2[5] = {0,0,0,0,0};
bool mover_bal2[5] = {false,false,false,false,false}, disparados2[5] = {false,false,false,false,false};
//posicion 3
int num_R3[7] = {0,0,0,0,0,0,0};
bool mover_bal3[7] = {false,false,false,false,false,false,false}, disparados3[7] = {false,false,false,false,false,false,false};
//posicion 4
int num_R4[3] = {0,0,0};
bool mover_bal4[3] = {false,false,false}, disparados4[3] = {false,false,false};
//variables controladoras generales del juego
int cant_ciudades = 6;
int cant_torretas = 3;
int cant_enemigos[4] = {3,5,7,3};
int nivel = 1;
//Variables controladoras de oleadas
int num_oleada = 1;
int danio = 1;
//----------------------------------------------------------------------------
struct console{
  console( unsigned width, unsigned height )
    {
    SMALL_RECT r;
    COORD      c;
    hConOut = GetStdHandle( STD_OUTPUT_HANDLE );

    r.Left   =
    r.Top    = 0;
    r.Right  = width -1;
    r.Bottom = height -1;
    SetConsoleWindowInfo( hConOut, TRUE, &r );

    c.X = width;
    c.Y = height;
    SetConsoleScreenBufferSize( hConOut, c );
    }

  ~console()
    {
    SetConsoleTextAttribute(    hConOut,        csbi.wAttributes );
    SetConsoleScreenBufferSize( hConOut,        csbi.dwSize      );
    SetConsoleWindowInfo(       hConOut, TRUE, &csbi.srWindow    );
    }

  void color( WORD color = 0x07 )
    {
    SetConsoleTextAttribute( hConOut, color );
    }

  HANDLE                     hConOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  };
//----------------------------------------------------------------------------
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
		gotoxy(8,4);SetColor(1);cout<<"Evelyn Gonzalez Aragon.";
		gotoxy(8,5);SetColor(5);cout<<"Angel Duarte Amador.";
		gotoxy(8,6);SetColor(2);cout<<"Universidad Autonoma de Baja California Sur.";
		gotoxy(8,7);SetColor(2);cout<<"Departamento Academico de Sistemas Computacionales.";
		gotoxy(8,8);SetColor(4);cout<<"Programacion I.";
		gotoxy(8,9);SetColor(4);cout<<"Jonathan Giovanni Soto Muñoz.";
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
void ini_nivel1(){
	torres[0].crear(2,15,1,2); torres[1].crear(43,13,1,1); torres[2].crear(85,13,1,3);
	//izquierda a derecha
	enemigos1[0].crear(0,2,2,1,1);
	//derecha a izquierda
	enemigos1[1].crear(84,5,2,1,0);
	enemigos1[2].crear(60,5,2,1,0);
	//ciudades
	ciudades[0].crear(9,22,1,1); ciudades[1].crear(22,19,1,2); ciudades[2].crear(37,19,1,3); ciudades[3].crear(47,17,1,4);
	ciudades[4].crear(55,20,1,5); ciudades[5].crear(81,17,1,6);
	//balas central
	balas_T[0].crear(torres[1].X(),torres[1].Y()-1,0);
	balas_T[3].crear(torres[1].X(),torres[1].Y()-1,0);
	//balas izquierda
	balas_T[1].crear(torres[0].X()+2, torres[0].Y()-1,1);
	balas_T[4].crear(torres[0].X()+2, torres[0].Y()-1,1);
	//balas derecha
	balas_T[2].crear(torres[2].X()-2, torres[2].Y()-1,2);
	balas_T[5].crear(torres[2].X()-2, torres[2].Y()-1,2);
	//balas de enemigos
	balas_E1[0].crear(0, 0,3);
	balas_E1[1].crear(0, 0,3);
	balas_E1[2].crear(0, 0,3);
	// enemigos nivel 2
	enemigos2[0].crear(0,2,1,2,1); /*izquierda a derecha*/ balas_E2[0].crear(0, 0,3);
	enemigos2[1].crear(84,5,1,1,0); /*derecha a izquierda*/balas_E2[1].crear(0, 0,3);
	enemigos2_2[0].crear(0,2,1,1,1); /*izquierda a derecha*/ balas_E2_2[0].crear(0, 0,3);
	enemigos2_2[1].crear(84,5,1,2,0); /*derecha a izquierda*/balas_E2_2[1].crear(0, 0,3);
	enemigos2_3[0].crear(0,2,1,2,1); /*izquierda a derecha*/ balas_E2_3[0].crear(0, 0,3);
	//enemigos nivel 3
	enemigos3[0].crear(0,2,2,2,1); /*izquierda a derecha*/ balas_E3[0].crear(0, 0,3);
	enemigos3[1].crear(10,5,2,1,1); /*izquierda a derecha*/balas_E3[1].crear(0, 0,3);
	enemigos3[2].crear(84,2,2,2,0); /*derecha a izquierda*/balas_E3[2].crear(0, 0,3);

	enemigos3_2[0].crear(0,2,2,1,1); /*izquierda a derecha*/ balas_E3_2[0].crear(0, 0,3);
	enemigos3_2[1].crear(84,5,2,2,0); /*derecha a izquierda*/balas_E3_2[1].crear(0, 0,3);
	
	enemigos3_3[0].crear(0,2,2,1,1); /*izquierda a derecha*/ balas_E3_3[0].crear(0, 0,3);
	enemigos3_3[1].crear(84,5,2,1,0); /*derecha a izquierda*/ balas_E3_3[1].crear(0, 0,3);
	//enemigos nivel final
	enemigos4[0].crear(0,2,2,2,1); /*izquierda a derecha*/ balas_E4[0].crear(0, 0,3);
	enemigos4[1].crear(84,5,2,2,0); /*derecha a izquierda*/balas_E4[1].crear(0, 0,3);
	enemigos4_2[0].crear(40, 5,8,3,1); balas_E4_2[0].crear(0,0,3);
}
int col_ciudades(Bala balitas[],int bal){ //colision balas enemigos.
	if(ciudades[0].getNC() == 1){
		// ciudades
		if (balitas[bal].xbala() >= ciudades[0].getX() && balitas[bal].xbala() < ciudades[0].getX()+6 && balitas[bal].ybala() >= ciudades[0].getY() && balitas[bal].ybala() < ciudades[0].getY()+2){
			Color(3,3);
			ciudades[0].borrar();
			Color(0,15);
			ciudades[0].destruct();
			cant_ciudades -= 1;
			return 1;
		}
		if (balitas[bal].xbala() >= ciudades[1].getX() && balitas[bal].xbala() < ciudades[1].getX()+6 && balitas[bal].ybala() >= ciudades[1].getY() && balitas[bal].ybala() < ciudades[1].getY()+2){
			Color(3,3);
			ciudades[1].borrar();
			Color(0,15);
			ciudades[1].destruct();
			cant_ciudades -= 1;
			return 1;
		}
		if (balitas[bal].xbala() >= ciudades[2].getX() && balitas[bal].xbala() < ciudades[2].getX()+2 && balitas[bal].ybala() >= ciudades[2].getY() && balitas[bal].ybala() < ciudades[2].getY()+2){
			Color(3,3);
			ciudades[2].borrar();
			Color(0,15);
			ciudades[2].destruct();
			cant_ciudades -= 1;
			return 1;
		}
		if (balitas[bal].xbala() >= ciudades[3].getX() && balitas[bal].xbala() < ciudades[3].getX()+2 && balitas[bal].ybala() >= ciudades[3].getY() && balitas[bal].ybala() < ciudades[3].getY()+2){
			Color(3,3);
			ciudades[3].borrar();
			Color(0,15);
			ciudades[3].destruct();
			cant_ciudades -= 1;
			return 1;
		}
		if (balitas[bal].xbala() >= ciudades[4].getX() && balitas[bal].xbala() < ciudades[4].getX()+6 && balitas[bal].ybala() >= ciudades[4].getY() && balitas[bal].ybala() < ciudades[4].getY()+2){
			Color(3,3);
			ciudades[4].borrar();
			Color(0,15);
			ciudades[4].destruct();
			cant_ciudades -= 1;
			return 1;
		}
		if (balitas[bal].xbala() >= ciudades[5].getX() && balitas[bal].xbala() < ciudades[5].getX()+1 && balitas[bal].ybala() >= ciudades[5].getY() && balitas[bal].ybala() < ciudades[5].getY()+2){
			Color(3,3);
			ciudades[5].borrar();
			Color(0,15);
			ciudades[5].destruct();
			cant_ciudades -= 1;
			return 1;
		}
		// torretas
		for(int k = 0; k < 3; ++k){
			if (balitas[bal].xbala() >= torres[k].X() && balitas[bal].xbala() < torres[k].X()+2 && balitas[bal].ybala() >= torres[k].Y() && balitas[bal].ybala() < torres[k].Y()+2){
				torres[k].setV(0);
				cant_torretas -= 1;
				return 1;
			}	
		}
		return 0;
	}
}
int dispEnemigo(int x, Bala balitas[], Enemigo enemys[]){
	srand(time(NULL));
	if(balitas[x].ybala() == 0){ // randomizamos la posicion al iniciar
		num_R[x] = 2 + rand() % (88-2);
		mover_bal[x] = false;
		disparados[x] = false;
	}
	if(enemys[x].Vidas() >= 1){ //bala aleatoria 1
		if(num_R[x] < 2 || num_R[x] > 84){
			while(true){
				num_R[x] = 2 + rand() % (86-2);
				if(num_R[x] > 1 && num_R[x] < 85){
					break;
				}
			}
		}
		if(num_R[x] == enemys[x].xEne() && disparados[x] == false){
			mover_bal[x] = true;
			disparados[x] = true;
			balitas[x].setY(enemys[x].yEne()+2);
			balitas[x].setX(enemys[x].xEne()+1);
			PlaySound(TEXT("Sounds/disparo1.wav"), NULL, SND_ASYNC);
			}else{}
		if(mover_bal[x] == true && disparados[x] == true){
			if (col_ciudades(balitas,x) == 1){ // si choco con una ciudad o torreta
				num_R[x] = 2 + rand() % (86-2);
				mover_bal[x] = false;
				disparados[x] = false;
			}else{}
			if(balitas[x].ybala() >= 22){
				num_R[x] = 2 + rand() % (86-2);
				Color(3,3);
				balitas[x].borrar();
				Color(0,15);
				mover_bal[x] = false;
				disparados[x] = false;
			}else{}
			if(balitas[x].ybala() >= 17){
				Color(3,3);
				balitas[x].borrar();
				balitas[x].movimiento();
				balitas[x].pintar();
				Color(0,15);
			}else{
				Color(0,15);
				balitas[x].borrar();
				balitas[x].movimiento();
				balitas[x].pintar();
				}
			}else{}
		}else{
			balitas[x].setX(89);
			balitas[x].setY(28);
			balitas[x].borrar();
			mover_bal[x] = false;
			disparados[x] = false;
		}
}
int movEnemigo(int x, Enemigo enemys[]){
	if(enemys[x].Vidas() >= 1){
		enemys[x].destruir();
		enemys[x].movimiento();
		enemys[x].pintar();
	}else{
		enemys[x].destruir();
		enemys[x].destruct();
	}
}
bool colisionT(Enemigo enemys[], Bala balitas[], int tam, int num_enemys){ // Colision a enemigos nivel 1
	for(int j = 0; j < 3; ++j){
		for(int i = 0; i < tam; ++i){
			if(balas_T[j].xbala() >= enemys[i].xEne() && balas_T[j].xbala() < enemys[i].xEne()+4 && balas_T[j].ybala() >= enemys[i].yEne() && balas_T[j].ybala() < enemys[i].yEne()+3){
				enemys[i].destruir();
				enemys[i].sVidas(danio);
				if(enemys[i].Vidas() <= 0){
					enemigos1[i].destruct();
					cant_enemigos[num_enemys] -= 1;
				}
				if(balitas[i].ybala() >=17){
					Color(3,3);
					balitas[i].borrar();
					Color(0,15);
				}else{
					balitas[i].borrar();
				}
				return true;
			}
		}
	}
	return false;
}
int movbalaT(int x, int _disp, Enemigo enemys[], Bala balitas[], int tam, int num_enemys){ // Movimiento y colision a enemigos
	Color(0,15);
	balas_T[x].borrar();
	balas_T[x].movimiento();
	balas_T[x].pintar();
	if(colisionT(enemys,balitas, tam, num_enemys) == true){
		balas_T[x].borrar();
		balas_T[x].setY(0);
		_disp = 0;
		return _disp;
	}
	if(balas_T[x].ybala() == 0){
		balas_T[x].borrar();
		_disp = 0;
		return _disp;
	}
	return _disp;
}
void rutina_enemigos1(Bala balitas[], Enemigo enemys[], int tam){
	//mover enemigos y disparar
	for (int i = 0; i < tam; i++){
		movEnemigo(i, enemys);
		dispEnemigo(i, balitas, enemys);
	}
}
void rutina_enemigos2_1(Bala balitas[], Enemigo enemys[], int tam){
	for (int i = 0; i < 2; i++){
		if(enemys[i].getnumE() == 2){
			movEnemigo(i, enemys);
		    dispEnemigo(i, balitas, enemys);
		    movEnemigo(i, enemys);
		    dispEnemigo(i, balitas, enemys);
		}else{
			movEnemigo(i, enemys);
			dispEnemigo(i, balitas, enemys);	
		}
	}
	int vi = 0;
	for (int m = 0; m < 2; m++){
		if(enemys[m].Vidas() <= 0){
			vi += 1;
		}
	}
	if (vi == 2){
		num_oleada = 2;
		for (int i = 0; i < 2; i++){
			enemys[i].destruir();
			enemys[i].destruct();
			balitas[i].setX(89);
			balitas[i].setY(28);
			balitas[i].borrar();
		}
	}
}
void rutina_enemigos2_2(Bala balitas[], Enemigo enemys[], int tam){
	for (int i = 0; i < 2; i++){
		if(enemys[i].getnumE() == 2){
			movEnemigo(i, enemys);
		    dispEnemigo(i, balitas, enemys);
		    movEnemigo(i, enemys);
		    dispEnemigo(i, balitas, enemys);
		}else{
			movEnemigo(i, enemys);
			dispEnemigo(i, balitas, enemys);	
		}
	}
	int vi = 0;
	for (int m = 0; m < 2; m++){
		if(enemys[m].Vidas() <= 0){
			vi += 1;
		}
	}
	if (vi == 2){
		num_oleada = 3;
		for (int i = 0; i < 2; i++){
			enemys[i].destruir();
			enemys[i].destruct();
			balitas[i].setX(89);
			balitas[i].setY(28);
			balitas[i].borrar();
		}
	}
}
void rutina_enemigos2_3(Bala balitas[], Enemigo enemys[], int tam){
	for (int i = 0; i < 1; i++){
		if(enemys[i].getnumE() == 2){
			movEnemigo(i, enemys);
		    dispEnemigo(i, balitas, enemys);
		    movEnemigo(i, enemys);
		    dispEnemigo(i, balitas, enemys);
		}else{
			movEnemigo(i, enemys);
			dispEnemigo(i, balitas, enemys);	
		}
	}
	int vi = 0;
	for (int m = 0; m < 1; m++){
		if(enemys[m].Vidas() <= 0){
			vi += 1;
		}
	}
	if (vi == 1){
		num_oleada = 1;
		for (int i = 0; i < 1; i++){
			enemys[i].destruir();
			enemys[i].destruct();
			balitas[i].setX(89);
			balitas[i].setY(28);
			balitas[i].borrar();
		}
	}
}
void rutina_enemigos3_1(Bala balitas[], Enemigo enemys[], int tam){
	for (int i = 0; i < 3; i++){
		if(enemys[i].getnumE() == 2){
			movEnemigo(i, enemys);
		    dispEnemigo(i, balitas, enemys);
		    movEnemigo(i, enemys);
		    dispEnemigo(i, balitas, enemys);
		}else{
			movEnemigo(i, enemys);
			dispEnemigo(i, balitas, enemys);	
		}
	}
	int vi = 0;
	for (int m = 0; m < 3; m++){
		if(enemys[m].Vidas() <= 0){
			vi += 1;
		}
	}
	if (vi == 3){
		num_oleada = 2;
		for (int i = 0; i < 3; i++){
			enemys[i].destruir();
			enemys[i].destruct();
			balitas[i].setX(89);
			balitas[i].setY(28);
			balitas[i].borrar();
		}
	}
}
void rutina_enemigos3_2(Bala balitas[], Enemigo enemys[], int tam){
	for (int i = 0; i < 2; i++){
		if(enemys[i].getnumE() == 2){
			movEnemigo(i, enemys);
		    dispEnemigo(i, balitas, enemys);
		    movEnemigo(i, enemys);
		    dispEnemigo(i, balitas, enemys);
		}else{
			movEnemigo(i, enemys);
			dispEnemigo(i, balitas, enemys);	
		}
	}
	int vi = 0;
	for (int m = 0; m < 2; m++){
		if(enemys[m].Vidas() <= 0){
			vi += 1;
		}
	}
	if (vi == 2){
		num_oleada = 3;
		for (int i = 0; i < 2; i++){
			enemys[i].destruir();
			enemys[i].destruct();
			balitas[i].setX(89);
			balitas[i].setY(28);
			balitas[i].borrar();
		}
	}
}
void rutina_enemigos3_3(Bala balitas[], Enemigo enemys[], int tam){
	for (int i = 0; i < 2; i++){
		if(enemys[i].getnumE() == 2){
			movEnemigo(i, enemys);
		    dispEnemigo(i, balitas, enemys);
		    movEnemigo(i, enemys);
		    dispEnemigo(i, balitas, enemys);
		}else{
			movEnemigo(i, enemys);
			dispEnemigo(i, balitas, enemys);	
		}
	}
	int vi = 0;
	for (int m = 0; m < 2; m++){
		if(enemys[m].Vidas() <= 0){
			vi += 1;
		}
	}
	if (vi == 2){
		num_oleada = 1;
		for (int i = 0; i < 2; i++){
			enemys[i].destruir();
			enemys[i].destruct();
			balitas[i].setX(89);
			balitas[i].setY(28);
			balitas[i].borrar();
		}
	}
}
void rutina_enemigos4_1(Bala balitas[], Enemigo enemys[], int tam){
	for (int i = 0; i < 2; i++){
		if(enemys[i].getnumE() == 2){
			movEnemigo(i, enemys);
		    dispEnemigo(i, balitas, enemys);
		    movEnemigo(i, enemys);
		    dispEnemigo(i, balitas, enemys);
		}else{
			movEnemigo(i, enemys);
			dispEnemigo(i, balitas, enemys);	
		}
	}
	int vi = 0;
	for (int m = 0; m < 2; m++){
		if(enemys[m].Vidas() <= 0){
			vi += 1;
		}
	}
	if (vi == 2){
		num_oleada = 2;
		for (int i = 0; i < 2; i++){
			enemys[i].destruir();
			enemys[i].destruct();
			balitas[i].setX(89);
			balitas[i].setY(28);
			balitas[i].borrar();
		}
	}
}
void rutina_enemigos4_2(Bala balitas[], Enemigo enemys[], int tam){
	for (int i = 0; i < 1; i++){
		if(enemys[i].getnumE() == 2){
			movEnemigo(i, enemys);
		    dispEnemigo(i, balitas, enemys);
		    movEnemigo(i, enemys);
		    dispEnemigo(i, balitas, enemys);
		}else{
			movEnemigo(i, enemys);
			dispEnemigo(i, balitas, enemys);	
		}
	}
	int vi = 0;
	for (int m = 0; m < 1; m++){
		if(enemys[m].Vidas() <= 0){
			vi += 1;
		}
	}
	if (vi == 1){
		num_oleada = 1;
		for (int i = 0; i < 1; i++){
			enemys[i].destruir();
			enemys[i].destruct();
			balitas[i].setX(89);
			balitas[i].setY(28);
			balitas[i].borrar();
		}
	}
}
void ganar(){
Color(0,2);
gotoxy(15,3);cout<<"  ____   ____  ____    ____  _____ ______    ___ ";
gotoxy(15,4);cout<<" /    | /    ||    \\  /    |/ ___/|      |  /  _]";
gotoxy(15,5);cout<<"|   __||  o  ||  _  ||  o  (   \\_ |      | /  [_ ";
gotoxy(15,6);cout<<"|  |  ||     ||  |  ||     |\\__  ||_|  |_||    _]";
gotoxy(15,7);cout<<"|  |_ ||  _  ||  |  ||  _  |/  \\ |  |  |  |   [_ ";
gotoxy(15,8);cout<<"|     ||  |  ||  |  ||  |  |\\    |  |  |  |     |";
gotoxy(15,9);cout<<"|___,_||__|__||__|__||__|__| \\___|  |__|  |_____|";
gotoxy(16,10);cout<<"Presiona enter para continuar.";
Color(0, 15);
}
void perder(){
Color(0,4);
gotoxy(15,3);cout<<" ____   ___  ____   ___    ____ _____ ______    ___ ";
gotoxy(15,4);cout<<"|    \\ /  _]|    \\ |   \\  |    / ___/|      |  /  _]";
gotoxy(15,5);cout<<"|  o  )  [_ |  D  )|    \\  |  (   \\_ |      | /  [_ ";
gotoxy(15,6);cout<<"|   _/    _]|    / |  D  | |  |\\__  ||_|  |_||    _]";
gotoxy(15,7);cout<<"|  | |   [_ |    \\ |     | |  |/  \\ |  |  |  |   [_ ";
gotoxy(15,8);cout<<"|  | |     ||  .  \\|     | |  |\\    |  |  |  |     |";
gotoxy(15,9);cout<<"|__| |_____||__|\\_||_____||____|\\___|  |__|  |_____|";
gotoxy(16,10);cout<<"Presiona enter para continuar.";
Color(0,15);
}
void jugar(){
	system("cls");
	OcultarCursor();
	fondo();
	escenario();
		//variables controladoras del juego
	int opc;
	bool on = true;
	int tecla;
	int nextlvl = 0;
	//controladores de los disparos torretas.
	int disparo=0;
	bool disparar = false;
	bool central = false, izq = false, der = false;
	//Declarar objetos a usar
	ini_nivel1();
	
	while(on){
		Color(0,15);
		for(int i = 0; i <3; i++){
				torres[i].pintar();
		}
		for(int i = 0; i < 6; i++){
			if (ciudades[i].getV() >= 1){
				ciudades[i].pintar();
			}
		}
		escenario();
		if (cant_torretas == 0){
			on = false;
			Color(0,15);
			system("cls");
			perder();
			do{
				tecla = getch();
			}while(tecla != 13);
		}
		if (cant_ciudades == 0){
			on = false;
			Color(0,15);
			system("cls");
			perder();
			do{
				tecla = getch();
			}while(tecla != 13);
		}
		if (nivel == 5){
			on = false;
			Color(0,15);
			system("cls");
			ganar();
			do{
				tecla = getch();
			}while(tecla != 13);
		}
		if(kbhit()){
				tecla = getch();
				if (tecla == 32){
					on = false;
					Color(0,15);
				}
				if(tecla == 80 && !central && !izq && !der && torres[1].getV() == 1){
					disparo = 1;
					central = true;
					PlaySound(TEXT("Sounds/disparo2.wav"), NULL,SND_ASYNC );
				}
				if(tecla == 75 && !central && !izq && !der && torres[0].getV() == 1){
					disparo = 2;
					izq = true;
					PlaySound(TEXT("Sounds/disparo2.wav"), NULL,SND_ASYNC );
				}
				if(tecla == 77 && !central && !izq && !der && torres[2].getV() == 1){
					disparo = 3;
					der = true;
					PlaySound(TEXT("Sounds/disparo2.wav"), NULL,SND_ASYNC );
				}
		    }
		if(nivel == 1){
			rutina_enemigos1(balas_E1, enemigos1, 3);
		    if(disparo == 1){
		    	disparo = movbalaT(0, disparo, enemigos1, balas_E1, 3, 0);
		    	if (disparo != 1){
		    		central = false;
				}
			}else if(disparo == 2){
				disparo = movbalaT(1, disparo, enemigos1, balas_E1, 3, 0);
				if (disparo != 2){
		    		izq = false;
				}
			}else if(disparo == 3){
				disparo = movbalaT(2, disparo, enemigos1, balas_E1, 3, 0);
				if (disparo != 3){
		    		der = false;
				}
			}
			nextlvl = 0;
			for(int n = 0; n < 3; n++){
				if(enemigos1[n].Vidas() == 0){
					nextlvl += 1;
				}
			}
			if(nextlvl == 3){
				nivel = 2;
				danio = 2;
				num_oleada = 1;
			}
		}else if(nivel == 2){
			if(num_oleada == 1){
				rutina_enemigos2_1(balas_E2, enemigos2, 2);
			}else if(num_oleada == 2){
				rutina_enemigos2_2(balas_E2_2, enemigos2_2, 2);
			}else if(num_oleada == 3){
				rutina_enemigos2_3(balas_E2_3, enemigos2_3, 1);
			}
		    if(disparo == 1){
		    	if(num_oleada == 1){
		    		disparo = movbalaT(0, disparo, enemigos2, balas_E2, 2, 1);	
				}else if(num_oleada == 2){
					disparo = movbalaT(0, disparo, enemigos2_2, balas_E2_2, 2, 1);
				}else if(num_oleada == 3){
					disparo = movbalaT(0, disparo, enemigos2_3, balas_E2_3, 1, 1);
				}else{}
		    	if (disparo != 1){
		    		central = false;
				}
			}else if(disparo == 2){
				if(num_oleada == 1){
		    		disparo = movbalaT(1, disparo, enemigos2, balas_E2, 2, 1);	
				}else if(num_oleada == 2){
					disparo = movbalaT(1, disparo, enemigos2_2, balas_E2_2, 2, 1);
				}else if(num_oleada == 3){
					disparo = movbalaT(1, disparo, enemigos2_3, balas_E2_3, 1, 1);
				}
				if (disparo != 2){
		    		izq = false;
				}
			}else if(disparo == 3){
				if(num_oleada == 1){
		    		disparo = movbalaT(2, disparo, enemigos2, balas_E2, 2, 1);
				}else if(num_oleada == 2){
					disparo = movbalaT(2, disparo, enemigos2_2, balas_E2_2, 2, 1);
				}else if(num_oleada == 3){
					disparo = movbalaT(2, disparo, enemigos2_3, balas_E2_3, 1, 1);
				}
				if (disparo != 3){
		    		der = false;
				}
			}
			nextlvl = 0;
			for(int n = 0; n < 2; n++){
				if(enemigos2[n].Vidas() <= 0){
					nextlvl += 1;
				}
			}
			for(int n = 0; n < 2; n++){
				if(enemigos2_2[n].Vidas() <= 0){
					nextlvl += 1;
				}
			}
			for(int n = 0; n < 1; n++){
				if(enemigos2_3[n].Vidas() <= 0){
					nextlvl += 1;
				}
			}
			if(nextlvl == 5){
				nivel = 3;
				torres[0].setV(1);
				torres[1].setV(1);
				torres[2].setV(1);
				cant_torretas = 3;
				num_oleada = 1;
			}
		}else if (nivel == 3){
			if(num_oleada == 1){
				rutina_enemigos3_1(balas_E3, enemigos3, 3);
			}else if(num_oleada == 2){
				rutina_enemigos3_2(balas_E3_2, enemigos3_2, 2);
			}else if(num_oleada == 3){
				rutina_enemigos3_3(balas_E3_3, enemigos3_3, 2);
			}
		    if(disparo == 1){
		    	if(num_oleada == 1){
		    		disparo = movbalaT(0, disparo, enemigos3, balas_E3, 3, 2);	
				}else if(num_oleada == 2){
					disparo = movbalaT(0, disparo, enemigos3_2, balas_E3_2, 2, 2);
				}else if(num_oleada == 3){
					disparo = movbalaT(0, disparo, enemigos3_3, balas_E3_3, 2, 2);
				}else{}
		    	if (disparo != 1){
		    		central = false;
				}
			}else if(disparo == 2){
				if(num_oleada == 1){
		    		disparo = movbalaT(1, disparo, enemigos3, balas_E3, 3, 2);	
				}else if(num_oleada == 2){
					disparo = movbalaT(1, disparo, enemigos3_2, balas_E3_2, 2, 2);
				}else if(num_oleada == 3){
					disparo = movbalaT(1, disparo, enemigos3_3, balas_E3_3, 2, 2);
				}
				if (disparo != 2){
		    		izq = false;
				}
			}else if(disparo == 3){
				if(num_oleada == 1){
		    		disparo = movbalaT(2, disparo, enemigos3, balas_E3, 3, 2);
				}else if(num_oleada == 2){
					disparo = movbalaT(2, disparo, enemigos3_2, balas_E3_2, 2, 2);
				}else if(num_oleada == 3){
					disparo = movbalaT(2, disparo, enemigos3_3, balas_E3_3, 2, 2);
				}
				if (disparo != 3){
		    		der = false;
				}
			}
			nextlvl = 0;
			for(int n = 0; n < 3; n++){
				if(enemigos3[n].Vidas() <= 0){
					nextlvl += 1;
				}
			}
			for(int n = 0; n < 2; n++){
				if(enemigos3_2[n].Vidas() <= 0){
					nextlvl += 1;
				}
			}
			for(int n = 0; n < 2; n++){
				if(enemigos3_3[n].Vidas() <= 0){
					nextlvl += 1;
				}
			}
			if(nextlvl == 7){
				num_oleada = 1;
				nivel = 4;
			}
		}else if (nivel == 4){
			if(num_oleada == 1){
				rutina_enemigos4_1(balas_E4, enemigos4, 2);
			}else if(num_oleada == 2){
				rutina_enemigos4_2(balas_E4_2, enemigos4_2, 1);
			}
		    if(disparo == 1){
		    	if(num_oleada == 1){
		    		disparo = movbalaT(0, disparo, enemigos4, balas_E4, 2, 3);	
				}else if(num_oleada == 2){
					disparo = movbalaT(0, disparo, enemigos4_2, balas_E4_2, 1, 3);
				}else{}
		    	if (disparo != 1){
		    		central = false;
				}
			}else if(disparo == 2){
				if(num_oleada == 1){
		    		disparo = movbalaT(1, disparo, enemigos4, balas_E4, 2, 3);	
				}else if(num_oleada == 2){
					disparo = movbalaT(1, disparo, enemigos4_2, balas_E4_2, 1, 3);
				}
				if (disparo != 2){
		    		izq = false;
				}
			}else if(disparo == 3){
				if(num_oleada == 1){
		    		disparo = movbalaT(2, disparo, enemigos4, balas_E4, 2, 3);
				}else if(num_oleada == 2){
					disparo = movbalaT(2, disparo, enemigos4_2, balas_E4_2, 1, 3);
				}
				if (disparo != 3){
		    		der = false;
				}
			}
			nextlvl = 0;
			for(int n = 0; n < 2; n++){
				if(enemigos4[n].Vidas() <= 0){
					nextlvl += 1;
				}
			}
			for(int n = 0; n < 1; n++){
				if(enemigos4_2[n].Vidas() <= 0){
					nextlvl += 1;
				}
			}
			if(nextlvl == 3){
				num_oleada = 1;
				nivel = 5;
			}
		}
	}
}
void reset(){
//posicion random de las balas enemigos 1
int num_R[3] = {0,0,0};
bool mover_bal[3] = {false,false,false}, disparados[3] = {false,false,false};
//posicion 2
int num_R2[5] = {0,0,0,0,0};
bool mover_bal2[5] = {false,false,false,false,false}, disparados2[5] = {false,false,false,false,false};
//posicion 3
int num_R3[7] = {0,0,0,0,0,0,0};
bool mover_bal3[7] = {false,false,false,false,false,false,false}, disparados3[7] = {false,false,false,false,false,false,false};
//posicion 4
int num_R4[3] = {0,0,0};
bool mover_bal4[3] = {false,false,false}, disparados4[3] = {false,false,false};
//variables controladoras generales del juego
cant_ciudades = 6;
cant_torretas = 3;
int cant_enemigos[4] = {3,5,7,3};
int nivel = 1;
//Variables controladoras de oleadas
int num_oleada = 1;
int danio = 1;
ini_nivel1();
}
void menu_general(){
	string opcs[100] = {"Jugar", "Instrucciones", "Creditos", "Salir"};
	int seleccion;
	bool escape = true;
	int cant_opc = 4,textos = 1;
	do{
		PlaySound(TEXT("Sounds/musica2.wav"), NULL, SND_ASYNC);
		seleccion = menu(opcs,cant_opc,textos);
		PlaySound(NULL, 0, 0);
		switch(seleccion){
			case 1:
				reset();
				jugar();
				break;
			case 2:
				instrucciones();
				break;
			case 3:
				creditos();
				break;
			case 4:
				escape=false;
				seleccion = -1;
				break;
		}
	}while(escape);
}

int main() {
	console con( 95, 30 );
	menu_general();
	return 0;
}
