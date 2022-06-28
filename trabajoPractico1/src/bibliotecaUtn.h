/*
 * getInt.h
 *
 *  Created on: 12 abr. 2022
 *      Author: lapir
 */

#ifndef BIBLIOTECAUTN_H_
#define BIBLIOTECAUTN_H_
/**
 * funcion para pedir y verificar un numero entero
 * char *inPut: puntero input retorna el valor tipo entero
 * char mensaje[]: parametro para dar un mensaje.
 * char errorMensaje[]: parametro para dar mensaje en caso de error.
 * char minimo: parametro para validar en un cierto rango. aca indico minimo.
 * char maximo: parametro para validar en un cierto rango. aca indico maximo.
 * int reintentos: parametro para dar cierta cantidad de reintentos.
 *  return: en caso de exito [0], en caso de error [-1]
 *
 */
int getInt(int *input,char mensaje[],char errorMensaje[], int minimo, int maximo, int reintentos);


/**
 * funcion para pedir y verificar un caracter .
 * char *inPut: puntero a char para gaurdar char
 * char mensaje[]: parametro para dar un mensaje.
 * char errorMensaje[]: parametro para dar mensaje en caso de error.
 * char minimo: parametro para validar en un cierto rango de caracteres, aca indico minimo.
 * char maximo: parametro para validar en un cierto rango de caracteres, aca indico maximo.
 * int reintentos: parametro para dar cierta cantidad de reintentos.
 * return: en caso de exito [0], en caso de error [-1]
 *
 */
/** */
int getChar(char *inPut, char mensaje[], char errorMensaje[],char minimo, char maximo,int reintentos);


/**
 * * funcion para pedir y verificar un numero tipo float.
 * float *inPut: puntero  para guardar float
 * char mensaje[]: parametro para dar un mensaje.
 * char errorMensaje[]: parametro para dar mensaje en caso de error.
 * float minimo: parametro para validar en un cierto rango flotante. aca indico minimo.
 * float maximo: parametro para validar en un cierto rango flotante. aca indico maximo.
 * int reintentos: parametro entero para dar cierta cantidad de reintentos.
 *  return: en caso de exito [0], en caso de error [-1]
 *
 */
int getFloat(float *input,char mensaje[],char errorMensaje[],float minimo,float maximo,int reintentos);

/**
 * * funcion para pedir y verificar un numero tipo float solo verificando el minimo
 * float *inPut : puntero input retorna el valor tipo float.
 * char mensaje[]: parametro para dar un mensaje.
 * char errorMensaje[]: parametro para dar mensaje en caso de error.
 * float minimo: parametro para validar en un cierto rango flotante. aca indico minimo.
 * int reintentos: parametro entero para dar cierta cantidad de reintentos.
 *  return: en caso de exito [0], en caso de error [-1]
 *
 */
int getFloatMinimo(float *input,char mensaje[],char errorMensaje[],float minimo,int reintentos);

/**
 * funcion pide el ingreso de dos flotantes, retorna 0 si los dos son datos validos.
 * input1: puntero para asignar resultado1
 * input2: puntero para asignar resultado2
 * mensaje1: indica a quien va dirijida la primer carga
 * mensaje2: indica a quien va dirijida la segunda carga
 * errormensaje: indica que se produjo un error en ingreso de cargas
 * minimo: inidica minimo numero aceptado
 * reintentos:cantidad de oportunidades para ingresar cargas
 */
int get2Floats(float *input1, float *input2, char mensaje1[],  char mensaje2[], char errorMensaje[], float minimo,int reintentos);

/**
 * funcion para aplicar un descuento del 10% al usar tarjeta de debito.
 * input1: variable tipo puntero reservada para asignar a Aerolinias
 * input2: variable tipo puntero reservada para asignar a latam
 * precioAerolinias: precio cargado por el usuario anteriromente
 * precioLatam precio cargado por el ususario anteriormente
 */
void funcionDebito(float *input1, float *input2, float precioAerolinias, float precioLatam);
/**
 *funcion para aplicar un interes.
 * *input1: puntero para asignar resultado
 * *input2 : para asignar resulatdo
 * precioAerolinias: parametro
 * precioLatam : parametro
 */
void funcionCredito(float *input1, float *input2, float precioAerolinias, float precioLatam);

/**
 * funcion para calcular precio de ambos parametros en bitcoin
 *  *input1: puntero para asignar resultado
 * *input2 : para asignar resulatdo
 * precioAerolinias: parametro
 * precioLatam : parametro
 */
void funcionBitcoin(float *input1, float *input2, float precioAerolinias, float precioLatam);

/**
 * funcion para calcular el precio por cada km recoorido
 * *input1: puntero para asignar resultado
 * *input2 : para asignar resulatdo
 * precioAerolinias: parametro
 * precioLatam : parametro
 * kmrealizados : parametro con km a realizar
 */

void funcionPrecioPorKm(float *input1, float *input2, float precioAerolinias, float precioLatam, float kmRealizados);

/**
 *funcion que calcula la diferencia de precios entre dos punteros
 * *input1: puntero para asignar resultado
 * precioAerolinias parametro a calcular
 * precioLatam parametro a calcular
 */
void funcionDifPrecio(float *input1,float precioAerolinias, float precioLatam);
/**
 *funcion que llama a  funcionDifPrecio,funcionPrecioPorKm,funcionBitcoin,funcionCredito, funcionDebito
 */
void calculoFunciones(float *pDebitoAerolinias, float *pDebitoLatam,float pVueloAerolinias,float pVueloLatam,
float *pCreditoAerolinias,float *pCreditoLatam,float *pBitcoinAerolinias,float *pBitcoinLatam, float *pPKmAerolinias,
float *pPKmLatam,float *difPrecios, float cargaKm);

/**
 * funcion que llama y a la muestra de resultados.
 */
void mostrarResultados(float cargaKm, float pVueloAerolinias,float pDebitoAerolinias,float pCreditoAerolinias,
		float pBitcoinAerolinias,float pPKmAerolinias, float pVueloLatam, float pDebitoLatam, float pCreditoLatam,
		float pBitcoinLatam, float pPKmLatam, float difPrecios);

#endif /* BIBLIOTECAUTN_H_ */
