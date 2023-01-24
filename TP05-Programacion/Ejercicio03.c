/*
Integrantes del grupo 5--------------

>Bobadilla, Juan Pablo.---------------
>Buahl, Paula Florencia.--------------
>Campos, Nestor Nazaret.---------------
*/

/*
+++++++++++++++++++++++++++++++++++++++++++   Algoritmo Principal   +++++++++++++++++++++++++++++++++++++++++
ALGORITMO: Trencito_de_Numeros
ENTRADAS: primerNumero, numeros: float
SALIDAS: suma, aux: float
VARAUX: aux: entero, numero: float

A0. suma, aux <- 0
A1. LEER (primerNumero)
A2. SUMA
A3. PARAR
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

A2. SUMA
    MIENTRAS (suma < primerNumero) 
        LEER (numeros)
        suma <- suma + numeros;
        aux = aux + 1;
    FIN_MIENTRAS

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <math.h>

int main() {

  float primerNumero, numeros, suma = 0;
  int aux=0;

  printf("Introduce el primer número con dos decimales: ");
  scanf("%f", &primerNumero);

  while (suma < primerNumero)
  {

  printf("\nIngrese un numero con dos decimales: \n");
  scanf("%f",&numeros);

  suma = suma + numeros; // con suma previamente inicializada en 0
  aux++; 

  }
  
  suma = suma + 1;
  suma = ceil(suma);

  printf("\nEl resultado de la suma es: %f", suma);
  printf("\nEl orden de la última suma es: %i", aux);
  

  return 0;
}