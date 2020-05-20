/*
 * informes.c
 *
 *  Created on: May 18, 2020
 *      Author: catalina
 */

/*
1-	Mostrar las notebooks del tipo seleccionado por el usuario.
2-	Mostrar notebooks de una marca seleccionada.
3-	Informar la o las notebooks más baratas.
4-	Mostrar un listado de las notebooks separadas por marca.
5-	Elegir un tipo y una marca y contar cuantas notebooks hay de ese tipo y esa marca.
6-	Mostrar la o las marcas más elegidas por los clientes.

7-	Pedir una notebook y mostrar todos los trabajos que se le hicieron a la misma.
8-	Pedir un notebook e informar la suma de los importes de los services se le hicieron a la misma.
9-	Pedir un servicio y mostrar las notebooks a las que se realizó ese servicio y la fecha.
10-	Pedir una fecha y mostrar todos los servicios realizados en la misma.


 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"
#include "eMarca.h"
#include "eTipo.h"
#include "utn.h"


void informar(eNotebook listaN[],int tamN, eMarca listaM[], int tamM, eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eTipo tipos[], int tamTipos, eMarcaMasElegida listaMME[])
{
	char seguir = 's';
	char confirmar;

	do{
		switch(menuInformes())
		{
			case 'a':
				informarNotebooksPorTipo(listaN, tamN, tipos, tamTipos, listaM, tamM);
				break;
			case 'b':
				informarNotebooksPorMarca(listaN, tamN, listaM, tamM, listaM, tamM);
				break;
			case 'c':
				informarNotebookMasBarata(listaN, tamN, tipos, tamTipos, listaM, tamM);
				break;
			case 'd':
				informarTodasNotebooksMarca(listaN, tamN, tipos, tamTipos, listaM, tamM);
				break;
			case 'e':
				//Elegir un tipo y una marca y contar cuantas notebooks hay de ese tipo y esa marca.
				informarNporTipoyMarca(listaN, tamN, tipos, tamTipos, listaM, tamM);
				break;
			case 'f':
				inicializarMME(listaMME, tamM); //le paso el tamanio de las marcas, porque es el mismo
				informarMarcaMasElegida(listaN, tamN, tipos, tamTipos, listaM, tamM, listaMME);
				break;
			case 'g':
				cantidadTrabajosPorNotebook(listaN, tamN, tipos, tamTipos, listaM, tamM, listaT, tamT, listaS, tamS);
				break;
			case 'h':
				sumaDeServiciosPorNotebook(listaN, tamN, tipos, tamTipos, listaM, tamM, listaT, tamT, listaS, tamS);
				break;
			case 'i':
				printf("Confirma salida? s/n: ");
				fpurge(stdin);
				scanf("%c", &confirmar);
				if(confirmar == 's')
				{
					seguir = 'n';
				}
				break;
			default:
				printf("Ingrese una opcion disponible\n\n");
		}
		pause();

	}while(seguir == 's');

}



char menuInformes()
{
	char opcion;

	system("clear");

	printf("***** Menu de informes *****\n\n");
	printf("a. Mostrar las notebooks del tipo seleccionado.\n");
	printf("b. Mostrar notebooks de una marca seleccionada.\n");
	printf("c. Informar la o las notebooks más baratas.\n");
	printf("d. Mostrar un listado de las notebooks separadas por marca.\n");
	printf("e. Cuantas notebooks hay de un tipo y una marca.\n");
	printf("f. Mostrar la o las marcas más elegidas por los clientes.\n");
	printf("g. Trabajos por notebook.\n");
	printf("h. Total Servicios por Notebook.\n");
	printf("i. Salir\n\n");
	printf("Ingrese la opcion elegida: ");
	fpurge(stdin);
	scanf("%c", &opcion);

	return opcion;

}


//A
void informarNotebooksPorTipo(eNotebook listaN[], int tamN, eTipo tipos[], int tamTipos, eMarca listaM[], int tamM)
{
	int tipo;
	int flag = 0;

	system("clear");
	printf("***** Informe Notebooks por un Tipo *****\n\n");

	mostrarTipos(tipos, tamTipos);
	utn_getEntero(&tipo, 3,"Ingrese el id del tipo al que pertenecen las notebooks a listar: ", "Id invalido.\n", 5000, 5003);

	printf("ID           Modelo          Marca          Tipo        Precio\n\n");
	for(int i = 0; i < tamN ; i++)
	{
		if(listaN[i].isEmpty == 0 && listaN[i].idTipo == tipo)
		{
			mostrarNotebook(listaN[i], tipos, tamTipos, listaM, tamM);
			flag = 1;
		}
	}
	if(flag == 0)
	{
		printf("No hay notebooks de este tipo.\n\n");
	}
}

//B
void informarNotebooksPorMarca(eNotebook listaN[], int tamN, eTipo tipos[], int tamTipos, eMarca listaM[], int tamM)
{
	int marca;
	int flag = 0;

	system("clear");
	printf("***** Informe Notebooks por un Marca *****\n\n");

	mostrarMarcas(listaM, tamM);
	utn_getEntero(&marca, 3,"Ingrese el id de la marca a la que pertenecen las notebooks a listar: ", "Id invalido.\n", 1000, 1003);

	printf("ID           Modelo          Marca          Tipo        Precio\n\n");
	for(int i = 0; i < tamN ; i++)
	{
		if(listaN[i].isEmpty == 0 && listaN[i].idMarca == marca)
		{
			mostrarNotebook(listaN[i], tipos, tamTipos, listaM, tamM);
			flag = 1;
		}
	}
	if(flag == 0)
	{
		printf("No hay notebooks de esta marca.\n\n");
	}
}

//C
void informarNotebookMasBarata(eNotebook listaN[], int tamN, eTipo tipos[], int tamTipos, eMarca listaM[], int tamM)
{
	float masBarata;
	int flag = 0;

	system("clear");
	printf("***** Informe Notebooks Mas Baratas *****\n\n");

	for(int i = 0; i < tamN; i++)
	{
		if(flag == 0 && listaN[i].isEmpty == 0)
		{
			masBarata = listaN[i].precio;
			flag = 1;
		}
		else if (listaN[i].isEmpty == 0 && listaN[i].precio < masBarata)
		{
			masBarata = listaN[i].precio;
		}
	}
	printf("El precio de las notebooks mas baratas es de: $ %.2f y son las siguientes: \n\n", masBarata);
	printf("ID           Modelo          Marca          Tipo        Precio\n\n");
	for(int i = 0; i < tamN; i++)
	{
		if(listaN[i].precio == masBarata)
		{
			mostrarNotebook(listaN[i], tipos, tamTipos, listaM, tamM);
		}
	}
}

//D
void informarTodasNotebooksMarca(eNotebook listaN[], int tamN, eTipo tipos[], int tamTipos, eMarca listaM[], int tamM)
{
	int flag;

	system("clear");
	printf("***** Informe Notebooks Ordenadas por Marca *****\n\n");

	for(int m = 0; m < tamM; m++)
	{
		flag = 0;//para la sig marca tengo que volver a poner la bandera en 0
		printf("\n---------------------------------------------------------------------------------------------\n");
		printf("\nMarca: %s\n\n", listaM[m].descripcion);
		printf("ID           Modelo          Marca          Tipo        Precio\n\n");

		for(int n = 0; n < tamN; n++)
		{
			if(listaN[n].isEmpty == 0 &&  listaN[n].idMarca == listaM[m].id)
			{
				mostrarNotebook(listaN[n], tipos, tamTipos, listaM, tamM);
				flag = 1;
			}
		}
		printf(" ");
		if(flag == 0)
		{
			printf("No hay notebooks de esta marca en el sistema.\n");
		}
	}
}

//F
//Elegir un tipo y una marca y contar cuantas notebooks hay de ese tipo y esa marca.
void informarNporTipoyMarca(eNotebook listaN[], int tamN, eTipo tipos[], int tamTipos, eMarca listaM[], int tamM)
{
	int flag = 0;
	int idTipo;
	int idMarca;
	int indiceTipo;
	int indiceMarca;
	int cantidad = 0;

	system("clear");
	printf("***** Informe Cantidad de Notebooks por Tipo y Marca *****\n\n");

	mostrarTipos(tipos, tamTipos);
	utn_getEntero(&idTipo, 3, "Ingrese el id del tipo de notebook a contar: ", "Error, id invalido.\n", 5000, 5003);

	mostrarMarcas(listaM, tamM);
	utn_getEntero(&idMarca, 3, "Ingrese el id de la marca de notebook a contar: ", "Error, id invalido.\n", 1000, 1003);

	indiceTipo = buscarTipoPorId(idTipo, tipos, tamTipos);
	indiceMarca = buscarMarcaPorId(idMarca, listaM, tamM);

	//printf("Las notebooks con el tipo %s y la marca %s son:\n\n", tipos[indiceTipo], listaM[indiceMarca]);
	//printf("ID    Modelo    Marca    Tipo     Precio\n\n");
	for(int n = 0; n < tamN; n++)
	{
		if(listaN[n].isEmpty == 0 && listaN[n].idMarca == idMarca && listaN[n].idTipo == idTipo)
		{
			//mostrarNotebook(listaN[n], tipos, tamTipos, listaM, tamM);
			cantidad++;
			flag = 1;
		}

	}

	if(flag == 0)
	{
		printf("No hay notebooks con ese tipo y marca\n\n");
	}
	else
	{
		printf("La cantidad de notebooks de tipo %s y marca %s es de: %d\n\n", tipos[indiceTipo].descripcion, listaM[indiceMarca].descripcion, cantidad);
	}

}

//G
//Mostrar la o las marcas más elegidas por los clientes.
void informarMarcaMasElegida(eNotebook listaN[], int tamN, eTipo tipos[], int tamTipos, eMarca listaM[], int tamM, eMarcaMasElegida listaMME[])
{
	int contadorM;
	int mme = 0;
	eMarcaMasElegida auxMME; //en esta estruct me va a guardar la marca mas elegida
	int flag = 0;
	int indiceMarca;


	system("clear");
	printf("***** Informe Marcas Mas Elegidas *****\n\n");

	for(int m = 0; m < tamM; m++) //recorro marcas
	{
		contadorM = 0; //reinicio el contador

		for(int n = 0; n < tamN; n++) //recorro notebooks
		{
			if(listaN[n].isEmpty == 0 && listaN[n].idMarca == listaM[m].id) //si el id de la notebook coincide con el id de la marca, contador++
			{
				contadorM++;
			}
		}

		listaMME[mme].idMarca = listaM[m].id;
		listaMME[mme].cantElegida = contadorM;
		listaMME[mme].isEmpty = 0; //ocupo el lugar
		mme++; //para que el la prox iteracion entre en otro lugar del vector listaMME

	}

	/* para corroborar que cuente bien:
	for(int mme = 0; mme < tamM; mme++)
	{
		printf("id marca     cantidad de veces elegida\n\n");
		printf("%d           %d\n", listaMME[mme].idMarca, listaMME[mme].cantElegida);
	}
	*/

	for(int mme = 0; mme < tamM; mme++)
	{
		if(flag == 0)
		{
			auxMME = listaMME[mme]; //si es la primera iteracion, la primer posicion es la que tiene mayor cantidad
			flag = 1;
		}
		else if(listaMME[mme].cantElegida > auxMME.cantElegida && listaMME[mme].isEmpty == 0)
		{
			auxMME = listaMME[mme];
		}
	}

	printf("Las marcas mas elegidas son: \n\n");
	printf("  ID     Descripcion\n\n");
	for(int mme = 0; mme < tamM; mme++)
	{
		if(auxMME.cantElegida == listaMME[mme].cantElegida && listaMME[mme].isEmpty == 0)
		{
			//mostrar la marca
			indiceMarca = buscarMarcaPorId(listaMME[mme].idMarca, listaM, tamM);
			mostrarMarca(listaM[indiceMarca]);
		}
	}

}

//la llamo cuando hago el ultimo informe
int inicializarMME(eMarcaMasElegida listaMME[], int tamMME) //el tamanio de la listaMME es igual al tamanio de marcas que existan (4)
{
	int isOk = -1;

	if(listaMME != NULL)
	{
		for(int i = 0; i < tamMME; i++)
		{
			listaMME[i].isEmpty = 1;
		}
		isOk = 0;
	}
	return isOk;

}

void cantidadTrabajosPorNotebook(eNotebook listaN[], int tamN, eTipo tipos[], int tamTipos, eMarca listaM[], int tamM, eTrabajo listaT[], int tamT, eServicio listaS[], int tamS)
{
	int idN;
	int indiceN;
	int flag = 0;

	system("clear");
	printf("***** Informe Cantidad de Trabajos Por Notebook *****\n\n");

	mostrarNotebooks(listaN, tamN, tipos, tamTipos, listaM, tamM);
	utn_getEntero(&idN, 3, "Ingresar el id de la notebook elegida: ", "Error, id inexistente\n\n", 1000, 1020); //el sistema acepta solo 20 notebooks
	indiceN = buscarNotebookPorId(idN, listaN, tamN);

	if(indiceN < 0)
	{
		printf("La notebook no existe en sistema.\n\n");
	}
	else
	{
		printf("La notebook elegida es: \n");
		printf("ID           Modelo          Marca          Tipo        Precio\n\n");
		mostrarNotebook(listaN[indiceN], tipos, tamTipos, listaM, tamM);
		printf("Los trabajos que se le realizaron son: \n\n");
		printf("ID   ID notebook     Servicio     Precio       Fecha\n\n");
		for(int t = 0; t < tamT; t++) //recorro trabajos
		{
			if(listaT[t].idNotebook == idN)
			{
				mostrarTrabajo(listaT[t], listaS, tamS);
				flag = 1;
			}

		}
		if(flag == 0)
		{
			printf("La notebook no tiene trabajos a listar");
		}
	}//else
}

void sumaDeServiciosPorNotebook(eNotebook listaN[], int tamN, eTipo tipos[], int tamTipos, eMarca listaM[], int tamM, eTrabajo listaT[], int tamT, eServicio listaS[], int tamS)
{
	int idN;
	int indiceN;
	int idServicio;
	int indiceServicio;
	float totalServicios = 0;

	system("clear");
	printf("***** Informe Total de Servicios Por Notebook *****\n\n");

	mostrarNotebooks(listaN, tamN, tipos, tamTipos, listaM, tamM);
	utn_getEntero(&idN, 3, "Ingresar el id de la notebook elegida: ", "Error, id inexistente\n\n", 1000, 1020);
	indiceN = buscarNotebookPorId(idN, listaN, tamN);

	if(indiceN < 0)
	{
		printf("La notebook no existe en sistema.\n\n");
	}
	else
	{
		printf("La notebook elegida es: \n");
		printf("ID           Modelo          Marca          Tipo        Precio\n\n");
		mostrarNotebook(listaN[indiceN], tipos, tamTipos, listaM, tamM);
		for(int t = 0; t < tamT; t++)//recorro trabajos
		{
			if(listaN[indiceN].id == listaT[t].idNotebook && listaT[t].isEmpty == 0)
			{
				idServicio = listaT[t].idServicio;
				indiceServicio = buscarServicioPorId(idServicio, listaS, tamS);
				totalServicios += listaS[indiceServicio].precio;
			}

		}

		if(totalServicios == 0)
		{
			printf("Esta notebook no tiene trabajos realizados.\n");
		}
		else
		{
			printf("El total de los servicios realizados a esta notebook es de %.2f\n\n", totalServicios);
		}
	}//else

}

