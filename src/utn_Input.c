/*
 * utn_Input.c
 *
 *  Created on: 21 may. 2022
 *      Author: BETO
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int rellenarInt(int* inputInt, char inputChar[], char inputError[], int min, int max){
	*inputInt = 0;
	int input = 0;
	int retorno;
	printf(inputChar);
	scanf("%d", inputInt);
	fflush(stdin);
	if(*inputInt < min || *inputInt > max){
		do{
			printf(inputError);
			scanf("%d", inputInt);
			fflush(stdin);
			if(*inputInt >= min && *inputInt <= max){
				input = 1;
			}
		}while(input != 1);
		retorno = *inputInt;
	} else {
		retorno = *inputInt;
	}

	while(*inputInt == 0){
		printf(inputError);
		scanf("%d", inputInt);
		fflush(stdin);
	}

	return retorno;
}

float rellenarFloat(float* inputFloat, char inputChar[], char inputError[], float min, float max){
	*inputFloat = 0;
		int input = 0;
		int retorno;
		printf(inputChar);
		scanf("%f", inputFloat);
		fflush(stdin);
		if(*inputFloat < min || *inputFloat > max){
			do{
				printf(inputError);
				scanf("%f", inputFloat);
				fflush(stdin);
				if(*inputFloat >= min && *inputFloat <= max){
					input = 1;
				}
			}while(input != 1);
			retorno = *inputFloat;
		} else {
			retorno = *inputFloat;
		}

		while(*inputFloat == 0){
			printf(inputError);
			scanf("%f", inputFloat);
			fflush(stdin);
		}

		return retorno;

}

int rellenarChar(char inputChar[], char outputChar[]){

	int retorno = 0;
	if(inputChar != NULL && strlen(inputChar) > 0){
		printf(outputChar);
		gets(inputChar);
		fflush(stdin);
		retorno = 1;
	}
/*
		for(int i=0; i<strlen(inputChar); i++){
			if(isdigit(inputChar[i]) != 0){
				retorno = 1;
				break;
			}
		}
		if(retorno == 1){
			printf("\nError!");
		}
	}*/
	return retorno;
}
