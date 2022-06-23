/*
 ============================================================================
 Name        : Segundo_Parcial.c
 Author      : Roberto Rocabado
 DNI  		 : 40731247
 Division    : D
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Controller.h"
#include "Parser.h"
#include "utn_Input.h"
#include "LinkedList.h"
#include "Servicio.h"

int opcionMM;
int rtnLFT;
int rtnLS;
int rtnAt;
int rtnFt;
int rtnSsort;
int rtnSsmod;
int rtnSat;
int rtnSatf;
int opcCarga;
int opcLista;
int archcarg = 0;

char cargArch[5000];

int main(void){

	setbuf(stdout, NULL);

	LinkedList* listaServicios = ll_newLinkedList();
	LinkedList* listaFiltrada = ll_newLinkedList();

	do{
		printf("\n-------------BIENVENIDO--------------------\n");
		printf("\n1)Cargar archivo"
				"\n2)Imprimir lista"
				"\n3)Asignar Totales"
				"\n4)Filtrar Por Tipo"
				"\n5)Mostrar Servicios"
				"\n6)Guardar servicios"
				"\n7)Salir"
				"\n\nIngrese la opcion a realizar---> ");
		fflush(stdin);
		scanf("%d", &opcionMM);

		switch(opcionMM){

		case 1:
			printf("\nIngrese el nombre del archivo a abrir: ");
			fflush(stdin);
			scanf("%s", cargArch);
			if(strcmp(cargArch, "data.csv") == 0){
				rtnLFT = controller_loadFromText(cargArch, listaServicios);
			} else {
				rtnLFT = 0;
				printf("\nNombre de archivo incorrecto!\n");
			}
			if(rtnLFT == 1){
				archcarg = 1;
				printf("\nEl archivo se abrio correctamente!\n");
			} else {
				printf("\nHubo un problema al abrir el archivo!\n");
			}
			break;

		case 2:
			if(archcarg == 1){
				controller_ListService(listaServicios);
			} else {
				printf("\nDebe haber cargado el archivo primero!\n");
			}
			break;

		case 3:
			if(archcarg == 1){
				rtnAt = controller_allocateTotal(listaServicios);
				if(rtnAt == 1){
					printf("\nSe han asignado los totales!\n\nPara visualizar los cambios presione la opcion 2!\n");
				} else {
					printf("\nHubo un problema al asignar los totales!\n");
				}
			} else {
				printf("\nDebe cargar el archivo -data.csv- !\n");
			}
			break;

		case 4:
			if(archcarg == 1){
				listaFiltrada = controller_filterType(listaServicios);
				rtnSatf = controller_saveAsText("datafilter.csv",listaFiltrada);
				if(rtnSatf == 1){
					printf("\nSe ha generado un nuevo archivo con los datos filtrados!\n");
				} else {
					printf("\nHubo un problema al generar el nuevo archivo!\n");
				}
			} else {
				printf("\nDebe cargar el archivo -data.csv- !\n");
			}
			break;
		case 5:
			if(archcarg == 1){
				rtnSsort = controller_sortService(listaServicios);
				if(rtnSsort == 0){
					controller_ListService(listaServicios);
					printf("\nEl archivo se ha ordenado por descripcion!\n");
				} else {
					printf("\nHubo un problema al ordenar!\n");
				}
			} else {
				printf("\nDebe cargar el archivo -data.csv- !\n");
			}
			break;
		case 6:
			if(archcarg == 1){
				rtnSsmod = controller_saveAsText("dataMod.csv",listaServicios);
				if(rtnSsmod == 1){
					printf("\nSe ha generado un nuevo archivo con los datos modificados ordenados!\n");
				} else {
					printf("\nHubo un problema al guardar el archivo modificado!\n");
				}
			} else {
				printf("\nDebe cargar el archivo -data.csv- !\n");
			}
			break;
		case 7:
			printf("\nCerrando programa...");
			break;

		default:
			printf("\nOpcion inconrrecta!\n");
			break;
		}
	}while(opcionMM != 7);

	return 0;
}
