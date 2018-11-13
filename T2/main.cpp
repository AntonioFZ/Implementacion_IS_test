#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include "menu.h"


using namespace std;

struct agenda{
	int DNI;
	string nombre;
	string apellidos;
	int telefono;
	string email;
	string domicilio;
	int curso;
	string fecha;
	int grupo;
	bool lider;
}control[100];

int controlador = 0;


int main(){

	//Limpiar Pantalla
	system("clear");

	//Creacion de variables
	int clave;
	int a;
	int b;
	int c;

	//Lectura Claves y comprabacion fichero
	FILE* f;
	f = fopen("CLAVES.dat", "rb");
	if(f==NULL){
   	cout<<"No se pudo abrir el fichero\n";
   return -1;
	}
	fread(&a,sizeof(int),1,f);
	fread(&b,sizeof(int),1,f);
	fread(&c,sizeof(int),1,f);
	fclose(f);

	//Selector de clave
	cout<<"Introduzca la clave de usuario\n";
	cin>>clave;
	if (clave==a){
		cout<<"Usted ha entrado como coordinador\n";
		sleep(1);
		system("clear");
	} else if ((clave==b)||(clave==c)){
		cout<<"Usted ha entrado como ayudante\n";
		sleep(1);
		system("clear");
	} else {
		cout<<"Clave erronea, volviendo al selector\n";
		sleep(1);
		system("clear");
		main();
	}

	//Llamada a la funcion MENU DE OPCIONES
	Menu(clave);
	system("clear");
	return 0;
}
