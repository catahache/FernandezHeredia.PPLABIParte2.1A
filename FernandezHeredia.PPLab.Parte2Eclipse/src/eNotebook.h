/*
 * eNotebook.h
 *
 *  Created on: May 13, 2020
 *      Author: catalina
 */

#ifndef ENOTEBOOK_H_
#define ENOTEBOOK_H_
#include "eTipo.h"
#include "eMarca.h"

typedef struct{
	int id;
	char modelo[20];
	int idMarca;
	int idTipo;
	float precio;
	int isEmpty;

}eNotebook;

int inicializarN(eNotebook listaN[], int tamN);
int buscarLibreN(eNotebook listaN[], int tamN);
int buscarNotebookPorId(int id, eNotebook listaN[], int tamN);
void mostrarNotebook(eNotebook notebook, eTipo tipos[], int tamTipos, eMarca listaM[], int tamM);
void mostrarNotebooks(eNotebook listaN[], int tamN, eTipo tipos[], int tamTipos, eMarca listaM[], int tamM);
int ordenarNotebooks(eNotebook listaN[], int tamN, int orden);
int altaNotebook(int idX, eNotebook listaN[], int tamN, eTipo listaT[], int tamT, eMarca listaM[], int tamM);
int bajaNotebook(int idN, int flagN, eNotebook listaN[], int tamN, eTipo listaTipos[], int tamTipos, eMarca listaM[], int tamM);;
int modificacionNotebook(int flagN, eNotebook listaN[], int tamN, eTipo listaT[], int tamT, eMarca listaM[], int tamM);


#endif /* ENOTEBOOK_H_ */
