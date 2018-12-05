#include <iostream>
#include <fstream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits>

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
	cout<<a;
	while(1){
		if(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout<<"Has introducido un caracter erroneo, vuelve a introducirlo: ";
			cin>>a;
		}
		if(!cin.fail())
		break;
	}
	cout<<"\n";
	cout<<"Introduce clave para primer ayudante: ";
	cin>>b;
	cout<<b;
		while(1){
		if(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout<<"Has introducido un caracter erroneo, vuelve a introducirlo: ";
			cin>>b;
		}
		if(!cin.fail())
		break;
	}
	cout<<"\n";
	cout<<"Introduce clave para segundo ayudante: ";
	cin>>c;
	cout<<c;
	while(1){
		if(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout<<"Has introducido un caracter erroneo, vuelve a introducirlo: ";
			cin>>c;
		}
		if(!cin.fail())
		break;
	}
	cout<<"\n";
	
	//Comprobacion Errores
	if((a==b)||(b==c)||(a==c)||((a==b)&&(b==c))){
		cout<<"No pueden existir 2 claves o más iguales.\n";
		sleep(1);
		exit(0);
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
