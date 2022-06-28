/*
 * getInt.c
 *
 *  Created on: 12 abr. 2022
 *      Author: lapir
 */

#include <stdio.h>
#include <stdlib.h>

#define DESCUENTO 10
#define INTERES 25
#define BITCOIN 4606954.55

int getInt(int *input,char mensaje[],char errorMensaje[], int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;

	if(input != NULL && mensaje != NULL && errorMensaje != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			scanf("%d",&bufferInt);
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				*input = bufferInt;
				retorno = 0;
				break;
			}
				printf("%s",errorMensaje);
				reintentos--;

		}while(reintentos >= 0);
	}


	return retorno;
}


int getFloat(float *input,char mensaje[],char errorMensaje[],float minimo,float maximo,int reintentos)
{
	int retorno = -1;
	float bufferFloat;

	if(input != NULL && mensaje != NULL && errorMensaje != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			scanf("%f",&bufferFloat);

			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*input = bufferFloat;
				retorno = 0;
				break;
			}
			printf("%s" ,errorMensaje);
			reintentos--;

		}while(reintentos >= 0);
	}




	return retorno;
}


int getChar(char *inPut, char mensaje[], char errorMensaje[],char minimo, char maximo,int reintentos)
{
	int retorno = -1;
	char bufferChar;

	if(inPut != NULL && mensaje != NULL && errorMensaje != NULL && minimo <= maximo && reintentos >= 0 )
	{
		do
		{
			printf("%s",mensaje);
			scanf("%c",&bufferChar);
			fflush(stdin);


			if(bufferChar >= minimo && bufferChar <= maximo )
			{
				*inPut = bufferChar;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",errorMensaje);
				reintentos--;

			}
		}while (reintentos >=0);

	}

	return retorno;
}

int getFloatMinimo(float *input,char mensaje[],char errorMensaje[],float minimo,int reintentos)
{
	int retorno = -1;
	float bufferFloat;

	if(input != NULL && mensaje != NULL && errorMensaje != NULL && minimo >= 1 && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			scanf("%f",&bufferFloat);

			if(bufferFloat >  minimo )
			{
				*input = bufferFloat;
				retorno = 0;
				break;
			}
			printf("%s" ,errorMensaje);
			reintentos--;

		}while(reintentos >= 0);
	}




	return retorno;
}

int get2Floats(float *input1, float *input2, char mensaje1[],  char mensaje2[], char errorMensaje[],float minimo,int reintentos)
{
	int retorno = -1;
	float bufferFloat1;
	float bufferFloat2;

	if(input1 != NULL && input2 != NULL && mensaje1 != NULL && mensaje2 != NULL && errorMensaje != NULL &&
			minimo >= 1 && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje1);
			scanf("%f",&bufferFloat1);

			printf("%s",mensaje2);
			scanf("%f",&bufferFloat2);

			if(bufferFloat1 >=  minimo && bufferFloat2 >=  minimo )
			{
				*input1 = bufferFloat1;
				*input2 = bufferFloat2;

				retorno = 0;
				break;
			}
			printf("%s" ,errorMensaje);
			reintentos--;

		}while(reintentos >= 0);
	}

	return retorno;
}

void funcionDebito(float *input1, float *input2,float precioAerolinias,float precioLatam)
{

	float bufferFloat1;
	float bufferFloat2;
	if(input1 != NULL && input2 != NULL && precioAerolinias >= 1 && precioLatam >= 1)
	{


		bufferFloat1 = precioAerolinias *DESCUENTO /100;
		*input1 = precioAerolinias - bufferFloat1;

		bufferFloat2 = precioLatam *DESCUENTO /100;
		*input2 = precioLatam - bufferFloat2;


	}

}

void funcionCredito(float *input1, float *input2,float precioAerolinias,float precioLatam)
{

	float bufferFloat1;
	float bufferFloat2;

	if(input1 != NULL && input2 != NULL && precioAerolinias >= 1 && precioLatam >= 1)
	{


		bufferFloat1 = precioAerolinias * INTERES /100;
		*input1 = precioAerolinias + bufferFloat1;

		bufferFloat2 = precioLatam * INTERES/100;
		*input2 = precioLatam + bufferFloat2;



	}
}

void funcionBitcoin(float *input1, float *input2,float precioAerolinias,float precioLatam)
{

	float bufferFloat1;
	float bufferFloat2;

	if(input1 != NULL && input2 != NULL && precioAerolinias >=1 && precioLatam >=1 )
	{


		bufferFloat1 = precioAerolinias / BITCOIN;
		*input1 =  bufferFloat1;

		bufferFloat2 = precioLatam / BITCOIN;
		*input2 = bufferFloat2;



	}


}

void funcionPrecioPorKm(float *input1, float *input2, float precioAerolinias, float precioLatam, float kmRealizados)
{

	float bufferFloat1;
	float bufferFloat2;

	if(input1 != NULL && input2 != NULL && precioAerolinias >=1 && precioLatam >=1 && kmRealizados >= 1)
	{

		bufferFloat1 = precioAerolinias / kmRealizados;
		*input1 =  bufferFloat1;

		bufferFloat2 = precioLatam  / kmRealizados;
		*input2 = bufferFloat2;


	}


}

void funcionDifPrecio(float *input1,float precioAerolinias, float precioLatam)
{

	float bufferFloat;


	if(input1 != NULL  && precioAerolinias >=1 && precioLatam >=1)
	{
		if(precioAerolinias > precioLatam)
		{
			bufferFloat= precioAerolinias - precioLatam;
			*input1 = bufferFloat;

		}
		else
		{
			bufferFloat = precioLatam - precioAerolinias;
			*input1 = bufferFloat;
		}

	}
}

void calculoFunciones(float *pDebitoAerolinias, float *pDebitoLatam,float pVueloAerolinias,float pVueloLatam,
float *pCreditoAerolinias,float *pCreditoLatam,float *pBitcoinAerolinias,float *pBitcoinLatam, float *pPKmAerolinias,
float *pPKmLatam,float *difPrecios, float cargaKm)
{
	// a) debito
	funcionDebito(pDebitoAerolinias,pDebitoLatam,pVueloAerolinias,pVueloLatam);
	// b) credito
	funcionCredito(pCreditoAerolinias,pCreditoLatam,pVueloAerolinias,pVueloLatam);
	// c ) bitcoin
	funcionBitcoin(pBitcoinAerolinias,pBitcoinLatam,pVueloAerolinias,pVueloLatam);
	// d) precio por km
	funcionPrecioPorKm(pPKmAerolinias,pPKmLatam,pVueloAerolinias,pVueloLatam,cargaKm);
	// e) diferencia de precio
	 funcionDifPrecio(difPrecios,pVueloAerolinias,pVueloLatam);

}

void mostrarResultados(float cargaKm, float pVueloAerolinias,float pDebitoAerolinias,float pCreditoAerolinias,
		float pBitcoinAerolinias,float pPKmAerolinias, float pVueloLatam, float pDebitoLatam, float pCreditoLatam,
		float pBitcoinLatam, float pPKmLatam, float difPrecios)
{
	printf("\n Kms Ingresados: %.2f Km",cargaKm);

	printf("\n \n Precio Aerolinias: %.2f ",pVueloAerolinias);
	printf("\n a) Precio con tarjeta de debito: $ %.2f ",pDebitoAerolinias);
	printf("\n b) Precio con tarjeta de credito: $ %.2f ",pCreditoAerolinias);
	printf("\n c) Precio pagando con bitcoin: $ %f ",pBitcoinAerolinias);
	printf("\n d) Mostrar precio unitario: $ %.2f ",pPKmAerolinias);

	printf("\n \n  Precio Latam: %.2f ",pVueloLatam);
	printf("\n a) Precio con tarjeta de debito: $ %.2f ",pDebitoLatam);
	printf("\n b) Precio con tarjeta de credito: $ %.2f ",pCreditoLatam);
	printf("\n c) Precio pagando con bitcoin: $ %f ",pBitcoinLatam);
	printf("\n d) Mostrar precio unitario: $ %.2f ",pPKmLatam);

	printf("\n \n La diferencia de precios es: $ %.2f ",difPrecios);
}





