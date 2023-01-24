/*
Integrantes del grupo 5--------------

>Bobadilla, Juan Pablo.---------------
>Buahl, Paula Florencia.--------------
>Campos, Nestor Nazaret.---------------
*/

/**
+++++++++++++++++++++++++++++++++++++++++++   Algoritmo Principal   +++++++++++++++++++++++++++++++++++++++++
ALGORITMO: Calentando_Motores
ENTRADAS: 
SALIDAS: vectorNumero: arrgelo
VARAUX: i, numero: enetro
CONSTANTES: tamañoVector =30, multiplo = 6 : entero
            //para hacer variar el taaño del arreglo, cambiaria la constante tamañoVecor, lo mismo para seleccionar el numero del que quiero que sean multiplos las componentes del arreglo.

A0. i <- 0
A1. Cargar_Numero
A2. PARAR
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

+++++++++++++++++++++++++++++++++++++++++++++++   Refinamiento+++   +++++++++++++++++++++++++++++++++++++++++++
A1. Cargar_Numero
    MIENTRAS (i <= tamañoVector) 
        numero <- ALEATOREO(0, 200)  --------->// Esta seria una funcion que te devuelve valores comprendidos entre los parametros de la funcion (0 y 200 en este caso)
        SI (RESTO(numero/multiplo) = 0)
            vectorNumero[i] <- numero
            i <- i + 1
        FIN_SI
    FIN_MIENTRAS
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANIOVECTOR 30  //---> haciendo cambiar la constante TAMANIOVECTOR haria variar el tamaño de mi arreglo.
// #define MULTIPLO 6  //----> usaba esta constante antes para poder generar los multiplos.

int main(void)
{   
    srand(time(NULL));
    int i=0;
    int numero;
    int vectorNumero[TAMANIOVECTOR];
    int multi;

    printf("Ingrse el valor del cual los numeros del arreglo seran multiplos: \n");
    scanf("%d",&multi);  //----> La linea 49 y 50 serian las actualizaciones agregadas a mi codigo para que el usuario defina el numero del cual quiere que sean multiplos las componenetes del arreglo, y tambien reemplazando donde estaba la constante MULTIPLO, dejando en su lugar la variable multi.

    while (i<=TAMANIOVECTOR)
    {
        numero =  rand() % 201;  //----> genero un numero aleatoreo entre 0 y 200
        
        if ((numero % multi) == 0)
        {
            vectorNumero[i] = numero;
            i++;
        } 
    }
    for (int i = 0; i <= TAMANIOVECTOR; i++)
    {
        printf("El arreglo vectorNumero en la poscicion [%d] es igual a: %d \n",i,vectorNumero[i]);
    }    
    return 0;
}