#include "tListaLlamadas.h"
#include <cstring>

bool operator<(tLlamada izq, tLlamada der)
{
	//Comparar fechas
	//Devuelvo fecha izq < fecha der; comparando por cadenas con strcm(izq,der) < 0, izq < der
	return ((strcmp(izq.fecha, der.fecha) < 0));
}

void inicializa(tListaLlamadas &lista)
{
	lista.contador = 0;
	lista.lista = new tLlamada[MAX_LLAMADAS]; //reservo espacio en heap y asigno puntero
}

bool insertaLlamada(tListaLlamadas &listaLlamadas, tLlamada llamada)
{
	bool salida = false;
	int i = 0;

	if(listaLlamadas.contador < MAX_LLAMADAS) //Si la lista no está llena
	{
		salida = true;
		//busco la posicon
		while((i < listaLlamadas.contador) && (listaLlamadas.lista[i] < llamada)) //Mientras no llegue al final ni encuentre una fecha mayor
			i++; //i me define la posicion donde insertar
		//Desplazo (desde el final hasta i)
		for (int j = listaLlamadas.contador; j > i; j--)
			listaLlamadas.lista[j] = listaLlamadas.lista[j - 1];
		//Inserto en la posición i
		listaLlamadas.lista[i] = llamada;
		listaLlamadas.contador++;
	}
	//else lista llena

	return salida;
}