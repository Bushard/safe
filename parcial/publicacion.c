#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "publicacion.h"
#include "utn.h"
#define PAUSADO 0
#define ACTIVO 1
/** \brief inicializa el array publicaciones
 * \param array EPublicacion*
 * \param limite int
 * \return int -1 si hay un error, un 0 si está todo OK
 *
 */
int publicacion_init(EPublicacion* arrayPublicaciones,int limitePublicacion)
{
    int retorno = -1;
    int i;
    if(limitePublicacion > 0 && arrayPublicaciones != NULL)
    {
        retorno = 0;
        for(i=0;i<limitePublicacion;i++)
        {
            arrayPublicaciones[i].isEmpty=1;
        }
    }
    return retorno;
}

/** \brief muestra las publicaciones del array Publicacion
 *
 * \param arrayPublicaciones EPublicacion*
 * \param limitePublicacion int
 * \return int -1 si hay un error, un 0 si está todo OK
 *
 */
int publicacion_mostrar(EPublicacion* arrayPublicaciones,int limitePublicacion)
{
    int retorno = -1;
    int i;
    if(limitePublicacion > 0 && arrayPublicaciones != NULL)
    {
        retorno = 0;
        for(i=0;i<limitePublicacion;i++)
        {
            if(!arrayPublicaciones[i].isEmpty && arrayPublicaciones[i].estado==ACTIVO)
            {
                printf("-ID: %d ",arrayPublicaciones[i].idPublicacion);
                switch (arrayPublicaciones[i].rubro)
                {
                    case 1:
                        printf("-Rubro: Electro  ");
                        break;
                    case 2:
                        printf("-Rubro: Jardin  ");
                        break;
                    case 3:
                        printf("-Rubro: Hogar ");
                        break;
                }
                printf("-DESCRIPCION: %s \n",arrayPublicaciones[i].descripcion);
            }
        }
    }
    return retorno;
}

/** \brief muestra las publicaciones del array Publicacion con estado PAUSADO
 *
 * \param arrayPublicaciones EPublicacion*
 * \param limitePublicacion int
 * \return int -1 si hay un error, un 0 si está todo OK
 *
 */
int publicacion_mostrarPausada(EPublicacion* arrayPublicaciones,int limitePublicacion)
{
    int retorno = -1;
    int i;
    if(limitePublicacion > 0 && arrayPublicaciones != NULL)
    {
        retorno = 0;
        for(i=0;i<limitePublicacion;i++)
        {
            if(!arrayPublicaciones[i].isEmpty && arrayPublicaciones[i].estado==PAUSADO)
            {
                printf("-ID: %d ",arrayPublicaciones[i].idPublicacion);
                switch (arrayPublicaciones[i].rubro)
                {
                    case 1:
                        printf("-Rubro: Electro  ");
                        break;
                    case 2:
                        printf("-Rubro: Jardin  ");
                        break;
                    case 3:
                        printf("-Rubro: Hogar ");
                        break;
                }
                printf("-DESCRIPCION: %s \n",arrayPublicaciones[i].descripcion);
            }
        }
    }
    return retorno;
}
/** \brief Da de alta una publicacion
 *
 * \param arrayPublicaciones EPublicacion*
 * \param limitePublicacion int
 * \param arrayCliente ECliente*
 * \param limiteCliente int
 * \return int -1 si hay un error,-3  si no hay datos cargados,-2 si no hay lugar libre y un 0 si está todo OK
 *
 */
int publicacion_alta(EPublicacion* arrayPublicaciones,int limitePublicacion,ECliente* arrayCliente, int limiteCliente)
{
    int retorno = -1;
    int i;
    int posicion;
    int auxId;
    int auxRubro;
    char auxDesc[65];
    if(cliente_verificarAlta(arrayCliente,limiteCliente))
    {
        if(limitePublicacion > 0 && arrayPublicaciones != NULL)
        {
            posicion = publicacion_buscarLugarLibre(arrayPublicaciones,limitePublicacion);
            if(posicion >= 0)
            {
                if(!getValidInt("\nID de usuario? ","\nId invalida\n",&auxId,0,999,2))
                {
                    for(i=0;i<limiteCliente;i++)
                    {
                        if (auxId==arrayCliente[i].idCliente);
                         {

                            if(!getValidInt("\nIngrese el rubro 1-electro 2-jardin 3-Hogar ","Rubro no valido", &auxRubro,1,3,2))
                            {
                                if(!getValidString("ingrese descripcion.(max 64 caracteres): ","Cadena no valida","Exceso de caracteres. MAX 64", auxDesc, 65, 2))
                                {
                                    retorno = 0;
                                    strcpy(arrayPublicaciones[posicion].descripcion,auxDesc);
                                    arrayPublicaciones[posicion].idCliente=auxId;
                                    arrayPublicaciones[posicion].rubro=auxRubro;
                                    arrayPublicaciones[posicion].estado=ACTIVO;
                                    arrayPublicaciones[posicion].idPublicacion = proximoIdPublicacion();
                                    arrayPublicaciones[posicion].isEmpty = 0;
                                    printf("-ID: %d ",arrayPublicaciones[posicion].idPublicacion);
                                    switch (arrayPublicaciones[posicion].rubro)
                                    {
                                    case 1:
                                        printf("-Rubro: Electro  ");
                                        break;
                                    case 2:
                                        printf("-Rubro: Jardin ");
                                        break;
                                    case 3:
                                        printf("-Rubro: Hogar ");
                                        break;
                                    }
                                    printf("-DESCRIPCION: %s \n",arrayPublicaciones[posicion].descripcion);
                                    break;
                                }
                                else
                                {
                                    retorno=-3;//DATOS NO CARGADOS
                                }

                            }
                         }
                    }
                    if (i==limiteCliente)
                        {
                            printf("ERROR NO EXISTE CLIENTE\n");
                        }
                }

            }
            else
            {
                retorno =-2;//no hay lugar libre
            }


    }
    }
    else
    {
        printf("Debe dar de alta un cliente primero\n");
    }
    return retorno;
}


/** \brief Da de baja logica a una publicacion
 *
 * \param arrayPublicaciones EPublicacion*
 * \param limitePublicacion int
 * \param id int
 * \return int -1 si hay un error,-2 si hay un error en algun parametro y un 0 si está todo OK
 *
 */
int publicacion_baja(EPublicacion* arrayPublicaciones,int limitePublicacion, int id)
{
    int retorno = -1;
    int i;
    if(limitePublicacion > 0 && arrayPublicaciones != NULL)
    {
        retorno = -2;
        for(i=0;i<limitePublicacion;i++)
        {
            if(!arrayPublicaciones[i].isEmpty && arrayPublicaciones[i].idPublicacion==id)
            {
                arrayPublicaciones[i].isEmpty = 1;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un lugar libre en el array de publicacion
 *
 * \param arrayPublicaciones EPublicacion*
 * \param limite int
 * \return int -1 si hay un error, un retorno si encontro un lugar
 *
 */
int publicacion_buscarLugarLibre(EPublicacion* arrayPublicaciones,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayPublicaciones != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(arrayPublicaciones[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


static int proximoIdPub = -1;
/** \brief genera un contador para generar una unica ID de publicacion
 *
 * \param void
 * \return int el ID generado
 *
 */
int proximoIdPublicacion(void)
{
    proximoIdPub++;
    return proximoIdPub;
}

/** \brief cambia el estado de una publicacion de ACTIVO a PAUSADO
 *
 * \param arrayPublicaciones EPublicacion*
 * \param limitePublicacion int
 * \param arrayCliente ECliente*
 * \param limiteCliente int
 * \return int -2 si hay un errorde carga,  un 0 si está todo OK
 *
 */
int publicacion_pausar(EPublicacion* arrayPublicaciones,int limitePublicacion, ECliente* arrayCliente, int limiteCliente)
{
    int retorno = -1;
    int i;
    int j;
    int auxId;
    if(publicacion_verificarAlta(arrayPublicaciones,limitePublicacion))
    {
            if(limitePublicacion > 0 && arrayPublicaciones !=NULL && limiteCliente > 0 && arrayCliente !=NULL)
        {
            retorno = -2;

            if(!getValidInt("\nIngrese el ID: ","\nID no valido.", &auxId,0,999,2))
            {
                for(i=0;i<limitePublicacion;i++)
                {
                    if(!arrayPublicaciones[i].isEmpty && arrayPublicaciones[i].idPublicacion==auxId)
                    {
                        for(j=0;j<limiteCliente;j++)
                        {
                            if(arrayPublicaciones[i].idCliente==arrayCliente[j].idCliente)
                            {
                                printf("\n-ID: %d -Nombre: %s -Apellido %s -CUIT: %s \n",arrayCliente[j].idCliente, arrayCliente[j].nombre, arrayCliente[j].apellido,arrayCliente[j].cuit);
                                break;
                            }

                        }
                        if(j==limiteCliente)
                        {
                            printf("\nERROR. NO EXISTE CLIENTE\n");
                        }
                        else if(!confirmacion("Desea Pausar?"))
                        {
                            retorno=0;
                            arrayPublicaciones[i].estado=PAUSADO;
                            printf("\nPUBLICACION PAUSADA\n");
                        }
                        break;
                    }
                }
            }
        }
    }
    else
    {
        printf("\nERROR. DEBE CARGAR UNA PUBLICACION PRIMERO\n");
    }

    return retorno;
}

/** \brief muestra los clientes con sus publicaciones activas
 *
 * \param arrayCliente ECliente*
 * \param limiteCliente int
 * \param arrayPublicaciones EPublicacion*
 * \param limitePublicacion int
 * \return int -1 si hay un error, un 0 si está todo OK
 *
 */
int publicacion_mostrarClientesConPublicacionesActivas(ECliente* arrayCliente, int limiteCliente, EPublicacion* arrayPublicaciones,int limitePublicacion)
{
    int retorno = -1;
    int i,j;
    if(limiteCliente > 0 && arrayCliente != NULL && limitePublicacion >0 && arrayPublicaciones !=NULL)
    {
        retorno = 0;
        printf("\n*********************************************************************\n");
        for(i=0;i<limiteCliente;i++)
        {
            if(!arrayCliente[i].isEmpty)
            {
                printf("\n-ID: %d -Nombre: %s -Apellido %s -CUIT: %s\n ",arrayCliente[i].idCliente, arrayCliente[i].nombre, arrayCliente[i].apellido,arrayCliente[i].cuit);
                for(j=0;j<limitePublicacion;j++)
                {
                    if (arrayPublicaciones[j].idCliente==arrayCliente[i].idCliente && arrayPublicaciones[j].estado==ACTIVO)
                    {
                         switch (arrayPublicaciones[j].rubro)
                        {
                        case 1:
                            printf("-Rubro: electro  ");
                            break;
                        case 2:
                            printf("-Rubro: jardin");
                            break;
                        case 3:
                            printf("-Rubro: Hogar");
                            break;
                        }
                         printf("-DESCRIPCION: %s \n",arrayPublicaciones[j].descripcion);

                    }

                }
                printf("\n*********************************************************************\n");


            }
        }
    }
    return retorno;
}

/** \brief Muestra todas las publicaciones con los cuits de los clientes
 *
 * \param arrayCliente ECliente*
 * \param limiteCliente int
 * \param arrayPublicaciones EPublicacion*
 * \param limitePublicacion int
 * \return int -1 si hay un error, un 0 si está todo OK
 *
 */
int publicacion_mostrarPublicacionesConCuitDelCliente(ECliente* arrayCliente, int limiteCliente, EPublicacion* arrayPublicaciones,int limitePublicacion)
{
    int retorno = -1;
    int i,j;
    if(limiteCliente > 0 && arrayCliente != NULL && limitePublicacion >0 && arrayPublicaciones !=NULL)
    {
        retorno = 0;
        printf("\n*********************************************************************\n");
        for(i=0; i<limitePublicacion; i++)
        {
            if(!arrayPublicaciones[i].isEmpty && arrayPublicaciones[i].estado)
            {
                printf("-ID: %d ",arrayPublicaciones[i].idPublicacion);
                switch (arrayPublicaciones[i].rubro)
                {
                    case 1:
                        printf("-Rubro: Electro  ");
                        break;
                    case 2:
                        printf("-Rubro: Jardin ");
                        break;
                    case 3:
                        printf("-Rubro: Hogar ");
                        break;
                }
                printf("-DESCRIPCION: %s \n",arrayPublicaciones[i].descripcion);
                for(j=0; j<limiteCliente; j++)
                {
                    if (arrayPublicaciones[i].idCliente==arrayCliente[j].idCliente && !arrayCliente[j].isEmpty )
                    {
                        printf("- CUIT: %s\n",arrayCliente[j].cuit);

                    }

                }
            }
        }
        printf("\n*********************************************************************\n");
    }
    return retorno;
}


/** \brief recorre el vertor y cuenta cuantos hay cargados segun parametro isEmpty
 *
 * \param arrayPublicacion EPublicacion*
 * \param limitePublicacion int
 * \return int contador
 *
 */
int publicacion_verificarAlta(EPublicacion* arrayPublicacion, int limitePublicacion)
{
    int i, contador=0;

    for(i=0; i<limitePublicacion; i++)
    {
        if(!arrayPublicacion[i].isEmpty)
        {
            contador++;
        }
    }
    return contador;
}

/** \brief Cambia el estado de una publicacion de PAUSADO a ACTIVO
 *
 * \param arrayPublicaciones EPublicacion*
 * \param limitePublicacion int
 * \param arrayCliente ECliente*
 * \param limiteCliente int
 * \return int
 *
 */
int publicacion_reanudar(EPublicacion* arrayPublicaciones,int limitePublicacion, ECliente* arrayCliente, int limiteCliente)
{
    int retorno = -1;
    int i;
    int j;
    int auxId;
    if(publicacion_verificarAlta(arrayPublicaciones,limitePublicacion))
    {
            if(limitePublicacion > 0 && arrayPublicaciones !=NULL && limiteCliente > 0 && arrayCliente !=NULL)
        {
            retorno = -2;
            if(!getValidInt("\nIngrese el ID: ","\nID no valido.", &auxId,0,999,2))
            {
                for(i=0;i<limitePublicacion;i++)
                {
                    if(!arrayPublicaciones[i].isEmpty && arrayPublicaciones[i].idPublicacion==auxId)
                    {
                        for(j=0;j<limiteCliente;j++)
                        {
                            if(arrayPublicaciones[i].idCliente==arrayCliente[j].idCliente)
                            {
                                printf("\n-ID: %d -Nombre: %s -Apellido %s -CUIT: %s \n",arrayCliente[j].idCliente, arrayCliente[j].nombre, arrayCliente[j].apellido,arrayCliente[j].cuit);
                                break;
                            }

                        }
                        if(j==limiteCliente)
                        {
                            printf("\nERROR. NO EXISTE CLIENTE\n");
                        }
                        else if(!confirmacion("Desea reanudar?"))
                        {
                            retorno=0;
                            arrayPublicaciones[i].estado=ACTIVO;
                            printf("\nPUBLICACION REANUDADA\n");
                        }
                        break;
                    }
                }
            }
        }
    }
    else
    {
        printf("\nERROR. DEBE CARGAR UNA PUBLICACION PRIMERO\n");
    }

    return retorno;
}

/** \brief ordena el array  de menor a mayor segun su Id de cliente
 *
 * \param arrayPublicacion EPublicacion*
 * \param limitePublicacion int
 * \return int -1 si hay un error, un 0 si está todo OK
 *
 */
int publicacion_ordenarPorIdCliente(EPublicacion* arrayPublicacion,int limitePublicacion)
{
    int retorno = -1;
    int i;
    int flag;
    EPublicacion auxiliarEstructura;
    if(publicacion_verificarAlta(arrayPublicacion,limitePublicacion))
    {
        if(limitePublicacion > 0 && arrayPublicacion != NULL)
        {
            do
            {
                flag = 0;
                for(i=0;i<limitePublicacion-1;i++)
                {
                    if(!arrayPublicacion[i].isEmpty && !arrayPublicacion[i+1].isEmpty)
                    {
                        if(arrayPublicacion[i].idCliente < arrayPublicacion[i+1].idCliente) //******
                        {
                            auxiliarEstructura = arrayPublicacion[i];
                            arrayPublicacion[i] = arrayPublicacion[i+1];
                            arrayPublicacion[i+1] = auxiliarEstructura;
                            flag = 1;
                        }
                    }
                }
            }while(flag);
        }
    }
    else
    {
        printf("ERROR. Debe dar un alta primero.");
    }
    return retorno;
}

