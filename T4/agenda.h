#ifndef _INTRODUCIR_H_
#define _INTRODUCIR_H_

using namespace std;


void IntroducirAlumno(bool coordinador,int *n_alumnos);
void checkEmail(string email,int *n_alumnos,bool coordinador);
void checkLider(int grupo,int *n_alumnos,bool coordinador);
void checkDNI(int DNI,int *n_alumnos,bool coordinador);

void MostrarAgenda(bool coordinador,int *n_alumnos);
void ordenaDNIAscendete(int *n_alumnos);

#endif
