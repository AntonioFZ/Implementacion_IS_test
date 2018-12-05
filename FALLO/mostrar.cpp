#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fstream>
#include <limits>



#include "struct.h"
#include "menu.h"
using namespace std;

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

