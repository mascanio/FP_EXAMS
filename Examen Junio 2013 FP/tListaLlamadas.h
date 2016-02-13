#ifndef tListaLlamadas_h
#define	tListaLlamadas_h

#include "tLlamada.h"

const int MAX_LLAMADAS = 100;

typedef tLlamada *tPtrLlamada; //Tipo puntero a llamadas

typedef struct
{
	int contador;
	tPtrLlamada lista; //Puntero a dinamico
} tListaLlamadas;
//Funcion operador < sobrecargada para dos tLlamadas, devuelve true si izq.fecha < que der.fecha
bool operator<(tLlamada izq, tLlamada der);
//Procedimiento que inicializa la lita de llamadas pasada como parametro 
//(contador a 0 y puntero apuntando a espacio reservado (en el propio procedimiento) en el heap
void inicializa(tListaLlamadas &lista);
//Insterta la llamada pasada como parametro en la listaLlamadas pasada tambien como parametro
//realiza una insercion ordenada deacuerdo al operator definido mas arriba
bool insertaLlamada(tListaLlamadas &listaLlamadas, tLlamada llamada);

#endif