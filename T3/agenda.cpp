#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

using namespace std;

#include "menu.h"
#include "struct.h"

//*************************INTRODUCIR ALUMNO INICIO****************************//

void IntroducirAlumno(bool coord, int *n_alumnos){

bool lider;
string newDNI;
string newEmail;
string esLiderSource;
Persona[n_alumnos].lider = false;

cout<< "Introduce el DNI \n"
cin<< newDNI;
checkDNI(newDNI);

cout<< "Introduce el nombre \n"
cin<< Persona[n_alumnos].nombre;

cout<< "Introduce el apellidos \n"
cin<< Persona[n_alumnos].apellidos;

cout<< "Introduce el telefono \n"
cin<< Persona[n_alumnos].telefono;

cout<< "Introduce el email \n"
cin<< newEmail;
checkEmail(newEmail);

cout<< "Introduce el domicilio \n"
cin<< Persona[n_alumnos].domicilio;

cout<< "Introduce el curso \n"
cin<< Persona[n_alumnos].curso;

cout<< "Introduce la fecha de nacimiento \n"
cin<< Persona[n_alumnos].fecha;

cout<< "Introduce el grupo al que pertenece \n"
cin<< Persona[n_alumnos].grupo;

cout<< "¿Es líder? Introduce 'Si', si no, introduce 'No' \n"
cin<< esLiderSource;

switch (esLiderSource){

case "Si":
checkLider(Persona[n_alumnos].grupo); 
Persona[n_alumnos].lider = true;
break;

case "No":
Persona[n_alumnos].lider = false;
break;
}

n_alumnos++;
Menu(coordinador);
}


void checkLider(int grupo){

for(int i = 0; i<n_alumnos; i++){
if( (Persona[i].grupo = grupo) && (Persona[i].lider) ){
printf("El grupo al que pertenece el alumno ya tiene un líder")
sleep(2);
Menu(coordinador);
}
}
}

void checkDNI(int dni){

for(int i = 0; i<n_alumnos; i++){
if(Persona[i].DNI = dni){
cout<<"Ya existe un alumno con ese DNI"
sleep(2);
Menu(coordinador);
}else{
Persona[n_alumnos].DNI = dni;
}
}
}

void checkEmail(string email){

for(int i = 0; i<n_alumnos; i++){
if(Persona[i].email = email){
cout<<"Ya existe un alumno con ese email"
sleep(2);
Menu(coordinador);
}else{
Persona[n_alumnos].email = email;
}
}
}

//*************************INTRODUCIR ALUMNO FINAL****************************//

void Mostrar_Agenda(bool coordinador){
	system ("clear");
	int i =0;
	string a;
	for (i=0;i<150;i++){
		cout<<"DNI Persona "<<i<<" = "<<Persona[i].DNI<<endl;
	}
	cout<<"\nIntroduzca un caracter para continuar\n";
	cin>>a;
	Menu(coordinador);

}
