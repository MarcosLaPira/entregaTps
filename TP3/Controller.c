#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "laibrery.h"
#include "controller.h"
#include "parser.h"


static int controller_printPassenger (Passenger* pPassenger);
/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	int retorno = 0;

	if (pArrayListPassenger != NULL && path != NULL)
	{
		pFile = fopen (path, "r");
		if (pFile == NULL)
		{
			printf("\nERROR al abrir el archivo.\n");
		}
		else
		{
			if(parser_PassengerFromText(pFile, pArrayListPassenger))
			{
				retorno = 1;
			}
		}
	}
	fclose(pFile);
	return retorno;
}


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	int retorno = 0;

	if (pArrayListPassenger != NULL && path != NULL)
	{
		pFile = fopen (path, "rb");
		if (pFile == NULL)
		{
			printf("\nERROR al abrir el archivo.\n");
		}
		else
		{
			if (parser_PassengerFromBinary(pFile , pArrayListPassenger))
			{
				retorno = 1;
			}
		}
	}
	fclose(pFile);
	return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	Passenger*  newPassenger = Passenger_new();
	int retorno = 0;
	int id;
	char nombre[LENNOMBRE];
	char apellido[LENNOMBRE];
	float precio;
	int tipoPasajeroint;
	char tipoPasajero[LENNOMBRE];
	char codigoVuelo[8];////////////////
	int estadoVueloInt;
	char estadoVuelo [LENNOMBRE];

	if (pArrayListPassenger != NULL)
	{


		id = controller_idSubSiguiente(pArrayListPassenger);

		if(	utn_getNombre(nombre,50,"\n Ingrese nombre del pasajero \n","\nError \n", 2) == 0 &&
			utn_getNombre(apellido,50,"\nIngrese el apelliod del pasajero \n","\nError \n", 2) == 0 &&
			getNumeroFlotante(&precio,"\n Ingrese el precio del vuelo","\nError.\n",1.0,500000.0,2)==0 &&
			getAlfanumerico(codigoVuelo,"\n Ingrese 7 digitos del codigo aereo\n","\nError \n",7,2) == 0 &&
			utn_getNumero(&tipoPasajeroint, "\n Ingrese el tipo de pasajero: \n 1- FirstClass \n 2- ExecutiveClass\n"
											" 3- EconomyClass\n","\nError \n",1,3,2) == 0 &&
			utn_getNumero(&estadoVueloInt,"\n Ingrese el estado del vuelo.\n "
			"1- Aterrizado \n 2- En Horario\n 3- Demorado\n 4- En vuelo\n","\nError. \n",1,4,3) == 0)
		{

			switch(tipoPasajeroint)
			{
				case 1 :
					strcpy(tipoPasajero,"FirstClass");
					break;
				case 2 :
					strcpy(tipoPasajero,"ExecutiveClass");
					break;
				case 3 :
					strcpy(tipoPasajero,"EconomyClass");
					break;
			}



			switch(estadoVueloInt)
			{
				case 1 :
					strcpy(estadoVuelo,"Aterrizado");
					break;
				case 2 :
					strcpy(estadoVuelo,"En Horario");
					break;
				case 3 :
					strcpy(estadoVuelo,"Demorado");
					break;
				case 4 :
					strcpy(estadoVuelo,"En vuelo");
					break;
			}


			id ++;

			if (newPassenger != NULL) // carga en el "buffer"
			{
				if(Passenger_setId(newPassenger,id)&&
				Passenger_setNombre(newPassenger,nombre) &&
				Passenger_setApellido(newPassenger,apellido) &&
				Passenger_setPrecio(newPassenger,precio) &&
				Passenger_setCodigoVuelo(newPassenger,codigoVuelo)&&
				Passenger_setTipoPasajero(newPassenger,tipoPasajero) &&
				Passenger_setEstadoVuelo(newPassenger,estadoVuelo))
				{
					printf("\n CARGA EXITOSA \n");
					ll_add(pArrayListPassenger, newPassenger);
					retorno = 1;
				}
				else
				{
					free (newPassenger);
					newPassenger = NULL;
					retorno=0;
				}
			}
		}

	}
	else
	{
		printf(" \n ERROR EN CARGA");
	}

    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{

	int bufferId;
	int bufferIndice;
	int retorno=0;
	int bufferIdMax;
	int subMenu;

	char bufferNombre[LENNOMBRE];
	char bufferApellido[LENNOMBRE];
	float bufferPrecio;
	char bufferCodigoDeVuelo[7];
	int auxTipoPasajero;
	char bufferTipoPasajero[LENNOMBRE];
	int auxEstadoDeVuelo;
	char bufferEstadoDeVuelo[LENNOMBRE];

	Passenger*  pAuxPassenger=NULL;

	if(pArrayListPassenger != NULL)
	{
		retorno=1;
		//busco id maximo
		bufferIdMax=controller_idSubSiguiente ( pArrayListPassenger);

		//pedir num de id
		//int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
		if(utn_getNumero(&bufferId,"\n ingrese el numero de id que desea modificar","\n error",1,bufferIdMax,2)==0)
		{
			//retorno indice con el id
			bufferIndice=controller_findById(pArrayListPassenger,bufferId) ;

			if(bufferIndice>=0)
			{
				pAuxPassenger = ll_get(pArrayListPassenger,bufferIndice);

				if(pAuxPassenger!= NULL)
				{
					do{
						if(utn_getNumero(&subMenu,"\n Ingrese opcion que desea modificar:"
								"1-Nombre\n 2-Apellido \n 3- Precio \n 4- Tipo de pasajero \n 5- Codigo de vuelo \n "
								"6- Estado de vuelo \n 7- Salir \n","\n error",1,7,2)==0)
						{

							switch(subMenu)
							{
							case 1:
								if(utn_getNombre(bufferNombre,50,"\n Ingrese el nombre. \n","\nError. \n", 2)== 0)
								{
									if(Passenger_setNombre(pAuxPassenger,bufferNombre))
									{
										printf("\n nombre modificado con exito \n ");
									}
								}
								break;
							case 2:
								if(utn_getNombre(bufferApellido,50,"\n Ingrese el pellido. \n","\nError. \n", 2) == 0)
								{
									if(Passenger_setApellido(pAuxPassenger,bufferApellido))
									{
										printf("\n apellido modificado con exito \n ");
									}
								}
								break;
							case 3:
								if(getNumeroFlotante(&bufferPrecio,"\n Ingrese el precio del vuelo.","\nError. \n",1.0,500000.0,2)==0)
								{
									if(Passenger_setPrecio(pAuxPassenger,bufferPrecio))
									{
										printf("\n  precio modificado con exito  \n ");
									}
								}
								break;
							case 4:
								if(getAlfanumerico(bufferCodigoDeVuelo,"\n Ingrese los 7 digitos del codigo aereo.\n","\nError. \n",7,2) == 0)
								{
									if(Passenger_setCodigoVuelo(pAuxPassenger,bufferCodigoDeVuelo))
									{
										printf("\n  codigo de vuelo modificado con exito \n ");
									}
								}
								break;
							case 5:
								if(utn_getNumero(&auxTipoPasajero, "\n Ingrese el tipo de pasajero : \n 1- FirstClass. \n 2- ExecutiveClass.\n"
																				" 3- EconomyClass.\n","\nError. \n",1,3,2) == 0)
								{
									switch(auxTipoPasajero)
									{
										case 1 :
											strcpy(bufferTipoPasajero,"FirstClass");
											break;
										case 2 :
											strcpy(bufferTipoPasajero,"ExecutiveClass");
											break;
										case 3 :
											strcpy(bufferTipoPasajero,"EconomyClass");
											break;
									}
									if(Passenger_setTipoPasajero(pAuxPassenger,bufferTipoPasajero))
									{
										printf("\n  tipo de pasajero modificado con exito \n ");
									}

								}

								break;
							case 6:
								if(utn_getNumero(&auxEstadoDeVuelo,"\nIngrese el estado del vuelo.\n "
									"1- Aterrizado  \n 2- En Horario \n 3-Demorado \n 4  En vuelo \n","\n Error. \n",1,4,2) == 0)
								{
									switch(auxEstadoDeVuelo)
									{
										case 1 :
											strcpy(bufferEstadoDeVuelo,"Aterrizado");
											break;
										case 2 :
											strcpy(bufferEstadoDeVuelo,"En Horario");
											break;
										case 3 :
											strcpy(bufferEstadoDeVuelo,"Demorado");
											break;
										case 4 :
											strcpy(bufferEstadoDeVuelo,"En vuelo");
											break;
									}
									if(Passenger_setEstadoVuelo(pAuxPassenger,bufferEstadoDeVuelo))
									{
										printf("\n  estado de vuelo modificado con exito  \n ");
									}
								}
								break;
							}
						}
					}while(subMenu != 7);
				}
			}
		}
	}


    return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno=0;
	int bufferId;
	int bufferIndice;
	int bufferIdMax;
	Passenger* pAuxPassenger=NULL;

	if(pArrayListPassenger!=NULL)
	{
		bufferIdMax = controller_idSubSiguiente ( pArrayListPassenger);
		if(utn_getNumero(&bufferId,"\n ingrese el numero de id que desea eliminar","\n error",1,bufferIdMax,2)==0)
		{
			bufferIndice=controller_findById(pArrayListPassenger,bufferId);
			if(bufferIndice>=0)
			{
				pAuxPassenger = ll_get(pArrayListPassenger,bufferIndice);
				if(pAuxPassenger != NULL)
				{
					ll_remove(pArrayListPassenger,bufferIndice);
					retorno=1;
				}
			}
		}
	}
    return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	Passenger*  pAuxPassenger;
	int retorno = 0;
	int tamanio;

	if (pArrayListPassenger != NULL){

		tamanio = ll_len(pArrayListPassenger);

		printf("\n 				  **LISTADO PASAJEROS** \n");
		printf("\n --------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("ID	 	NOMBRE		 APELLIDO		 PRECIO		 CODIGO	AEREO	TIPO PASAJERO 		ESTADO");
		printf("\n --------------------------------------------------------------------------------------------------------------------------------------------\n");

		for (int i = 0;i<tamanio;i++)
		{

			pAuxPassenger = ll_get(pArrayListPassenger,i); //???


			controller_printPassenger(pAuxPassenger);

		}

		printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
		retorno = 0;
	}
    return retorno;
}

static int controller_printPassenger (Passenger* pPassenger)
{
	int retorno = 0;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char tipoPasajero[50];
	char codigoVuelo[8];
	char estadoVuelo [50];

	if (pPassenger != NULL &&
		Passenger_getId(pPassenger,&id) &&
		Passenger_getNombre(pPassenger,nombre)&&
		Passenger_getApellido(pPassenger,apellido)&&
		Passenger_getPrecio(pPassenger,&precio)&&
		Passenger_getCodigoVuelo(pPassenger,codigoVuelo)&&
		Passenger_getEstadoVuelo(pPassenger,estadoVuelo) &&
		Passenger_getTipoPasajero(pPassenger,tipoPasajero))

	{
		/*
		printf("\n%d	 	%-10s		 %-10s     		  %.2f	  	 %-15s    	 %-15s  		 %-15s \n",
		id, nombre, apellido, precio,codigoVuelo,tipoPasajero,estadoVuelo);*/
		printf("\n%d	 	%-10s		 %-5s     		%.2f	  	     %-15s  	 %-15s    %s \n",
			id, nombre, apellido, precio,codigoVuelo,tipoPasajero,estadoVuelo);
		retorno = 1;

	}
	return retorno;
}




/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
/*
 *
*/
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno =0;
	int i;
	int flagSwap;
	int limite;
	char bufferNombre[LENNOMBRE];
	char bufferSigNombre[LENNOMBRE];

	Passenger* pAuxPassenger=NULL;
	Passenger* pAuxSigPassenger=NULL;


//printf("\n previo a validar");
	if( pArrayListPassenger != NULL)
	{
		//printf("\n despues de validar");
		retorno = 1;
		limite = ll_len(pArrayListPassenger);
	//	printf("\n limite: %d",limite);
		do
		{
			flagSwap = 0;

			for(i=0;i<limite-1;i++)
			{

				for(int j=i+1;j<limite;j++)
				{
					pAuxPassenger = ll_get(pArrayListPassenger,i);
					pAuxSigPassenger = ll_get(pArrayListPassenger,j);


					if(pAuxPassenger != NULL && pAuxSigPassenger  != NULL)
					{
						//printf("\n ambos punteros difernetes de NULL");
						Passenger_getNombre(pAuxPassenger,bufferNombre);
						Passenger_getNombre(pAuxSigPassenger,bufferSigNombre);

						if(strncmp(bufferNombre,bufferSigNombre,LENNOMBRE) > 0)
						{
							ll_set(pArrayListPassenger, i, pAuxSigPassenger);
							ll_set(pArrayListPassenger, j, pAuxPassenger);
							flagSwap=1;
						}
					}
				}
			}
			limite--;
		}while(flagSwap);
	}

	pAuxPassenger = NULL;                     ///////////////////////////////
	pAuxSigPassenger = NULL;					//////////////////////////////

    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int id;
	char nombre[LENNOMBRE];
	char apellido[LENNOMBRE];
	float precio;
	char tipoPasajero[LENNOMBRE];
	char codigoVuelo[8];
	char estadoVuelo [LENNOMBRE];
	Passenger*  pAuxPassenger;
	FILE* pFile;

	if (path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path,"w");
		if(pFile == NULL)
		{
			printf("\nEl archivo no pudo abrirse.\n");
			system("pause");
			exit (EXIT_FAILURE);
		}
		for (int i = 0; i< ll_len(pArrayListPassenger);i++ )
		{
			pAuxPassenger = ll_get(pArrayListPassenger,i);
			if (pAuxPassenger != NULL &&
				Passenger_getId(pAuxPassenger,&id) &&
				Passenger_getNombre(pAuxPassenger,nombre)&&
				Passenger_getApellido(pAuxPassenger,apellido)&&
				Passenger_getPrecio(pAuxPassenger,&precio)&&
				Passenger_getCodigoVuelo(pAuxPassenger,codigoVuelo)&&
				Passenger_getTipoPasajero(pAuxPassenger,tipoPasajero)&&
				Passenger_getEstadoVuelo(pAuxPassenger,estadoVuelo))
			{
				fprintf(pFile,"%d,%s,%s,%f,%s,%s,%s\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);
				retorno = 1;
			}
			else
			{
				pAuxPassenger = NULL;
			}
		}
	}
	fclose(pFile);
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int limite;
	Passenger*  pAuxPassenger;
	FILE* pFile;

	if (path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path,"wb");
		if(pFile == NULL)
		{
			printf("\nEl archivo no pudo abrirse.\n");
			system("pause");
			exit (EXIT_FAILURE);
		}
		limite =ll_len(pArrayListPassenger);
		for (int i = 0; limite;i++ )
		{
			pAuxPassenger = ll_get(pArrayListPassenger,i);
			if (pAuxPassenger != NULL)
			{
				fwrite(pAuxPassenger, sizeof(Passenger),1,pFile);
				retorno = 1;
			}
			else
			{
				pAuxPassenger = NULL;
			}
		}
	}
	fclose(pFile);
    return retorno;
}

int controller_idSubSiguiente (LinkedList* pArrayListPassenger)
{
	Passenger*  pAuxPassenger =NULL;
	int siguienteId;
	int id;
	int tamanio;
	if (pArrayListPassenger != NULL)
	{
		tamanio = ll_len(pArrayListPassenger);
		for(int i = 0;i<tamanio; i++)
		{
			pAuxPassenger = ll_get(pArrayListPassenger,i);
			if(pAuxPassenger != NULL)
			{
				Passenger_getId(pAuxPassenger,&id);
				if(id > siguienteId || i == 0)
				{
					siguienteId = id;
				}
			}
		}
	}


	return siguienteId;
}
int controller_findById(LinkedList* pArrayListPassenger,int idABuscar)
{
	Passenger*  pAuxPassenger=NULL;
	int bufferId;
	int tamanio;
	int retorno = -1;
	if (pArrayListPassenger != NULL && idABuscar>0)
	{
		tamanio = ll_len(pArrayListPassenger);
		for(int i = 0;i<tamanio; i++)
		{
			pAuxPassenger = ll_get(pArrayListPassenger,i);
			if(pAuxPassenger != NULL)
			{
				Passenger_getId(pAuxPassenger,&bufferId);\
				if(idABuscar == bufferId )
				{
					retorno=i;
					break;
				}
			}

		}
	}
	return retorno;
}




