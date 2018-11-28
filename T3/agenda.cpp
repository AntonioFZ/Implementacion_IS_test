#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fstream>
#include <limits>

using namespace std;

#include "menu.h"
#include "struct.h"
#include "agenda.h"


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
	checkDNI(newDNI,n_alumnos,coordinador);

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
	checkEmail(newEmail,n_alumnos,coordinador);

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
			checkLider(Persona[*n_alumnos].grupo,n_alumnos,coordinador); 
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


void checkLider(int grupo,int *n_alumnos,bool coordinador){

	for(int i = 0; i<*n_alumnos;i++){
		if( (Persona[i].grupo == grupo) && (Persona[i].lider) ){
			printf("El grupo al que pertenece el alumno ya tiene un líder");
			sleep(2);
			Menu(coordinador);
		}
	}
}

void checkDNI(int dni,int *n_alumnos,bool coordinador){

	for(int i = 0; i<*n_alumnos; i++){
		if(Persona[i].DNI == dni){
			cout<<"Ya existe un alumno con ese DNI";
			sleep(2);
			Menu(coordinador);
		}else{
			Persona[*n_alumnos].DNI = dni;
		}
	}
}

void checkEmail(string email,int *n_alumnos,bool coordinador){

	for(int i = 0; i<*n_alumnos; i++){
		if(Persona[i].email == email){
			cout<<"Ya existe un alumno con ese email";
			sleep(2);
			Menu(coordinador);
		}else{
			Persona[*n_alumnos].email = email;
		}
	}
}

//*************************INTRODUCIR ALUMNO FINAL****************************//

//*************************MOSTRAR AGENDA INICIO******************************//
void Mostrar_Agenda(bool coordinador,int *n_alumnos){
	int i;

	//Creacion de fichero
	ofstream ficheroSalida;
	ficheroSalida.open ("temporal.html");
	ficheroSalida << "<html><head><title>Listado de alumnos</title></head><body><h1>Listado de alumnos</h1><table border = 10><tr><td><strong>Nombre</strong></td><td><strong>Apellidos</strong></td><td><strong>Telefono</strong></td><td><strong>Email</strong></td><td><strong>Domicilio</strong></td><td><strong>Curso</strong></td><td><strong>Fecha</strong></td><td><strong>Grupo</strong></td><td><strong>Lider</strong></td><td><strong>DNI</strong></td></tr>";
	for(i=0;i<*n_alumnos;i++){
		ficheroSalida << "<tr><td>"<<Persona[i].nombre<<"</td><td>"<<Persona[i].apellidos<<"</td><td>"<<Persona[i].telefono<<"</td><td>"<<Persona[i].email<<"</td><td>"<<Persona[i].domicilio<<"</td><td>"<<Persona[i].curso<<"</td><td>"<<Persona[i].fecha<<"</td><td>"<<Persona[i].grupo<<"</td><td>"<<Persona[i].lider<<"</td><td>"<<Persona[i].DNI<<"</td></tr>";
	}

	ficheroSalida << "</table></body></html>";

	//Cerrar fichero
	ficheroSalida.close();

	//Abrir fichero
	sleep(1);
	system("firefox temporal.html &");
	sleep(10);
	system("rm temporal.html");

	Menu(coordinador);

}
//*************************MOSTRAR AGENDA FINAL*******************************//

