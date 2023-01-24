/**
INTEGRANTES:GRUPO:CINCO:--------------

>Bobadilla, Juan Pablo.---------------
>Buahl, Paula Florencia.--------------
>Campos, Nestor Nazaret.---------------
*/
/**
+++++++++++++++++++++++++++++++++++++++++++   Algoritmo Principal   +++++++++++++++++++++++++++++++++++++++++++++++

ALGORITMO: Analizando_El_Curso
ENTRADAS: n:entero
          vector[MAX]: arreglo de reales
SALIDAS: escalon[3]:arreglo de reales, aprovados: entero, promGeneral: real.
VARAUX: i: entero, *p_vector: puntero a reales, posMayor:real
CONSTANTES: MAX <- 300 

A1. posMayor mayor acumulador <-- 0
A2. Procesar_Arreglo/Datos
A3. Generar_Escalon
A4. ESCRIVIR(escalon[3],aprovados,promGeneral)
A5. PARAR

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


++++++++++++++++++++++++++++++++++++++++++++++   Refinameintos   ++++++++++++++++++++++++++++++++++++++++++++++++++

A2. Procesar_Arreglo/Datos
    LEER(n)
    MIENTRAS (n > MAX)
        LEER(n)
    FIN_MIENTRAS
    p_vector <-- vector
    HACER (n) VESES (i=0...n)
        LEER(p_vector[i])
        acumulador = acumulador + p_vector[i]
        SI (p_vector[i] >= 6)
            aprovados = aprovados + 1
        FIN_SI 
    FIN_HACER
    promGeneral <-- acumulador/n


A3. Generar_Escalon
    posMayor <-- MayorDelArreglo(vector,n)  //MayorDelArreglo es una funcion que me devuelve la posicion del mayor elemento del arreglo.
    escalon[0] <-- p_vector[posMayor]
    p_vector[posMayor] <-- 0

    posMayor <-- MayorDelArreglo(vector,n)  
    escalon[1] <-- p_vector[posMayor]
    p_vector[posMayor] <-- 0

    posMayor <-- MayorDelArreglo(vector,n)  
    escalon[2] <-- p_vector[posMayor]
    p_vector[posMayor] <-- 0


+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

++++++++++++++++++++++++++++++++++++++++++++++   Función   ++++++++++++++++++++++++++++++++++++++++++++++++++

    FUNCION: MayorDelArreglo
    ARGUMENTOS: vector:arreglo de reales.
                tamaño: entero
    RESULTADO: entero.
    VARAUX:  p_vector: puntero a reales.
            mayor: real.
            posMayor: Entero

    posMayor <-- 0
    p_vector <-- vector
    mayor <-- p_vector[0]
    HACER (tamaño) VESES (i=1...tamaño)
        SI (p_vector[i] > mayor)
            mayor <-- p_vector[i]
            posMayor <-- i
        FIN_SI
    FIN_HACER
    MayorDelArreglo <--  posMayor
    FIN_FUNCIÓN

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 300
float vector[MAX],escalon[3];

int MayorDelArreglo(float vector[MAX], int tamanio);

int main(void)
{   
    int n, aprovados;
    int posMayor=0;
    float mayor=0, *p_vector,acumulador=0,promGeneral;
    
    printf("Ingrese la cantidad de alumnos (se solicita que sea menor a %d)\n",MAX);
    scanf("%d",&n);
    
    while (n > MAX)
    {
        printf("Cantidad de alumnos mal ingresada, por favor intente de nuevo\n");
        printf("Ingrese la cantidad de alumnos (se solicita que sea menor a 300)\n");
        scanf("%d",&n);
    }
    

    p_vector = vector;
    for (int i = 0; i < n; i++)
    {
        printf("Cargue la nota del alumno\n");
        scanf("%f",&p_vector[i]);
        acumulador=acumulador + p_vector[i];
        if (p_vector[i] >= 6)
        {
            aprovados++;
        }
        

    }
    promGeneral = acumulador/n;

    p_vector = vector;
    posMayor= MayorDelArreglo(vector,n);
    //printf("El mayor fue: %f (indice: %d) \n \n",vector[posMayor], posMayor);
    escalon[0] = p_vector[posMayor];
    p_vector[posMayor] = 0;

    posMayor= MayorDelArreglo(vector,n);
    //printf("El mayor fue: %f (indice: %d) \n",vector[posMayor], posMayor);
    escalon[1] = p_vector[posMayor];
    p_vector[posMayor] = 0;

    posMayor= MayorDelArreglo(vector,n);
    //printf("El mayor fue: %f (indice: %d) \n",vector[posMayor], posMayor);
    escalon[2] = p_vector[posMayor];
    p_vector[posMayor] = 0;

    printf("Las tres mejores notas de todo el curso son %.2f, %.2f y %.2f \n",escalon[0],escalon[1],escalon[2]);
    printf("El promedio general de curso es %.2f y la cantida de aprovados es de %d \n",promGeneral,aprovados);
    
    return 0;
}

int MayorDelArreglo(float vector[MAX], int tamanio)
{
    float *p_vector, mayor;
    int posMayor=0;

    p_vector = &vector[0];
    mayor = p_vector[0];
    for (int i = 1; i < tamanio; i++)
    {
        if (p_vector[i] > mayor)
        {
            mayor = p_vector[i];
            posMayor = i;

        }        
    }
    return posMayor;
}