#include "tdaPlaylist.h"


int pasarDeArchivoPlaylistToADL(nodoArbolCancion * canciones, stNodo * usuarios, stCelda playlist[]) {
    stPlaylist escucha;
    Cancion cancion;
    Usuario usuario;
    int val = 0;
    int pos = 0;
    FILE * archi = fopen(filePlaylist, "rb");

    if (archi != NULL) {
        while (fread(&escucha, sizeof(stPlaylist), 1, archi)>0) {
                cancion = buscarIdEnArbol(canciones, escucha.idCancion)->song;
                pos = buscarUsuarioEnArreglo(playlist, val, escucha.idUsuario);
                if (pos == -1) {
                    usuario = buscarUsuarioPorId(usuarios, escucha.idUsuario);
                    val = agregarUsuario(playlist, val, usuario);
                    pos = val - 1;
                }
                playlist[pos] = agregarCancionToUsuario(cancion, playlist[pos]);
        }
    fclose(archi);
    }

    return val;
}


int buscarUsuarioEnArreglo(stCelda playlist[], int val, int id) {
    int flag = 0;
    int i = 0;
    while (i < val && flag == 0) {
        if (playlist[i].usr.idUsuario == id) {
            flag = 1;
        }
        else {
            i++;
        }
    }
    if (flag == 0) {
        i = -1;
    }
    return i;
}

int agregarUsuario(stCelda playlist[], int val, Usuario usuario) {
    stCelda celda;
    celda = inicCelda(usuario);
    playlist[val] = celda;
    val++;
    return val;
}

stCelda inicCelda(Usuario usuario) {
    stCelda nuevaCelda;
    nuevaCelda.usr = usuario;
    nuevaCelda.listaCanciones = NULL;
    return nuevaCelda;
}

stCelda agregarCancionToUsuario(Cancion cancion, stCelda usuario) {
    nodoListaCancion * nuevoNodo;
    nuevoNodo = crearNodoLista(cancion);
    usuario.listaCanciones = agregarAlFinal(nuevoNodo, usuario.listaCanciones);
return usuario;
}

void mostrarUsuarios(stCelda playlist[], int val) {
    for (int i=0; i<val; i++) {
        mostrarAlumno(playlist[i].usr);
        mostrarLista(playlist[i].listaCanciones);
    }
}

void persistirCancionesEscuchadas(stCelda playlist[], int val) {
    nodoListaCancion * seg;
    stPlaylist escucha;
    FILE * archi = fopen(filePlaylist, "wb");
    if (archi != NULL) {
        int cont = 0;
        for (int i=0; i<val; i++) {
            seg = playlist[i].listaCanciones;
            while(seg!=NULL) {
                cont++;
                escucha.idPlaylist = cont;
                escucha.idUsuario = playlist[i].usr.idUsuario;
                escucha.idCancion = seg->c.idCancion;
                fwrite(&escucha, sizeof(stPlaylist), 1, archi);
            }
        }
        fclose(archi);
    }
}

/*int limpiarArregloDeListas(stCelda playlist[], int val) {

};*/
