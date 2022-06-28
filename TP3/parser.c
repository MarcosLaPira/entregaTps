#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "laibrery.h"
#include "controller.h"
#include "parser.h"


/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	char id[4096],nombre[4096],apellido[4096],precio[4096],codigoVuelo[8],tipoPasajero[4096],estadoVuelo[4096];

	int cant;
	Passenger* pAuxPassenger;
	if (pFile == NULL)
	{
		printf("\n Error al abrir el archivo.");
		retorno = 0;
		exit (EXIT_FAILURE);
	}
	else
	{
		//lectura famtasma de primer linea
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
								id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);
		while(!feof(pFile))
		{
			cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
								id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);
/*
			printf("\n %s ",id);
			printf("\n %s ",nombre);
			printf("\n %s ",apellido);
			printf("\n %s ",precio);
			printf("\n %s",codigoVuelo);
			printf("\n %s ",tipoPasajero);
			printf("\n %s ",estadoVuelo);
*/
			if(cant!=7)
			{
				printf("\n error dentro del archivo");
				break;
			}
			else
			{
				pAuxPassenger = Passenger_newParametrosTxt(id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);
				if(pAuxPassenger != NULL)
				{
					ll_add(pArrayListPassenger,pAuxPassenger);
					retorno = 1;
				}
			}

		}
	}
    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* pAuxPassenger;
	int tamanio;
	int retorno;


	if(pFile != NULL && pArrayListPassenger != NULL )
	{
		while(!feof(pFile))
		{
			pAuxPassenger = Passenger_new();
			tamanio = fread(pAuxPassenger,sizeof(Passenger),1,pFile);

			if(pAuxPassenger != NULL && tamanio == 1)
			{
				ll_add(pArrayListPassenger,pAuxPassenger);
				retorno = 1;
			}
			else{

				retorno = 0;
			}

		}
	}
	return retorno;
}
