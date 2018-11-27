#ifndef _INTRODUCIR_H_
#define _INTRODUCIR_H_

using namespace std;


void IntroducirAlumno(bool coordinador,int *n_alumnos);
void checkEmail(string email,int *n_alumnos,bool coordinador);
void checkLider(int grupo,int *n_alumnos,bool coordinador);
void checkDNI(int DNI,int *n_alumnos,bool coordinador);

void Mostrar_Agenda(bool coordinador,int *n_alumnos);

#endif
