#include "archivo.h"

#include <fstream>
using namespace std;
#include <cstring>
#include <iomanip>

bool cargaLlamadas(tListaClientes &listaClientes)
{
	bool salida = true, noInsertar;
	//Auxiliares
	tLlamada llamadaAux;
	tNif nifAux;

	int pos; //Para la posicion en la que insertar

	listaClientes.contador = 0;

	ifstream archivo;

	archivo.open(ARCHIVO);

	if (archivo.is_open())
	{
		salida = true;

		archivo >> setw(TAM_NIF) >> nifAux;
		while (strcmp(nifAux, CENTINELA) != 0) //Mientras no lea el centinela
		{
			noInsertar = false; //Aunque llene la lista, puedo seguir insertando llamadas
			pos = buscaCliente(listaClientes, nifAux); 
			if (pos == -1) //No he encontrado el cliente, voy a insertar al final, pos = lista.contador
			{
				noInsertar = (listaClientes.contador == MAX_CLIENTES); //Por si la lista se llena (si la lista se llena entonces no insertar = true)
				if (!noInsertar) //Solo inserto si no lo he llenado
				{
					pos = listaClientes.contador;
					inicializa(listaClientes.lista[listaClientes.contador].lista); //Inicializo el nuevo cliente su (lista de llamadas)
					listaClientes.lista[pos].gasto = 0.0; //Inicializo su gasto
					strcpy (listaClientes.lista[pos].nif, nifAux); //Le pongo su nif (el que he leido antes)
					listaClientes.contador++; //ActualizoContador
				}
			}
			//else pos apunta a la posicion del cliente
			if(!noInsertar) //Si noInsertar esta a true, quiere decir que he intentado introducir un nuevo cliente cuando la lista estaba llena, 
				//y por tanto el codigo que sigue introducuria los datos en posiciones erroneas
			{
				//Leo la llamada
				archivo >> setw(TAM_FECHA) >> llamadaAux.fecha;
				archivo >> llamadaAux.duracion;
				calculaCoste(llamadaAux);
				//Aumento el gasto del cliente con la ult llamada
				listaClientes.lista[pos].gasto += llamadaAux.coste;
				//Inserto la llamada (paso la lista de llamadas del cliente con el que estoy trabajando y la llamda auxiliar
				insertaLlamada(listaClientes.lista[pos].lista, llamadaAux);
			}
			//Leo el siguiente nif (puede ser centinela)
			archivo >> setw(TAM_NIF) >> nifAux;
		}
		archivo.close();
	}

	return salida;
}