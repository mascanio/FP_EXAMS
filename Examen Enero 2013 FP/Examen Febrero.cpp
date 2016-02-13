// Miguel Ascanio G�mez

#include <iostream>
using namespace std;

#include <fstream>
#include <cmath>

/*
Funci�n men�. Muestra el pen� y pide al usuario opci�n (se romcprueba correcta en main)
Devuelve opci�n
*/
int menu();

/*
Procedimiento que escribe los n�meros que el usuaro introduce entre 1 y limite especificado en main
Entrada: parametro int max (limite para los numeros)
*/
void generar(int max);

/*
Procedimiento que recorre datos.txt  buscando n�meros felices, mostrando si lo son o no.
Usa esFeliz(...) para comprobar si son felices o no
*/
void recorrer();
/*
Funcion que determina si un numero es feliz o no
Entrada: el numero a comprobar(tipo int)
Devuelve: bool si es feliz o no
*/
bool esFeliz(int entrada);

/*
Funcion que busca en datos.txt si un n�mero esta en una diferencia con el anterior (en valor absoluto) introducida pro el usuario
Entrada: parametro por variable del tipo int como error m�ximo (se modifica para devolver la diferencia entre los dos numeros)
Salida: el valor que toma la funcion por el return como tipo bool si lo ha encontrado, por parametros por variable tipo int 
el n�mero de la linea en la que esta el numero anterior (en la salida por consola se le suma 1 para mostrar la linea adecuada) y 
la diferencia entre los dos n�meros
*/
bool buscar(int &error, int &linea);
//>>>>> No reutilices par�metros (error entra como el error admisible y sale como error real)

int menu()
{
	int opcion;

	cout << endl 
		<< "1 - Generar la secuencia" << endl
		<< "2 - Procesar la secuencia" << endl
		<< "3 - Buscar en la secuencia" << endl
		<< "0 - Salir" << endl
		<< "Opci�n: " ;
	cin >> opcion;

	return opcion;
}

void generar(int max)
{
	int entrada = 1; //entrada del usuario

	ofstream archivo;
	archivo.open("datos.txt");

	while(entrada != 0)//si centinela, fin
	{
		cout << "Entero positivo (0 termina): " ;
		cin >> entrada;
		if(entrada >= 1 && entrada <= max) //Escribir n�mero si est� entre 1 y limite (el centinela 0 no entra, el 1 y el l�mite s�)
			archivo << entrada << endl;
	}
	archivo << -1 ; //escribir centinela 
	archivo.close();
}

void recorrer()
{
	int leido; //Numero leido de archivo

	ifstream archivo;
	archivo.open("datos.txt");
	//El archivo ya est� creado

	archivo >> leido;

	if(leido == -1) //si lee -1 de primeras, archivo vac�o
		cout << "El archivo se ha creado pero est� vac�o." ;
	else
	{
		while(leido != -1)
		{	//Se procesa el anterior (que nunca va a ser el centinela) mediente esFeliz(...); se muestra con ? : si es feliz o no
			cout << leido << (esFeliz(leido) ? " s�" : " no") << " es feliz" << endl ; 
			archivo >> leido;
		}
	}
	archivo.close();
}
bool esFeliz(int entrada)
{
	int aux = entrada, digito, suma = 0;
	bool terminar = false;

	while(!terminar) //Terminar = (suma tiene un d�gito)
	{
		while(aux != 0)
		{
			digito = aux % 10;		 //Extraigo d�gito
			aux /= 10;				 //Elimino d�gito
			suma += digito * digito; //Sumo cuadrado
		}
		if(suma > 9)				//Seguir si no es un s�lo d�gito
		{
			aux = suma;				//Procesar suma
			suma = 0;
		}
		else
			terminar = true;
	}
	return (suma == 1); //si es 1 es feliz
}

bool buscar(int &error, int &linea)
{
	int leido = 1, anterior,
		errorIntroducido = error;
	bool encontrado = false;

	linea = 0; //contador de l�nea a 0

	ifstream archivo;
	archivo.open("datos.txt");
	//El archivo ya est� creado

	archivo >> anterior; 
	if(anterior != -1) //Si s�lo centinela fin
	{
		archivo >> leido;

		while((leido != -1) && !encontrado)
		{
			linea++;

			error = (abs(anterior - leido));

			if(abs(anterior - leido) <= errorIntroducido)
			{
				encontrado = true;
			}
			else
			{
				anterior = leido;
				archivo >> leido;
			}
		}
	}
	return encontrado;
}

int main()
{
	system ("chcp 1252");

	int opcion = 1, 
		max, 
		linea;
	bool generado = false;

	while(opcion != 0)
	{
		opcion = menu(); //Llamamos a menu y asignamos valor a opcion evaluado en el switch
		switch(opcion)
		{
		case 1:
			cout << "L�mite para los valores: " ;
			cin >> max ;

			generar(max);
			generado = true; //secuencia generada (suponemos que siempre se crea el archivo)

			break;

		case 2:
			if(generado) //comprobar si se ha ejecutado 1.
				recorrer();
			else
				cout << "Ninguna secuencia generada." << endl ;
			break;

		case 3:
			if(generado) //comprobar si se ha ejecutado 1.
			{
				cout << "L�mite de diferencia con anterior: " ;
				cin >> max;
				if(buscar(max, linea))
				{
					cout << "Encontrado en la l�nea " << linea + 1 << " (diferencia: " << max << ")" << endl ;
				}
				else
					cout << "No encontrado." << endl ;
			}
			else
				cout << "Ninguna secuencia generada." << endl ;
			break;

		case 0: //salir
			break;

		default:
			cout << "Opci�n no v�lida!" << endl ;
			break;
		}
	}
	return 0;
}