/*
 ============================================================================
 Name        : Parte2Eclipse.c
 Author      : Catalina Fernandez Heredia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "eMarca.h"
#include "eTipo.h"
#include "eServicio.h"
#include "eNotebook.h"
#include "eTrabajo.h"
#include "menus.h"
#include "informes.h"

#define LENN 20
#define LENT 20
#define TAMTIPO 4
#define LENM 4
#define LENS 4

int main(void) {

	eMarca marcas[LENM] = { {1000, "Compaq"},
					  {1001, "Asus"},
					  {1002, "Acer"},
					  {1003, "HP"} };

	eTipo tipos[TAMTIPO] = { {5000, "Gamer"},
					{5001, "Disenio"},
					{5002, "Ultrabook"},
					{5003, "Normalita"} };

	eServicio servicios[LENS] = { {20000, "Bateria", 250},
							{20001, "Antivirus", 300},
							{20002, "Actualizacion", 400},
							{20003, "Fuente", 600} };
	eNotebook listaN[LENN] = { {1000, "A", 1000, 5000, 50000, 0},
							   {1001, "B", 1002, 5003, 51000, 0},
							   {1002, "C", 1001, 5001, 37000, 0},
							   {1003, "D", 1000, 5003, 37000, 0},
							   {1004, "E", 1001, 5001, 37000, 0} };
	eTrabajo listaT[LENT] = { {1000, 1000, 20000, {12, 4, 2020}, 0},
							  {1001, 1002, 20001, {13, 5, 1996}, 0},
							  {1002, 1001, 20000, {1, 11, 2007}, 0},
							  {1003, 1002, 20003, {3, 5, 1997}, 0},
							  {1004, 1000, 20001, {4, 3, 2019}, 0},};
	eMarcaMasElegida listaMME[LENM];

	char continueS = 's';
	char confirm;


	//Flags Alta:
	int flagN = 1; //VOLVER A 0 DESPUES DE HARCODEAR
	int flagT = 1; //VOLVER A 0 DESPUES DE HARCODEAR

	//Inicializar arrays:
	inicializarN(listaN, LENN);
	inicializarT(listaT, LENT);

	//FORS PARA OCUPAR IS EMPTY, BORRAR LUEGO DE HARCODEAR:
	for(int n = 0; n < 5; n++)
	{
		listaN[n].isEmpty = 0;
	}
	for(int t = 0; t < 5; t++)
	{
		listaT[t].isEmpty = 0;
	}


	do
	{
		system("clear");
		switch(menu())
		{
			case 1:
				alta( &flagN,  &flagT, listaT, LENT, listaN, LENN, tipos, TAMTIPO, marcas, LENM, servicios, LENS);
				break;

			case 2:
				baja(flagN, listaN, LENN, marcas, LENM, tipos, TAMTIPO);
				break;

			case 3:
				modificacionNotebook(flagN, listaN, LENN, tipos, TAMTIPO, marcas, LENM);
				break;

			case 4:
				listar(flagN, flagT, listaN, LENN, tipos, TAMTIPO, marcas, LENM, listaT, LENT, servicios, LENS);
				break;
			case 5:
				informar(listaN, LENN, marcas, LENM, listaT, LENT, servicios, LENS, tipos, TAMTIPO, listaMME);
				break;

			case 6:
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
		pause();


	}while(continueS == 's');


	return EXIT_SUCCESS;
}
