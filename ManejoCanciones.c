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
            printf("entro a guardarArchivo\n");
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

void mostrarCancionesEliminadas(nodoArbolCancion * arbol)
{
    if(arbol!=NULL)
    {
        mostrarCancionesEliminadas(arbol->izq);
        if(arbol->song.eliminado == 1)
        {
            mostrarCancion(arbol->song);
        }
        mostrarCancionesEliminadas(arbol->der);
    }

}

int buscarID(char buscador[])
{
    FILE * archi=fopen(SONGS,"rb");
    Cancion buscando;
    int pos=-1;
    if(archi!=NULL)
    {
        while(fread(&buscando,sizeof(Cancion),1,archi))
        {
            if(strcmp(buscador,buscando.titulo)== 0)
            {
                pos=buscando.idCancion;
            }
        }
        fclose(archi);
    }
    return pos;
}



nodoArbolCancion * altaCreado(nodoArbolCancion * arbol,char buscador[])
{
    Cancion buscar;

    FILE * archi=fopen(SONGS,"r+b");
    if(archi!=NULL)
    {
        fseek(archi,sizeof(Cancion)*buscarID(buscador),SEEK_SET);
        fread(&buscar,sizeof(Cancion),1,archi);
        fseek(archi,sizeof(Cancion)*-1,SEEK_CUR);
        buscar.eliminado=0;
        arbol=cargarArbolOrdenado(arbol,CrearNodoArbolSong(buscar));
        fwrite(&buscar,sizeof(Cancion),1,archi);
        fclose(archi);
    }
    return arbol;
}


int contarRegistrosCanciones(int pesoDat)
{
    FILE * archi=fopen(SONGS,"rb");
    int total;
    if(archi!=NULL)
    {
        fseek(archi,0,SEEK_END);
        total=ftell(archi)/pesoDat;
        fclose(archi);
    }
    return total;
}



nodoArbolCancion * modificarCancion(nodoArbolCancion * arbol, int eleccion,nodoArbolCancion * nuevo)
{

    if(eleccion!=0 && eleccion<5)
    {


        switch(eleccion)
        {
        case 1:
            printf("Cambiar Nombre:\n");
            fflush(stdin);
            printf("Nombre anterior: %s",nuevo->song.titulo);
            printf("Nuevo nombre: ");
            gets(nuevo->song.titulo);
            break;
        case 2:
            printf("Cambiar Album:");
            printf("Nombre del album anterior: %s",nuevo->song.album);
            printf("Nombre del album nuevo : ");
            fflush(stdin);
            gets(nuevo->song.album);
            break;
        case 3:
            printf("Cambiar tiempo:\n");
            printf("Tiempo anterior de : %i",nuevo->song.duracion);
            printf("Nuevo tiempo :");
            fflush(stdin);
            scanf("%i",&nuevo->song.duracion);
            break;
        case 4:
            printf("Cambiar anio:\n");
            printf("Anio Anterior: %i\n",nuevo->song.anio);
            printf("Nuevo anio :");
            fflush(stdin);
            scanf("%i",&nuevo->song.anio);
            break;

        }
        FILE * archi=fopen(SONGS,"r+b");
        if(archi!=NULL)
        {
            fseek(archi,sizeof(Cancion)*nuevo->song.idCancion,SEEK_SET);
            fwrite(&nuevo->song,sizeof(Cancion),1,archi);
            fclose(archi);
        }
    }
    return arbol;
}



void mostrarArchivoCancion()
{
    Cancion cancioncita;
    FILE * archi=fopen(SONGS,"rb");
    if(archi!=NULL)
    {
        while(fread(&cancioncita,sizeof(Cancion),1,archi)>0)
        {
            mostrarCancion(cancioncita);
        }
        fclose(archi);
    }
}



void bajarDelArchivo(char nombre[])
{
    Cancion cancioncita;
    int flag=0;
    FILE * archi=fopen(SONGS,"r+b");
    if(archi!=NULL)
    {
        while(fread(&cancioncita,sizeof(Cancion),1,archi)>0 && flag == 0)
        {
            if(strcmp(cancioncita.titulo,nombre)==0)
            {
                cancioncita.eliminado=0;
                fseek(archi,sizeof(Cancion)*cancioncita.idCancion,SEEK_SET);
                fwrite(&cancioncita,sizeof(Cancion),1,archi);
                flag=1;
            }
        }
        fclose(archi);
    }
}


nodoArbolCancion * bajaCancion(nodoArbolCancion * arbol,char nombre[])
{
    bajarDelArchivo(nombre);
    arbol=borrarCancionPorID(arbol,buscarID(nombre));
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
