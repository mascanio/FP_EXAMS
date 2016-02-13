#ifndef	tCliente_h
#define tCliente_h

#include "tListaLlamadas.h"

const int TAM_NIF = 10;

typedef char tNif[TAM_NIF];

typedef struct
{
	tNif nif;
	double gasto;
	tListaLlamadas lista;
} tCliente;
//Procedimiento que muestra en pantalla el cliente pasado por parametro
void muestraCliente(tCliente cliente);

#endif