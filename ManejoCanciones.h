#ifndef MANEJOCANCIONES_H_INCLUDED
#define MANEJOCANCIONES_H_INCLUDED
#include "cancionesTDA2.h"

nodoArbolCancion* cargarCanciones(nodoArbolCancion*arbol);
int IdCancion(int id);
nodoArbolCancion *  archivoToArbol(nodoArbolCancion* arbol);
void GuardarCancion (Cancion musica);
int buscarID(char buscador[]);
nodoArbolCancion * altaCreado(nodoArbolCancion * arbol,char buscador[]);
void mostrarCancionesEliminadas(nodoArbolCancion * arbol);
nodoArbolCancion * bajaCancion(nodoArbolCancion * arbol,char nombre[]);
void bajarDelArchivo(char nombre[]);
void mostrarArchivoCancion();
nodoArbolCancion * modificarCancion(nodoArbolCancion * arbol, int eleccion,nodoArbolCancion * nuevo);
int contarRegistrosCanciones(int pesoDat);


#endif // MANEJOCANCIONES_H_INCLUDED
