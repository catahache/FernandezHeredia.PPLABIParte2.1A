/*
 * eTrabajo.h
 *
 *  Created on: May 13, 2020
 *      Author: catalina
 */

#ifndef ETRABAJO_H_
#define ETRABAJO_H_
#include "eFecha.h"
#include "eServicio.h"
#include "eNotebook.h"
#include "eMarca.h"
#include "eTipo.h"

typedef struct{
	int id;
	int idNotebook;
	int idServicio;
	eFecha fecha;
	int isEmpty;

}eTrabajo;

int inicializarT(eTrabajo listaT[], int tamT);
int buscarLibreT(eTrabajo listaT[], int tamT);
int buscarTrabajoPorId(int id, eTrabajo listaT[], int tamT);
void mostrarTrabajo(eTrabajo trabajo, eServicio listaS[], int tamS);
void mostrarTrabajos(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS);
int altaTrabajo(int idX, eTrabajo listaT[], int tamT, eNotebook listaN[], int tamN, eServicio listaS[], int tamS, eMarca listaM[], int tamM, eTipo tipos[], int tamTipos);



#endif /* ETRABAJO_H_ */
