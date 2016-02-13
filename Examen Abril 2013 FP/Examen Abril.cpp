// Miguel Ascanio Gómez

#include <iostream>
#include <string>
using namespace std;

#include <iomanip>
#include <fstream>

//>>>>> Estilo correcto. Algo comentado.

//CONSTANTES Y TIPOS

const string ARCHIVO_COCHES = "coches.txt" ;
const string ARCHIVO_ALQUILERES = "rent.txt" ;

const int MAX_COCHES = 20,
	MAX_ALQUILERES = 100;

const int CENTINELA = -1;

// Estructuras lista coches

typedef struct
{
	int modelo;
	string nombre;
} tCoche;

typedef tCoche tCoches[MAX_COCHES];

typedef struct
{
	int contador;
	tCoches lista;
} tListaCoches;


//Estructura lista Alquileres

typedef struct
{
	int modelo;
	string fecha;
	int diasAlquiler;
} tAlquiler;

typedef tAlquiler tAlquileres[MAX_ALQUILERES];

typedef struct
{
	int contador;
	tAlquileres lista;
} tListaAlquileres;

//PROTOTIPOS

//Funcion < sobrecargada para comparar listas por fecha
bool operator< (tAlquiler lista1, tAlquiler lista2);
//Lee de los archivos pertinentes y guarda los datos en las listas adecuados
bool leerAlquileres(tListaAlquileres& listaAlquileres);
bool leerModelos(tListaCoches& lista);
//Ordena la lista de alquileres pasada por referecia usando el método de la burbuja mejorado (natural)
void ordenar(tListaAlquileres &listaAlquileres);
//Realiza una búsqeda binaria sobre la tLitaCoches lista el elemento cuyo código es el buscado pasado por variable
//Devuelve int del índice del elemento con el código buscado
int buscar(tListaCoches lista, int buscado);
//Mustra en pantalla los datos de la lista de alquileres, ordenada por fechas, junto con los nombresde modelo de la listaCoches,
//mostrando error si hay un código inválido en la listaAlquileres
void mostrar(tListaCoches listaCoches, tListaAlquileres listaAlquileres);

int main()
{
	system("chcp 1252");

	cout << endl ;

	tListaCoches listaCoches;
	tListaAlquileres listaAlquileres;

	//Si se cargan bien los array (apertura de archivos correcta y no desborda la lista) se sigue la ejecución
	//Por shortcut para && si falla leerModelos no ejectua leerAlquileres
	if (leerModelos(listaCoches) && leerAlquileres(listaAlquileres))
	{
		ordenar(listaAlquileres);
		mostrar(listaCoches, listaAlquileres);
	}

	cout << endl << "Pulse intro para continuar..." ;
	cin.get();

	return 0;
}

void mostrar(tListaCoches listaCoches, tListaAlquileres listaAlquileres)
{
	int indice;
	for (int i = 0; i < listaAlquileres.contador; i++)
	{
		//Mustro fecha
		cout << listaAlquileres.lista[i].fecha << " " ;
		//Busco el nombre del coche numero de modelo de la posición i del array listaAlquileres
		indice = buscar(listaCoches, listaAlquileres.lista[i].modelo);

		if (indice != -1) //Modelo correcto
		{
			//							muestro el nombre								//dias de alquiler 8ternario par mostar o no la s plural
			cout << setw(25) << left << listaCoches.lista[indice].nombre << setw(2) << listaAlquileres.lista[i].diasAlquiler << " día"  
				<< (listaAlquileres.lista[i].diasAlquiler == 1 ? "" : "s") << endl ;
		}
		else
			cout << "ERROR:	¡¡¡Modelo inexistente!!!" << endl ;
	}
}

bool operator< (tAlquiler lista1, tAlquiler lista2)
{
	return lista1.fecha < lista2.fecha ;
}

bool leerModelos(tListaCoches& listaCoches)
{
	listaCoches.contador = 0;

	bool salida = true, salirWhile = false;
	int leido;

	ifstream archivo;
	archivo.open(ARCHIVO_COCHES.c_str());

	if (archivo.is_open())
	{
		while(!salirWhile) //Mientras no centinela o superar MAX de la listaCoches
		{
			archivo >> leido;
			//Si no centinela
			if (leido != CENTINELA)
			{
				if (listaCoches.contador < MAX_COCHES)
				{
					listaCoches.lista[listaCoches.contador].modelo = leido;
					getline(archivo, listaCoches.lista[listaCoches.contador].nombre);
					listaCoches.contador++;
				}
				else
				{
					cout << "Error, lista de coches llena" << endl ; //>>>>> No hay que mostrar nada
					salida = false;
					salirWhile = true;
				}
			}
			else
				salirWhile = true;
		}
		archivo.close();
	}
	else
		cout << "Error de apertura de archivo " << ARCHIVO_COCHES << endl ;
	return salida;
}
bool leerAlquileres(tListaAlquileres &listaAlquileres)
{
	listaAlquileres.contador = 0;

	bool salida = true, salirWhile = false;

	int leido;

	ifstream archivo;
	archivo.open(ARCHIVO_ALQUILERES.c_str());

	if (archivo.is_open())
	{
		while(!salirWhile) //Mientras no centinela o superar MAX de la listaAlquileres
		{
			archivo >> leido;
			//Si no centinela
			if (leido != CENTINELA)
			{
				if (listaAlquileres.contador < MAX_ALQUILERES)
				{
					listaAlquileres.lista[listaAlquileres.contador].modelo = leido;
					archivo >> listaAlquileres.lista[listaAlquileres.contador].fecha;
					archivo >> listaAlquileres.lista[listaAlquileres.contador].diasAlquiler;
					listaAlquileres.contador++;
				}
				else
				{
					cout << "Error, lista de alquileres llena" << endl ;
					salida = false;
					salirWhile = true;
				}
			}
			else
				salirWhile = true;
		}
		archivo.close();
	}
	else
		cout << "Error de apertura de archivo " << ARCHIVO_ALQUILERES << endl ;

	return salida;
}

void ordenar(tListaAlquileres &lista)
{
	bool inter = true;
	int i = 0;
	tAlquiler tmp;
	while ((i < lista.contador - 1) && inter) 
	{
		// Desde el primer elemento hasta el penúltimo o no haya que seguir
		inter = false;
		for (int j = lista.contador - 1; j > i; j--)
			// Desde el último hasta el siguiente a i
			if (lista.lista[j] < lista.lista[j-1]) 
			{
				tmp = lista.lista[j];
				lista.lista[j] = lista.lista[j-1];
				lista.lista[j-1] = tmp;
				inter = true;
			}
			if (inter) i++;
	}
}

int buscar(tListaCoches lista, int buscado)
{
	int ini = 0, fin = lista.contador - 1, mitad;
	bool encontrado = false;
	while ((ini <= fin) && !encontrado) 
	{
		mitad = (ini + fin) / 2; // División entera
		if (buscado == lista.lista[mitad].modelo) 
			encontrado = true;
		else if (buscado < lista.lista[mitad].modelo) 
			fin = mitad - 1;
		else 
			ini = mitad + 1;
	}
	if (!encontrado)
		mitad = -1;
	//Devolvemos el indice del encontrado (que es mitad) o el -1 si no encontrado
	return mitad;
}