#include "menuCanciones.h"

void menuCanciones(nodoArbolCancion * arbol)
{
    int total;
    int seleccion;
    char cancion[50];
    nodoArbolCancion * cancione=InicArbol();
    int confirmacion;
    int opcion;
    arbol=archivoToArbol(arbol);
    do
    {
        system("cls");
        Logo();

        printf("\n\t\t\t\t<<<<<<<CARGAR CANCIONES>>>>>>>>\n");
        printf(" \t\t\t\t1:CARGA DE CANCIONES\n\t\t\t\t2:MOSTRAR\n\t\t\t\t3:TOTAL DE REGISTROS\n\t\t\t\t4:BAJA CANCION\n\t\t\t\t5:MODIFICAR\n\t\t\t\t6:MOSTRAR TODAS LAS CANCIONES\n\t\t\t\t0:SALIR\n\t\t\t\t");
        fflush(stdin);
        scanf("%i",&seleccion);
        switch (seleccion)
        {
        case 1:
            system("cls");
            Logo();
            printf("\t\t\t\t<<<<<<<<CARGA DE CANCIONES>>>>>>>>>>>\n");
            printf("\n\t\t\t\t1:Cargar cancion nueva\n\t\t\t\t2:Dar de alta cancion existente\n\t\t\t\t");
            fflush(stdin);
            scanf("%i",&opcion);
            switch(opcion)
            {
            case 1:
                arbol=cargarCanciones(arbol);
                break;
            case 2:
                  mostrarCancionesEliminadas(arbol);
                  printf("\n\t\t\t\tIngrese el nombre de la cancion que desea dar de alta\n\t\t\t\t");
                  fflush(stdin);
                  gets(cancion);
                  arbol=altaCreado(arbol,cancion);
                break;
            }
            break;

        case 2:
            system("cls");
            Logo();
            printf("\t\t\t\t<<<<<<<<LISTADO DE CANCIONES>>>>>>>>>>>\n");
            mostrarInOrder(arbol);
            getch();
            break;

            case 3:
            system("cls");
            Logo();
            printf("\t\t\t\t<<<<<<<<CANTIDAD DE REGISTROS>>>>>>>>>>>\n");
            total=contarRegistrosCanciones(sizeof(Cancion));
            printf("\t\t\t\tcantidad de registos %i",total);
            getch();

            break;
             case 4:
            system("cls");
            Logo();
            printf("\t\t\t\t<<<<<<<<<<<<<BAJA CANCION>>>>>>>>>>>>>>>\n");
            mostrarInOrder(arbol);
            printf("\t\t\t\tIngrese nombre de cancion a dar de baja\n\t\t\t\t");
            fflush(stdin);
                gets(cancion);
                arbol=bajaCancion(arbol,cancion);
                break;

            case 5:
            system("cls");
             Logo();
             printf("\t\t\t\t<<<<<<<<<<<<MODIFICAR>>>>>>>>>>>\n");
            mostrarArchivoCancion();
             printf("\t\t\t\tIngrese nombre de cancion que desea modificar\n\t\t\t\t");
             fflush(stdin);
             gets(cancion);
             confirmacion=buscarID(cancion);
             if(confirmacion!=-1){
                 cancione=buscarCancionEnArbol(arbol,cancion);
                 printf(" \t\t\t\t1:CAMBIAR NOMBRE\n\t\t\t\t2:CAMBIAR ALBUM\n\t\t\t\t3:CAMBIAR TIEMPO\n\t\t\t\t4:CAMBIAR ANIO\n\t\t\t\t0:SALIR\n\t\t\t\t");
                 fflush(stdin);
                 scanf("%i",&seleccion);
                 arbol=modificarCancion(arbol,seleccion,cancione);

        }
         break;

        case 6:
        system("cls");
        Logo();
        printf("\t\t\t\t<<<<<<<<LISTADO DE CANCIONES>>>>>>>>>>>\n");
        mostrarArchivoCancion();
        getch();


    }
}    while(seleccion!=0);

}

