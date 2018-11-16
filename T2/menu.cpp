#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <limits>
#include "introducir.h"
#include "main.h"

using namespace std;

int Menu(bool coordinador){
	int opcion;
	cout<<"	\033[35;1;4m\n	MENÚ DE OPCIONES:\033[0m\n\n";
	cout<<"	\033[36;1m1.\033[0m \033[1mIntroducir un alumno.\033[0m\n";
	cout<<"	\033[36;1m2.\033[0m \033[1mMostrar Agenda.\033[0m\n";
	cout<<"	\033[36;1m3.\033[0m \033[1mBuscar Alumno.\033[0m\n";
	cout<<"	\033[36;1m4.\033[0m \033[1mModificar Alumno.\033[0m\n";
	cout<<"	\033[36;1m5.\033[0m \033[1mBorrar Alumno.\033[0m\n";
	cout<<"	\033[36;1m6.\033[0m \033[1mGuardar Agenda.\033[0m\n";
	cout<<"	\033[36;1m7.\033[0m \033[1mCrear Copia de Seguridad.\033[0m\n";
	cout<<"	\033[36;1m8.\033[0m \033[1mCargar Agenda.\033[0m\n";
	cout<<"	\033[36;1m9.\033[0m \033[1mCargar Copia de Seguridad.\033[0m\n";
	cout<<"	\033[36;1m10.\033[0m \033[1mVolver al selector.\033[0m\n";
	cout<<"	\033[36;1m11.\033[0m \033[1mCerrar el programa.\033[0m\n\n";
	cout<<"	\033[1;34mSeleccione la opción que desea usar: \033[0m";
	cin>>opcion;
	cout<<"\n";

	switch(opcion){

		case 1:	cout<<"\033[32;1m	Introducir Alumno\033[0m\n";
					sleep(1);
					Introducir_alumno(coordinador);
					sleep(1);
					break;

		case 2:	cout<<"\033[32;1m	Mostrar\033[0m\n";
					sleep(1);
					break;

		case 3:	cout<<"\033[32;1m	Buscar\033[0m\n";
					sleep(1);
					break;

		case 4:	cout<<"\033[32;1m	Modificar\033[0m\n";
					sleep(1);
					break;

		case 5:	cout<<"\033[32;1m	Borrar\033[0m\n";
					sleep(1);
					break;

		case 6:	cout<<"\033[32;1m	Guardar\033[0m\n";
					sleep(1);
					break;

		case 7:	if(coordinador==false){
						cout<<"\033[1;31m	No tienes acceso a esta opción.\n	Vuelta al MENÚ DE OPCIONES\033[0m\n";
						sleep(1);
						system("clear");
						Menu(coordinador);
					} else {
						cout<<"\033[32;1m	Crear Copia de Seguridad\033[0m\n";
						sleep(1);
						break;
					}
					break;

		case 8:	cout<<"\033[32;1m	Cargar Agenda\033[0m\n";
					sleep(1);
					break;

		case 9:	if(coordinador==false){
						cout<<"\033[1;31m	No tienes acceso a esta opción.\n	Vuelta al MENÚ DE OPCIONES\033[0m\n";
						sleep(1);
						system("clear");
						Menu(coordinador);
					} else {
						cout<<"\033[32;1m	Cargar Copia de Seguridad\033[0m\n";
						sleep(1);
						break;
					}
					break;

		case 10: cout<<"\033[32;1m	Vuelta al selector de clave.\033[0m\n";
					sleep(1);
					main();
					break;

		case 11: cout<<"\033[32;1m	Cerrar\n";
					sleep(1);
					system("clear");
					exit(0);
					break;

	}
	
	//Validación de caracteres
	while(1){
		if(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout<<"\033[1;31mHas introducido un caracter erroneo, vuelve a introducirlo\033[0m\n";
			sleep(1);
			system("clear");
			Menu(coordinador);
		}
		if(!cin.fail())
		break;
	}
	
	//Numero no válido
	if((opcion<1)||(opcion>10)){
		cout<<"Opción no válida\n";
	}
	
	//Vuelta al menú
	sleep(1);
	system("clear");
	Menu(coordinador);
	return 0;
}
