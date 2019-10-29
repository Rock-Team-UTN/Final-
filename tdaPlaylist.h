#ifndef PLAYLIST_H_INCLUDED
#define PLAYLIST_H_INCLUDED
#include "tdaLista.h"
#include "menuAdm.h"
#include "ManejoCanciones.h"

typedef struct
{
    Usuario usr;
    nodoListaCancion * listaCanciones;
} stCelda;

typedef struct
{
    int idPlaylist;
    int idUsuario;
    int idCancion;
} stPlaylist;


#define filePlaylist "playlist.dat"

int pasarDeArchivoPlaylistToADL(nodoArbolCancion * canciones, stNodo * usuarios, stCelda playlist[]);
int agregarUsuario(stCelda playlist[], int val, Usuario usuario); // crea un nuevo usuario en el arreglo
int buscarUsuarioEnArreglo(stCelda playlist[], int val, int id); // busca un usuario por idUsuario y retorna la posición que ocupa en el arreglo
void mostrarUsuarios(stCelda playlist[], int val); // muestra todo el arreglo de listas, cada usuario con sus canciones escuchadas
stCelda agregarCancionToUsuario(Cancion cancion, stCelda usuario);/// agrega una Cancion al Usuario correspondiente
///int limpiarArregloDeListas(); // esta función “vacía” todo el arreglo de listas, dejando la estructura preparada para volver a trabajar
void persistirCancionesEscuchadas(stCelda playlist[], int val); // esta función realizará la persistencia de todas las canciones escuchadas en el archivo correspondiente
stCelda inicCelda(Usuario usuario);

#endif // TDAUSUARIO_H_INCLUDED
