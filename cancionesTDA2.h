#ifndef CANCIONESTDA2_H_INCLUDED
#define CANCIONESTDA2_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SONGS "canciones.dat"

typedef struct
{
    int idCancion;
    char titulo[30];
    char artista[20];
    int duracion;
    char album[20];
    int anio;
    char genero[20];
    char comentario[100];
    int eliminado;  /// indica 1 o 0 si la canción fue eliminada
} Cancion;

typedef struct  ///Arbol de clientes
{
    Cancion song;
    struct nodoArbolCancion * izq;
    struct nodoArbolCancion * der;
} nodoArbolCancion;

///Prototipados de funciones
nodoArbolCancion * InicArbol();
nodoArbolCancion * CrearNodoArbolSong (Cancion song);
nodoArbolCancion * cargarArbolOrdenado (nodoArbolCancion * arbol,nodoArbolCancion * nuevo);
void mostrarCancion(Cancion song);
void mostrarPreOrder(nodoArbolCancion* arbol);
void mostrarInOrder(nodoArbolCancion* arbol);
void mostrarPostOrder(nodoArbolCancion* arbol);
nodoArbolCancion * buscarIdEnArbol (nodoArbolCancion * arbol, int idSong);
nodoArbolCancion *NMD(nodoArbolCancion* arbol);
nodoArbolCancion *NMI(nodoArbolCancion* arbol);
nodoArbolCancion * borrarCancionPorID(nodoArbolCancion*arbol,int idSong);
nodoArbolCancion * buscarCancionEnArbol (nodoArbolCancion* arbol,char nombreCancion[]);

#endif // CANCIONESTDA2_H_INCLUDED
