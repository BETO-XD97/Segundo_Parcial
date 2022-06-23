/*
 * Controller.h
 *
 *  Created on: 17 jun. 2022
 *      Author: BETO
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "LinkedList.h"
#include "Servicio.h"
#endif /* CONTROLLER_H_ */

/**
 * brief Carga los datos de los servicios desde el archivo data.csv (modo texto).
 * @param path char *
 * @param pArrayListServicio LinkedList*
 * @return [1]-ok [0]-fail
 */
int controller_loadFromText(char* path , LinkedList* pArrayListServicio);

/**
 * brief Listar servicios
 * @param pArrayListServicio LinkedList*
 * @return [1]-ok [0]-fail
 */
int controller_ListService(LinkedList* pArrayListServicio);

/**
 * brief Calcula el espacio de totalServicio usando ll_map y un puntero a funcion(CalcularTotServ)
 * @param pArrayListServicio LinkedList*
 * @return [1]-ok  [0]-fail
 */
int controller_allocateTotal(LinkedList* pArrayListServicio);

/**
 * brief Uso un puntero a funcion(Filtrar...) para filtrar la linkedlist y que el resultado se guarde
 * en otra linkedlist creada en el controller
 * @param pArrayListServicio LinkedLis*
 * @return LinkedList (servicioFiltrado)
 */
LinkedList* controller_filterType(LinkedList* pArrayListServicio);

/**
 * brief Ordena la linkedlist por el elemento de la estructura descripcion
 * de forma ascendente(1) llamando a un puntero a funcion(Service_sortByDesc)
 * @param pArrayListServicio
 * @return [1]-ok  [0]-fail
 */
int controller_sortService(LinkedList* pArrayListServicio);

/**
 * brief Guarda los datos de los servicios en el archivo dataMod.csv
 * y tambien es usado para guardar los datos de los servicios filtrados
 * @param path char*
 * @param pArrayListServicio LinkedList*
 * @return [1]-ok  [0]-fail
 */
int controller_saveAsText(char* path , LinkedList* pArrayListServicio);

/**
 * brief Calcula el total Servicio
 * @param this eServicio*
 */
void CalcularTotServ(eServicio* this);

/**
 * brief Filtra la lista por tipo minorista
 * @param this eServicio*
 * @return [1]-ok  [0]-fail
 */
int FiltrarTipoMinorista(eServicio* this);

/**
 * brief Filtra la lista por tipo mayorista
 * @param this eServicio*
 * @return [1]-ok  [0]-fail
 */
int FiltrarTipoMayorista(eServicio* this);

/**
 * brief Filtra la lista por tipo exportar
 * @param this eServicio*
 * @return [1]-ok  [0]-fail
 */
int FiltrarTipoExportar(eServicio* this);

/**
 * brief Recibe como parametros 2 elementos tipo void*, luego son casteados para ser almacenados
 * en 2 estructuras diferentes. Por ultimo comparo con strcmp los campos de descripcion de las estructuras
 * @param descOne void*
 * @param descTwo void*
 * @return resultado de strcmp
 */
int Service_sortByDesc(void* descOne, void* descTwo);

