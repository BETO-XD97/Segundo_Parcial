#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Controller.h"
#include "LinkedList.h"
#include "Servicio.h"
#include "utn_Input.h"
#include "Parser.h"

int controller_loadFromText(char* path, LinkedList* pArrayListServicio){

	int retorno = 0;

	FILE* pFile = fopen(path, "r");

	if(pFile != NULL){

		parser_ServiceFromText(pFile, pArrayListServicio);
		fclose(pFile);
		retorno = 1;
	}
	return retorno;
}

int controller_ListService(LinkedList* pArrayListServicio){

	int retorno = 0;
	int cant = 0;

	eServicio* servicioAux;

	if(pArrayListServicio != NULL){

		cant = ll_len(pArrayListServicio);

		printf("\n[-------------------------------------------------------------------------------------]\n");
		printf("[-ID-] [--------DESCRIPCION--------] [-----TIPO SERVICIO-----] [--PRECIO UNITARIO--] [--CANTIDAD--] [--TOTAL SERVICIO---]\n");

		for(int i=0; i<cant; i++){

			servicioAux = (eServicio*) ll_get(pArrayListServicio, i);
			Servicio_printOne(servicioAux);
		}
		retorno = 1;
	}
	return retorno;
}

int controller_allocateTotal(LinkedList* pArrayListServicio){

	int retorno = 0;

	if(pArrayListServicio != NULL){

		//void (*fn) (eServicio*);
		//fn = CalcularTotServ;
		ll_map(pArrayListServicio, CalcularTotServ);
		retorno = 1;
	}
	return retorno;
}

LinkedList* controller_filterType(LinkedList* pArrayListServicio){

	int opcionF;

	LinkedList* servicioFiltrado;

	if(pArrayListServicio != NULL){

		rellenarInt(&opcionF, "\nIngrese por el tipo de servicio que desea filtrar: 1-MINORISTA / 2-MAYORISTA / 3-EXPORTAR\n------> ", "\nError! Reingrese--->", 1 ,3);

		switch(opcionF){

			case 1:
				servicioFiltrado = ll_filter(pArrayListServicio, FiltrarTipoMinorista);
				break;

			case 2:
				servicioFiltrado = ll_filter(pArrayListServicio, FiltrarTipoMayorista);
				break;

			case 3:
				servicioFiltrado = ll_filter(pArrayListServicio, FiltrarTipoExportar);
				break;
		}
	}
	return servicioFiltrado;
}

int controller_sortService(LinkedList* pArrayListServicio){

	int retorno = 0;

	if(pArrayListServicio != NULL){

		retorno = ll_sort(pArrayListServicio, Service_sortByDesc, 1);
	}
	return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayListServicio){

	 int retorno = 0;

	 FILE* pArchivoTexto;

	 eServicio* pServiceAux;

	 int id;
	 float precioUnit;
	 int cantidad;
	 float totalServicio;
	 char tipoAux[8000];

	 char idAux[8000];
	 char descripcion[8000];
	 char tipo[8000];
	 char precioAux[8000];
	 char cantidadAux[8000];
	 char totalServicioAux[8000];

	 int tamano;

	 if(pArrayListServicio != NULL){

		 pArchivoTexto = fopen(path, "w");

		 if(pArchivoTexto != NULL){

			 tamano = ll_len(pArrayListServicio);

			 fprintf(pArchivoTexto, "id_Servicio,descripcion,tipo,precioUnitario,cantidad,totalServicio\n");

			 for(int i=0; i<tamano; i++){

				 pServiceAux = (eServicio*) ll_get(pArrayListServicio, i);

				 if(pServiceAux != NULL){

					 if(Servicio_getId(pServiceAux, &id) &&
							 Servicio_getDescripcion(pServiceAux, descripcion) &&
							 Servicio_getTipo(pServiceAux, tipo) &&
							 Servicio_getPrecioUnitario(pServiceAux, &precioUnit) &&
							 Servicio_getCantidad(pServiceAux, &cantidad) &&
							 Servicio_getTotalServicio(pServiceAux, &totalServicio)){

	    					itoa(id,idAux,10);
	    					itoa(precioUnit,precioAux,10);
	    					itoa(cantidad, cantidadAux, 10);
	    					itoa(totalServicio, totalServicioAux, 10);
	    					Servicio_tipoGuardado(tipo, tipoAux);

	    					fprintf(pArchivoTexto,"%s,%s,%s,%s,%s,%s\n",idAux,descripcion,tipoAux,precioAux,cantidadAux,totalServicioAux);
	    					retorno = 1;
					 }
				 }
			 }
		 }
		 fclose(pArchivoTexto);
	 }
	 return retorno;
}

//FUNCIONES DE MAPEO Y FILTRADO........

void CalcularTotServ(eServicio* this){

	if(this != NULL){

		this->totalServicio = this->precioUnitario * this->cantidad;
	}
}

int FiltrarTipoMinorista(eServicio* this){

	int retorno = 0;

	if(strcmp(this->tipo, "Minorista") == 0){

		retorno = 1;
	}
	return retorno;
}

int FiltrarTipoMayorista(eServicio* this){

	int retorno = 0;

	if(strcmp(this->tipo, "Mayorista") == 0){

		retorno = 1;
	}
	return retorno;
}

int FiltrarTipoExportar(eServicio* this){

	int retorno = 0;

	if(strcmp(this->tipo, "Exportar") == 0){

		retorno = 1;
	}
	return retorno;
}

int Service_sortByDesc(void* descOne, void* descTwo){

	int retorno = 0;

	eServicio* pServiceOne;
	eServicio* pServiceTwo;

	if(descOne != NULL && descTwo != NULL){

		pServiceOne = (eServicio*) descOne;
		pServiceTwo = (eServicio*) descTwo;

		retorno = strcmp(pServiceOne->descripcion, pServiceTwo->descripcion);
	}

	return retorno;
}
