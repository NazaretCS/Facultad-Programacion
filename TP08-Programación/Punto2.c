#include <stdio.h>

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
    char Area[70];
    char Descripcion[500];
    controlador ApeNom;   
    char FechaContro[40];
    int ListoPublicar;
}typedef articulo;  // lo que me pide en el apartado dos no o entiendo bien...

articulo CargarDatos();
int Modificar(int nivel, char area[70], int destinatarios);
void MostraDatos(articulo arti);

int main(void)
{       
    articulo artic;
    artic = CargarDatos();
    artic.ListoPublicar = Modificar(artic.Nivel, artic.Area, artic.Destinatarios);
    MostraDatos(artic);
    return 0;
}

articulo CargarDatos()
{
    articulo arti;
    int bandera=0, bandera2=0, bandera3=0;
    printf("-------------------------   CARGA  DE  DATOS   -------------------------\n");
    
    printf("Ingrese el nombre del Articulo: \n");
    gets(arti.NombreArticulo);
    fflush(stdin);
    printf("Ingrese los destinatarios: (1 = Alumnos, 2 = Docentes, o 3 = Directivos)\n");
    scanf("%d",&arti.Destinatarios);
    while (bandera2 == 0)
    {
        if (arti.Destinatarios == 1 ||arti.Destinatarios == 2 || arti.Destinatarios == 3)
        {
            bandera2 = 1;
        } else {
            printf("Destinatarios mal ingresado, por favor intente de nuevo \n");
            printf("Ingrese los destinatarios: (1 = Alumnos, 2 = Docentes, o 3 = Directivos)\n");
            scanf("%d",&arti.Destinatarios);
            fflush(stdin);
            bandera2 = 0;
        }
    }

    printf("Ingrese el Nivel (1 = Inicial, 2 = Primario, 3 = Secundario, o 4 = Superior)\n");
    scanf("%d",&arti.Nivel);
    fflush(stdin);
    while (bandera == 0)
    {
        if (arti.Nivel == 1 ||arti.Nivel == 2 || arti.Nivel == 3 || arti.Nivel == 4)
        {
            bandera = 1;
        } else {
            printf("Nivel mal ingresado, por favor intente de nuevo \n");
            printf("Ingrese el Nivel (1 = Inicial, 2 = Primario, 3 = Secundario, o 4 = Superior)\n");
            scanf("%d",&arti.Nivel);
            fflush(stdin);
            bandera = 0;
        }
    }
    
    
    
    printf("Ingrese el Area (Lengua, Matematica, Ciencias Naturales, etc)\n");
    gets(arti.Area);
    fflush(stdin);
    printf("De una breve descripcion de lo que trata el material:\n");
    gets(arti.Descripcion);
    printf("Nombre y apellido de quien controla este articulo: \n");
    printf("Apeliido: ");
    gets(arti.ApeNom.Apellido);
    fflush(stdin);
    printf("Nombre: ");
    gets(arti.ApeNom.Nombre);
    fflush(stdin);
    printf("Ingrese la fecha de de control con formato dia-mes-anio\n");
    gets(arti.FechaContro);
    printf("Ingrese El estado del articulo (1: esta listo, 0: falta controlar)\n");
    scanf("%d",&arti.ListoPublicar);
    while (bandera3 == 0)
    {
        if (arti.ListoPublicar == 1 ||arti.ListoPublicar == 0)
        {
            bandera3 = 1;
        } else {
            printf("Estado del Articulo mal ingresado, por favor intente de nuevo \n");
            printf("Ingrese El estado del articulo (1: esta listo, 0: falta controlar)\n");
            scanf("%d",&arti.ListoPublicar);
            fflush(stdin);
            bandera3 = 0;
        }
    }
    printf("------------------------------------------------------------------------\n");
    return arti;
}



void MostraDatos(articulo arti)
{
    printf("\n------------------------   MUESTRA  DE  DATOS   ------------------------\n");
    printf("Nombre del Articulo:                             ");
    puts(arti.NombreArticulo);
    printf("Destinatario:                                    ");
    switch (arti.Destinatarios)
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
    switch (arti.Nivel)
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
    puts(arti.Area);
    printf("Descripcion                                      ");
    puts(arti.Descripcion);
    printf("Apellido y Nombre del Controlador                ");
    puts(arti.ApeNom.Apellido);
    printf("                                                 ");
    puts(arti.ApeNom.Nombre);
    printf("Fecha de Control                                 ");
    puts(arti.FechaContro);
    printf("Estado de Pucblicacion                           ");
    switch (arti.ListoPublicar)
    {
    case 1:
        printf("Esta listo\n");
        break;
    case 0:
        printf("Falta Controlar\n");
        break;
    }

    printf("------------------------------------------------------------------------\n");
}

int Modificar(int nivel, char area[70], int destinatarios)
{   
    int aux, coincidencias=0, bandera=0;
    char palabra[10]="robotica";
    for (int i = 0; i < 9; i++)
    {
        if (area[i] == palabra[i])
        {
            coincidencias++;
            //printf("uvo coincidencia\n");
        }        
    }
    
    if (nivel == 3 && destinatarios == 1 && coincidencias == 9)
    {
        printf("Cumple con las condiciones para modificar el estado del articulo \nIndique el valor por el cual desea modificarlo (1: esta listo, 0:falta controlar)");
        scanf("%d",&aux);
        while (bandera == 0)
        {
            if (aux == 1 ||aux == 0)
            {
                bandera = 1;
            } else {
                printf("Estado del Articulo mal ingresado, por favor intente de nuevo \n");
                printf("Ingrese El estado del articulo (1: esta listo, 0: falta controlar)\n");
                scanf("%d",&aux);
                fflush(stdin);
                bandera = 0;
            }
        }
    }
    
    
    return aux;
}