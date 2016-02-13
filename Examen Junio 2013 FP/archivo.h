#ifndef	archivo_h
#define archivo_h

#include "tListaClientes.h"

const char ARCHIVO[] = "llamadas.txt";
const char CENTINELA[] = "X"; 
//Funcion que carga del archivo definido más arriba los datos en la lista clientespasada por referencia
//Devuelve true siel archivo abre
bool cargaLlamadas(tListaClientes &listaClientes);

#endif