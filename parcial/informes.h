#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
int informe_cantidadPublicacionesActivas(EPublicacion* arrayPublicacion, int limitePublicacion, int idCliente);
int informe_clienteConMasAvisosActivos(ECliente* arrayCliente, int limiteCliente, EPublicacion* arrayPublicacion, int limitePublicacion);
int informe_cantidadPublicacionesPausadas(EPublicacion* arrayPublicacion, int limitePublicacion, int idCliente);
int informe_clienteConMasAvisosPausados(ECliente* arrayCliente, int limiteCliente, EPublicacion* arrayPublicacion, int limitePublicacion);
int informe_cantidadPublicaciones(EPublicacion* arrayPublicacion, int limitePublicacion, int idCliente);
int informe_clienteConMasAvisos(ECliente* arrayCliente, int limiteCliente, EPublicacion* arrayPublicacion, int limitePublicacion);
int informe_cantidadDePublicacionesPorRubro(EPublicacion* arrayPublicaciones, int limitePublicaciones);
int informe_rubrosConMasYMenosActivas(EPublicacion* arrayPublicaciones, int limitePublicaciones);
void informe_hard(ECliente* arrayClientes, EPublicacion* arrayPublicaciones);
#endif // INFORMES_H_INCLUDED
