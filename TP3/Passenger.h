/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#define LENNOMBRE 50

typedef struct
{
	int id;
	char nombre[LENNOMBRE];
	char apellido[LENNOMBRE];
	float precio;
	char tipoPasajero[LENNOMBRE];
	char codigoVuelo[8];
	char estadoVuelo[LENNOMBRE];

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametrosTxt(char* idTxt,char* nombreStr,char* apellidoStr,char* precioStr,char* codVueloStr, char* tipoPasajeroS, char* estadoVueloStr);
Passenger* Passenger_newParametros(int id,char* nombre,char* apellido,float precio,char* codVuelo, char* tipoPasajero, char* estadoVuelo);
void Passenger_delete();

int Passenger_setIdTxt(Passenger* this,char* id);
int Passenger_getIdTxt(Passenger* this,char* id);
int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);

int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo);

int Passenger_setPrecioTxt(Passenger* this,char* precio);
int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);



#endif /* PASSENGER_H_ */
