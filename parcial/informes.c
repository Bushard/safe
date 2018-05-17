#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "publicacion.h"
#include "informes.h"
#include "utn.h"
#define PAUSADO 0
#define ACTIVO 1

/** \brief enumera la canntidad de publicaciones activas
 *
 * \param arrayPublicacion EPublicacion*
 * \param limitePublicacion int
 * \param idCliente int
 * \return int contadorDe Activas
 *
 */
int informe_cantidadPublicacionesActivas(EPublicacion* arrayPublicacion, int limitePublicacion, int idCliente)
{
    int i;
    int contadorDeActivas=0;
    publicacion_ordenarPorIdCliente(arrayPublicacion,limitePublicacion);
    for(i=0;i<limitePublicacion;i++)
    {
        if(!arrayPublicacion[i].isEmpty && arrayPublicacion[i].idCliente == idCliente && arrayPublicacion[i].estado==ACTIVO)
        {
            contadorDeActivas++;
        }
    }
    return contadorDeActivas;
}

/** \brief muestra los clientes con más avisos activos
 *
 * \param arrayCliente ECliente*
 * \param limiteCliente int
 * \param arrayPublicacion EPublicacion*
 * \param limitePublicacion int
 * \return int -1 si hay un error, un 0 si está todo OK
 *
 */
int informe_clienteConMasAvisosActivos(ECliente* arrayCliente, int limiteCliente, EPublicacion* arrayPublicacion, int limitePublicacion)
{
    int retorno = -1;
    int i;
    int cantidadDeActivas;
    int maximoDePublicaciones=0;
    if(publicacion_verificarAlta(arrayPublicacion,limitePublicacion))
    {
        if(limiteCliente > 0 && arrayCliente != NULL && limitePublicacion >0 && arrayPublicacion !=NULL)
        {
            for(i=0;i<limiteCliente;i++)
            {
                if(!arrayCliente[i].isEmpty)
                {
                    cantidadDeActivas = informe_cantidadPublicacionesActivas(arrayPublicacion, limitePublicacion, arrayCliente[i].idCliente);
                    if(maximoDePublicaciones<cantidadDeActivas)
                    {
                        maximoDePublicaciones=cantidadDeActivas;
                    }
                }
            }
            for(i=0;i<limiteCliente;i++)
            {
                if(!arrayCliente[i].isEmpty)
                {
                    cantidadDeActivas=informe_cantidadPublicacionesActivas(arrayPublicacion,limitePublicacion,arrayCliente[i].idCliente);
                    if(maximoDePublicaciones == cantidadDeActivas)
                    {
                        printf("\nEl cliente con mas publicaciones activas es %s %s con %d avisos \n",arrayCliente[i].nombre, arrayCliente[i].apellido,maximoDePublicaciones);
                        retorno=0;
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


/** \brief enumera la cantidad de publicaciones pausadas
 *
 * \param arrayPublicacion EPublicacion*
 * \param limitePublicacion int
 * \param idCliente int
 * \return int contadoredPausadas
 *
 */
int informe_cantidadPublicacionesPausadas(EPublicacion* arrayPublicacion, int limitePublicacion, int idCliente)
{
    int i;
    int contadorDePausadas=0;
    publicacion_ordenarPorIdCliente(arrayPublicacion,limitePublicacion);
    for(i=0;i<limitePublicacion;i++)
    {
        if(!arrayPublicacion[i].isEmpty && arrayPublicacion[i].idCliente == idCliente && arrayPublicacion[i].estado==PAUSADO)
        {
            contadorDePausadas++;
        }
    }
    return contadorDePausadas;
}

/** \brief muestra al cliente con mas avisos pausados
 *
 * \param arrayCliente ECliente*
 * \param limiteCliente int
 * \param arrayPublicacion EPublicacion*
 * \param limitePublicacion int
 * \return int -1 si hay un error, un 0 si está todo OK
 *
 */
int informe_clienteConMasAvisosPausados(ECliente* arrayCliente, int limiteCliente, EPublicacion* arrayPublicacion, int limitePublicacion)
{
    int retorno = -1;
    int i;
    int cantidadDePausados;
    int maximoDePublicaciones=0;
    if(publicacion_verificarAlta(arrayPublicacion,limitePublicacion))
    {
        if(limiteCliente > 0 && arrayCliente != NULL && limitePublicacion >0 && arrayPublicacion !=NULL)
        {
            for(i=0;i<limiteCliente;i++)
            {
                if(!arrayCliente[i].isEmpty)
                {
                    cantidadDePausados = informe_cantidadPublicacionesPausadas(arrayPublicacion, limitePublicacion, arrayCliente[i].idCliente);
                    if(maximoDePublicaciones<cantidadDePausados)
                    {
                        maximoDePublicaciones=cantidadDePausados;
                    }
                }
            }
            for(i=0;i<limiteCliente;i++)
            {
                if(!arrayCliente[i].isEmpty)
                {
                    cantidadDePausados=informe_cantidadPublicacionesPausadas(arrayPublicacion,limitePublicacion,arrayCliente[i].idCliente);
                    if(maximoDePublicaciones == cantidadDePausados)
                    {
                        printf("\nEl cliente con mas publicaciones pausadas es %s %s con %d avisos \n",arrayCliente[i].nombre, arrayCliente[i].apellido,maximoDePublicaciones);
                        retorno=0;
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

/** \brief cuenta la cantidad de publicaciones de cada cliente
 *
 * \param arrayPublicacion EPublicacion*
 * \param limitePublicacion int
 * \param idCliente int
 * \return int contadorDePublicaciones
 *
 */
int informe_cantidadPublicaciones(EPublicacion* arrayPublicacion, int limitePublicacion, int idCliente)
{
    int i;
    int contadorDePublicaciones=0;
    publicacion_ordenarPorIdCliente(arrayPublicacion,limitePublicacion);
    for(i=0;i<limitePublicacion;i++)
    {
        if(!arrayPublicacion[i].isEmpty && arrayPublicacion[i].idCliente == idCliente)
        {
            contadorDePublicaciones++;
        }
    }
    return contadorDePublicaciones;
}

/** \brief muestra al cliente con más avisos
 *
 * \param arrayCliente ECliente*
 * \param limiteCliente int
 * \param arrayPublicacion EPublicacion*
 * \param limitePublicacion int
 * \return int -1 si hay un error, un 0 si está todo OK
 *
 */
int informe_clienteConMasAvisos(ECliente* arrayCliente, int limiteCliente, EPublicacion* arrayPublicacion, int limitePublicacion)
{
    int retorno = -1;
    int i;
    int cantidadDePublicaciones;
    int maximoDePublicaciones=0;
    if(publicacion_verificarAlta(arrayPublicacion,limitePublicacion))
    {
        if(limiteCliente > 0 && arrayCliente != NULL && limitePublicacion >0 && arrayPublicacion !=NULL)
        {
            for(i=0;i<limiteCliente;i++)
            {
                if(!arrayCliente[i].isEmpty)
                {
                    cantidadDePublicaciones = informe_cantidadPublicaciones(arrayPublicacion, limitePublicacion, arrayCliente[i].idCliente);
                    if(maximoDePublicaciones<cantidadDePublicaciones)
                    {
                        maximoDePublicaciones=cantidadDePublicaciones;
                    }
                }
            }
            for(i=0;i<limiteCliente;i++)
            {
                if(!arrayCliente[i].isEmpty)
                {
                    cantidadDePublicaciones=informe_cantidadPublicaciones(arrayPublicacion,limitePublicacion,arrayCliente[i].idCliente);
                    if(maximoDePublicaciones == cantidadDePublicaciones)
                    {
                        printf("\nEl cliente con mas publicaciones es %s %s con %d avisos \n",arrayCliente[i].nombre, arrayCliente[i].apellido,maximoDePublicaciones);
                        retorno=0;
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


/** \brief muestra la cantidad de publicaciones por rubro
 *
 * \param arrayPublicaciones EPublicacion*
 * \param limitePublicaciones int
 * \return int -1 si hay un error, un 0 si está todo OK
 *
 */
int informe_cantidadDePublicacionesPorRubro(EPublicacion* arrayPublicaciones, int limitePublicaciones)
{
    int retorno=-1;
    int auxRubro;
    int i;
    int contadorDeRubro=0;
    if(publicacion_verificarAlta(arrayPublicaciones,limitePublicaciones))
    {
        if(limitePublicaciones > 0 && arrayPublicaciones != NULL)
        {
            if(!getValidInt("\nIngrese el numero de Rubro:\n1- Electro.\n2- Jardin.\n3- Hogar.\nRubro: ","\nNumero no valido",&auxRubro,1,3,2))
            {
                for(i=0;i<limitePublicaciones;i++)
                {
                    if(arrayPublicaciones[i].rubro==auxRubro)
                    {
                        contadorDeRubro++;
                    }
                }
                switch (auxRubro)
                {
                case 1:
                    printf("El Rubro Electro tiene %d publicaciones activas",contadorDeRubro);
                    break;
                case 2:
                    printf("El Rubro Jardineria tiene %d publicaciones activas",contadorDeRubro);
                    break;
                case 3:
                    printf("El Rubro Hogar tiene %d publicaciones activas",contadorDeRubro);
                    break;
                }
            }

        }
    }
    else
    {
        printf("\nERROR.DEBE CARGAR UNA PUBLICACION ANTES\n");
    }
    return retorno;
}



/** \brief muestra los rubros con mas y menos publicaciones activas
 *
 * \param arrayPublicaciones EPublicacion*
 * \param limitePublicaciones int
 * \return int -1 si hay un error, un 0 si está todo OK
 *
 */
int informe_rubrosConMasYMenosActivas(EPublicacion* arrayPublicaciones, int limitePublicaciones)
{
    int retorno=-1;
    int i;
    int contadorElectro=0;
    int contadorJardin=0;
    int contadorHogar=0;
    int menor=999;
    int mayor=0;
    if(publicacion_verificarAlta(arrayPublicaciones,limitePublicaciones))
    {
        if(limitePublicaciones>0 && arrayPublicaciones != NULL)
        {
        retorno =0;
            for(i=0;i<limitePublicaciones;i++)
            {
                switch (arrayPublicaciones[i].rubro)
                {
                case 1:
                    contadorElectro++;
                    break;
                case 2:
                    contadorJardin++;
                    break;
                case 3:
                    contadorHogar++;
                    break;
                }
            }

            if(contadorElectro>mayor);
                mayor= contadorElectro;
            if(contadorJardin > mayor)
                mayor = contadorJardin;
            if(contadorHogar > mayor)
                mayor = contadorHogar;

            printf("\nEl rubro con mas publicaciones activas es: ");

            if(mayor == contadorElectro)
            {
                printf("Electro ");
            }
            if(mayor == contadorHogar)
            {
                printf("Hogar ");
            }

            if(mayor == contadorJardin)
            {
                printf("Jardin ");
            }
            printf("con %d avisos\n",mayor);

            if(contadorElectro<menor)
               menor= contadorElectro;
            if(contadorJardin < menor)
                menor = contadorJardin;
            if(contadorHogar < menor)
                menor = contadorHogar;

            printf("El rubro con menos publicaciones activas es: ");

            if(menor == contadorElectro)
                printf("Electro ");
            if(menor == contadorHogar)
                printf("hogar ");
            if(menor == contadorJardin)
                printf("Jardin ");
            printf("\n");

        }
    }
    else
    {
        printf("\nERROR.DEBE CARGAR UNA PUBLICACION ANTES\n");
    }
    return retorno;
}



/** \brief hardcodea los usuarios y publicaciones
 *
 * \param arrayClientes ECliente*
 * \param arrayPublicaciones EPublicacion*
 * \return void
 *
 */
void informe_hard(ECliente* arrayClientes, EPublicacion* arrayPublicaciones)
{
    strcpy(arrayClientes[0].nombre,"German");
    strcpy(arrayClientes[0].apellido,"Santos");
    strcpy(arrayClientes[0].cuit,"12344567891");
    arrayClientes[0].isEmpty=0;
    arrayClientes[0].idCliente= proximoIdCliente();
    arrayPublicaciones[0].idCliente=0;
    arrayPublicaciones[0].estado=ACTIVO;
    arrayPublicaciones[0].isEmpty=0;
    arrayPublicaciones[0].rubro=1;
    strcpy(arrayPublicaciones[0].descripcion,"Snes");
    arrayPublicaciones[0].idPublicacion=proximoIdPublicacion();


    strcpy(arrayClientes[1].nombre,"Marisa");
    strcpy(arrayClientes[1].apellido,"Ramirez");
    strcpy(arrayClientes[1].cuit,"12344577891");
    arrayClientes[1].isEmpty=0;
    arrayClientes[1].idCliente=proximoIdCliente();
    arrayPublicaciones[1].idCliente=1;
    arrayPublicaciones[1].estado=ACTIVO;
    arrayPublicaciones[1].isEmpty=0;
    arrayPublicaciones[1].rubro=2;
    strcpy(arrayPublicaciones[1].descripcion,"Tierra");
    arrayPublicaciones[1].idPublicacion=proximoIdPublicacion();

    strcpy(arrayClientes[2].nombre,"Luis");
    strcpy(arrayClientes[2].apellido,"Peranta");
    strcpy(arrayClientes[2].cuit,"23344567891");
    arrayClientes[2].isEmpty=0;
    arrayClientes[2].idCliente=proximoIdCliente();
    arrayPublicaciones[2].idCliente=2;
    arrayPublicaciones[2].estado=ACTIVO;
    arrayPublicaciones[2].isEmpty=0;
    arrayPublicaciones[2].rubro=3;
    strcpy(arrayPublicaciones[2].descripcion,"Heladera");
    arrayPublicaciones[2].idPublicacion=proximoIdPublicacion();

    strcpy(arrayClientes[3].nombre,"Milo");
    strcpy(arrayClientes[3].apellido,"Santos");
    strcpy(arrayClientes[3].cuit,"20528333434");
    arrayClientes[3].isEmpty=0;
    arrayClientes[3].idCliente=proximoIdCliente();
    arrayPublicaciones[3].idCliente=3;
    arrayPublicaciones[3].estado=ACTIVO;
    arrayPublicaciones[3].isEmpty=0;
    arrayPublicaciones[3].rubro=1;
    strcpy(arrayPublicaciones[3].descripcion,"Switch");
    arrayPublicaciones[3].idPublicacion=proximoIdPublicacion();

    arrayPublicaciones[4].idCliente=3;
    arrayPublicaciones[4].estado=PAUSADO;
    arrayPublicaciones[4].isEmpty=0;
    arrayPublicaciones[4].rubro=2;
    strcpy(arrayPublicaciones[4].descripcion,"Planta");
    arrayPublicaciones[4].idPublicacion=proximoIdPublicacion();

    arrayPublicaciones[5].idCliente=0;
    arrayPublicaciones[5].estado=ACTIVO;
    arrayPublicaciones[5].isEmpty=0;
    arrayPublicaciones[5].rubro=3;
    strcpy(arrayPublicaciones[5].descripcion,"Cocina");
    arrayPublicaciones[5].idPublicacion=proximoIdPublicacion();

    arrayPublicaciones[6].idCliente=3;
    arrayPublicaciones[6].estado=PAUSADO;
    arrayPublicaciones[6].isEmpty=0;
    arrayPublicaciones[6].rubro=1;
    strcpy(arrayPublicaciones[6].descripcion,"Home theater");
    arrayPublicaciones[6].idPublicacion=proximoIdPublicacion();

    arrayPublicaciones[7].idCliente=0;
    arrayPublicaciones[7].estado=ACTIVO;
    arrayPublicaciones[7].isEmpty=0;
    arrayPublicaciones[7].rubro=1;
    strcpy(arrayPublicaciones[7].descripcion,"Playstation");
    arrayPublicaciones[7].idPublicacion=proximoIdPublicacion();

    arrayPublicaciones[8].idCliente=0;
    arrayPublicaciones[8].estado=ACTIVO;
    arrayPublicaciones[8].isEmpty=0;
    arrayPublicaciones[8].rubro=2;
    strcpy(arrayPublicaciones[8].descripcion,"Bordeadora");
    arrayPublicaciones[8].idPublicacion=proximoIdPublicacion();





}















