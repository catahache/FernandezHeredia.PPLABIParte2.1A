/*
 * eServicio.c
 *
 *  Created on: May 13, 2020
 *      Author: catalina
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "eServicio.h"


int cargarDescripServicio(char descripcion[], int idS, eServicio servicios[], int tamS)
{
	int isOk = 0;

	for(int i = 0; i < tamS; i++)
	{
		if(servicios[i].id == idS) //si el id del sector es igual al id sector que estoy buscando(lo pase por parametros)
		{
			strcpy(descripcion, servicios[i].descripcion); //copio a descripcion la descripcion que tengo en ese sector
			isOk = 1; //exito
			break;
		}
	}

	return isOk;
}


int mostrarServicios(eServicio servicios[], int tamS)
{
	int isOk = 0;
	if(servicios != NULL)
	{
		isOk = 1;
		printf("*** Servicios ***\n");
		printf("  ID     Descripcion   Precio\n\n");

		for(int i = 0; i < tamS; i++)
		{
			printf("%d   %10s   %.2f\n", servicios[i].id, servicios[i].descripcion, servicios[i].precio);
		}
	}
	return isOk;
}


int buscarServicioPorId(int id, eServicio listaS[], int tamS)
{
	int indice = -1;

	for(int i = 0; i < tamS; i++)
	{
		if(listaS[i].id == id) //si el vec id existe ya, me devuelve donde esta
		{
			indice = i;
			break;
		}
	}

	return indice;
}
