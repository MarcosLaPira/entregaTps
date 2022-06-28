#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "laibrery.h"
#include "controller.h"
#include "parser.h"


/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);

    int option = 0;
    int flagGuardado=1;


    LinkedList* listaPasajeros = ll_newLinkedList();
    do{
    	if(utn_getNumero(&option,"seleccione una opcion:\n 1- cargar datos modo texto\n 2-caragr datos modo bianrio\n 3- dar un alta\n "
    			"4-modificar un pasajero\n  5-baja de pasajero\n  6- listar pasajeros\n 7-ordenar pasajeros\n 8- guardar datos modo texto\n"
    			"  9- guardar datos modo binario\n 10- salir","opcion no valida",1,10,3)==0)
    	{

			switch(option)
			{
				case 1://carga modo texto
					if(controller_loadFromText("data.csv",listaPasajeros))
					{
						printf("\n Archivo de texto cargado exitosamente\n");
					}
					else
					{
						printf("ERROR abriendo archivo\n");
					}
					break;
				case 2: //carga modo binaria
					if(controller_loadFromBinary("data.bin",listaPasajeros))
					{
						printf("\n Archivo binario cargado exitosamente");
					}
					break;
				case 3://alta
					if (controller_addPassenger(listaPasajeros))
						{
							printf("\n** alta exitosa **");
						}
						break;

					break;
				case 4://modificacion
				 controller_editPassenger(listaPasajeros);
					break;
				case 5://baja
					if(controller_removePassenger(listaPasajeros))
					{
						printf(" \n ** eliminacion exitosa **");
					}
					else
					{
						printf(" \n ** no se pudo eliminar **");
					}
					break;
				case 6://listar

					controller_ListPassenger(listaPasajeros);

					break;
				case 7://ordenar
					controller_sortPassenger(listaPasajeros);
					break;
				case 8://guardar datos modo texto
					 if(controller_saveAsText("data.csv",listaPasajeros))
					 {
						 flagGuardado=1;
					 }
					break;
				case 9://guardar datos modo binarios

					if(controller_saveAsBinary("data.bin",listaPasajeros))
					{
						flagGuardado=1;
					}

					break;

			}
        }
    }while(option != 10 && flagGuardado==1);

    return 0;
}

