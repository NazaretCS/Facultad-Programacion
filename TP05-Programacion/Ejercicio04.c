/*
Integrantes del grupo 5--------------

>Bobadilla, Juan Pablo.---------------
>Buahl, Paula Florencia.--------------
>Campos, Nestor Nazaret.---------------
*/

/*
+++++++++++++++++++++++++++++++++++++++++++   Algoritmo Principal   +++++++++++++++++++++++++++++++++++++++++
ALGORITMO: Conversor_de_Numeros
ENTRADAS: binario: arreglo de caracteres
SALIDAS: numeroDecimal: entero
VARAUX: N, i, p: entero

A0. numeroDecimal, p <- 0
A1. LEER (binario)
A2. CALCULO
A3. PARAR
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

A2. CALCULO

    HACER (N - 1) VECES (i= 0... N-1)
        
        SI(binario[i] == '1')
          numeroDecimal = numeroDecimal + 2^p
      
        p = p + 1

    FIN_HACER

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <math.h>



int main() {

  int i, N, numeroDecimal=0, p=0;
  char binario[30];
  printf("Introduce un número binario");
  gets(binario);
  N = strlen(binario);

  for(int i=N-1; i >= 0; i--) {

      if (binario[i] == '1')
      {
        numeroDecimal += pow(2,p);
      }

    p++;
  }

  printf("El binario %s es %i en decimal", binario, numeroDecimal);
 
 
  return 0;
}