#ifndef PUBLICACION_H_INCLUDED
#define PUBLICACION_H_INCLUDED
typedef struct
{
    char descripcion[65];
    int idCliente;
    int rubro;
    int estado;
    //------------
    int idPublicacion;
    int isEmpty;
}EPublicacion;

int publicacion_init(EPublicacion* array,int limite);
int publicacion_mostrar(EPublicacion* array,int limite);
int publicacion_mostrarPausada(EPublicacion* arrayPublicaciones,int limitePublicacion);
int publicacion_mostrarDebug(EPublicacion* array,int limite);
//int publicacion_alta(EPublicacion* array,int limite);
int publicacion_modificacion(EPublicacion* array,int limite, int id);
int publicacion_ordenar(EPublicacion* array,int limite, int orden);
int publicacion_ordenarPorIdCliente(EPublicacion* arrayPublicacione,int limitePublicacion);
int publicacion_buscarLugarLibre(EPublicacion* arrayPublicaciones,int limite);
int publicacion_pausar(EPublicacion* arrayPublicaciones,int limitePublicacion, ECliente* arrayCliente, int limiteCliente);
int publicacion_reanudar(EPublicacion* arrayPublicaciones,int limitePublicacion, ECliente* arrayCliente, int limiteCliente);
int publicacion_alta(EPublicacion* array,int limite, ECliente* arrayCliente, int LimiteCliente);
int publicacion_verificarAlta(EPublicacion* arrayPublicacion, int limitePublicacion);
int publicacion_mostrarClientesConPublicacionesActivas(ECliente* arrayCliente, int limiteCliente, EPublicacion* arrayPublicaciones,int limitePublicacion);
int publicacion_mostrarPublicacionesConCuitDelCliente(ECliente* arrayCliente, int limiteCliente, EPublicacion* arrayPublicaciones,int limitePublicacion);
int proximoIdPublicacion(void);


#endif // PUBLICACION_H_INCLUDED





