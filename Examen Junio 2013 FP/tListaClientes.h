#ifndef tListaClientes_h
#define tListaClientes_h

#include "tCliente.h"

const int MAX_CLIENTES = 300;
const int SEG_DESCUENTO = 180; //Segundos necesarios apra aplicar el descuento
const double DESCUENTO = 10; //Porcentaje de descuento a aplicar

typedef tCliente tArrayClientes[MAX_CLIENTES];

typedef struct
{
	int contador;
	tArrayClientes lista;
} tListaClientes;
//Funcion que busca en la lista clientes el cliente cuyo nif sea el apsado
//Devuelve -1 si no se encuentra, o la posicion del buscado en la lista
int buscaCliente(tListaClientes clientes, tNif nif);
//Procedimiento que muestra todos los clientes
void muestraClientes(tListaClientes listaClientes);
//Procedimiento que aplica el descuento (segun definido más arriba) de todas las llamadas de todos los clientes, y actualiza los gastos
void descuento(tListaClientes &listaClientes);

#endif