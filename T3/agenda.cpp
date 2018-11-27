#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fstream>

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
	
	cout<<"\nINTRODUCIR ALUMNO\n";
	
	cout<< "\033[1;4;34mIntroduce el DNI\033[0m\n";
	cin>> newDNI;
	checkDNI(newDNI,n_alumnos,coordinador);

	cout<< "\033[1;4;34mIntroduce el nombre\033[0m\n";
	cin>> Persona[*n_alumnos].nombre;

	cout<< "\033[1;4;34mIntroduce el apellidos\033[0m \n";
	cin>> Persona[*n_alumnos].apellidos;

	cout<< "\033[1;4;34mIntroduce el telefono\033[0m\n";
	cin>> Persona[*n_alumnos].telefono;

	cout<< "\033[1;4;34mIntroduce el email\033[0m \n";
	cin>> newEmail;
	checkEmail(newEmail,n_alumnos,coordinador);

	cout<< "\033[1;4;34mIntroduce el domicilio\033[0m\n";
	cin>> Persona[*n_alumnos].domicilio;

	cout<< "\033[1;4;34mIntroduce el curso\033[0m \n";
	cin>> Persona[*n_alumnos].curso;

	cout<< "\033[1;4;34mIntroduce la fecha de nacimiento\033[0m\n";
	cin>> Persona[*n_alumnos].fecha;

	cout<< "\033[1;4;34mIntroduce el grupo al que pertenece\033[0m\n";
	cin>> Persona[*n_alumnos].grupo;

	cout<< "\033[1;4;34m¿Es líder? Introduce 1 si es Si\nIntroduce 2 si es No\033[0m\n";
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

	(*n_alumnos)=(*n_alumnos)+1;
	cout<<*n_alumnos;
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
	ficheroSalida.open ("mostrar.html");
	ficheroSalida << "<html><head><title>Listado de alumnos</title></head><body><h1>Listado de alumnos</h1><table><tr><td><strong>Nombre</strong></td><td><strong>Apellidos</strong></td><td><strong>Telefono</strong></td><td><strong>Email</strong></td><td><strong>Domicilio</strong></td><td><strong>Curso</strong></td><td><strong>Fecha</strong></td><td><strong>Grupo</strong></td><td><strong>Lider</strong></td><td><strong>DNI</strong></td></tr>";
	for(i=0;i<*n_alumnos;i++){
		ficheroSalida << "<tr><td>"<<Persona[i].nombre<<"</td><td>"<<Persona[i].apellidos<<"</td><td>"<<Persona[i].telefono<<"</td><td>"<<Persona[i].email<<"</td><td>"<<Persona[i].domicilio<<"</td><td>"<<Persona[i].curso<<"</td><td>"<<Persona[i].fecha<<"</td><td>"<<Persona[i].grupo<<"</td><td>"<<Persona[i].lider<<"</td><td>"<<Persona[i].DNI<<"</td></tr>";
	}

	//Cerrar fichero
	ficheroSalida.close();

	//Abrir fichero
	system("firefox mostrar.html");
	sleep(1);
	system("rm mostrar.html");

	Menu(coordinador);

}
//*************************MOSTRAR AGENDA FINAL*******************************//

