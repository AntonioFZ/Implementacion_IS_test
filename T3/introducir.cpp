#include "introducir.h"



using namespace std;

void Introducir_alumno(bool coordinador,int *n_alumnos){
	//Limpia pantalla
	system("clear");
	//Lo que hace la función
	cin>>Persona[1].DNI;
	sleep(1);

	//Limpia pantalla
	system("clear");
	
	//Añade al contador un alumno
	(*n_alumnos)=(*n_alumnos)+1;

	//Volver al MENU DE OPCIONES
	Menu(coordinador);
}
