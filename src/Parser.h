/*
 * Parser.h
 *
 *  Created on: 17 jun. 2022
 *      Author: BETO
 */

#ifndef PARSER_H_
#define PARSER_H_

#endif /* PARSER_H_ */

/**
 * brief Parsea los datos de los servicios desde el archivo data.csv(modo texto)
 * @param pFile char* path(nombred del archivo)
 * @param pArrayServicios LinkedList*
 * @return [1]-ok  [0]-fail
 */
int parser_ServiceFromText(FILE* pFile , LinkedList* pArrayServicios);
