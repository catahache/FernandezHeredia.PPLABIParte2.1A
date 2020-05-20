/*
 * eServicio.h
 *
 *  Created on: May 13, 2020
 *      Author: catalina
 */

#ifndef ESERVICIO_H_
#define ESERVICIO_H_


typedef struct{
	int id;
	char descripcion[25];
	float precio;

}eServicio;

int cargarDescripServicio(char descripcion[], int idS, eServicio servicios[], int tamS);
int mostrarServicios(eServicio servicios[], int tamS);
int buscarServicioPorId(int id, eServicio listaS[], int tamS);


#endif /* ESERVICIO_H_ */
