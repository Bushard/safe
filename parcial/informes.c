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

int informe_cantidadDePublicacionesPorRubro(EPublicacion* arrayPublicaciones, int limitePublicaciones)
{
    int retorno=-1;
    int auxRubro;
    int i;
    int acumuladorDeRubro;
    if(publicacion_verificarAlta(arrayPublicaciones,limitePublicaciones))
    {
        if(limitePublicaciones > 0 && arrayPublicaciones != NULL)
        {
            if(!getValidInt("\nIngrese el numero de Rubro:\n1- Electro.\n2- Jardin.\n3- Hogar. ","\nNumero no valido",&auxRubro,1,3,2))
            {
                for(i=0;i<limitePublicaciones;i++)
                {
                    if(arrayPublicaciones[i].rubro==auxRubro)
                    {
                        acumuladorDeRubro++;
                    }
                }
                switch (auxRubro)
                {
                case 1:
                    printf("El Rubro Electro tiene %d publicaciones activas",acumuladorDeRubro);
                    break;
                case 2:
                    printf("El Rubro Jardineria tiene %d publicaciones activas",acumuladorDeRubro);
                    break;
                case 3:
                    printf("El Rubro Hogar tiene %d publicaciones activas",acumuladorDeRubro);
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

int informe_rubrosConMasYMenosActivas(EPublicacion* arrayPublicaciones, int limitePublicaciones)
{
    int retorno=-1;
    int i;
    int acumuladorElectro=0;
    int acumuladorJardin=0;
    int acumuladorHogar=0;
    if(publicacion_verificarAlta(arrayPublicaciones,limitePublicaciones))
    {
        if(limitePublicaciones>0 && arrayPublicaciones != NULL)
        {
            retorno=0;
            for(i=0;i<limitePublicaciones;i++)
            {
                switch(arrayPublicaciones[i].rubro)
                {
                    case 1:
                    {
                        acumuladorElectro++;
                        break;
                    }
                    case 2:
                    {
                        acumuladorJardin++;
                        break;
                    }
                    case 3:
                    {
                        acumuladorHogar++;
                        break;
                    }

                }
            }

            if(acumuladorElectro>acumuladorJardin && acumuladorElectro>acumuladorHogar)
            {
                printf("\nEl Rubro con mas publicaciones activas es : Electro \n");
            }
            else if(acumuladorJardin>acumuladorElectro && acumuladorJardin>acumuladorHogar)
            {
                printf("\nEl Rubro con mas publicaciones activas es : Jardineria\n");
            }
            else if(acumuladorHogar>acumuladorElectro && acumuladorHogar>acumuladorJardin)
            {
                printf("\nEl Rubro con mas publicaciones activas es : Hogar\n");
            }
            else if (acumuladorElectro==acumuladorHogar && acumuladorElectro > acumuladorJardin)
            {
                printf("\nLos rubros con mas publicaciones activas son: Electro y Hogar");
            }
            else if (acumuladorElectro==acumuladorJardin && acumuladorElectro > acumuladorHogar)
            {
                printf("\nLos rubros con mas publicaciones activas son: Electro y Jardin");
            }
            else if (acumuladorJardin==acumuladorHogar && acumuladorJardin>acumuladorElectro)
            {
                printf("\nLos rubros con mas publicaciones activas son: Hogar y Jardin");
            }
            if(acumuladorElectro<acumuladorJardin && acumuladorElectro<acumuladorHogar)
            {
                printf("\nEl Rubro con menos publicaciones activas es : Electro \n");
            }
            else if(acumuladorJardin<acumuladorElectro && acumuladorJardin<acumuladorHogar)
            {
                printf("\nEl Rubro con menos publicaciones activas es : Jardineria\n");
            }
            else if(acumuladorHogar<acumuladorElectro && acumuladorHogar<acumuladorJardin)
            {
                printf("\nEl Rubro con menos publicaciones activas es : Hogar\n");
            }
            else if (acumuladorElectro==acumuladorJardin && acumuladorElectro < acumuladorHogar)
            {
                printf("\nLos rubros con menos publicaciones activas son: Electro y Jardin");
            }
            else if (acumuladorElectro==acumuladorHogar && acumuladorElectro < acumuladorJardin)
            {
                printf("\nLos rubros con menos publicaciones activas son: Electro y Hogar");
            }
            else if (acumuladorJardin==acumuladorHogar && acumuladorJardin < acumuladorElectro)
            {
                printf("\nLos rubros con menos publicaciones activas son: Hogar y Jardin");
            }


        }
    }
    else
    {
        printf("\nERROR. DEBE CARGAR UNA PUBLICACION PRIMERO.\n");
    }
    return retorno;
}



void informe_hard(ECliente* arrayClientes, EPublicacion* arrayPublicaciones)
{
    strcpy(arrayClientes[0].nombre,"German");
    strcpy(arrayClientes[0].apellido,"Santos");
    strcpy(arrayClientes[0].cuit,"123445678910");
    arrayClientes[0].isEmpty=0;
    arrayClientes[0].idCliente=0;
    arrayPublicaciones[0].idCliente=0;
    arrayPublicaciones[0].estado=ACTIVO;
    arrayPublicaciones[0].isEmpty=0;
    arrayPublicaciones[0].rubro=1;
    strcpy(arrayPublicaciones[0].descripcion,"Snes");
    arrayPublicaciones[0].idPublicacion=0;


    strcpy(arrayClientes[1].nombre,"Marisa");
    strcpy(arrayClientes[1].apellido,"Ramirez");
    strcpy(arrayClientes[1].cuit,"123445678910");
    arrayClientes[1].isEmpty=0;
    arrayClientes[1].idCliente=1;
    arrayPublicaciones[1].idCliente=0;
    arrayPublicaciones[1].estado=ACTIVO;
    arrayPublicaciones[1].isEmpty=0;
    arrayPublicaciones[1].rubro=2;
    strcpy(arrayPublicaciones[1].descripcion,"Tierra");
    arrayPublicaciones[1].idPublicacion=1;

    strcpy(arrayClientes[2].nombre,"Luis");
    strcpy(arrayClientes[2].apellido,"Peranta");
    strcpy(arrayClientes[2].cuit,"233445678910");
    arrayClientes[2].isEmpty=0;
    arrayClientes[2].idCliente=2;
    arrayPublicaciones[2].idCliente=0;
    arrayPublicaciones[2].estado=ACTIVO;
    arrayPublicaciones[2].isEmpty=0;
    arrayPublicaciones[2].rubro=3;
    strcpy(arrayPublicaciones[2].descripcion,"Heladera");
    arrayPublicaciones[2].idPublicacion=2;

    strcpy(arrayClientes[3].nombre,"Milo");
    strcpy(arrayClientes[3].apellido,"Santos");
    strcpy(arrayClientes[3].cuit,"20528333434");
    arrayClientes[3].isEmpty=0;
    arrayClientes[3].idCliente=3;
    arrayPublicaciones[3].idCliente=3;
    arrayPublicaciones[3].estado=ACTIVO;
    arrayPublicaciones[3].isEmpty=0;
    arrayPublicaciones[3].rubro=1;
    strcpy(arrayPublicaciones[3].descripcion,"Switch");
    arrayPublicaciones[3].idPublicacion=3;

    arrayPublicaciones[4].idCliente=3;
    arrayPublicaciones[4].estado=PAUSADO;
    arrayPublicaciones[4].isEmpty=0;
    arrayPublicaciones[4].rubro=2;
    strcpy(arrayPublicaciones[4].descripcion,"Planta");
    arrayPublicaciones[4].idPublicacion=4;

    arrayPublicaciones[5].idCliente=0;
    arrayPublicaciones[5].estado=ACTIVO;
    arrayPublicaciones[5].isEmpty=0;
    arrayPublicaciones[5].rubro=3;
    strcpy(arrayPublicaciones[5].descripcion,"Cocina");
    arrayPublicaciones[5].idPublicacion=5;

    arrayPublicaciones[6].idCliente=3;
    arrayPublicaciones[6].estado=PAUSADO;
    arrayPublicaciones[6].isEmpty=0;
    arrayPublicaciones[6].rubro=3;
    strcpy(arrayPublicaciones[6].descripcion,"Microondas");
    arrayPublicaciones[6].idPublicacion=6;

    arrayPublicaciones[7].idCliente=0;
    arrayPublicaciones[7].estado=ACTIVO;
    arrayPublicaciones[7].isEmpty=0;
    arrayPublicaciones[7].rubro=1;
    strcpy(arrayPublicaciones[7].descripcion,"Playstation");
    arrayPublicaciones[7].idPublicacion=7;





}















