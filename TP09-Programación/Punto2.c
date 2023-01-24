#include <stdio.h>
#include <stdlib.h>
#define MAX 200
struct DATOS
{
    char Apellido[100];
    char Nombre[100];
}typedef controlador;

struct 
{
    char NombreArticulo[150];
    int Destinatarios;
    int Nivel;
    int Area;
    char Descripcion[500];
    controlador ApeNom;   
    char FechaContro[40];
    int ListoPublicar;
}typedef articulo;  // lo que me pide en el apartado dos no o entiendo bien...

void CargarDatos(articulo *p_arti, int *p_cant);
int Modificar(int nivel, char area[70], int destinatarios);
void MostraDatos(articulo *p_arti, int *p_cant);
void MostrarDato_o_Datos(articulo *p_arti, int *p_cant);

int main(void)
{    
    int cant, area;
    printf("Ingrese la cantidad de articulos que desea cargar \n");
    scanf("%d",&cant);
    fflush(stdin);

    articulo artic[MAX], *p_artic, *p_aux;
    p_artic = artic;
    p_artic = malloc(cant * sizeof(articulo));
    
    p_aux = p_artic;
    CargarDatos(p_aux, &cant);
    
    p_aux = p_artic;   
    MostrarDato_o_Datos(p_aux, &cant);

    free(p_artic);
    return 0;
}

void CargarDatos(articulo *p_arti, int *p_cant)
{
    //articulo arti;
    for(int i=0 ; i < *p_cant ; i++)
    {
        int bandera=0, bandera2=0, bandera3=0, bandera4=0;
        printf("-------------------------   CARGA  DE  DATOS = Articulo %d   -------------------------\n",i+1);
        
        printf("Ingrese el nombre del Articulo: \n");
        gets(p_arti->NombreArticulo);
        fflush(stdin);
        printf("Ingrese los destinatarios: (1 = Alumnos, 2 = Docentes, o 3 = Directivos)\n");
        scanf("%d",&p_arti->Destinatarios);
        while (bandera2 == 0)
        {
            if (p_arti->Destinatarios == 1 ||p_arti->Destinatarios == 2 || p_arti->Destinatarios == 3)
            {
                bandera2 = 1;
            } else {
                printf("Destinatarios mal ingresado, por favor intente de nuevo \n");
                printf("Ingrese los destinatarios: (1 = Alumnos, 2 = Docentes, o 3 = Directivos)\n");
                scanf("%d",&p_arti->Destinatarios);
                fflush(stdin);
                bandera2 = 0;
            }
        }

        printf("Ingrese el Nivel (1 = Inicial, 2 = Primario, 3 = Secundario, o 4 = Superior)\n");
        scanf("%d",&p_arti->Nivel);
        fflush(stdin);
        while (bandera == 0)
        {
            if (p_arti->Nivel == 1 ||p_arti->Nivel == 2 || p_arti->Nivel == 3 || p_arti->Nivel == 4)
            {
                bandera = 1;
            } else {
                printf("Nivel mal ingresado, por favor intente de nuevo \n");
                printf("Ingrese el Nivel (1 = Inicial, 2 = Primario, 3 = Secundario, o 4 = Superior)\n");
                scanf("%d",&p_arti->Nivel);
                fflush(stdin);
                bandera = 0;
            }
        }
        
        
        
        printf("Ingrese el Area (1: Lengua, 2: Matematica, 3: Ciencias Naturales, 4: Ciencias Sociales, 5: Educacion Fisica, 6: Educacion Artistica, 7: Religion, 8: Informatica, 9: Otra)\n");
        scanf("%d",&p_arti->Area);
        fflush(stdin);
        while (bandera4 == 0)
        {
            if (p_arti->Area == 1 ||p_arti->Area == 2 || p_arti->Area == 3 || p_arti->Area == 4 || p_arti->Area == 5 || p_arti->Area == 6 || p_arti->Area == 7 || p_arti->Area == 8 || p_arti->Area == 9)
            {
                bandera4 = 1;
            } else {
                printf("Area mal ingresado, por favor intente de nuevo \n");
                printf("Ingrese el Area (1: Lengua, 2: Matematica, 3: Ciencias Naturales, 4: Ciencias Sociales, 5: Educacion Fisica, 6: Educacion Artistica, 7: Religion, 8: Informatica, 9: Otra)\n");
                scanf("%d",&p_arti->Area);
                fflush(stdin);
                bandera4 = 0;
            }
        }
        printf("De una breve descripcion de lo que trata el material:\n");
        gets(p_arti->Descripcion);
        printf("Nombre y apellido de quien controla este articulo: \n");
        printf("Apeliido: ");
        gets(p_arti->ApeNom.Apellido);
        fflush(stdin);
        printf("Nombre: ");
        gets(p_arti->ApeNom.Nombre);
        fflush(stdin);
        printf("Ingrese la fecha de de control con formato dia-mes-anio\n");
        gets(p_arti->FechaContro);
        printf("Ingrese El estado del articulo (1: esta listo, 0: falta controlar)\n");
        scanf("%d",&p_arti->ListoPublicar);
        while (bandera3 == 0)
        {
            if (p_arti->ListoPublicar == 1 ||p_arti->ListoPublicar == 0)
            {
                bandera3 = 1;
            } else {
                printf("Estado del Articulo mal ingresado, por favor intente de nuevo \n");
                printf("Ingrese El estado del articulo (1: esta listo, 0: falta controlar)\n");
                scanf("%d",&p_arti->ListoPublicar);
                fflush(stdin);
                bandera3 = 0;
            }
        }
        printf("-------------------------------------------------------------------------------------\n");
        p_arti++;
        fflush(stdin);
    }
        
}



void MostraDatos(articulo *p_arti, int *p_cant)
{
    for(int i=0 ; i < *p_cant ; i++)
    {
        printf("\n------------------------   MUESTRA  DE  DATOS = Articulo %d  ------------------------\n",i+1);
        printf("Nombre del Articulo:                             ");
        puts(p_arti->NombreArticulo);
        printf("Destinatario:                                    ");
        switch (p_arti->Destinatarios)
        {
        case 1:
            printf("Alumnos\n");
            break;
        case 2:
            printf("Docentes\n");
            break;
        case 3:
            printf("Directivos\n");
            break;
        }
        
        printf("Nivel                                            ");
        switch (p_arti->Nivel)
        {
        case 1:
            printf("Inicial\n");
            break;
        case 2:
            printf("Primario\n");
            break;
        case 3:
            printf("Secundario\n");
            break;
        case 4:
            printf("Superior\n");
            break;
        }

        printf("Area                                             ");
        switch (p_arti->Area)
        {
        case 1:
            printf("Lengua\n");
            break;
        case 2:
            printf("Matematica\n");
            break;
        case 3:
            printf("Ciencisa Naturales\n");
            break;
        case 4:
            printf("Ciencias Sociales\n");
            break;
        case 5:
            printf("Educacion Fisica\n");
            break;
        case 6:
            printf("Educacion Artistica\n");
            break;
        case 7:
            printf("Religion\n");
            break;
        case 8:
            printf("Area Informatica\n");
            break;
        case 9:
            printf("Otra Area\n");
            break;
        }
        
        printf("Descripcion                                      ");
        puts(p_arti->Descripcion);
        printf("Apellido y Nombre del Controlador                ");
        puts(p_arti->ApeNom.Apellido);
        printf("                                                 ");
        puts(p_arti->ApeNom.Nombre);
        printf("Fecha de Control                                 ");
        puts(p_arti->FechaContro);
        printf("Estado de Pucblicacion                           ");
        switch (p_arti->ListoPublicar)
        {
        case 1:
            printf("Esta listo\n");
            break;
        case 0:
            printf("Falta Controlar\n");
            break;
        }

        printf("---------------------------------------------------------------------------------\n");
        p_arti++;
    }
    
}

void MostrarDato_o_Datos(articulo *p_arti, int *p_cant)
{
    int respuesta, respuestaArticulo, bandera=0, bandera2=0, cantidadMostrado =1;
    articulo *p_aux;
    p_aux = p_arti;
    printf("Usted desea:\n  1 = Mostrar toda la informacion disponible.\n  2 = Mostrar solamente la informacion de un area especifica\n\n");
    scanf("%d",&respuesta);

    
    while (bandera == 0)
    {
        if (respuesta == 1 || respuesta == 2)
        {
            bandera = 1;
        } else {
            printf("Respuesta mal tipeada, por favor corrobore su eleccion \n");
            printf("Usted desea:\n  1 = Mostrar toda la informacion disponible.\n  2 = Mostrar solamente lainformacion de un area especifica\n");
            scanf("%d",&respuesta);
            fflush(stdin);
            bandera = 0;
        }
    }
    if( respuesta == 1){
        MostraDatos(p_aux, p_cant);
    } 

    if(respuesta == 2){
        printf("Ingrese el area de los articulos que desea mostrar: 1: Lengua, 2: Matematica, 3: Ciencias Naturales, 4: Ciencias Sociales, 5: Educacion Fisica, 6: Educacion Artistica, 7: Religion, 8: Informatica, 9: Otra\n");
        scanf("%d",&respuestaArticulo);
        while (bandera2 == 0)
        {
            if (respuestaArticulo == 1 ||respuestaArticulo == 2 || respuestaArticulo == 3 || respuestaArticulo == 4 || respuestaArticulo == 5 || respuestaArticulo == 6 || respuestaArticulo == 7 || respuestaArticulo == 8 || respuestaArticulo == 9)
            {
                bandera2 = 1;
            } else {
                printf("Area de articulo mal ingresada, por favor intentelo de nuevo");
                printf("Ingrese el area de los articulos que desea mostrar: 1: Lengua, 2: Matematica, 3: Ciencias Naturales, 4: Ciencias Sociales, 5: Educacion Fisica, 6: Educacion Artistica, 7: Religion, 8: Informatica, 9: Otra\n");
                scanf("%d",&respuestaArticulo);
                fflush(stdin);
                bandera2 = 0;
            }
        }
        p_aux = p_arti;
        for(int i=0; i < *p_cant ; i++)
        {   
            
           
            if( p_aux->Area == respuestaArticulo)
            {
                MostraDatos(p_aux, &cantidadMostrado);
            }
            p_aux++;
        }
    }
}