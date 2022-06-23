#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Servicio.h"
#include "LinkedList.h"


eServicio* Service_new(){

	eServicio* unServicio;
	unServicio = (eServicio*) malloc(sizeof(eServicio));

	if(unServicio != NULL){

		unServicio->id = 0;
		strcpy(unServicio->descripcion, " ");
		strcpy(unServicio->tipo, " ");
		unServicio->precioUnitario = 0;
		unServicio->cantidad = 0;
		unServicio->totalServicio = 0;
	}
	return unServicio;
}

eServicio* Service_newParametros(char* id,char* descripcion,char* tipo, char* precioUnitario, char* cantidad, char* totalServicio){

	eServicio* unServicio;

	unServicio = Service_new();

	int idAux;
	int tipoAux;
	float precioUnitAux;
	int cantidadAux;
	char tipoDesc[12];
	float totalServicioAux;

	idAux = atoi(id);
	tipoAux = atoi(tipo);
	Servicio_tipoServicio(tipoAux, tipoDesc);
	precioUnitAux = atof(precioUnitario);
	cantidadAux = atoi(cantidad);
	totalServicioAux = atof(totalServicio);

	if(unServicio != NULL && id != NULL && descripcion != NULL && tipo != NULL && precioUnitario != NULL && cantidad != NULL && totalServicio != NULL){

		if(!(Servicio_setId(unServicio, idAux) &&
			Servicio_setDescripcion(unServicio, descripcion) &&
			Servicio_setTipo(unServicio, tipoDesc) &&
			Servicio_setPrecioUnitario(unServicio, precioUnitAux) &&
			Servicio_setCantidad(unServicio, cantidadAux) &&
			Servicio_setTotalServicio(unServicio, totalServicioAux))
			)
		{
			Servicio_delete(unServicio);
		}
	}
	return unServicio;
}

void Servicio_delete(eServicio* this){

	if(this != NULL){

		free(this);
	}
}

int Servicio_setId(eServicio* this,int id){

	int retorno;
	retorno = 0;

	if(this != NULL && id > 0){

		this->id = id;
		retorno = 1;
	}
	return retorno;
}

int Servicio_getId(eServicio* this,int* id){

	int retorno;
	retorno = 0;

	if(this != NULL && id != NULL){

		*id = this->id;
		retorno = 1;
	}
	return retorno;
}

int Servicio_setDescripcion(eServicio* this,char* descripcion){

	int retorno = 0;

	if(this != NULL && descripcion != NULL){

		strlwr(descripcion);
		descripcion[0] = toupper(descripcion[0]);
		strcpy(this->descripcion, descripcion);
		retorno = 1;
	}
	return retorno;
}

int Servicio_getDescripcion(eServicio* this,char* descripcion){

	int retorno = 0;

	if(this != NULL && descripcion != NULL){

		strcpy(descripcion, this->descripcion);
		retorno = 1;
	}
	 return retorno;
}

int Servicio_setTipo(eServicio* this, char* tipo){

	int retorno = 0;

	if(this != NULL && tipo != NULL){

		strlwr(tipo);
		tipo[0] = toupper(tipo[0]);
		strcpy(this->tipo, tipo);
		retorno = 1;
	}
	return retorno;
}

int Servicio_getTipo(eServicio* this, char* tipo){

	int retorno = 0;

	if(this != NULL && tipo != NULL){

		strcpy(tipo, this->tipo);
		retorno = 1;
	}
	return retorno;
}

int Servicio_setPrecioUnitario(eServicio* this,float precioUnitario){

	int retorno;
	retorno = 0;

	if(this != NULL && precioUnitario > 0){

		this->precioUnitario = precioUnitario;
		retorno = 1;
	}
	return retorno;
}

int Servicio_getPrecioUnitario(eServicio* this,float* precioUnitario){

	int retorno;
	retorno = 0;

	if(this != NULL && precioUnitario != NULL){

		*precioUnitario = this->precioUnitario;
		retorno = 1;
	}
	return retorno;
}

int Servicio_setCantidad(eServicio* this,int cantidad){

	int retorno;
	retorno = 0;

	if(this != NULL && cantidad > 0){

		this->cantidad = cantidad;
		retorno = 1;
	}
	return retorno;
}

int Servicio_getCantidad(eServicio* this,int* cantidad){

	int retorno;
	retorno = 0;

	if(this != NULL && cantidad != NULL){

		*cantidad = this->cantidad;
		retorno = 1;
	}
	return retorno;
}

int Servicio_setTotalServicio(eServicio* this,float totalServicio){

	int retorno;
	retorno = 0;

	if(this != NULL && totalServicio >= 0){

		this->totalServicio = totalServicio;
		retorno = 1;
	}
	return retorno;
}

int Servicio_getTotalServicio(eServicio* this,float* totalServicio){

	int retorno;
	retorno = 0;

	if(this != NULL && totalServicio != NULL){

		*totalServicio = this->totalServicio;
		retorno = 1;
	}
	return retorno;
}

int Servicio_tipoServicio(int tipo, char* tipoDesc){

	int retorno;
	retorno = 0;

	if(tipo != 0 && tipoDesc != NULL){

		switch(tipo){

		case 1:
			strcpy(tipoDesc, "Minorista");
			break;
		case 2:
			strcpy(tipoDesc, "Mayorista");
			break;
		case 3:
			strcpy(tipoDesc, "Exportar");
			break;
		}
		retorno = 1;
	}
	return retorno;
}

void Servicio_tipoGuardado(char* input, char* output){

	if(input != NULL && output != NULL){

		if(strcmp(input, "Minorista") == 0){
			strcpy(output, "1");
		} else {
			if(strcmp(input, "Mayorista") == 0){
				strcpy(output, "2");
			} else {
				if(strcmp(input, "Exportar") == 0){
					strcpy(output, "3");
				}
			}
		}
	}
}
void Servicio_printOne(eServicio* unServicio){

	//Variables auxiliares para imprimir
	int idAux;
	char descripcionAux[25];
	char tipoAux[25];
	float precioUnitarioAux;
	int cantidadAux;
	float totalServicioAux;

	if(unServicio != NULL){

		Servicio_getId(unServicio, &idAux);
		Servicio_getDescripcion(unServicio, descripcionAux);
		Servicio_getTipo(unServicio, tipoAux);
		Servicio_getPrecioUnitario(unServicio, &precioUnitarioAux);
		Servicio_getCantidad(unServicio, &cantidadAux);
		Servicio_getTotalServicio(unServicio, &totalServicioAux);

		printf("|%4d| |%-27s| |%-23s| |$%18.2f| |%12d| |$%18.2f|\n",idAux,descripcionAux,tipoAux,precioUnitarioAux,cantidadAux,totalServicioAux);
	}
}

int Servicio_sortDescripcion(void* descripcionServOne, void* descripcionServTwo){

	int retorno = 0;

	eServicio* servicioOne;
	eServicio* servicioTwo;

	if(descripcionServOne != NULL && descripcionServTwo != NULL){

		servicioOne = (eServicio*) descripcionServOne;
		servicioTwo = (eServicio*) descripcionServTwo;

		retorno = strcmp(servicioOne->descripcion, servicioTwo->descripcion);
	}
	return retorno;
}
