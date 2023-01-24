#include <stdio.h>
#define MAX 300
struct 
{
    char titulo[100];
    char editorial[150];
    short edicion;
    char fechaPublicacion[50];
    long int isbn;
    char categoria;
    int cantidadEjemplares;
    int stock;
}typedef publicaciones;  

void MostrarPublicaciones(publicaciones publicacion);
char Modificar(char categoria, long int isbn, char editorial[150]);
publicaciones CargarPublicaciones();

int main(void)
{   
    publicaciones publi, inventario[MAX], *p_inventario;
    int cantPublicaciones;
    printf("Ingrese la cantidad de publicaciones que desea cargar: \n");
    scanf("%d",&cantPublicaciones);
    p_inventario = malloc(cantPublicaciones * sizeof(publicaciones));


    publi = CargarPublicaciones(cantPublicaciones,);
    publi.categoria = Modificar(publi.categoria, publi.isbn, publi.editorial);
    MostrarPublicaciones(publi);   
    return 0;
}

publicaciones CargarPublicaciones()
{   
    publicaciones publicacion;

    int bandera, bandera2;
    printf("--------------   CARGADO DE BIBLIOTECA   -------------- \n\n");
    printf("Ingrese el titulo de la publicacion\n");
    gets(publicacion.titulo);
    fflush(stdin);
    printf("Ingrese el editorial de la publicacion\n");
    gets(publicacion.editorial);
    fflush(stdin);
    printf("Ingrese la edicion de la publicacion\n");
    scanf("%d",&publicacion.edicion);
    fflush(stdin);
    printf("Ingrese la fecha de la publicacion, con formato dia-mes-anio, por ejemplo 02-08-2019\n");
    gets(publicacion.fechaPublicacion);
    fflush(stdin);
    
    do 
    {
        printf("Ingrese su correspondiente ISBN (El ISB debe ser un codigo formado por 10-13 diguitos, o ser 0)\n");
        scanf("%d",&publicacion.isbn);   
        fflush(stdin);
        if ((publicacion.isbn >= 1000000000 && publicacion.isbn < 9999999999999) || publicacion.isbn == 0)
        {
            bandera2 = 1;
            //printf("paso por aqui\n");
        } else {
            bandera2 = 0;
            //printf("paso por alla\n");
        }           
    } while(bandera2 != 1);
    
    
    do
    {
        printf("Cual es la categoria de la publicacion (L para libro, T para tesis, o R para resvista)\n");    
        scanf("%c",&publicacion.categoria);
        fflush(stdin);

        if (publicacion.categoria != 'L' || publicacion.categoria != 'T' || publicacion.categoria !='R' || publicacion.categoria != 'l' || publicacion.categoria != 'r' || publicacion.categoria != 't')
        {
            bandera = 1;
            //printf("paso por aqui");
        } else {
            bandera = 0;
            //printf("paso por alla");
        }
    } while (bandera != 1);    
    printf("De cuantos ejemplares se trata\?\n"); 
    scanf("%d",&publicacion.cantidadEjemplares);
    printf("Cuantos hay en stock\?\n"); 
    scanf("%d",&publicacion.stock);
    printf("\n--------------------------------------------------- \n\n");

    return publicacion;
}

void MostrarPublicaciones(publicaciones publicacion)
{
    printf("--------------   DATOS DE LA PUBLICACION   -------------- \n\n");
    printf("Titulo:                       ");
    puts(publicacion.titulo);
    printf("Editorial:                    ");
    puts(publicacion.editorial);
    printf("Edicion:                      %d",publicacion.edicion);
    printf("\nFecha de Publicacion:         ");
    puts(publicacion.fechaPublicacion);
    printf("ISBN:                         %d",publicacion.isbn);
    printf("\nCategoria:                    ");
    if (publicacion.categoria == 'L')
    {
        printf("Libro\n");
    }
    if (publicacion.categoria == 'R')
    {
        printf("Revista\n");
    }
    if (publicacion.categoria == 'T')
    {
        printf("Tesis\n");
    }
    
    //printf("%c",publicacion.categoria);
    printf("\nCantidad de ejemplares:       %d",publicacion.cantidadEjemplares);
    printf("\nStock:                        %d",publicacion.stock);
    printf("\n--------------------------------------------------------- \n\n");
}

char Modificar(char categoria, long int isbn, char editorial[150])
{
    char aux,arre[150]= "FACET";
    int coincidencias=0;
    if (isbn != ' ')
    {
        aux = 'L';
    }

    for (int i = 0; i < 6; i++)
    {
        if (editorial[i] == arre[i])
        {
            coincidencias= coincidencias + 1;
            //printf("Uvo coincidencia");
        }
        
    }    

    if (isbn == 0 && coincidencias == 6)
    {
        aux = 'T';
    } else {
        if (isbn == 0)
        {
            aux = 'R';
        }
    }
    return aux;    
}
