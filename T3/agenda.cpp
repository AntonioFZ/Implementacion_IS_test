#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

using namespace std;

#include "menu.h"
#include "struct.h"

void Introducir_alumno(bool coordinador,int *n_alumnos){
	//Limpia pantalla
	system("clear");
	//Lo que hace la función
	cin>>Persona[1].DNI;
	cin>>Persona[24].DNI;
	system("clear");
	cout<<"DNI.Persona 24 = "<<Persona[24].DNI<<endl;
	sleep(1);
	
	//Añade al contador un alumno
	(*n_alumnos)=(*n_alumnos)+1;

	//Volver al MENU DE OPCIONES
	Menu(coordinador);
}

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
