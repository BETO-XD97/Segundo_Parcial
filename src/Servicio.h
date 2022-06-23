/*
 * Servicio.h
 *
 *  Created on: 17 jun. 2022
 *      Author: BETO
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_

#include "LinkedList.h"
#define TAM 50

typedef struct{

	int id;
	char descripcion[TAM];
	char tipo[TAM];
	float precioUnitario;
	int cantidad;
	float totalServicio;

}eServicio;

#endif /* SERVICIO_H_ */

/**
 * brief Crea un nuevo pasajero(un nuevo nodo)
 * @return retorna el servicio con sus parametros inicializados en NULL
 */
eServicio* Service_new();

/**
 * brief Toma los valores del archivo data.csv y setea los datos en cada uno de los elementos de un nodo
 * @param id puntero a char
 * @param descripcion puntero a char
 * @param tipo puntero a char
 * @param precioUnitario puntero a char
 * @param cantidad puntero a char
 * @param totalServicio puntero a char
 * @return unServicio
 */
eServicio* Service_newParametros(char* id_Servicio, char* descripcion, char* tipo, char* precioUnitario, char* cantidad, char* totalServicio);

/**
 * bried Destruye un nodo de tipo servicio
 * @param this referencia
 */
void Servicio_delete(eServicio* this);

/**
 * brief Guarda el id recibido en el campo id de la estructura
 * @param this estructura
 * @param id int
 * @return [1]-ok  [0]-fail
 */
int Servicio_setId(eServicio* this, int id);

/**
 * brief Envia el dato en el elemento id a un puntero
 * @param this estructura
 * @param id int
 * @return [1]-ok  [0]-fail
 */
int Servicio_getId(eServicio* this, int *id);

/**
 * brief Guarda la descripcion recibida en el campo descripcion de la estructura
 * @param this estructura
 * @param descripcion char*
 * @return [1]-ok  [0]-fail
 */
int Servicio_setDescripcion(eServicio* this, char* descripcion);

/**
 * brief Envia el dato en el elemento descripcion a un puntero char
 * @param this estructura
 * @param descripcion char*
 * @return [1]-ok  [0]-fail
 */
int Servicio_getDescripcion(eServicio* this, char* descripcion);

/**
 * brief Guarda el tipo recibida en el campo tipo de la estructura
 * @param this estructura
 * @param descripcion char*
 * @return [1]-ok  [0]-fail
 */
int Servicio_setTipo(eServicio* this, char* descripcion);

/**
 * brief Envia el dato en el elemento descripcion a un puntero char
 * @param this estructuta
 * @param descripcion char*
 * @return [1]-ok  [0]-fail
 */
int Servicio_getTipo(eServicio* this, char* descripcion);

/**
 * brief Guarda el precio recibido en el campo precio de la estructura
 * @param this estructura
 * @param precioUnitario flot
 * @return [1]-ok  [0]-fail
 */
int Servicio_setPrecioUnitario(eServicio* this, float precioUnitario);

/**
 * brief Envia el dato en el elemento precio a un puntero float
 * @param this estructura
 * @param precioUnitario float*
 * @return [1]-ok  [0]-fail
 */
int Servicio_getPrecioUnitario(eServicio* this, float* precioUnitario);

/**
 * brief Guarda la cantidad recibida en el campo cantidad de la estructura
 * @param this estructura
 * @param cantidad int
 * @return [1]-ok  [0]-fail
 */
int Servicio_setCantidad(eServicio* this, int cantidad);

/**
 * brief Envia el dato en el elemento cantidad a un puntero int
 * @param this estructura
 * @param cantidad int*
 * @return [1]-ok  [0]-fail
 */
int Servicio_getCantidad(eServicio* this, int* cantidad);

/**
 * brief Guarda el total servicio recibida en el campo totalServicio de la estructura
 * @param this estructura
 * @param totalServicio float
 * @return [1]-ok  [0]-fail
 */
int Servicio_setTotalServicio(eServicio* this, float totalServicio);

/**
 *	brief Envia el dato en el elemento total servicio a un puntero float
 * @param this estructura
 * @param totalServicio float*
 * @return [1]-ok  [0]-fail
 */
int Servicio_getTotalServicio(eServicio* this, float* totalServicio);

/**
 * brief Recibe el dato de tipo int y dependiendo del numero implementa un strcpy
 * y lo devuelve en el puntero char
 * @param tipo int
 * @param tipoDesc char*
 * @return [1]-ok  [0]-fail
 */
int Servicio_tipoServicio(int tipo, char* tipoDesc);

/**
 * brief Recibe como parametros 2 elementos tipo void*, luego son casteados para ser almacenados
 * en 2 estructuras diferentes. Por ultimo comparo con strcmp los campos de descripcion de las estructuras
 * @param descripcionServOne void*
 * @param descripcionServTwo void*
 * @return resultado de strcmp
 */
int Servicio_sortDescripcion(void* descripcionServOne, void* descripcionServTwo);

/**
 * brief Toma los datos de una estructura con los getters y los imprime
 * @param unServicio estructura
 */
void Servicio_printOne(eServicio* unServicio);

/**
 * brief Recibe un puntero input y lo compara con Minorista Mayorista y Exportar, en caso de resultar
 * cero devuelve 1 2 3 con strcpy en el puntero output (algo parecido con Servicio_tipoServicio)
 * @param input char*
 * @param output char*
 */
void Servicio_tipoGuardado(char* input, char* output);
