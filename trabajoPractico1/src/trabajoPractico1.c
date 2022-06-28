/*
 ============================================================================
 Name        : trabajoPractico1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaUtn.h"
//creo menu
int main (void)
{
	setbuf(stdout,NULL);
	//declaro variables

	int respuestaMenu;
	int opcion;

	float cargaKm;
	int rCargaKm;

	float pVueloAerolinias;
	float pVueloLatam;
	int rCargaVuelos;
			//A
	float pDebitoAerolinias;
	float pDebitoLatam;
			//B
	float pCreditoAerolinias;
	float pCreditoLatam;
			//C
	float pBitcoinAerolinias;
	float pBitcoinLatam;
			//D
	float pPKmAerolinias;
	float pPKmLatam;
			//E
	float difPrecios;

	int rOpcion3 = -1;

								//menu
	// creo bucle
	do
	{
	//llamo funcion pedir numero entero
	respuestaMenu = getInt(&opcion," \n ingrese:\n 1- para cargar km \n 2- Ingresar Precio de Vuelos "
			" \n 3- calcular todos los costos  \n 4- Informar Resultados "
			" \n 5- carga forzada de datos \n 6- Salir  ", " \n ERROR,ingrese un numero entres 1 y 6 incluidos", 1, 6, 2);

		//verifico valor
		if(respuestaMenu == 0)
		{

			switch(opcion)
			{
		//carga de km
				case 1:
					rCargaKm =  getFloatMinimo(&cargaKm," \n ingrese kms a realizar ", "\n ERROR en la carga de kms  debe serr > 0 ", 1, 2);
					if(rCargaKm == 0)
					{
						printf(" \n carga exitosa");
					}
					else
					{
						printf(" \n ERROR en la carga, no cumple los parametros solicitados");
					}
					break;

		//precios de vuelos
				case 2:
					rCargaVuelos = get2Floats(&pVueloAerolinias, &pVueloLatam," \n ingrese precio de vuelo de Aerolinias",
							" \n ingrese precio de vuelo de Latam"," \n ERROR en la carga de precios, ambos deben de ser >0",1,2);
					if(rCargaVuelos == 0)
					{
						printf(" \n carga exitosa");
					}
					else
					{
						printf(" \n ERROR en la carga, no cumple los parametros solicitados");
					}
					break;

		//calculo de funciones			//solo se ejecuta si resCargakm y resCargaVuelos tienen datos cargados
				case 3:
					if(rCargaKm == 0 && rCargaVuelos ==0 )
					{
						calculoFunciones(&pDebitoAerolinias, &pDebitoLatam, pVueloAerolinias, pVueloLatam,
						&pCreditoAerolinias,&pCreditoLatam,&pBitcoinAerolinias,&pBitcoinLatam, &pPKmAerolinias,
						&pPKmLatam,&difPrecios,cargaKm);

					    rOpcion3 = 0;

					    printf(" \n calculo de resultados exitosa");
					}
					else
					{
						printf(" \n ERROR, primero debe de cargar los datos 1 y 2");
					}
					//solo se ejecuta si resCargakm y resCargaVuelos
					break;

			//muestra de resultados         //se ejecuta si opcion 1, 2 y 3 se hicieron
				case 4:
					if(rCargaKm == 0 && rCargaVuelos == 0 && rOpcion3 == 0)
					{
						mostrarResultados(cargaKm, pVueloAerolinias, pDebitoAerolinias, pCreditoAerolinias, pBitcoinAerolinias, pPKmAerolinias, pVueloLatam, pDebitoLatam, pCreditoLatam, pBitcoinLatam,  pPKmLatam,  difPrecios);
					}
					else
					{
						printf(" \n ERROR, primero debe de cargar los datos 1 , 2 y 3");
					}
					break;

			//carga forzada          //se ejecuta si //solo se ejecuta si opcion 1 y dos tienen datos cargados
				case 5:
					if(rCargaKm == 0 && rCargaVuelos ==0 )
					{
						calculoFunciones(&pDebitoAerolinias, &pDebitoLatam, pVueloAerolinias, pVueloLatam,
						&pCreditoAerolinias,&pCreditoLatam,&pBitcoinAerolinias,&pBitcoinLatam, &pPKmAerolinias,
						&pPKmLatam,&difPrecios,cargaKm);

						mostrarResultados(cargaKm, pVueloAerolinias, pDebitoAerolinias, pCreditoAerolinias, pBitcoinAerolinias,
						pPKmAerolinias, pVueloLatam, pDebitoLatam, pCreditoLatam, pBitcoinLatam,  pPKmLatam,  difPrecios);

					}
					else
					{
						printf(" /n no se puede realizar la carga forzada sin el ingreso 1 y 2");
					}
					break;
			}
		}
	}while(opcion != 6);


	return 0;
}
