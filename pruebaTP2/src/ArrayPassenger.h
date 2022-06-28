/*
 * ArrayPassenger.h
 *
 *  Created on: 14 may. 2022
 *      Author: lapir
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

//caracteres para name y lastName

#define LENNOMBRE 51


typedef struct
{
	int idStatusFlight;
	char description[20];

}eEstatusFlight;

typedef struct
{
	int idTypePassenger;
	char description[20];

}eTypePassenger;

typedef struct
{
int id;
char name[LENNOMBRE];
char lastName[LENNOMBRE];
float price;
char flyCode[10];
int idTypePassenger;
int idStatusFlight;
int isEmpty;
}Passenger;

#endif /* ARRAYPASSENGER_H_ */

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
//inicializa variables

int initPassengers(Passenger* list, int len);

/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/

//alta
int addPassengers(Passenger* array,int len, int indice, int* id);

//busca lugar libre
int findEmptyFree(Passenger* list, int len, int* freeEmpty);

/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
//encontrar un pasajero por id

int findPassengerById(Passenger* list, int len,int id, int *indice);


int printPassengers(Passenger* list,int len );

void printOnePassenger(Passenger pasenger);

/**
 *\brief Actualiza los datos en la posicion de Empleado del array
 *\param array Array de empleados a ser actualizado
 *\param tamanio limite del array de empleado
 *\param indice Posicion a ser acutualizada
 *\param retorna un 0 (EXITO) y -1 (ERROR)
 */
void modifyMenu(Passenger* bufferPasenger, int size);


/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* bufferPassenger);

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(Passenger* list, int len);
/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
*/
int sortPassengersByFlyCode(Passenger* list, int len);

int informe(Passenger* list, int len);

int sortBueno(Passenger* list, int len);
