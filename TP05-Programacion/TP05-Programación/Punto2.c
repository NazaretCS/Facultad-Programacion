/*
Integrantes del grupo 5--------------

>Bobadilla, Juan Pablo.---------------
>Buahl, Paula Florencia.--------------
>Campos, Nestor Nazaret.---------------
*/

/**
++++++++++++++++++++++++++++++++++++++++++++   Algoritmo Principal  +++++++++++++++++++++++++++++++++++++++++++++

ALGORITMO: Amigas_Vocales
ENTRADA: nombre1, nombre2, nombre3: arreglo
SALIDAS: cadena de caracteres
VARAUX: cantidad, contVocales1, contVocales2, contVocales3: enteros
CONSTANTES:

A1. LEER(nombre1, nombre2, nombre3)
A2. Contar_Vocales
A3. Calcular_Mayor
A4. ESCRIVIR(masVocales)
A5. PARAR

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

++++++++++++++++++++++++++++++++++++++++++++   Refinameinto   ++++++++++++++++++++++++++++++++++++++++++++++++++++
A2. Contar_Vocales
    cantidad1 <- Tamaño_Arreglo(nombre1) 
    cantidad2 <- Tamaño_Arreglo(nombre2)
    cantidad3 <- Tamaño_Arreglo(nombre3) -------> // Funcion que me devuelve la cantidad de componentes que contiene el arreglo.
    
    contVocales1 <- Contador_Vocales(nombre1, cantidad1)
    contVocales2 <- Contador_Vocales(nombre2, cantidad2)
    contVocales3 <- Contador_Vocales(nombre3, cantidad3)

A3. Calcular_Mayor
    SI (contVocales1 >= contVocales2 && contVocales1 >= contVocales3)
        SI (contVocales1 = contVocales2 && contVocales1 = contVocales3)
            ESCRIVIR("Los 3 nombres tienen La misma cantidad de vocales")
        SINO
            ESCRIVIR("El 1° nombre es el que tiene mas vocales")
        FIN_SI
    SINO
        SI (contVocales2 >= contVocales3)
            SI (contVocales2 = contVocales3)
                ESCRIVIR("El 2° y 3° nombre tienen mayor cantidad de vocales (ambos con la misma cantidad)"")
            SINO
                ESCRIVIR("El segundo nombre contiene mas vocales")
            FIN_SI
        SINO
            ESCRIVIR("El tercer nombre es el mayor")
        FIN_SI
    FIN_SI

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

+++++++++++++++++++++++++++++++++++++++++++++++++++   Función   ++++++++++++++++++++++++++++++++++++++++++++++++++

    FUNCION: Contador_Vocales
    ARGUMENTOS: nombre: arreglo
                cantidad: entero
    SALIDA: entero
    VARAUX: contVocales

    contVocales <- 0
    HACER (cantidad) VESES (i=1 ... cantidad)
        letra <-  nombre[i]
        SI ( letra = 'a' || letra = 'A' || letra = 'e' || letra = 'E' || letra = 'i' || letra = 'I' || letra = 'o' || letra = 'O' || letra = 'U' || letra = 'u')
            contVocales = contVocales + 1
        FIN_SI
    FIN_HACER
    Contador_Vocales <- contVocales 

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/


#include <stdio.h>
#include <string.h>
#define MAX 100
int  Contador_Vocales(char nombre[MAX], int cantidad);

int main(void)
{

    char nombre1[MAX];
    char nombre2[MAX];
    char nombre3[MAX];
    int cantidad1=0;
    int cantidad2=0;
    int cantidad3=0;
    int contVocales1=0; 
    int contVocales2=0;
    int contVocales3=0; 

    printf("ingrese el nombre del primer integrante: \n");
    gets(nombre1);

    printf("ingrese el nombre del segundo integrante: \n");
    gets(nombre2);

    printf("ingrese el nombre del tercer integrante: \n");
    gets(nombre3);

    cantidad1 = strlen(nombre1);
    cantidad2 = strlen(nombre2);
    cantidad3 = strlen(nombre3);

    contVocales1 = Contador_Vocales(nombre1, cantidad1);
    contVocales2 = Contador_Vocales(nombre2, cantidad2);
    contVocales3 = Contador_Vocales(nombre3, cantidad3);

    if (contVocales1 >= contVocales2 && contVocales1 >= contVocales3)
    {
        if (contVocales1 == contVocales2 && contVocales1 == contVocales3)
        {
            printf("Los nombres %s , %s y %s tienen la misma cantidad de vocales\n",nombre1,nombre2,nombre3);
        } else {
            printf("El nombre %s tienen la misma cantidad de vocales \n",nombre1);
        } 
    } else {
        if (contVocales2 >= contVocales3)
        {
            if (contVocales2 == contVocales3)
            {
                printf("Los nombres %s y %s tienen mas vocales, ambos con la misma cantidad \n",nombre2,nombre3);
            } else {
                printf("El nombre %s tiene mas vocales \n",nombre2);
            }
            
        } else {
            printf("El nombre %s tiene mas vocales\n",nombre3);
        }  
    }
    return 0;
}


int  Contador_Vocales(char nombre[MAX], int cantidad)
{
    int contVocales=0; 
    char letra;

    for (int i = 0; i < cantidad; i++)
    {
        letra = nombre[i];
        if (letra == 'a' || letra == 'A' || letra == 'e' || letra == 'E' || letra == 'i' || letra == 'I' || letra == 'o' || letra == 'O' || letra == 'U' || letra == 'u')
        {
            contVocales++;
        }  
    }
    return(contVocales);
}
