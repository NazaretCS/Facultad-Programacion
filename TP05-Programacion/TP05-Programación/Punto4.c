/**
+++++++++++++++++++++++++++++++++++++++++++   Algoritmo Principal   +++++++++++++++++++++++++++++++++++++++++++++++

ALGORITMO: Conversor_De_Números
ENTRADAS: codigo: arreglo de enteros
SALIDAS: suma: entero
VARAUX: cantidad, bandera, i, j: entero

A1. Leer_ y_Verificar_Codigo
A2. Procesar_Codigo
A3. ESCRIVIR(suma)

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


++++++++++++++++++++++++++++++++++++++++++++++   Refinameintos   ++++++++++++++++++++++++++++++++++++++++++++++++++

A1. Leer_ y_Verificar_Codigo
    bandera <- 1
    MIENTRAS (bandera = 1)
        LEER(codigo)
        cantidad <- Tamaño_Arreglo(codigo) - 1 -------> //Funcion que me devuelve la cantidad de componentes que contiene el arreglo.
        HACER (cantidad) veses (i=0...cantidad)
            SI ( codigo[i] = 0 || codigo[i] = 1)
                bandera <- 0
            SINO
                bandera <- 1
                ESCRIVIR(codigo mal ingresado)
            FIN_SI
        Fin_HACER
    FIN_MIENTRAS

A2. Procesar_Codigo
    HACER (cantidad) veses (j=0...cantidad)
        expoenete <- cantidad - j
        suma <- codigo[j] * (Exponente(2,exponente))   ----> //la funcion exponente me devuelve el primer argumento elevado al segundo armento.
    FIN_HACER

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 10


int main(void)
{
    int bandera=0;
    int cantidad=0;
    int exponente=0;
    int suma;
    int x;
    char codigo[MAX];
    
    do
    {
        printf("Ingrese su numero a trasformarPPP \n");
        gets(codigo);
        cantidad = strlen(codigo) - 1;
        puts(codigo);
        
        for (int i = 0; i <= cantidad; i++)
        {
            printf("%c \n",codigo[i]);
            x = codigo[i];
            printf("El numero a analizar es: %c \n",x);

            /* if ( x == 1 || x==0)
            {
                bandera = 0;
                printf("entro por donde queria \n");
                
            } else {
               printf("entro por donde NO queria \n");
               bandera = 1;
               
            }*/
            switch (x)
            {
            case 0:
            case 1: 
                bandera = 0;
                printf("entro por donde queria \n");
                break;
            
            default:
                printf("entro por donde NO queria \n");
                bandera = 1;
                break;
            }
            printf("bandera toma el valor de: %d \n",bandera);
        }
        if (bandera == 1)
        {
            printf("Numero mal ingresado\n");
        }
        
    } while (bandera != 0);
    
     
    

    for (int j = 0; j <= cantidad; j++)
    {
        exponente = cantidad - j;
        suma = codigo[j] * (pow(2,exponente));
    }
    
    return 0;
}
