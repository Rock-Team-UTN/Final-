#ifndef TDALISTA_H_INCLUDED
#define TDALISTA_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include "ManejoCanciones.h"

typedef struct
{
    Cancion c;
    struct nodoListaCancion * sig;
} nodoListaCancion;

nodoListaCancion * inicListaCanciones();
nodoListaCancion * crearNodoLista(Cancion c);
nodoListaCancion * agregarAlPrincipio(nodoListaCancion * cancion, nodoListaCancion * lista);
nodoListaCancion * agregarAlFinal(nodoListaCancion * cancion, nodoListaCancion * lista);
nodoListaCancion * agregarEnOrdenPorNombreDeCancion(nodoListaCancion * cancion, nodoListaCancion * lista);
void mostrarLista(nodoListaCancion * lista);
nodoListaCancion * borrarNodoPorIdCancion(nodoListaCancion * lista, int id);


#endif // TDAUSUARIO_H_INCLUDED
