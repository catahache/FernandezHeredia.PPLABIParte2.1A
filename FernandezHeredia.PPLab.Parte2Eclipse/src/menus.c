/*
 * menus.c
 *
 *  Created on: May 13, 2020
 *      Author: catalina
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menus.h"
#include "utn.h"
#include "eNotebook.h"
#include "eTrabajo.h"

//MAIN:

int menu()
{
	int opcion;

	system("clear");
	printf("***** MENU *****\n\n");
	printf("1. ALTAS\n");
	printf("2. BAJAS\n");
	printf("3. MODIFICACIONES\n");
	printf("4. LISTAS\n");
	printf("5. INFORMES\n");
	printf("6. SALIR\n\n");
	utn_getEntero(&opcion, 3, "Ingrese la opcion elegida: ", "Error, no es una opcion valida.\n", 1, 6);

	return opcion;

}

//ALTAS:

int menuAltas()
{
	int opcion;

	system("clear");
	printf("***** Altas *****\n");
	printf("1. Notebook\n");
	printf("2. Trabajos\n");
	printf("3. Salir\n\n");
	utn_getEntero(&opcion, 3, "Ingrese la opcion elegida: ", "Error, no es una opcion valida.\n", 1, 3);

	return opcion;

}

//esta es la funcion que llamo en main:
void alta(int* flagN, int* flagT, eTrabajo listaT[], int tamT, eNotebook listaN[], int tamN,  eTipo listaTipo[], int tamTipo, eMarca listaM[], int tamM, eServicio listaS[], int tamS)
{

	char continueS = 's';
	char confirm;

	int idN = 1000;
	int idT = 1000;

	if(flagN != NULL && listaN != NULL && flagT != NULL && listaTipo != NULL && listaM != NULL && listaS != NULL)
	{
		do
		{
			switch(menuAltas())
			{
				case 1:
					if(altaNotebook(idN, listaN, tamN, listaTipo, tamTipo, listaM, tamM) == 1)
					{
						idN++;
						*flagN = 1;
					}
					break;
				case 2:
					if(altaTrabajo(idT, listaT, tamT, listaN, tamN, listaS, tamS, listaM, tamM, listaTipo, tamTipo)  == 1)
					{
						idT++;
						*flagT = 1;
					}
					break;
				case 3:
					system("clear");
					printf("\n***** Salir *****\n\n ");
					printf("Confirma salida? s/n: ");
					fpurge(stdin);
					scanf("%c", &confirm);
					if(confirm == 's')
					{
						continueS = 'n';
					}
					break;
				default:
					printf("No es una opcion valida.\n");

			}
		}while(continueS == 's');
	}
}

//BAJAS:


//esta es la funcion que llamo en main para dar de baja:
void baja(int flagN, eNotebook listaN[], int tamN, eMarca listaM[], int tamM, eTipo listaTipos[], int tamTipos)
{

	int idN;


	if(listaN != NULL && listaM != NULL && listaTipos != NULL)
	{

		if(flagN == 1)
		{
			mostrarNotebooks(listaN, tamN, listaTipos, tamTipos, listaM, tamM);
			utn_getEntero(&idN, 3, "Ingrese el id del generico a eliminar: ", "Error,id no valido.\n", 1000, 1020);
			if(bajaNotebook(idN, flagN, listaN, tamN, listaTipos, tamTipos, listaM, tamM)  == 1)
			{
				printf("Se ha eliminado la notebook con exito.\n\n");
			}
		}
		else
		{
			printf("Error. No hay notebooks cargadas.\n");
		}

	}//if null
}



//esta es la funcion que llamo en main para modificar:



//LISTAS:
int menuListas()
{
	int opcion;

	system("clear");
	printf("***** Listar *****\n");
	printf("1. Notebooks\n");
	printf("2. Marcas\n");
	printf("3. Tipos\n");
	printf("4. Sevicios\n");
	printf("5. Trabajos\n");
	printf("6. Salir\n\n");
	utn_getEntero(&opcion, 3, "Ingrese la opcion elegida: ", "Error, no es una opcion valida.\n", 1, 6);

	return opcion;
}

//esta es la funcion que llamo en main para listar:
void listar(int flagN, int flagT, eNotebook listaN[], int tamN, eTipo listaTipo[], int tamTipo, eMarca listaM[], int tamM, eTrabajo listaT[], int tamT, eServicio listaS[], int tamS)
{
	int orden;
	char continuar = 's';
	char confirmar;

	do
	{
		switch(menuListas())
		{
			case 1:
				//notebooks
				if(flagN == 1)
				{
					//Ascendente o descendente? :
					utn_getEntero(&orden, 3, "Ascendente 1, Descendente 0: ", "Error, no es un criterio\n", 0, 1);
					ordenarNotebooks(listaN, tamN, orden);
					mostrarNotebooks(listaN, tamN, listaTipo, tamTipo, listaM, tamM);
				}
				else
				{
					printf("Error. No hay notebooks cargadas.\n");
				}
				break;
			case 2:
				//marca
				mostrarMarcas(listaM, tamM);
				break;
			case 3:
				//tipos
				mostrarTipos(listaTipo, tamTipo);
				break;
			case 4:
				//servicios
				mostrarServicios(listaS, tamS);
				break;
			case 5:
				//trabajos
				if(flagT == 1)
				{
					mostrarTrabajos(listaT, tamT, listaS, tamS);
				}
				else
				{
					printf("Error. No hay trabajos cargados.\n");
				}
				break;
			case 6:
				//salir
				system("clear");
				printf("\n***** Salir *****\n\n ");
				printf("Confirma salida? s/n: ");
				fpurge(stdin);
				scanf("%c", &confirmar);
				if(confirmar == 's')
				{
					continuar = 'n';
				}
				break;
			default:
				printf("No es una opcion valida.\n");

		}

	}while(continuar == 's');

}









