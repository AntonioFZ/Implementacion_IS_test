#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fstream>
#include <limits>



#include "struct.h"
#include "menu.h"

using namespace std;

//*************************INTRODUCIR ALUMNO INICIO****************************//

void IntroducirAlumno(bool coordinador, int *n_alumnos){
		
	system("clear");

	bool lider;
	int newDNI;
	string newEmail;
	int esLiderSource;
	Persona[*n_alumnos].lider = false;
	
	cout<<"\033[35;4;1m\n	INTRODUCIR ALUMNO\033[0m\n\n";
	
	cout<< "\033[1;34m	Introduce el DNI : \033[0m";
	cin>> newDNI;
	while(1){
		if(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout<<"\n\033[1;31m	Caracter invalido, volviendo al Menu\033[0m\n";
			sleep(1);
			Menu(coordinador);
		}
		if(!cin.fail())
		break;
	}

	cout<< "\033[1;34m	Introduce el nombre : \033[0m";
	cin>>Persona[*n_alumnos].nombre;
	
	cout<< "\033[1;34m	Introduce el apellidos : \033[0m ";
	cin>> Persona[*n_alumnos].apellidos;
	
	cout<< "\033[1;34m	Introduce el telefono : \033[0m";
	cin>> Persona[*n_alumnos].telefono;
		while(1){
		if(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout<<"\n\033[1;31m	Caracter invalido, volviendo al Menu\033[0m\n";
			sleep(1);
			Menu(coordinador);
		}
		if(!cin.fail())
		break;
	}
	
	cout<< "\033[1;34m	Introduce el email : \033[0m";
	cin>> newEmail;

	cout<< "\033[1;34m	Introduce el domicilio : \033[0m";
	cin>> Persona[*n_alumnos].domicilio;
	
	cout<< "\033[1;34m	Introduce el curso : \033[0m";
	cin>> Persona[*n_alumnos].curso;	
		while(1){
		if(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout<<"\n\033[1;31m	Caracter invalido, volviendo al Menu\033[0m\n";
			sleep(1);
			Menu(coordinador);
		}
		if(!cin.fail())
		break;
	}
	
	cout<< "\033[1;34m	Introduce la fecha de nacimiento : \033[0m";
	cin>> Persona[*n_alumnos].fecha;
	
	cout<< "\033[1;34m	Introduce el grupo al que pertenece : \033[0m";
	cin>> Persona[*n_alumnos].grupo;
	
		while(1){
		if(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout<<"\n\033[1;31m	Caracter invalido, volviendo al Menu\033[0m\n";
			sleep(1);
			Menu(coordinador);
		}
		if(!cin.fail())
		break;
	}

	cout<< "\033[1;34m	¿Es líder? 1 -> Si, 2->No : \033[0m";
	cin>> esLiderSource;

	switch (esLiderSource){

		case 1:
			Persona[*n_alumnos].lider = true;
		break;

		case 2:
			Persona[*n_alumnos].lider = false;
		break;
	}
	
	while(1){
		if(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout<<"\n\033[1;31m	Caracter invalido, volviendo al Menu\033[0m\n";
			sleep(1);
			Menu(coordinador);
		}
		if(!cin.fail())
		break;
	}

	//Suma 1 alumno a la lista
	(*n_alumnos)=(*n_alumnos)+1;

	//Vuelve al Menu
	Menu(coordinador);
}

//*************************INTRODUCIR ALUMNO FINAL****************************//


