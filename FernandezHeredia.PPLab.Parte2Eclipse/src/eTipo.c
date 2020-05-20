/*
 * eTipo.c
 *
 *  Created on: May 13, 2020
 *      Author: catalina
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "eTipo.h"

int cargarDescripTipo(char descripcion[], int idTipo, eTipo tipos[], int tamT)
{
	int isOk = 0;

	for(int i = 0; i < tamT; i++)
	{
		if(tipos[i].id == idTipo) //si el id del sector es igual al id sector que estoy buscando(lo pase por parametros)
		{
			strcpy(descripcion, tipos[i].descripcion); //copio a descripcion la descripcion que tengo en ese sector
			isOk = 1; //exito
			break;
		}
	}
	return isOk;
}


int mostrarTipos(eTipo tipos[], int tamT)
{
	int isOk = 0;
	if(tipos != NULL)
	{
		isOk = 1;
		printf("*** Tipos ***\n");
		printf("  ID      Descripcion\n\n");

		for(int i = 0; i < tamT; i++)
		{
			printf("%d   %10s \n", tipos[i].id, tipos[i].descripcion);
		}
	}
	return isOk;
}

int buscarTipoPorId(int id, eTipo tipos[], int tamTipos)
{
	int indice = -1;

	for(int i = 0; i < tamTipos; i++)
	{
		if(tipos[i].id == id) //si el vec id existe ya, me devuelve donde esta
		{
			indice = i;
			break;
		}
	}

	return indice;
}
