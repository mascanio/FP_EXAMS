#include "tCliente.h"

#include <iostream>
using namespace std;
#include <iomanip>

void muestraCliente(tCliente cliente)
{
	cout << setw(TAM_NIF) << cliente.nif << endl ;
	for (int i = 0; i < cliente.lista.contador; i++)
	{
		cout << "\t" ;
		muestraLlamada(cliente.lista.lista[i]);
	}
	cout << endl ;
	cout << "Coste total de las llamadas: " << setprecision(2) << fixed << cliente.gasto << " Eur" << endl << endl ;
}