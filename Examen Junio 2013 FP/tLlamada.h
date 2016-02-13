#ifndef	tLlamadas_h
#define tLlamadas_h

const int TAM_FECHA = 9;

const double COSTE_POR_MINUTO = 0.08;
const double ESTABLECIMIENTO = 0.15;

typedef char tFecha[TAM_FECHA];

typedef struct
{
	tFecha fecha;
	int duracion;
	double coste;
} tLlamada;
// Procedimiento que calcula el coste de una llamada, 
// toma los datos de duracion del parametro tLlamda, y actualiza el coste de la misma
void calculaCoste(tLlamada &llamada);
// Procedimiento que muestra los datos de la llamda pasada como parámetro
void muestraLlamada(tLlamada llamada);

#endif