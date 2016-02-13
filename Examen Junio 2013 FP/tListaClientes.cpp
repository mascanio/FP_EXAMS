#include "tListaClientes.h"

#include <cstring>

int buscaCliente(tListaClientes clientes, tNif nif)
{
	int pos = -1, i = 0;
	//Busco en la lista mientras no encontrado (pos sea -1) y no llegue al final (i < contador)
	while ((pos == -1) && (i < clientes.contador))
	{
		//Comparo el nif del cliente de la lista en posició i: si es igual al que quiero, pos = i (sale del bucle y devuelve esa pos); 
		//si no, pos = -1 y sigo buscando
		pos = (strcmp(clientes.lista[i].nif, nif) == 0 ? i : -1);
		i++;
	}
	return pos;
}

void muestraClientes(tListaClientes listaClientes)
{
	//recorro la listad e clientes, mostrando cada cliente 
	for (int i = 0; i < listaClientes.contador; i++)
		//llamo a mostrar cliente para mostrar el cliente i (para todos)
		muestraCliente(listaClientes.lista[i]);
}
void descuento(tListaClientes &listaClientes)
{
	//Recorrido de la lista de clientes
	for(int i = 0; i < listaClientes.contador; i++)
	{
		//Recorro la lista de llamadas del cliente actual
		for(int j = 0; j < listaClientes.lista[i].lista.contador; j++)
		{
			//Si supera la duración de descuento
			if(listaClientes.lista[i].lista.lista[j].duracion > SEG_DESCUENTO)
			{
				//Quito el precio coste de la llamada
				listaClientes.lista[i].gasto -= listaClientes.lista[i].lista.lista[j].coste;
				//Calculo el nuevo precio con descuento
				listaClientes.lista[i].lista.lista[j].coste *= ((100 - DESCUENTO) * 0.01);
				//Vuelvo a añadir el coste de la llamada (con el coste ya aplicado el descuento)
				listaClientes.lista[i].gasto += listaClientes.lista[i].lista.lista[j].coste;
			}
		}
	}
}