#include "tLlamada.h"

#include <iostream>
using namespace std;
#include <iomanip>

void calculaCoste(tLlamada &llamada)
{
	//Coste de llamada (duracion en minutos * costeMinuto + establecimientDeLlamada)
	llamada.coste = (llamada.duracion / 60) * COSTE_POR_MINUTO + ESTABLECIMIENTO;
}
void muestraLlamada(tLlamada llamada)
{
	cout << setw(TAM_FECHA) << llamada.fecha << setw(6) << llamada.duracion << " seg. " << setw (5) << setprecision(2) << fixed << llamada.coste << " Eur" << endl ;
}