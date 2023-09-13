#include "mantenimiento.h"

void InicializarCostos(Mantenimiento* pMantenimiento)
{
	pMantenimiento->hospedaje = 0;
	pMantenimiento->comida = 0;
	pMantenimiento->transporte = 0;
}

int mant_setHospedaje(Mantenimiento* this,int valor)
{
	int retorno = -1;
	if(this != NULL && valor >= 0)
	{
		retorno = 0;
		this->hospedaje = valor;
	}
	return retorno;
}

int mant_getHospedaje(Mantenimiento* this,int* valor)
{
	int retorno = -1;
	if(this != NULL && valor != NULL)
	{
		retorno = 0;
		*valor = this->hospedaje;
	}
	return retorno;
}

int mant_setComida(Mantenimiento* this,int valor)
{
	int retorno = -1;
	if(this != NULL && valor >= 0)
	{
		retorno = 0;
		this->comida = valor;
	}
	return retorno;
}

int mant_getComida(Mantenimiento* this,int* valor)
{
	int retorno = -1;
	if(this != NULL && valor != NULL)
	{
		retorno = 0;
		*valor = this->comida;
	}
	return retorno;
}

int mant_setTransporte(Mantenimiento* this,int valor)
{
	int retorno = -1;
	if(this != NULL && valor >= 0)
	{
		retorno = 0;
		this->transporte = valor;
	}
	return retorno;
}

int mant_getTransporte(Mantenimiento* this,int* valor)
{
	int retorno = -1;
	if(this != NULL && valor != NULL)
	{
		retorno = 0;
		*valor = this->transporte;
	}
	return retorno;
}

////////////////////////////////////////////


int mant_MostrarSubMenuMantenimiento(Mantenimiento* pMantenimiento)
{
	int retorno = -1;
	int opcion;
	char mensajeError[50] = "\nERROR. Ingrese un numero del 1 al 4";
	char mensajeErrorDos[50] = "\nERROR. Ingrese un numero positivo";
	char mensajeOpciones[100] = "\n1. Hospedaje\n2. Comida\n3. Transporte\n4. Volver\n";
	int hospedaje, comida, transporte;

	if(pMantenimiento != NULL)
	{
		utn_getNumero(&opcion, mensajeOpciones, mensajeError, 1, 4, 2);

		switch (opcion)
		{
			case 1:
				if(utn_getNumero(&hospedaje, "\nCosto hopesdaje: ",mensajeErrorDos, 1, 99999, 2) == 0 &&
				mant_setHospedaje(pMantenimiento, hospedaje) == 0)
				{
					retorno = 0;
				}
				break;
			case 2:
				if(utn_getNumero(&comida, "\nCosto comida: ", mensajeErrorDos, 1,99999, 2) == 0 &&
				mant_setComida(pMantenimiento, comida) == 0)
				{
					retorno = 0;
				}
				break;
			case 3:
				if(utn_getNumero(&transporte, "\nCosto transporte: ",mensajeErrorDos, 1, 99999, 2) == 0 &&
				mant_setTransporte(pMantenimiento, transporte) == 0)
				{
					retorno = 0;
				}
				break;
			case 4:
				break;
		}
	}
	return retorno;
}
