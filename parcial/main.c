#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "publicacion.h"
#include "informes.h"
#include "utn.h"
#define QTY_CLIENTE 100
#define QTY_PUBLICACIONES 1000

int main()
{
    ECliente arrayClientes[QTY_CLIENTE];
    EPublicacion arrayPublicaciones[QTY_PUBLICACIONES];
    int menu;
    int auxiliarId;
    int aux;
    cliente_init(arrayClientes,QTY_CLIENTE);
    publicacion_init(arrayPublicaciones, QTY_PUBLICACIONES);
    do
    {

        getValidInt("\n\n\n1.Alta Cliente\n2.Modificar dato de cliente \n3.Baja de cliente\n4.Publicar\n5.Pausar publicacion\n6.Reanudar publicacion\n7.Imprimir clientes (con publicaciones Activas)\n8.Imprimir publicaciones (junto a los cuits de los clientes)\n9.Informar cliente \n\tA-Cliente con mas avisos activos \n\tB-Cliente con mas avisos pausados \n\tC-Cliente con mas avisos\n10.Informar Publicaciones \n\tA-Cantidad de publicaciones de un rubro \n\tB-Rubro con mas publicaciones activas \n\tC-Rubro con menos publicaciones activas) .\n11.Salir\n","\nNo valida\n",&menu,1,3010,1);
        switch(menu)
        {
            case 1:
                clearScreen();
                printf("\n\n\n******CARGA DE CLIENTE******\n\n\n");
                aux=cliente_alta(arrayClientes,QTY_CLIENTE);
                if(aux<=-1 && aux>= -5)
                {
                    printf("ERROR: %d, DATOS NO CARGADOS\n",aux);
                }

                break;
            case 2:
                clearScreen();
                printf("\n\n\n******MODIFICAR DATOS DE CLIENTE******\n\n\n");
                cliente_mostrar(arrayClientes, QTY_CLIENTE);
                getValidInt("ID?","\nNumero no valido\n",&auxiliarId,0,200,2);
                aux=cliente_modificacion(arrayClientes,QTY_CLIENTE,auxiliarId);
                if(aux<=-1 && aux>= -5)
                {
                    printf("ERROR: %d, DATOS NO CARGADOS\n",aux);
                }
                break;
            case 3:
                clearScreen();
                printf("\n\n\n******DAR DE BAJA A UN CLIENTE******\n\n\n");
                cliente_mostrar(arrayClientes, QTY_CLIENTE);
                getValidInt("ID?","\nNumero no valido\n",&auxiliarId,0,200,2);
                aux=cliente_baja(arrayClientes,QTY_CLIENTE,auxiliarId);
                if(aux==-1 || aux== -2)
                    printf("ERROR: %d, DATOS NO CARGADOS\n",aux);
                else
                    printf("\n**********************\n");
                    printf("*Cliente dado de baja*\n");
                    printf("**********************\n");
                break;
            case 4:
                clearScreen();
                printf("\n\n\n******DAR DE ALTA PUBLICACIONES******\n\n\n");
                cliente_mostrar(arrayClientes, QTY_CLIENTE);
                aux = publicacion_alta(arrayPublicaciones, QTY_PUBLICACIONES, arrayClientes,QTY_CLIENTE);
                if(aux>=-1 && aux<= -3)
                printf("ERROR: %d, DATOS NO CARGADOS\n",aux);
                break;
            case 5:
                clearScreen();
                printf("\n\n\n******PAUSAR PUBLICACION******\n\n\n");
                publicacion_mostrar(arrayPublicaciones,QTY_PUBLICACIONES);
                aux=publicacion_pausar(arrayPublicaciones,QTY_PUBLICACIONES,arrayClientes,QTY_CLIENTE);
                if(aux>=-1 && aux<= -3)
                printf("ERROR: %d, PUBLICACION SIN PAUSAR\n",aux);
                break;
            case 6:
                clearScreen();
                printf("\n\n\n******REANUDAR PUBLICACION******\n\n\n");
                publicacion_mostrarPausada(arrayPublicaciones,QTY_PUBLICACIONES);
                aux=publicacion_reanudar(arrayPublicaciones,QTY_PUBLICACIONES,arrayClientes, QTY_CLIENTE);
                if(aux>=-1 && aux<= -3)
                    printf("ERROR: %d, PUBLICACION SIN REANUDAR \n\n\n",aux);
                break;
            case 7:
                clearScreen();
                printf("\n\n\n******CLIENTES CON PUBLICACIONES ACTIVAS******\n\n\n");
                publicacion_mostrarClientesConPublicacionesActivas(arrayClientes,QTY_CLIENTE,arrayPublicaciones,QTY_PUBLICACIONES);
                break;
            case 8:
                clearScreen();
                printf("\n\n\n******PUBLICACIONES JUNTO A EL CUIT DEL CLIENTE******\n\n\n");
                publicacion_mostrarPublicacionesConCuitDelCliente(arrayClientes,QTY_CLIENTE,arrayPublicaciones,QTY_PUBLICACIONES);
                break;
            case 9:
                clearScreen();
                printf("\n\n\n******INFORME DE CLIENTES******\n\n\n");
                informe_clienteConMasAvisosActivos(arrayClientes,QTY_CLIENTE,arrayPublicaciones,QTY_PUBLICACIONES);
                informe_clienteConMasAvisosPausados(arrayClientes,QTY_CLIENTE,arrayPublicaciones,QTY_PUBLICACIONES);
                informe_clienteConMasAvisos(arrayClientes,QTY_CLIENTE,arrayPublicaciones,QTY_PUBLICACIONES);
                break;
            case 10:
                clearScreen();
                printf("\n\n\n******INFORME DE RUBROS******\n\n\n");
                informe_cantidadDePublicacionesPorRubro(arrayPublicaciones,QTY_PUBLICACIONES);
                informe_rubrosConMasYMenosActivas(arrayPublicaciones,QTY_PUBLICACIONES);
                break;
            case 11:
                menu=11;
                break;
            case 3010:
                clearScreen();
                informe_hard(arrayClientes,arrayPublicaciones);
                break;
            default:
                printf("\nOpcion invalida.");
                break;

        }

    }while(menu != 11);

    return 0;
}
