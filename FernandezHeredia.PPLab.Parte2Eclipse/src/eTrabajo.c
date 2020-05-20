/*
 * eTrabajo.c
 *
 *  Created on: May 13, 2020
 *      Author: catalina
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "eTrabajo.h"
#include "eServicio.h"
#include "eNotebook.h"
#include "eMarca.h"
#include "eTipo.h"

//INICIALIZAR

int inicializarT(eTrabajo listaT[], int tamT)
{
	if(listaT != NULL)
	{
		for(int i = 0; i < tamT; i++)
		{
			listaT[i].isEmpty = 1;
		}
		return 0;
	}
	else
	{
		return -1;
	}
}

//--------------------------------------------------------------------------------------------------------------------------------------------------
//BUSCAR


int buscarLibreT(eTrabajo listaT[], int tamT)
{
	//-1 no consiguio lugar
	int indice = -1;//-1 no es una posicion en el vec
	for(int i = 0; i < tamT; i++)
	{
		if(listaT[i].isEmpty == 1)
		{
			indice = i; //devuelvo el valor que tiene el indice
			break;
		}
	}
	return indice;
}


int buscarTrabajoPorId(int id, eTrabajo listaT[], int tamT)
{
	int indice = -1;

	for(int i = 0; i < tamT; i++)
	{
		if(listaT[i].id == id && listaT[i].isEmpty == 0) //si el vec id existe ya, me devuelve donde esta
		{
			indice = i;
			break;
		}
	}

	return indice;
}


//--------------------------------------------------------------------------------------------------------------------------------------------------
//MOSTRAR


void mostrarTrabajo(eTrabajo trabajo, eServicio listaS[], int tamS)
{
	char descripS[20];
	float precioTrabajo = 0;
	cargarDescripServicio(descripS, trabajo.idServicio, listaS, tamS);

	for(int s = 0; s < tamS; s++)
	{
		if(trabajo.idServicio == listaS[s].id)
		{
			precioTrabajo = listaS[s].precio;
			break;
		}
	}

	printf("%d    %d      %10s     %.2f     %d/%d/%d\n\n", trabajo.id, trabajo.idNotebook, descripS, precioTrabajo, trabajo.fecha.dia, trabajo.fecha.mes, trabajo.fecha.anio);
}


void mostrarTrabajos(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS)
{
	printf("ID   ID notebook     Servicio     Precio       Fecha\n\n");
	for(int i = 0; i < tamT; i++)
	{
		if(listaT[i].isEmpty == 0)
		{
			mostrarTrabajo(listaT[i], listaS, tamS);
		}
	}
}

//ALTA

int altaTrabajo(int idX, eTrabajo listaT[], int tamT, eNotebook listaN[], int tamN, eServicio listaS[], int tamS, eMarca listaM[], int tamM, eTipo tipos[], int tamTipos)
{
	int todoOk = 0; //no pudo dar de alta
	int indice = buscarLibreT(listaT, tamT);
	int auxIdN;
	int auxIdS;
	int auxDia;
	int auxMes;
	int auxAnio;

	if(listaT != NULL && listaN != NULL && tamN > 0 && tamT > 0 && listaS != NULL && tamS > 0 && listaM != NULL && tamM > 0)
	{
		system("clear");
		printf("***** Alta Trabajo *****\n");
		if(indice < 0)
		{
			printf("Sistema completo.\n");
		}
		else
		{
			printf("Ingrese fecha DD/MM/AAAA: ");

			if(utn_getEntero(&auxDia, 3, "Ingrese dia del 1 al 31: ", "Incorrecto.\n", 1, 31) == 0 &&
					utn_getEntero(&auxMes, 3, "Ingrese mes del 1 al 12: ", "Incorrecto.\n", 1, 12) == 0 &&
					utn_getEntero(&auxAnio, 3, "Ingrese anio del 1990 al 2020: ", "Incorrecto.\n", 1990, 2020) == 0)

			{
				listaT[indice].fecha.dia = auxDia;
				listaT[indice].fecha.mes = auxMes;
				listaT[indice].fecha.anio = auxAnio;

				//scanf("%d/%d/%d", &listaT[indice].fecha.dia, &listaT[indice].fecha.mes, &listaT[indice].fecha.anio);
				mostrarNotebooks(listaN, tamN, tipos, tamTipos, listaM, tamT);
				if(utn_getEntero(&auxIdN, 3, "Ingrese id Notebook: ", "Error.", 1000, 1020) == 0)
				{
					if(buscarNotebookPorId(auxIdN, listaN, tamN) > -1)
					{
						listaT[indice].idNotebook = auxIdN;
						mostrarServicios(listaS, tamS);

						if(utn_getEntero(&auxIdS, 3, "Ingrese id Servicio: ", "El id ingresado no es valido.\n", 20000, 20003) == 0)
						{
							if(buscarServicioPorId(auxIdS, listaS, tamS) > -1)
							{

								listaT[indice].idServicio = auxIdS;
								listaT[indice].id = idX;
								listaT[indice].isEmpty = 0; //lleno el lugar
								todoOk = 1; //exito
							}
							else
							{
								printf("No existe ese servicio\n");
							}

						}

					}
					else
					{
						printf("No existe esa notebook\n");
					}
				}



			}


		}//if indice
	}//if NULL
	return todoOk;
}

