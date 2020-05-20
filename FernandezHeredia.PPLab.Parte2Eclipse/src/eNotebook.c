/*
 * eNotebook.c
 *
 *  Created on: May 13, 2020
 *      Author: catalina
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "eNotebook.h"
#include "eTipo.h"
#include "eMarca.h"

//INICIALIZAR


int inicializarN(eNotebook listaN[], int tamN)
{
	if(listaN != NULL)
	{
		for(int i = 0; i < tamN; i++)
		{
			listaN[i].isEmpty = 1;
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


int buscarLibreN(eNotebook listaN[], int tamN)
{
	//-1 no consiguio lugar
	int indice = -1;//-1 no es una posicion en el vec
	for(int i = 0; i < tamN; i++)
	{
		if(listaN[i].isEmpty == 1)
		{
			indice = i; //devuelvo el valor que tiene el indice
			break;
		}
	}
	return indice;
}


int buscarNotebookPorId(int id, eNotebook listaN[], int tamN)
{
	int indice = -1;

	for(int i = 0; i < tamN; i++)
	{
		if(listaN[i].id == id && listaN[i].isEmpty == 0) //si el vec id existe ya, me devuelve donde esta
		{
			indice = i;
			break;
		}
	}

	return indice;
}


//--------------------------------------------------------------------------------------------------------------------------------------------------
//MOSTRAR


void mostrarNotebook(eNotebook notebook, eTipo tipos[], int tamTipos, eMarca listaM[], int tamM)
{
	char descripTipo[20];
	char descripMarca[20];

	cargarDescripTipo(descripTipo, notebook.idTipo, tipos, tamTipos);
	cargarDescripMarca(descripMarca, notebook.idMarca, listaM, tamM);
	printf("%d    %10s      %10s     %10s      %.2f\n\n", notebook.id, notebook.modelo, descripMarca, descripTipo, notebook.precio);
}


void mostrarNotebooks(eNotebook listaN[], int tamN, eTipo tipos[], int tamTipos, eMarca listaM[], int tamM)
{
	printf("ID           Modelo          Marca          Tipo        Precio\n\n");
	for(int i = 0; i < tamN; i++)
	{
		if(listaN[i].isEmpty == 0)
		{
			mostrarNotebook(listaN[i], tipos, tamTipos, listaM, tamM);
		}
	}
}


//--------------------------------------------------------------------------------------------------------------------------------------------------
//ORDENAR

int ordenarNotebooks(eNotebook listaN[], int tamN, int orden)
{
	int isOk = -1;
	eNotebook auxN;

	if(listaN != NULL)
	{
		for(int i = 0; i < tamN -1; i++)
		{
			for(int j = i + 1; j < tamN; j ++)
			{
				if(listaN[i].isEmpty == 0 && listaN[j].isEmpty == 0) //solo hace el burbujeo si no estan vacias las posiciones
				{

					if(orden == 1)
					{
						if(listaN[i].idTipo > listaN[j].idTipo || (listaN[i].idTipo == listaN[j].idTipo && listaN[i].precio > listaN[j].precio)) //de menor a mayor sector (agrupa) y apellido (ordena)
						{
							auxN = listaN[i];
							listaN[i] = listaN[j];
							listaN[j] = auxN;
						}

					}
					else if(orden == 0)
					{
						if(listaN[i].idTipo < listaN[j].idTipo || (listaN[i].idTipo == listaN[j].idTipo && listaN[i].precio < listaN[j].precio)) //de mayor a menor sector (agrupa) y apellido (ordena)
						{
							auxN = listaN[i];
							listaN[i] = listaN[j];
							listaN[j] = auxN;
						}

					}//else if
				}//if isEmpty
			}//for
		}//for
		isOk = 0;
	}//if list != NULL
	return isOk;
}


//ALTA

int altaNotebook(int idX, eNotebook listaN[], int tamN, eTipo listaT[], int tamT, eMarca listaM[], int tamM)
{
	int todoOk = 0; //no pudo dar de alta
	int indice = buscarLibreN(listaN, tamN);

	if(listaN != NULL && listaT != NULL && tamN > 0 && tamT > 0 && listaM != NULL && tamM > 0)
	{
		system("clear");
		printf("***** Alta Notebook *****\n");
		if(indice < 0)
		{
			printf("Sistema completo.\n");
		}
		else
		{
			if(utn_getCadena(listaN[indice].modelo, 30, 3, "\nIngrese Modelo: ", "El modelo ingresado es invalido.\n") == 0)
			{
				mostrarMarcas(listaM, tamM);

				if(utn_getEntero(&listaN[indice].idMarca, 3, "Ingrese id marca: ", "El id ingresado no es valido.\n", 1000, 1003) == 0)
				{
					mostrarTipos(listaT, tamT);
					if(utn_getEntero(&listaN[indice].idTipo, 3, "Ingrese id tipo: ", "El id ingresado no es valido.\n", 5000, 5003) == 0 && utn_getFlotante(&listaN[indice].precio, 3, "Ingrese precio de 5000 a 100000: ", "Error, el precio ingresado no es valido\n", 5000, 100000) == 0)
					{
						listaN[indice].id = idX;
						listaN[indice].isEmpty = 0; //lleno el lugar
						todoOk = 1; //exito
					}

				}
			}
		}//if indice
	}//if NULL

	return todoOk;
}

//BAJA

int bajaNotebook(int idN, int flagN, eNotebook listaN[], int tamN, eTipo listaTipos[], int tamTipos, eMarca listaM[], int tamM)
{
	int isOk = 0;
	char eliminarN;
	int indiceN;

	if(flagN == 1)
	{
		indiceN = buscarNotebookPorId(idN, listaN, tamN); //busca con el ID que conseguimos en la funcion baja y devuelve el indice donde esta o -1
		if(indiceN > -1)
		{
			mostrarNotebook(listaN[indiceN], listaTipos, tamTipos, listaM, tamM);//muestra la notebook a eliminar
			printf("Eliminar? s/n: ");
			scanf("%c", &eliminarN);
			if(eliminarN == 's')
			{
				listaN[indiceN].isEmpty = 1; //eliminar
				isOk = 1;
			}
			else
			{
				printf("No se han realizado cambios.\n");
			}
		}
		else
		{
			printf("No existe notebook con ese id.\n");
		}
	}
	else
	{
		printf("No hay notebooks cargadas\n");
	}
	return isOk;
}

//MODIFICACION

int modificacionNotebook(int flagN, eNotebook listaN[], int tamN, eTipo listaT[], int tamT, eMarca listaM[], int tamM)
{
	int isOk = -1;
	int auxId;
	int opcion;
	char confirmar;
	char continuar;
	int indice;

	float nuevoPrecio;
	int nuevoTipo;

	system("clear");
	printf("***** Modificar *****\n\n");

	if(flagN == 1 && listaN != NULL && listaT != NULL && listaM != NULL)
	{
		mostrarNotebooks(listaN, tamN, listaT, tamT, listaM, tamM);

		if(listaN != NULL && tamN > 0 && utn_getEntero(&auxId, 3, "\nIngrese ID de la notebook a modificar: ", "Error. No es un ID.\n", 1000, 1020) == 0 )
		{
			indice = buscarNotebookPorId(auxId, listaN, tamN);

			if(indice == -1)
			{
				printf("No existe ese ID en el sistema.\n");
			}
			else
			{
				printf("El ID %d pertenece a la siguiente notebook:\n", auxId);
				printf("ID    Modelo    Marca    Tipo     Precio\n\n");
				mostrarNotebook(listaN[indice], listaT, tamT, listaM, tamM);
				printf("Desea modificarla? s/n: ");
				fpurge(stdin);
				scanf("%c", &confirmar);

				if(confirmar == 's')
				{
					do
					{
						system("clear");
						printf("    1. Modificar precio\n");
						printf("    2. Modificar tipo\n");
						if(utn_getEntero(&opcion, 3, "Ingrese opcion a modificar: ", "Error, no es una opcion valida", 1, 2) == 0)
						{
							switch(opcion) //copio los nuevos valores
							{
								case 1:
									if(utn_getFlotante(&nuevoPrecio, 3, "Ingrese nuevo precio de 5000 a 100000: ", "Error, invalido.\n", 5000, 100000) == 0)
									{
										listaN[indice].precio = nuevoPrecio;
										isOk= 0;
									}
									break;
								case 2:
									mostrarTipos(listaT, tamT);
									if(utn_getEntero(&nuevoTipo, 3, "Ingrese id nuevo tipo: ", "Error, invalido\n", 5000, 5003) == 0)
									{
										listaN[indice].idTipo = nuevoTipo;
										isOk= 0;
									}
									break;
								default:
									printf("No es una opcion valida.\n\n");
							}
							if(isOk == 0)
							{
								printf("Se han modificado los datos correctamente. \n");
								printf("ID    Modelo    Marca    Tipo     Precio\n\n");
								mostrarNotebook(listaN[indice], listaT, tamT, listaM, tamM);
							}
							printf("Desea seguir modificando? s/n: ");
							fpurge(stdin);
							scanf("%c", &confirmar);
							if(confirmar == 's')
							{
								continuar = 'n';
							}
						}//if opcion a modificar == 0
					}while(continuar == 's');
				}//if confirma
				else if(confirmar == 'n')
				{
					printf("No se han registrado modificaciones.\n");
				}
			}//else
		}//if NULL
	}//if flagM == 1
	else
	{
		printf("No hay que modificar.\n");

	}

	return isOk;
}
