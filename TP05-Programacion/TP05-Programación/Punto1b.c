/*
Integrantes del grupo 5--------------

>Bobadilla, Juan Pablo.---------------
>Buahl, Paula Florencia.--------------
>Campos, Nestor Nazaret.---------------
*/

/**
++++++++++++++++++++++++++++++++++++++++++   Algoritmo Principal   ++++++++++++++++++++++++++++++++++++++++++++++

ALGORITMO: Calentando_Motores
ENTRADA: tamaño: entero
SALIDAS: sumaPares, paresEnInpares: enteros
VARAUX: numeros: Arreglo de enteros
        num, cantidad, lugar: Enteros
CONSTANTES: tamañoNumero = 20: entero

A0. Tamaño
A1. Cargar_Arreglo.
A2. Calcular_Suma_Posiciones_Pares
A3. Calcular_Pares_En_impares
A4. ESCRIVIR(sumaPares, paresEnInpares)
A5. PARAR

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

++++++++++++++++++++++++++++++++++++++++++++   Refinamientos   ++++++++++++++++++++++++++++++++++++++++++++++++++
A0. Tamaño
    LEER(tamaño)
    MIENTRAS (tamaño > 20 || tamaño < 0)
        LEER(tamaño)
    FIN_MIENTRAS

A1. Cargar_Arreglo.
    HACER (tamaño) VESES (i = 1... tamaño)
        num <- ALEATOREO(150, 250) -----> //Esta seria una funcion que te devuelve valores comprendidos entre los parametros de la funcion (150 y 250 en este caso)
        numero[i] <- num
    FIN_HACER

A2. Calcular_Suma_Posiciones_Pares
    lugar <- 0
    MIENTRAS (lugar <= tamaño)  
        SI (RESTO(lugar/2) = 0)
            sumaPares <- sumaPares + numeros[lugar] 
        SINO 
            SI (RESTO(numero[lugar]/2) = 0)
                paresEnInpares <- paresEnInpares + 1
            FIN_SI
        FIN_SI
        lugar <- lugar + 1
    FIN_MIENTRAS     

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAXIMO 20


int main(void)
{   
    srand(time(NULL));
    int i=0;
    int lugar = 0;
    int sumaPares = 0;
    int paresEnInpares = 0;
    int cantidad;
    int numero;
    int tamanio;
    

    printf("Indique la cantidad de componentes de su arreglo (se solicita que sea un numero menor o igual a 20)\n");
    scanf("%d",&tamanio);

    while (tamanio > MAXIMO )
    {
        printf("La cantidad indicada no corresponde con lo solicitado, por favor intente de nuevo.\n");
        printf("Indique la cantidad de componentes de su arreglo (se solicita que sea un numero menor o igual a 20)\n");
        scanf("%d",&tamanio);
    } 

    int numeros[tamanio];

    while (i<tamanio)
    {
        numero =  rand() % 101 + 150;  //----> genero un numero aleatoreo entre 0 y 200
        numeros[i] = numero;
        i++;   
    }

    while (lugar <= tamanio)
    {
       if ((lugar%2) == 0)
       {
           //printf("este valor se vaa sumar %d \n",lugar);
           sumaPares =  sumaPares + numeros[lugar];
       } else
       {
           if ((numeros[lugar]%2) == 0)
           {
               //printf("este valor se va aumentar en 1 %d \n",lugar);
               paresEnInpares++;
           } 
       }
       lugar++; 
    }
    /* 
    int pruevaDeTrabajo;
    pruevaDeTrabajo = numeros[23] + numeros[24];
    printf("La suma de las componentes exedidas del arreglo da: %d \n",pruevaDeTrabajo);
    */
    /* for (int i = 0; i <= tamanio; i++)
    {
        printf("el arreglo es numeros[%d]=%d \n",i,numeros[i]);
    } */

    printf("La suma de pares en impares da: %d \n",paresEnInpares);
    printf("La suma de las pociciones pares da: %d \n",sumaPares);
    
    
    return 0;
    /*
    En lo personal siempre me gusta hacer controles para  verificar que el ususario halla ingresado los datos correctos, por eso si ingresa que el tamaño del arreglo sea mayor a 20 le vuelvo a solicitar el tamaño (linea 80 a linea 85)
    Pero en caso de que ese control no este, si se generan las componentes del arreglo. Incluso prove sumarlas y su suma es correcta (linea 113 a 115) pero supongo que no seria lo ideal, ya que al momento de indicarle un maximo de 20 le estariamos reservando ese espacio de memeoria, y exederlo podria significar salirse de los limites indicados y hasta escrivir sobre otros datos.
    */
}

