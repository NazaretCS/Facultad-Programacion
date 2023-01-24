/**
+++++++++++++++++++++++++++++++++++++++++  Algoritmo Principal  ++++++++++++++++++++++++++++++++++++++++

PROGRAMA: De_La_Trigonometría
ENTRADAS: 
SALIDAS: anguloRadianes, anguloSeno: reales
VARAUX: i: Entero.
CONTASTANTES: cantAngulos = 10, PI=3.14159:Reales

A1. Trasnformar_Angulo
A2. PARAR

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

++++++++++++++++++++++++++++++++++++++++++++  Refinamiento ++++++++++++++++++++++++++++++++++++++++++++++

A1. Trasnformar_Angulo
   HACER cantAngulos VESES (i=1 ... cantAngulos)
        anguloRadianes <- (i * PI) / 180
        anguloSeno <- SENO(i)
        ESCRIVIR (i, anguloRadianes, anguloSeno)
   FIN_HACER

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   
*/

#include<stdio.h>
#include<math.h>
#define CANTANGULOS 10

int main(void)
{
   printf (" X [ grados ]   |    X [ radianes ]  |   Seno(x)  \n");
   printf("--------------------------------------------------\n");
   float anguloRadianes, anguloSeno;
   for (int i = 0; i <= CANTANGULOS; i++)
   {
      anguloRadianes = (i * M_PI ) / 180;
      anguloSeno = sin(i);
      printf("       %d        |     %f       |   %f      \n",i,anguloRadianes, anguloSeno);
   }
   return 0;
}