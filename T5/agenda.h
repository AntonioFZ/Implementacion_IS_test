#ifndef _INTRODUCIR_H_
#define _INTRODUCIR_H_
//#include <string>
using namespace std;


void IntroducirAlumno(bool coordinador,int *n_alumnos);
void checkEmail(string email,int *n_alumnos,bool coordinador);
void checkLider(int grupo,int *n_alumnos,bool coordinador);
void checkDNI(int DNI,int *n_alumnos,bool coordinador);
void BuscarAlumno(bool coordinador,int *n_alumnos);
void busquedaDNI(int *n_alumnos);
void busquedaApellidos(int *n_alumnos);
void busquedaEmail(int *n_alumnos);
string muestraLider(bool lider);
void Mostrar_Agenda(bool coordinador,int *n_alumnos);

#endif
