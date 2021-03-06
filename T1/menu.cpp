#include<iostream>
#include<stdlib.h>
#include<unistd.h>

using namespace std;

int Menu(int clave){
	int opcion;
	cout<<"MENÚ DE OPCIONES:\n";
	cout<<"  1. Introducir un alumno.\n";
	cout<<"  2. Mostrar Agenda.\n";
	cout<<"  3. Buscar Alumno.\n";
	cout<<"  4. Modificar Alumno.\n";
	cout<<"  5. Borrar Alumno.\n";
	cout<<"  6. Guardar Agenda.\n";
	cout<<"  7. Crear Copia de Seguridad.\n";
	cout<<"  8. Cargar Copia de Seguridad.\n";
	cout<<"  9. Cerrar el programa.\n ";
	cout<<"Seleccione la opción que desea usar: ";
	cin>>opcion;
	switch(opcion){

		case 1:	cout<<"Introducir\n";
					sleep(1);
					break;

		case 2:	cout<<"Mostrar\n";
					sleep(1);
					break;

		case 3:	cout<<"Buscar\n";
					sleep(1);
					break;

		case 4:	cout<<"Modificar\n";
					sleep(1);
					break;

		case 5:	cout<<"Borrar\n";
					sleep(1);
					break;

		case 6:	cout<<"Guardar\n";
					sleep(1);
					break;

		case 7:	if(clave!=1){
						cout<<"No tienes acceso a esta opción.\nVuelta al MENÚ DE OPCIONES\n";
						sleep(1);
						system("clear");
						Menu(clave);
					} else {
						cout<<"CS\n";
						sleep(1);
						break;
					}
					break;

		case 8:	cout<<"Cargar\n";
					sleep(1);
					break;

		case 9:	cout<<"Cerrar\n";
					sleep(1);
					system("clear");
					exit(0);
					break;

		default:	cout<<"Error, vuelva a introducir\n";
					sleep(1);
					Menu(clave);
					break;
	}
	return 0;
}
