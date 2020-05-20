/*
 * informes.h
 *
 *  Created on: May 18, 2020
 *      Author: catalina
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include "eNotebook.h"
#include "eMarca.h"
#include "eTrabajo.h"
#include "eServicio.h"
#include "eTipo.h"

typedef struct{

	int idMarca;
	int cantElegida;
	int isEmpty;

}eMarcaMasElegida;

char menuInformes();
void informar(eNotebook listaN[],int tamN, eMarca listaM[], int tamM, eTrabajo listaT[], int tamT, eServicio listaS[], int tamS, eTipo tipos[], int tamTipos, eMarcaMasElegida listaMME[]);
void informarNotebooksPorTipo(eNotebook listaN[], int tamN, eTipo tipos[], int tamTipos, eMarca listaM[], int tamM);
void informarNotebooksPorMarca(eNotebook listaN[], int tamN, eTipo tipos[], int tamTipos, eMarca listaM[], int tamM);
void informarNotebookMasBarata(eNotebook listaN[], int tamN, eTipo tipos[], int tamTipos, eMarca listaM[], int tamM);
void informarTodasNotebooksMarca(eNotebook listaN[], int tamN, eTipo tipos[], int tamTipos, eMarca listaM[], int tamM);
void informarNporTipoyMarca(eNotebook listaN[], int tamN, eTipo tipos[], int tamTipos, eMarca listaM[], int tamM);
void informarMarcaMasElegida(eNotebook listaN[], int tamN, eTipo tipos[], int tamTipos, eMarca listaM[], int tamM, eMarcaMasElegida listaMME[]);
int inicializarMME(eMarcaMasElegida listaMME[], int tamMME);
void cantidadTrabajosPorNotebook(eNotebook listaN[], int tamN, eTipo tipos[], int tamTipos, eMarca listaM[], int tamM, eTrabajo listaT[], int tamT, eServicio listaS[], int tamS);
void sumaDeServiciosPorNotebook(eNotebook listaN[], int tamN, eTipo tipos[], int tamTipos, eMarca listaM[], int tamM, eTrabajo listaT[], int tamT, eServicio listaS[], int tamS);
void informarNotebooksPorServicio(eNotebook listaN[], int tamN, eTipo tipos[], int tamTipos, eMarca listaM[], int tamM, eTrabajo listaT[], int tamT, eServicio listaS[], int tamS);
void serviciosPorFecha(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS);



#endif /* INFORMES_H_ */
