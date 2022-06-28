/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "laibrery.h"
#include "controller.h"
#include "parser.h"


static int isValidNombre(char* cadena,int longitud);
static int esNumerica(char* cadena, int limite);
//static int esFlotante(char* cadena,int limite);

Passenger* Passenger_new()
{
	Passenger* newPassenger = NULL;
	newPassenger = (Passenger*)malloc(sizeof(Passenger));
	if(newPassenger != NULL)
	{
		newPassenger->id = 0;
		strcpy(newPassenger->nombre," ");
		strcpy(newPassenger->apellido," ");
		newPassenger-> precio = 0;
		strcpy(newPassenger-> codigoVuelo," ");
		strcpy(newPassenger-> tipoPasajero," ");
		strcpy(newPassenger->estadoVuelo," ");
	}
	else
	{
		free(newPassenger);
	}
	return newPassenger;
}
Passenger* Passenger_newParametrosTxt(char* IdTxt,char* nombreStr,char* apellidoStr,char* precioStr,char* codVueloStr, char* tipoPasajeroS, char* estadoVueloStr)
{
	Passenger* newPassenger = Passenger_new ();

	if (newPassenger != NULL)
	{

		if(
				Passenger_setIdTxt(newPassenger,IdTxt)==0 || ///////////////////////////
				Passenger_setNombre(newPassenger,nombreStr)==0 ||
				Passenger_setApellido(newPassenger,apellidoStr)==0 ||
				Passenger_setPrecioTxt(newPassenger,precioStr) ==0 ||
				Passenger_setCodigoVuelo(newPassenger,codVueloStr) ==0 ||
				Passenger_setTipoPasajero(newPassenger,tipoPasajeroS)==0 ||
				Passenger_setEstadoVuelo(newPassenger,estadoVueloStr)==0
		)
		{
			free(newPassenger);
			newPassenger = NULL;
		}
	}
	return newPassenger;
}
Passenger* Passenger_newParametros(int id,char* nombre,char* apellido,float precio,char* codVuelo, char* tipoPasajero, char* estadoVuelo)
{
	Passenger* newPassenger = Passenger_new ();
	if (newPassenger != NULL)
	{
		if(		Passenger_setId(newPassenger,id)==0 ||
				Passenger_setNombre(newPassenger,nombre)==0 ||
				Passenger_setApellido(newPassenger,apellido)==0 ||
				Passenger_setPrecio(newPassenger,precio) ==0 ||
				Passenger_setCodigoVuelo(newPassenger,codVuelo) ==0 ||
 				Passenger_setTipoPasajero(newPassenger,tipoPasajero) ==0 ||
				Passenger_setEstadoVuelo(newPassenger,estadoVuelo)==0 )
		{

			free (newPassenger);
			newPassenger = NULL;
		}
	}
	return newPassenger;
}

//**************************************************************************************************************************
/*
void Passenger_delete(); // ***************** SIN HACER *****************
*/
//**************************************************************************************************************************

int Passenger_setIdTxt(Passenger* this,char* id)   /////////////////////////////////
{
	int retorno = 0;
	if(this != NULL && id != NULL)
	{
		if(esNumerica(id,10))
		{
			retorno = 1;
			this->id = atoi(id);
		}
	}
	return retorno;
}
int Passenger_getIdTxt(Passenger* this,char* id)	////////////////////////
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		sprintf(id,"%d",this->id);
	}
	return retorno;
}
int Passenger_setId(Passenger* this,int id)
{
	int retorno = 0;
	if(this != NULL && id > 0)
	{
		this->id = id;

		retorno = 1;
	}
	return retorno;
}
int Passenger_getId(Passenger* this,int* id)
{
	int retorno = 0;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 1;
	}
	return retorno;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno = 0;

	if(this != NULL && nombre!= NULL && isValidNombre(nombre, LENNOMBRE))
	{
		strcpy(this->nombre,nombre);

		retorno = 1;
	}
	return retorno;
}
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno = 0;
	if(this != NULL &&  nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = 1;
	}
	return retorno;
}
int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno = 0;
	if(this != NULL &&  apellido != NULL && isValidNombre( apellido, LENNOMBRE) )
	{
		strcpy(this->apellido,apellido);
		retorno = 1;
	}
	return retorno;
}
int Passenger_getApellido(Passenger* this, char* apellido)
{
	int retorno = 0;
	if(this != NULL &&  apellido != NULL)
	{
		strcpy(apellido,this->apellido);
		retorno = 1;
	}
	return retorno;
}
/*
int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno = 0;
	char estadoPrint[15];
	if(this != NULL && estadoVuelo != NULL)
	{

		strcpy(this->estadoVuelo,estadoVuelo);
		Passenger_getEstadoVuelo(this,estadoPrint);
		printf("\n %s",estadoPrint);

		retorno = 1;
	}
	printf(" \n set estado de vuelo %d",retorno);
	return retorno;
}
*/
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = 0;
	//char codigoPrint[50];


	if(this != NULL &&  codigoVuelo != NULL )
	{
		///esAlfanumerico								////////////////////
		strncpy(this->codigoVuelo,codigoVuelo,8);


		retorno = 1;
	}
	//printf("\n set codigo vuelo %d",retorno);
	return retorno;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = 0;

	if(this != NULL &&  codigoVuelo != NULL)
	{
		strncpy(codigoVuelo,this->codigoVuelo,8);
		retorno = 1;
	}
	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno = 0;
	if(this != NULL && tipoPasajero != NULL && isValidNombre( tipoPasajero, LENNOMBRE))
	{
		strcpy(this->tipoPasajero,tipoPasajero);
		retorno = 1;
	}
	return retorno;
}
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno = 0;
	if(this != NULL &&  tipoPasajero != NULL)
	{
		strcpy(tipoPasajero,this->tipoPasajero);
		retorno = 1;
	}
	return retorno;
}
int Passenger_setPrecioTxt(Passenger* this,char* precio)
{
	int retorno = 0;
	float auxiliarPrecio;
	if(this != NULL && precio!= NULL )
	{
		//if(esFlotante(precio,10)==0)									/////////////////////////////
			auxiliarPrecio = atof(precio);
			if(auxiliarPrecio >= 0)
			{
				retorno = 1;
				this->precio= auxiliarPrecio;
			}
	}
	return retorno;
}
int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno = 0;
	if(this != NULL &&  precio > 0 && precio<=1000000)
	{
		this->precio = precio;
		retorno = 1;
	}

	return retorno;
}
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno = 0;
	if(this != NULL &&  precio != NULL)
	{
		*precio = this->precio;
		retorno = 1;
	}
	return retorno;
}

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno = 0;
	//char estadoPrint[15];
	if(this != NULL && estadoVuelo != NULL)
	{

		strcpy(this->estadoVuelo,estadoVuelo);
		/*
		Passenger_getEstadoVuelo(this,estadoPrint);
		printf("\n %s",estadoPrint);
		*/
		retorno = 1;
	}
	//printf(" \n set estado de vuelo %d",retorno);
	return retorno;
}
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno = 0;
	if(this != NULL &&  estadoVuelo != NULL)
	{
		strcpy(estadoVuelo,this->estadoVuelo);
		retorno = 1;
	}
	return retorno;
}
///////////////////////////////////////////////////////////////////////////////
//*****************************************************************************//

/**********************************************************************/
/**********************************************************************/
/**********************************************************************/

/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int isValidNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es y -1 en caso de error
 *
 */
static int esNumerica(char* cadena, int limite)
{
	int retorno = -1; // ERROR
	int i;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1; // VERDADERO
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			//CONTINUE
		}
		//BREAK
	}
	return retorno;
}
/*
static int esFlotante(char* cadena,int limite)
 {
 	int retorno = 1;
 	int flagDecimal=1;

 	int i;
 	if(cadena != NULL && limite>0)
 	{
 		for(i=0; i < limite && cadena[i] != '\0';i++)
 		{
 			if(flagDecimal==1 && i !=0 && cadena[i]=='.')
 			{
 				flagDecimal=0;
 				continue;
 			}
 			if(cadena[i] < '0' || cadena[i] > '9')
 			{
 				retorno = 0;
 				break;
 			}
 		}
 	}
 	return retorno;
 }
*/
/**********************************************************************/

