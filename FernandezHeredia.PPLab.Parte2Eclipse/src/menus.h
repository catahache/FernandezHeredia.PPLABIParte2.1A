/*
 * menus.h
 *
 *  Created on: May 13, 2020
 *      Author: catalina
 */

#ifndef MENUS_H_
#define MENUS_H_
#include "eTrabajo.h"
#include "eNotebook.h"
#include "eTipo.h"
#include "eMarca.h"
#include "eServicio.h"

int menu();
int menuAltas();
void alta(int* flagN, int* flagT, eTrabajo listaT[], int tamT, eNotebook listaN[], int tamN,  eTipo listaTipo[], int tamTipo, eMarca listaM[], int tamM, eServicio listaS[], int tamS);
void baja(int flagN, eNotebook listaN[], int tamN, eMarca listaM[], int tamM, eTipo listaTipos[], int tamTipos);
int menuListas();
void listar(int flagN, int flagT, eNotebook listaN[], int tamN, eTipo listaTipo[], int tamTipo, eMarca listaM[], int tamM, eTrabajo listaT[], int tamT, eServicio listaS[], int tamS);

#endif /* MENUS_H_ */
