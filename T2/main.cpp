#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits>
#include "menu.h"


using namespace std;

//Declaracion de variables
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

//Funcion MAIN
int main(){

	//Limpiar Pantalla
	system("clear");

	//Creacion de variables
	int clave;
	int a;
	int b;
	int c;
	bool coordinador;

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
	cout<<"	\033[35;1m\n	LOGIN:\033[0m\n\n";
	cout<<"	\033[1mLa clave del coordinador es: "<<a<<"\n";
	cout<<"	La clave del primer ayudante es: "<<b<<"\n";
	cout<<"	La clave del segundo ayudante es: "<<c<<"\033[0m\n\n";
	cout<<"	\033[1;34mIntroduzca la clave de usuario: \033[0m";
	cin>>clave;
	
	//Comprobacion de caracter introducido
	while(1){
		if(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout<<"\n\033[1;31m	Clave erronea, volviendo al selector\033[0m\n";
			sleep(1);
			main();
		}
		if(!cin.fail())
		break;
	}
	
	//Comparador de clave
	if (clave==a){
		cout<<"\n\033[1;32m	Usted ha entrado como coordinador\033[0m\n";
		coordinador=true;
		sleep(1);
		system("clear");
	} else if ((clave==b)||(clave==c)){
		cout<<"\n\033[1;32m	Usted ha entrado como ayudante\033[0m\n";
		coordinador=false;
		sleep(1);
		system("clear");
	} else {
		cout<<"\n\033[1;31m	Clave erronea, volviendo al selector\033[0m\n";
		sleep(1);
		system("clear");
		main();
	}

	//Llamada a la funcion MENU DE OPCIONES
	Menu(coordinador);
	system("clear");
	return 0;
}
