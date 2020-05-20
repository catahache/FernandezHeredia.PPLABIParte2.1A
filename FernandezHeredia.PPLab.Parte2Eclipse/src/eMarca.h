/*
 * eMarca.h
 *
 *  Created on: May 13, 2020
 *      Author: catalina
 */

#ifndef EMARCA_H_
#define EMARCA_H_

typedef struct{
	int id;
	char descripcion[20];
}eMarca;

int cargarDescripMarca(char descripcion[], int idMarca, eMarca marcas[], int tamM);
int mostrarMarcas(eMarca marcas[], int tamM);
void mostrarMarca(eMarca marca);
int buscarMarcaPorId(int id, eMarca listaM[], int tamM);


#endif /* EMARCA_H_ */
