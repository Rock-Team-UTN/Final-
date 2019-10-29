#include <stdlib.h>
#include <stdio.h>
#include "tdaLista.h"
#include "cancionesTDA2.h"

nodoListaCancion * inicListaCanciones() {
    return NULL;
}

nodoListaCancion * crearNodoLista(Cancion c) {
    nodoListaCancion * nodo = (nodoListaCancion *) malloc(sizeof(nodoListaCancion));
    nodo->c = c;
    nodo->sig = NULL;
    return nodo;
}

nodoListaCancion * agregarAlPrincipio(nodoListaCancion * cancion, nodoListaCancion * lista) {
    cancion->sig = lista;
    lista = cancion;
    return lista;
}

nodoListaCancion * agregarAlFinal(nodoListaCancion * cancion, nodoListaCancion * lista) {
    nodoListaCancion * seg = lista;
    if (lista != NULL) {
        while (seg->sig != NULL) {
            seg = seg->sig;
        }
        seg->sig = cancion;
    } else {
        lista = cancion;
    }
    return lista;
}

nodoListaCancion * agregarEnOrdenPorNombreDeCancion(nodoListaCancion * cancion, nodoListaCancion * lista) {
    if(lista == NULL) {
      lista = cancion;
    } else {
        if(strcmp(cancion->c.titulo,lista->c.titulo)<0){
            lista = agregarAlPrincipio(cancion, lista);
        } else {
            nodoListaCancion * ante = lista;
            nodoListaCancion * seg = lista->sig;
            while((seg != NULL)
                    &&(strcmp(cancion->c.titulo,seg->c.titulo)>0)) {
                ante = seg;
                seg = seg->sig;
            }
            cancion->sig = seg;
            ante->sig = cancion;
        }
    }
    return lista;
}

nodoListaCancion * borrarNodoPorIdCancion(nodoListaCancion * lista, int id) {
    nodoListaCancion * seg;
    nodoListaCancion * ante;
    if((lista != NULL) && (lista->c.idCancion == id)) {
        nodoListaCancion * aux = lista;
        lista = lista->sig;
        free(aux);
    } else {
        seg = lista;
        while((seg != NULL) && (seg->c.idCancion != id)) {
            ante = seg;
            seg = seg->sig;
        }
        if(seg!=NULL) {
            ante->sig = seg->sig;
            free(seg);
        }
    }
}

void mostrarLista(nodoListaCancion * lista) {
    nodoListaCancion * seg = lista;
    while (seg != NULL) {
        mostrarCancion(seg->c);
        seg = seg->sig;
    }
}
