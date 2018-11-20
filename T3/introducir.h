#ifndef _INTRODUCIR_H_
#define _INTRODUCIR_H_

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "menu.h"
#include "introducir.h"

using namespace std;

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
}Persona[150];



void Introducir_alumno(bool coordinador,int *n_alumnos);


#endif
