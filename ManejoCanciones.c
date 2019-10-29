#include "ManejoCanciones.h"

nodoArbolCancion* cargarCanciones(nodoArbolCancion*arbol)
{
    Cancion cancioncita;
    char opcion = 0;
    nodoArbolCancion* aux= NULL;
    int id=0;
    do
    {
        cancioncita.idCancion = IdCancion(id);
        printf("ID: %i \n",cancioncita.idCancion);
        printf("Ingrese el titulo de la cancion: \n");
        fflush(stdin);
        gets(cancioncita.titulo);

        printf("\nIngrese Artista: \n");
        fflush(stdin);
        gets(cancioncita.artista);

        printf("\nIngrese duracion en segundos: \n");
        fflush(stdin);
        scanf("%i",&cancioncita.duracion);

        printf("\nIngrese nombre del Album: \n");
        fflush(stdin);
        gets(cancioncita.album);

        printf("\nIngrese a%co del disco: \n",164);
        fflush(stdin);
        scanf("%i",&cancioncita.anio);

        printf("\nIngrese genero: \n");
        fflush(stdin);
        gets(cancioncita.genero);

        printf("\nIngrese Comentario: \n");
        fflush(stdin);
        gets(cancioncita.comentario);
        GuardarCancion(cancioncita);
        arbol = cargarArbolOrdenado(arbol,CrearNodoArbolSong(cancioncita));

        printf("\nPresiones ESC para salir...\n");
        opcion = getch();

    }
    while(opcion!=27);
    return arbol;


}
int IdCancion(int id)
{
    FILE*archi =fopen(SONGS,"rb");
    Cancion musica;
    if(archi!=NULL)
    {
        fseek(archi,sizeof(Cancion)*-1,SEEK_END);
        fread(&musica,sizeof(Cancion),1,archi);
        id=musica.idCancion + 1;
        fclose(archi);
    }
    return id;
}
nodoArbolCancion *  archivoToArbol(nodoArbolCancion* arbol)
{
    Cancion cancioncita;

    FILE * archi = fopen(SONGS,"rb");
    if(archi!=NULL)
    {
        while(fread(&cancioncita,sizeof(Cancion),1,archi)>0)
        {
            arbol=cargarArbolOrdenado(arbol,CrearNodoArbolSong(cancioncita));
        }
    }
    return arbol;
}

void GuardarCancion (Cancion musica)
{
    FILE *archi = fopen(SONGS,"ab");
    Cancion cancioncita;
    if (archi!=NULL)
    {
        fwrite(&musica,sizeof(Cancion),1,archi);
        fclose(archi);
    }

}

void mostrarCancionesEliminadas(nodoArbolCancion * arbol){
   if(arbol!=NULL){
    mostrarCancionesEliminadas(arbol->izq);
    if(arbol->song.eliminado == 1){
        mostrarCancion(arbol->song);
    }
    mostrarCancionesEliminadas(arbol->der);
   }

}

int buscarID(char buscador[]){
    FILE * archi=fopen(SONGS,"rb");
    Cancion buscando;
    int pos-1;
    if(archi!=NULL){
        while(fread(&buscando,sizeof(Cancion),1,archi)){
            if(strcmp(buscador,buscando.titulo)== 0){
                pos=buscando.idCancion;
            }
        }
    fclose(archi);
    }
return id;
}


nodoArbolCancion * altaCreado(nodoArbolCancion * arbol,char buscador[]){
    Cancion buscar;

    FILE * archi=fopen(SONGS,"r+b");
    if(archi!=NULL){
        fseek(archi,sizeof(Cancion)*buscarID(buscador),SEEK_SET);
        fread(&buscar,sizeof(Cancion),1,archi);
        fseek(archi,sizeof(Cancion)*-1,SEEK_CUR);
        buscar.eliminado=0;
        arbol=cargarArbolOrdenado(arbol,CrearNodoArbolSong(buscar));
        fwrite(&nuevo->song,sizeof(Cancion),1,archi);
        fclose(archi);
        }
return arbol;
}


/*void MostrarPorNombreCancion(nodoArbolCancion * arbol);
    nodoArbolCancion * aux=NULL;
    char titulo[DIM];

    printf("\n Ingrese la cancion que desea buscar\n");
    fflush(stdin);
    gets(titulo);

    aux=buscarCancionEnArbol(arbol,titulo);
    if (aux!=NULL){
    ///printf("\nID Cancion:  %i\n",song.idCancion);
    printf("Titulo: %s\n",aux->song.titulo);
    printf("Artista: %s\n",aux->song.artista);
    printf("Duraci%cn: %i\n",162,aux->song.duracion);
    printf("A%co: %i\n",164,aux->song.anio);
    printf("Genero: %c\n",aux->song.genero);
    printf("Comentario: %s\n",aux->song.comentario);
    }else{
        printf("\nNo se ha encontrado dicho apellido\n");
    }
}*/
