/**
++++++++++++++++++++++++++++++++++++++++++++++   Algortimo Principal   +++++++++++++++++++++++++++++++++++++++++++

ALGORITMO: Trencito_De_Numeros
ENTRADAS: numero: real
SALIDAS: suma, ultDato: enteros
         arregloNumero: arreglo de enteros
VARAUX: limite, sumaComponetes: real
        i, j: entero.
CONSTANTE: tamaño: entero

A1. Cargar_Datos
A2. Sumar_Componentes
A3. ESCRIVIR(suma, ultDato)
A4 PARAR

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

++++++++++++++++++++++++++++++++++++++++++++++++   Refinamientos   +++++++++++++++++++++++++++++++++++++++++++++++

A1 Cargar_Datos
    HACER (tamaño) VESES (i=1...tamaño)
        LEER(numero)
        MIENTRAS (numero < 0)
            LEER(numero)
        FIN_MIENTRAS
        arregloNumero[i] <- numero
    FIN_HACER


A2. Sumar_Componentes
    j <-  0
    sumaComponetes <- 0
    limite <- arregloNumero[0]
    MIENTRAS (limite > sumaComponentes)
        sumaComponentes <- sumaComponentes + arregloNumero[j+1]
        j <- j + 1 
    FIN_MIENTRAS
    suma <- RedondeoPorExeso(sumaComponentes) ---------> //Funcion que me redondea "hacia arriva" el numero dado como argumento.
    ultDato <- j

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


*/


#include <stdio.h>
#include <math.h>
#define TAMANIO 5

int main(void)
{
    int j=0, suma, ultDato;
    float  sumaComponentes = 0;
    float limite;
    float numero;
    float arregloNumeros[TAMANIO];

    for (int i = 0; i < TAMANIO ; i++)
    {
        printf("Cargue un numero real (el mismo sera reducido a tener dos decimales): \n");
        scanf("%f",&numero);

        while (numero < 0)
        {
            printf("el numero ingresado no corresponde con el formato, por favor trate de nuevo\n");
            printf("Cargue un numero real: \n");
            scanf("%f",&numero);
        }

        printf("El numero que se ingresara es: %f \n",numero);
        arregloNumeros[i] = numero;
    }

    limite = arregloNumeros[0];
    while (limite > sumaComponentes)
    {
        sumaComponentes = sumaComponentes + arregloNumeros[j+1];
        j++;
    }
    suma = floor(sumaComponentes);
    ultDato = j;

    printf("La suma de los compoenetes da: %d y el ultimo dato sumado es de orden: %d ",suma,j);
}
