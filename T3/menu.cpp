#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <limits>

using namespace std;

#include "agenda.h"
#include "main.h"


int n_alumnos = 0;

int Menu(bool coordinador){
	//Creacion de Variables
	int opcion;

	//Limpieza de pantalla
	system("clear");

	//Muestra el MENU DE OPCIONES
	cout<<"	\033[35;1;4m\n	MENÚ DE OPCIONES\033[0m\033[35;1m:\033[0m\n\n";
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
	cout<<"	\033[1;4;34mSeleccione la opción que desea usar\033[0m\033[1;34m:\033[0m ";

	//Eleccion de la opcion
	cin>>opcion;
	cout<<"\n";


	//Elige dependiendo de opcion
	switch(opcion){

		case 1:	if(n_alumnos<150){
						cout<<"\033[32;1m	Introducir Alumno.\033[0m\n";
						sleep(1);
						IntroducirAlumno(coordinador,&n_alumnos);
						sleep(1);
						break;
					} else {
						cout<<"	\033[1;31mEl número de alumnos no puede ser superior a 150.\n	Vuelta al MENÚ DE OPCIONES\033[0m\n";
						sleep(1);
						system("clear");
						Menu(coordinador);
						break;
					}

		case 2:	cout<<"\033[32;1m	Mostrar Agenda.\033[0m\n";
					Mostrar_Agenda(coordinador,&n_alumnos);
					sleep(1);
					break;

		case 3:	cout<<"\033[32;1m	Buscar Alumno.\033[0m\n";
					sleep(1);
					break;

		case 4:	cout<<"\033[32;1m	Modificar Alumno.\033[0m\n";
					sleep(1);
					break;

		case 5:	cout<<"\033[32;1m	Borrar Alumno.\033[0m\n";
					sleep(1);
					break;

		case 6:	cout<<"\033[32;1m	Guardar Agenda.\033[0m\n";
					sleep(1);
					break;

		case 7:	if(coordinador==false){
						cout<<"\033[1;31m	No tienes acceso a esta opción.\n	Vuelta al MENÚ DE OPCIONES.\033[0m\n";
						sleep(1);
						system("clear");
						Menu(coordinador);
					} else {
						cout<<"\033[32;1m	Crear Copia de Seguridad.\033[0m\n";
						sleep(1);
						break;
					}
					break;

		case 8:	cout<<"\033[32;1m	Cargar Agenda.\033[0m\n";
					sleep(1);
					break;

		case 9:	if(coordinador==false){
						cout<<"\033[1;31m	No tienes acceso a esta opción.\n	Vuelta al MENÚ DE OPCIONES.\033[0m\n";
						sleep(1);
						system("clear");
						Menu(coordinador);
					} else {
						cout<<"\033[32;1m	Cargar Copia de Seguridad.\033[0m\n";
						sleep(1);
						break;
					}
					break;

		case 10: cout<<"\033[32;1m	Vuelta al selector de clave.\033[0m\n";
					sleep(1);
					main();
					break;

		case 11: cout<<"\033[32;1m	Cerrar.\033[0m\n";
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
			cout<<"\033[1;31m	Has introducido un caracter erroneo, vuelve a introducirlo.\033[0m\n";
			sleep(1);
			system("clear");
			Menu(coordinador);
		}
		if(!cin.fail())
		break;
	}
	
	//Numero no válido
	if((opcion<1)||(opcion>11)){
		cout<<"	\033[31;1mOpción no válida.\033[0m\n";
	}
	
	//Vuelta al menú
	sleep(1);
	system("clear");
	Menu(coordinador);
	return 0;
}
