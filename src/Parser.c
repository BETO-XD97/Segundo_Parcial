
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Servicio.h"

int parser_ServiceFromText(FILE* pFile , LinkedList* pArrayServicios)
{
	int retorno = 0;

	char id[8000];
	char descripcion[8000];
	char tipo[8000];
	char precioUnitario[8000];
	char cantidad[8000];
	char totalServicio[8000];

	int cant;

	eServicio* unServicio;

	fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id,descripcion,tipo,precioUnitario,cantidad,totalServicio);

	while(!feof(pFile))
	{
		cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id,descripcion,tipo,precioUnitario,cantidad,totalServicio);

		if(cant == 6){
			unServicio = Service_newParametros(id,descripcion,tipo,precioUnitario,cantidad,totalServicio);
		}
		if(unServicio != NULL){
			ll_add(pArrayServicios, unServicio);
			retorno = 1;
		}
	}

    return retorno;
}


