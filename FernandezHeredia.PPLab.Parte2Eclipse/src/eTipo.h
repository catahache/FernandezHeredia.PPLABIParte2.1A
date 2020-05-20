/*
 * eTipo.h
 *
 *  Created on: May 13, 2020
 *      Author: catalina
 */

#ifndef ETIPO_H_
#define ETIPO_H_

typedef struct{
	int id;
	char descripcion[20];

}eTipo;

int cargarDescripTipo(char descripcion[], int idTipo, eTipo tipos[], int tamT);
int mostrarTipos(eTipo tipos[], int tamT);
int buscarTipoPorId(int id, eTipo tipos[], int tamTipos);


#endif /* ETIPO_H_ */
