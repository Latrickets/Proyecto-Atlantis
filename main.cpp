#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <ctime>

#include "Torretas.h"
#include "Enemigo.h"
#include "Ciudad.h"
#include "Bala.h"
using namespace std;
Enemigo enemigos1[3];
Enemigo enemigos2[5];
Enemigo enemigos3[7];
Enemigo enemigos4[3];
Torretas torres[3];
Ciudad ciudades[6];
Bala balas_T[3];

//posicion random de las balas enemigos 1
int num_R[3] = {0,0,0};
bool mover_bal[3] = {false,false,false}, disparados[3] = {false,false,false};
Bala balas_E1[3];
//posicion 2
int num_R2[5] = {0,0,0,0,0};
bool mover_bal2[5] = {false,false,false,false,false}, disparados2[5] = {false,false,false,false,false};
Bala balas_E2[5];
//posicion 3
int num_R3[7] = {0,0,0,0,0,0,0};
bool mover_bal3[7] = {false,false,false,false,false,false,false}, disparados3[7] = {false,false,false,false,false,false,false};
Bala balas_E3[7];
//posicion 4
int num_R4[3] = {0,0,0};
bool mover_bal4[3] = {false,false,false}, disparados4[3] = {false,false,false};
Bala balas_E4[3];
//variables controladoras generales del juego
int cant_ciudades = 6;
int cant_torretas = 3;
int cant_enemigos[4] = {3,5,7,3};
int nivel = 1;

//----------------------------------------------------------------------------
/*struct console
  {
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
*/
//----------------------------------------------------------------------------
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
void menu_general(){
	string opcs[100] = {"Jugar", "Instrucciones", "Creditos", "Salir"};
	int seleccion;
	bool escape = true;
	int cant_opc = 4,textos = 1;
	do{
		seleccion = menu(opcs,cant_opc,textos);
		switch(seleccion){
			case 1:
				escape = false;
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

void ini_nivel1(){
	torres[0].crear(2,15,1,2); torres[1].crear(43,13,1,1); torres[2].crear(85,13,1,3);
	//izquierda a derecha
	enemigos1[0].crear(0,2,1,1,1);
	//derecha a izquierda
	enemigos1[1].crear(84,5,1,1,0);
	enemigos1[2].crear(50,5,1,1,0);
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
	// enemigos
	enemigos2[0].crear(0,2,1,2,1); /*izquierda a derecha*/ balas_E2[0].crear(0, 0,3);
	enemigos2[1].crear(84,5,1,1,0); /*derecha a izquierda*/balas_E2[1].crear(0, 0,3);
	enemigos2[2].crear(0,2,1,1,1); /*izquierda a derecha*/ balas_E2[2].crear(0, 0,3);
	enemigos2[3].crear(84,5,1,2,0); /*derecha a izquierda*/balas_E2[3].crear(0, 0,3);
	enemigos2[4].crear(0,2,1,2,1); /*izquierda a derecha*/ balas_E2[4].crear(0, 0,3);

}

bool colisionT(Enemigo enemys[], Bala balitas[], int tam, int num_enemys){ // Colision a enemigos nivel 1
	for(int j = 0; j < 3; ++j){
		for(int i = 0; i < tam; ++i){
			if(balas_T[j].xbala() >= enemys[i].xEne() && balas_T[j].xbala() < enemys[i].xEne()+4 && balas_T[j].ybala() >= enemys[i].yEne() && balas_T[j].ybala() < enemys[i].yEne()+3){
				enemys[i].destruir();
				enemys[i].sVidas(0);
				if(balitas[i].ybala() >=17){
					Color(3,3);
					balitas[i].borrar();
					Color(0,15);
				}else{
					balitas[i].borrar();	
				}
				cant_enemigos[num_enemys] -= 1;
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

int col_ciudades(Bala balitas[],int bal, int tam){ //colision balas enemigos.
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
				return 1;
			}	
		}
		return 0;
	}
}

void rutina_enemigos1(Bala balitas[], Enemigo enemys[], int tam){
	//mover enemigos nivel 1
	for(int i = 0; i < tam; i++){
		if (enemys[i].Vidas() >= 1){
			enemys[i].destruir();
			enemys[i].movimiento();
			enemys[i].pintar();
		}else{
			enemys[i].destruct();
			enemys[i].destruir();
		}
	}
	//disparos del nivel 1
	srand(time(NULL));
	for(int j = 0; j < tam; j++){
		if(balitas[j].ybala() == 0){ // randomizamos la posicion al iniciar
			num_R[j] = 2 + rand() % (88-2);
		}
		if(enemys[j].Vidas() >= 1){ //bala aleatoria 1
			if(num_R[j] < 2 || num_R[j] > 84){
				while(true){
					num_R[j] = 2 + rand() % (86-2);
					if(num_R[j] > 1 && num_R[j] < 85){
						break;
					}
				}
			}
			if(num_R[j] == enemys[j].xEne() && disparados[j] == false){
				mover_bal[j] = true;
				disparados[j] = true;
				balitas[j].setY(enemys[j].yEne()+2);
				balitas[j].setX(enemys[j].xEne()+1);
			}else{}
			if(mover_bal[j] == true && disparados[j] == true){
				if (col_ciudades(balitas,j, tam) == 1){ // si choco con una ciudad o torreta
					num_R[j] = 2 + rand() % (86-2);
					mover_bal[j] = false;
					disparados[j] = false;
				}else{}
					if(balitas[j].ybala() >= 22){
						num_R[j] = 2 + rand() % (86-2);
						Color(3,3);
						balitas[j].borrar();
						Color(0,15);
						mover_bal[j] = false;
						disparados[j] = false;
					}else{}
						if(balitas[j].ybala() >= 17){
							Color(3,3);
							balitas[j].borrar();
							balitas[j].movimiento();
							balitas[j].pintar();
							Color(0,15);
						}else{
							Color(0,15);
							balitas[j].borrar();
							balitas[j].movimiento();
							balitas[j].pintar();
						}
			}
		}else{}
	}
}


void rutina_enemigos2(Bala balitas[], Enemigo enemys[], int tam){
	if (cant_enemigos[1] > 3){
		//mov
		for (int i = 0; i < 2; ++i){ // rutina primeras 2 naves
			if (enemys[i].Vidas() >= 1){
				enemys[i].destruir();
				enemys[i].movimiento();
				enemys[i].pintar();
			}else{
				enemys[i].destruct();
				enemys[i].destruir();
			}
		}
		//disparo
	srand(time(NULL));
	for(int j = 0; j < 2; j++){
		if(balitas[j].ybala() == 0){ // randomizamos la posicion al iniciar
			num_R[j] = 2 + rand() % (88-2);
		}
		if(enemys[j].Vidas() >= 1){ //bala aleatoria 1
			if(num_R[j] < 2 || num_R[j] > 84){
				while(true){
					num_R[j] = 2 + rand() % (86-2);
					if(num_R[j] > 1 && num_R[j] < 85){
						break;
					}
				}
			}
			if(num_R[j] == enemys[j].xEne() && disparados[j] == false){
				mover_bal[j] = true;
				disparados[j] = true;
				balitas[j].setY(enemys[j].yEne()+2);
				balitas[j].setX(enemys[j].xEne()+1);
			}
			if(mover_bal[j] == true && disparados[j] == true){
				if (col_ciudades(balitas,j, tam) == 1){ // si choco con una ciudad o torreta
					num_R[j] = 2 + rand() % (86-2);
					mover_bal[j] = false;
					disparados[j] = false;
				}else{}
					if(balitas[j].ybala() >= 22){
						num_R[j] = 2 + rand() % (86-2);
						Color(3,3);
						balitas[j].borrar();
						Color(0,15);
						mover_bal[j] = false;
						disparados[j] = false;
					}else{}
						if(balitas[j].ybala() >= 17){
							Color(3,3);
							balitas[j].borrar();
							balitas[j].movimiento();
							balitas[j].pintar();
							Color(0,15);
						}else{
							Color(0,15);
							balitas[j].borrar();
							balitas[j].movimiento();
							balitas[j].pintar();
						}
			}
		}
	}
		
	}else if(cant_enemigos[1] <= 3 && cant_enemigos[1] > 1){
		//mov
		for (int k = 2; k <= 3; k++){ // rutina siguientes 2 naves
			if (enemys[k].Vidas() >= 1){
				enemys[k].destruir();
				enemys[k].movimiento();
				enemys[k].pintar();
			}else{
				enemys[k].destruct();
				enemys[k].destruir();
			}
		}
		//disparo
		srand(time(NULL));
		for(int j = 2; j <= 3; j++){
			if(balitas[j].ybala() == 0){ // randomizamos la posicion al iniciar
				num_R[j] = 2 + rand() % (88-2);
			}
			if(enemys[j].Vidas() >= 1){ //bala aleatoria 1
				if(num_R[j] < 2 || num_R[j] > 84){
					while(true){
						num_R[j] = 2 + rand() % (86-2);
						if(num_R[j] > 1 && num_R[j] < 85){
							break;
						}
					}
				}
				if(num_R[j] == enemys[j].xEne() && disparados[j] == false){
					mover_bal[j] = true;
					disparados[j] = true;
					balitas[j].setY(enemys[j].yEne()+2);
					balitas[j].setX(enemys[j].xEne()+1);
				}
				if(mover_bal[j] == true && disparados[j] == true){
					if (col_ciudades(balitas,j, tam) == 1){ // si choco con una ciudad o torreta
						num_R[j] = 2 + rand() % (86-2);
						mover_bal[j] = false;
						disparados[j] = false;
					}else{}
						if(balitas[j].ybala() >= 22){
							num_R[j] = 2 + rand() % (86-2);
							Color(3,3);
							balitas[j].borrar();
							Color(0,15);
							mover_bal[j] = false;
							disparados[j] = false;
						}else{}
						if(balitas[j].ybala() >= 17){
							Color(3,3);
							balitas[j].borrar();
							balitas[j].movimiento();
							balitas[j].pintar();
							Color(0,15);
						}else{
							Color(0,15);
							balitas[j].borrar();
							balitas[j].movimiento();
							balitas[j].pintar();
						}
				}
			}
		}//fin disparo
		
	}
}
void estadisticas(){
	if (nivel == 1){
		gotoxy(50,24);cout<<"Enemigos faltantes: "<<cant_enemigos[0];
	}else if(nivel == 2){
		gotoxy(30,24);cout<<"Enemigos faltantes: "<<cant_enemigos[1];
	}
}
int main() {
	//console con( 90, 35 );
	menu_general();
	system("cls");
	OcultarCursor();
	fondo();
	escenario();
	//Juego.
	/*char soundfile[] = "Sounds/disparo1.wav";
	cout<<PlaySound((LPCSTR)soundfile, NULL, SND_FILENAME | SND_ASYNC );
	*/
	//variables controladoras del juego
	int opc;
	bool on = true;
	int tecla;
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
		//estadisticas();
		if(nivel == 1){
			rutina_enemigos1(balas_E1, enemigos1, 3);
			if(kbhit()){
				tecla = getch();
				if(tecla == 80 && !central && !izq && !der && torres[1].getV() == 1){
					disparo = 1;
					central = true;
				}
				if(tecla == 75 && !central && !izq && !der && torres[0].getV() == 1){
					disparo = 2;
					izq = true;
				}
				if(tecla == 77 && !central && !izq && !der && torres[2].getV() == 1){
					disparo = 3;
					der = true;
				}
		    }
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
			if(cant_enemigos[0] == 0){
				nivel += 1;
			}
		}else if(nivel == 2){
			rutina_enemigos2(balas_E2, enemigos2, 5);
			if(kbhit()){
				tecla = getch();
				if(tecla == 80 && !central && !izq && !der && torres[1].getV() == 1){
					disparo = 1;
					central = true;
				}
				if(tecla == 75 && !central && !izq && !der && torres[0].getV() == 1){
					disparo = 2;
					izq = true;
				}
				if(tecla == 77 && !central && !izq && !der && torres[2].getV() == 1){
					disparo = 3;
					der = true;
				}
		    }
		    if(disparo == 1){
		    	disparo = movbalaT(0, disparo, enemigos2, balas_E2, 5, 1);
		    	if (disparo != 1){
		    		central = false;
				}
			}else if(disparo == 2){
				disparo = movbalaT(1, disparo, enemigos2, balas_E2,5, 1);
				if (disparo != 2){
		    		izq = false;
				}
			}else if(disparo == 3){
				disparo = movbalaT(2, disparo, enemigos2, balas_E2,5, 1);
				if (disparo != 3){
		    		der = false;
				}
			}
			if(cant_enemigos[1] == 0){
				nivel += 1;
			}
		}
	}
	return 0;
}


