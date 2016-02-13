// Miguel Ascanio Gómez

#include <iostream>
using namespace std;
#include "tListaClientes.h"
#include "archivo.h"

//>>>>> Estilo correcto. Bien comentado.

int main()
{
	system("chcp 1252");
	tListaClientes listaClientes;
	if(cargaLlamadas(listaClientes))
	{
		cout << "=========================" << endl ;
		cout << "Coste antes de descuento: " << endl ;
		cout << "=========================" << endl << endl ;
		muestraClientes(listaClientes);
		descuento(listaClientes);
		cout << "===========================" << endl ;
		cout << "Coste después de descuento: " << endl ;
		cout << "===========================" << endl ;
		muestraClientes(listaClientes);

		//Libero la memoria de listas dinamicas de cada cliente (de las llamadas)
		for (int i = 0; i < listaClientes.contador; i++)
			delete [] listaClientes.lista[i].lista.lista;
	}
	else
		cout << "Error de apertura de archivo " << ARCHIVO << endl ;
	return 0;
}