#include <iostream>
#include <fstream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

int main() {
	//Creacion Variables
   int a;
	int b;
	int c;
	
	system("clear");
	//Introducir Datos
	cout<<"Introduce clave para coordinador: ";
	cin>>a;
	cout<<"\n";
	cout<<"Introduce clave para primer ayudante: ";
	cin>>b;
	cout<<"\n";
	cout<<"Introduce clave para segundo ayudante: ";
	cin>>c;
	cout<<"\n";
	
	//Comprobacion Errores
	if((a==b)||(b==c)||(a==c)){
		cout<<"No pueden existir 2 claves o más iguales.\nVuelve a introducir las claves.\n";
		sleep(1);
		main();
	}

	//Creacion fichero
	FILE* fsalida;
	fsalida = fopen("CLAVES.dat", "wb");
	fwrite(&a, sizeof(int),1, fsalida);
	fwrite(&b, sizeof(int),1, fsalida);
	fwrite(&c, sizeof(int),1, fsalida);
	fclose(fsalida);
	
	system("clear");
   return 0;
}
