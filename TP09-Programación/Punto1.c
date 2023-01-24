#include <stdio.h>
#include <stdlib.h>
#define MAX 200
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

void CargarPublicaciones(publicaciones *p_publicacion, int cant);
void MostrarPublicaciones(publicaciones *p_publicacion, int cant);
void ContarLibroSinStok(publicaciones *p_publicacion, int *p_cant);
void Modificar(publicaciones *p_publicacion, int *p_cant);
void ModificarPublicacion(char *p_categoria, long int *p_isbn, char editorial[150]);

int main(void)
{
    publicaciones inventario[MAX], *p_inventario, *p_aux;
    int cant, cantLibroSinStok=0;
    p_inventario = inventario;
    printf("Ingrese la cantidad de publicaciones que desea agregar al inventario\n");
    scanf("%d",&cant);
    fflush(stdin);
    p_inventario = malloc(cant * sizeof(publicaciones));
    p_aux = p_inventario;    
    

    CargarPublicaciones(p_aux, cant);     

    //printf("La cantidad de libros sin stock es de %d \n",cantLibroSinStok);
    //printf("La categoria es de %c \n", p_inventario[1].categoria);
    
    p_aux=p_inventario;
    Modificar(p_aux, &cant);

    p_aux=p_inventario;
    for (int k = 0; k < cant; k++)
    {
        ContarLibroSinStok(p_aux, &cantLibroSinStok);
        p_aux++;
    }

    p_aux=p_inventario;
    MostrarPublicaciones(p_aux, cant);       

    printf("La cantidad de libros sin stock es de %d \n",cantLibroSinStok);
    free(p_inventario);
    return 0;
}


void CargarPublicaciones(publicaciones *p_publicacion, int cant)
{   

    int bandera, bandera2;       

    for (int i = 0; i < cant; i++) 
    {        
        printf("--------------   CARGADO DE BIBLIOTECA = Articulo %d  -------------- \n\n",i+1);
        printf("Ingrese el titulo de la publicacion\n");
        gets(p_publicacion->titulo);
        fflush(stdin);
        printf("Ingrese el editorial de la publicacion\n");
        gets(p_publicacion->editorial);
        fflush(stdin);
        printf("Ingrese la edicion de la publicacion\n");
        scanf("%d",&p_publicacion->edicion);
        fflush(stdin);
        printf("Ingrese la fecha de la publicacion, con formato dia-mes-anio, por ejemplo 02-08-2019\n");
        gets(p_publicacion->fechaPublicacion);
        fflush(stdin);
        
        do 
        {
            printf("Ingrese su correspondiente ISBN (El ISB debe ser un codigo formado por 10-13 diguitos, o ser 0)\n");
            scanf("%d",&p_publicacion->isbn);   
            fflush(stdin);
            if ((p_publicacion->isbn >= 1000000000 && p_publicacion->isbn < 9999999999999) || p_publicacion->isbn == 0)
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
            scanf("%c",&p_publicacion->categoria);
            fflush(stdin);

            if (p_publicacion->categoria == 'L' || p_publicacion->categoria == 'T' || p_publicacion->categoria =='R' || p_publicacion->categoria == 'l' || p_publicacion->categoria == 'r' || p_publicacion->categoria == 't')
            {
                bandera = 1;
                //printf("paso por aqui");
            } else {
                bandera = 0;
                //printf("paso por alla");
            }
        } while (bandera == 0);    
        printf("De cuantos ejemplares se trata\?\n"); 
        scanf("%d",&p_publicacion->cantidadEjemplares);
        printf("Cuantos hay en stock\?\n"); 
        scanf("%d",&p_publicacion->stock);
        printf("\n----------------------------------------------------------------- \n\n");
        fflush(stdin);
        p_publicacion++;
    }   
    
    
}

void MostrarPublicaciones(publicaciones *p_publicacion, int cant)
{
    for (int j = 0; j < cant; j++)  
    {    
        printf("--------------   MOSTRADO DE BIBLIOTECA = Articulo %d  -------------- \n\n",j+1);
        printf("Titulo:                       ");
        puts(p_publicacion->titulo);
        printf("Editorial:                    ");
        puts(p_publicacion->editorial);
        printf("Edicion:                      %d",p_publicacion->edicion);
        printf("\nFecha de Publicacion:         ");
        puts(p_publicacion->fechaPublicacion);
        printf("ISBN:                         %d",p_publicacion->isbn);
        printf("\nCategoria:                    ");
        if (p_publicacion->categoria == 'L' || p_publicacion->categoria == 'l')
        {
            printf("Libro\n");
        }
        if (p_publicacion->categoria == 'R' || p_publicacion->categoria == 'r')
        {
            printf("Revista\n");
        }
        if (p_publicacion->categoria == 'T' || p_publicacion->categoria == 't')
        {
            printf("Tesis\n");
        }
        
        //printf("%c",publicacion.categoria);
        printf("\nCantidad de ejemplares:       %d",p_publicacion->cantidadEjemplares);
        printf("\nStock:                        %d",p_publicacion->stock);
        printf("\n---------------------------------------------------------------------- \n\n");
        p_publicacion++;
    }
}


void ContarLibroSinStok(publicaciones *p_publicacion, int *p_cant)
{   
    //printf("Entro a la funcion \n la categoria es: %c \n",p_publicacion->categoria);
    if (p_publicacion->categoria == 'L' || p_publicacion->categoria == 'l')
    {
        //printf("Ingreso al primer if de la funcin\n");
       if (p_publicacion->stock == 0)
       {
           *p_cant = (*p_cant) + 1;
           //printf("Se incremento la cantidad de libros sin stock en uno");
       }
       
    }
    
}


void Modificar(publicaciones *p_publicacion, int *p_cant)
{
    for (int l = 0; l < *p_cant; l++)  
    {
        ModificarPublicacion(&p_publicacion->categoria, &p_publicacion->isbn, p_publicacion->editorial);
        p_publicacion++;
    }
}

void ModificarPublicacion(char *p_categoria, long int *p_isbn,  char editorial[150])
{   
    char aux,arre[15]= "FACET";
    int coincidencias=0;

    //printf("Acava de entrar a la funcion\n");
    //puts(arre);
    //puts(editorial);
    if (*p_isbn != ' ')
    {
        *p_categoria = 'L';
    }

    for (int i = 0; i < 6; i++)
    {
        if (editorial[i] == arre[i])
        {
            coincidencias= coincidencias + 1;
            //printf("Uvo coincidencia\n\n");
        }
        
    }    

    if (*p_isbn == 0 && coincidencias == 6)
    {
        *p_categoria = 'T';
    } else {
        if (*p_isbn == 0)
        {
            *p_categoria = 'R';
        }
    }  

}