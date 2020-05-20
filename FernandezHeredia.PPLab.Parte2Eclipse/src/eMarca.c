/*
 * eMarca.c
 *
 *  Created on: May 13, 2020
 *      Author: catalina
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "eMarca.h"


int cargarDescripMarca(char descripcion[], int idMarca, eMarca marcas[], int tamM)
{
	int isOk = 0;

	for(int i = 0; i < tamM; i++)
	{
		if(marcas[i].id == idMarca) //si el id del sector es igual al id sector que estoy buscando(lo pase por parametros)
		{
			strcpy(descripcion, marcas[i].descripcion); //copio a descripcion la descripcion que tengo en ese sector
			isOk = 1; //exito
			break;
		}
	}

	return isOk;
}


int mostrarMarcas(eMarca marcas[], int tamM)
{
	int isOk = 0;
	if(marcas != NULL)
	{
		isOk = 1;
		printf("*** Marcas ***\n");
		printf("  ID     Descripcion\n\n");

		for(int i = 0; i < tamM; i++)
		{
			printf("%d   %10s \n", marcas[i].id, marcas[i].descripcion);
		}
	}
	return isOk;
}

void mostrarMarca(eMarca marca)
{

	printf("%d   %10s \n", marca.id, marca.descripcion);

}


int buscarMarcaPorId(int id, eMarca listaM[], int tamM)
{
	int indice = -1;

	for(int i = 0; i < tamM; i++)
	{
		if(listaM[i].id == id) //si el vec id existe ya, me devuelve donde esta
		{
			indice = i;
			break;
		}
	}

	return indice;
}
