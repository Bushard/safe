#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include "cliente.h"
#include "utn.h"

/** \brief inicializa el arrayCliente
 * \param arrayCliente ECliente*
 * \param limiteCliente int
 * \return int int -1 si hay un error, un 0 si está todo OK
 *
 */
int cliente_init(ECliente* arrayCliente,int limiteCliente)
{
    int retorno = -1;
    int i;
    if(limiteCliente > 0 && arrayCliente != NULL)
    {
        retorno = 0;
        for(i=0;i<limiteCliente;i++)
        {
            arrayCliente[i].isEmpty=1;
        }
    }
    return retorno;
}


/** \brief Muestra los parametros de array Cliente
 *
 * \param arrayCliente ECliente*
 * \param limiteCliente int
 * \return int -1 si hay un error, un 0 si está todo OK
 *
 */
int cliente_mostrar(ECliente* arrayCliente,int limiteCliente)
{
    int retorno = -1;
    int i;
    if(limiteCliente > 0 && arrayCliente != NULL)
    {
        retorno = 0;
        for(i=0;i<limiteCliente;i++)
        {
            if(!arrayCliente[i].isEmpty)
                printf("\n-ID: %d -Nombre: %s -Apellido %s -CUIT: %s \n",arrayCliente[i].idCliente, arrayCliente[i].nombre, arrayCliente[i].apellido,arrayCliente[i].cuit);
        }
    }
    return retorno;
}

/** \brief Da de alta una estructura ECliente
 *
 * \param arrayCliente ECliente*
 * \param limiteCliente int
 * \return int -1 si hay un error, un 0 si está todo OK
 *
 */
int cliente_alta(ECliente* arrayCliente,int limiteCliente)
{
    int retorno = -1;
    int i;
    char auxNombre[51];
    char auxApellido[51];
    char auxCuit[12];
if(limiteCliente > 0 && arrayCliente != NULL)
    {
        i = buscarLugarLibre(arrayCliente,limiteCliente);
        if(i >= 0)
        {
            if(!getValidString("\nNombre? ","\nEso no es un nombre","\nEl maximo son 50 letras",auxNombre,51,2))
            {
                if(!getValidString("\nApellido? ", "\nApellido no valido","\nEl maximo son 50 letras",auxApellido,51,2))
                {
                        if(!cliente_getCuit("Ingrese su CUIT: ","(solo numeros)\n",auxCuit))
                        {
                            retorno = 0;
                            strcpy(arrayCliente[i].nombre, auxNombre);
                            strcpy(arrayCliente[i].apellido, auxApellido);
                            strcpy(arrayCliente[i].cuit, auxCuit);
                            arrayCliente[i].idCliente = proximoIdCliente();
                            arrayCliente[i].isEmpty = 0;
                            printf("\nDATOS CARGADOS\n");

                        }
                        else
                        {
                            retorno = -5;
                        }
                }
                else
                {
                    retorno = -4;
                }
            }
            else
            {
                retorno = -3;
            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}


/** \brief Da de baja una estructura
 *
 * \param arrayCliente ECliente*
 * \param limiteCliente int
 * \param id int
 * \return int -1 si hay un error, un 0 si está todo OK
 *
 */
int cliente_baja(ECliente* arrayCliente,int limiteCliente, int id)
{
    int retorno = -1;
    int i;
    if(cliente_verificarAlta(arrayCliente,limiteCliente))
    {
        if(limiteCliente > 0 && arrayCliente != NULL)
        {
            retorno = -2;
            if(!confirmacion("\nSeguro desea eliminar este usuario?\n"))
            {
                for(i=0;i<limiteCliente;i++)
                {

                    if(!arrayCliente[i].isEmpty && arrayCliente[i].idCliente==id)
                    {
                        arrayCliente[i].isEmpty = 1;
                        retorno = 0;
                        break;
                    }
                }
            }
        }
    }
    else
    {
        printf("\nERROR. Debe dar un alta primero.\n");
    }
    return retorno;
}




/** \brief Modifica una estructura ECliente ya cargada
 *
 * \param arrayCliente ECliente*
 * \param limiteCliente int
 * \param id int
 * \return int -1 si hay un error, un 0 si está todo OK
 *
 */
int cliente_modificacion(ECliente* arrayCliente,int limiteCliente, int id)
{
    int retorno = -1; // null exception
    int i;
    char auxNombre[51];
    char auxApellido[51];
    char auxCuit[12];
    if(cliente_verificarAlta(arrayCliente,limiteCliente))
    {
        if(limiteCliente > 0 && arrayCliente != NULL)
        {
            for(i=0; i<limiteCliente; i++)
            {
                if(!arrayCliente[i].isEmpty && arrayCliente[i].idCliente==id)
                {
                    if(!getValidString("\nNombre? ","\nEso no es un nombre","\nEl maximo son 50 letras",auxNombre,51,2))
                    {
                        if(!getValidString("\nApellido? ", "\nApellido no valido","\nEl maximo son 50 letras",auxApellido,51,2))
                        {
                            if(!cliente_getCuit("\nIngrese su cuit: ","CUIT INVALIDO\n",auxCuit))
                            {
                                retorno = 0;
                                strcpy(arrayCliente[i].nombre, auxNombre);
                                strcpy(arrayCliente[i].apellido, auxApellido);
                                strcpy(arrayCliente[i].cuit,auxCuit);
                                arrayCliente[i].isEmpty = 0;
                                break;

                            }
                            else
                            {
                                retorno = -5; // cuit invalido
                            }
                        }
                        else
                        {
                            retorno = -4; //apellido invalido
                        }
                    }
                    else
                    {
                        retorno = -3; //nombre invalido
                    }
                }
                else
                {
                    retorno = -2; //no existe cliente
                }
            }
        }
    }
    else
    {
        printf("\nERROR DEBE CARGAR UN CLIENTE PRIMERO\n");
    }

    return retorno;
}


/** \brief Busca el primer lugar disponible en el array
 *
 * \param arrayCliente ECliente*
 * \param limiteCliente int
 * \return int -1 si hay un error, un 0 si está todo OK
 *
 */
int buscarLugarLibre(ECliente* arrayCliente,int limiteCliente)
{
    int retorno = -1;
    int i;
    if(limiteCliente > 0 && arrayCliente != NULL)
    {
        for(i=0;i<limiteCliente;i++)
        {
            if(arrayCliente[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


/** \brief genera un contador para no repetir la ID
 *
 * \param
 * \param
 * \return proximoId
 *
 */
static int proximoId = -1;
int proximoIdCliente()
{
    proximoId++;
    return proximoId;
}

/** \brief verifica si el arrayCliente tiene un dato cargado
 *
 * \param arrayCliente ECliente*
 * \param limiteCliente int
 * \return int contador 0 si esta vacio X si está cargado
 *
 */
int cliente_verificarAlta(ECliente* arrayCliente, int limiteCliente)
{
    int i;
    int contador=0;

    for(i=0; i<limiteCliente; i++)
    {
        if(!arrayCliente[i].isEmpty)
        {
            contador++;
        }
    }
    return contador;
}

/** \brief toma una cadena numerica y verifica que tenga 11 caracteres numericos
 *
 * \param mensaje char*
 * \param mensajeError char*
 * \param input char*
 * \return int 1 si hay error 0 si esta todo OK
 *
 */
int cliente_getCuit(char* mensaje, char* mensajeError, char* input)
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux)&& (strlen(aux)==11 ))
    {
        strcpy(input,aux);
        return 0;
    }
    else
    {
        printf(mensajeError);
    }
    return 1;
}

/** \brief Pregunta al usuario si esta seguro de la accion a realizar
 *
 * \param texto char*
 * \return int 0 si cancelo la operacion 1 si la aceptó
 *
 */
int confirmacion(char* texto)
{
    char confirmar;

    printf("%s", texto);
    printf("\npresione ENTER para continuar o ESC para cancelar?\n\n");
    fflush(stdin);
    confirmar = getch();
    while (!(confirmar==27 || confirmar==13))
    {
        printf("\nERROR. presione ENTER para continuar o ESC para cancelar?\n\n");
        fflush(stdin);
        confirmar= getch();
    }
    if (confirmar!= 27 )
    {
        return 0;
    }
    else
    {
        printf("\nACCION CANCELADA POR EL USUARIO\n\n");
        return 1;
    }


}
















