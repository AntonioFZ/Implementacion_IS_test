#include <iostream>
#include <fstream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

int main(){
	//Creacion Variables
	int a;
	int b;
	int c;

	system("clear");
	
	//Abrir y leer fichero
	FILE* f;
	f = fopen("CLAVES.dat", "rb");
	
	if(f==NULL){
   	cout<<"No se pudo abrir el fichero\n";
   return -1;
	}

	cout<<"\n\033[35;1m	LISTADO DE CLAVES:\033[0m\n\n";
	fread(&a,sizeof(int),1,f);
	cout<<"	\033[1mLa clave del coordinador es: "<<a<<"\n";
	fread(&b,sizeof(int),1,f);
	cout<<"	La clave del primer ayudante es: "<<b<<"\n";
	fread(&c,sizeof(int),1,f);
	cout<<"	La clave del segundo ayudante es: "<<c<<"\n";
	cout<<"\033[0m\n\n";
	fclose(f);
	return 0;
}
