/**
+++++++++++++++++++++++++++++++++  ALGORITMO PRINCIPAL  +++++++++++++++++++++++++++++++++++

ALGORITMO: Operaciones
ENTRADAS: num1, num2: enteros
          operación (1=Suma, 2=Resta, 3=Multiplicacion, 4=Divicion, 5=Potencia, 6=Porcentaje)
SALIDA: resultado: entero
VARAUX:

A1 LEER (num1, num2, operación)
A2 Control
A3 SEGÚN (operación)
	  operación = 1: resultado <- Calc_Suma(num1,num2)
	  operación = 2: resultado <- Calc_Resta(num1,num2)
 	  operación =3: resultado <- Calc_Multiplicacion(num1,num2)
	  operación =4: resultado<- Calc_Divicion(num1,num2)
	  operación =5: resultado <- Calc_Potencia(num1,num2)
	  operación =6: resultado <- Calc_Porcentaje(num1,num2)
   FIN_SEGUN
A4 ESCRIVIR(resultado)
A5 PARAR.

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

++++++++++++++++++++++++++++++++++  REFINAMINETO  ++++++++++++++++++++++++++++++++++++++++

A2 Control
    MIENTRAS (num1 <= 0)
        LEER(num1)
    FIN_MIENTRAS

    MIENTRAS (num2 <= 0)
        LEER(num2)
    FIN_MIENTRAS

    MIENTRAS(operacion < 1  || operacion > 6)
        LEER(operacion)
    FIN_MIENTRAS

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


++++++++++++++++++++++++++++++++++  FUNCIONES  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

FUNCION: Calc_Suma                                   FUNCION: Calc_Resta
ARGUMENTOS: num1, num2: Enteros                      ARGUMENTOS: num1, num2: Enteros
RESULTADO: Entero.                                   RESULTADO: Entero.
VARAUX:                                              VARAUX:

    Calc_Suma <- num1 + num2                             Calc_Suma <- num1 - num2                    

FIN_FUNCIÓN                                          FIN_FUNCIÓN



FUNCION: Calc_Multiplicación                         FUNCION: Calc_Divición
ARGUMENTOS: num1, num2: Enteros                      ARGUMENTOS: num1, num2: Enteros
RESULTADOS: Entero                                   RESULTADOS: Entero
VARAUX: sumatoria                                    VARAUX: cosiente: Entero 
.                                                    cosiente <- 0
HACER num2 VECES (i=1 ... num2)                      MIENTRAS (num1 > num2)
    sumatoria <- sumatoria + num1                       num1 <- num1 - num2
FIN_HACER                                               cosinte<- cosiente + 1
Calc_Multiplicación <- sumatoria                    FIN_MIENTRAS
FIN_FUNCIÖN                                         Calc_Divición <- cosiente        
.                                                   FIN_FUNCiÓN           


FUNCION: Calc_Potencia                              FUNCION: Calc_Porcentaje
ARGUMENTOS: num1, num2: enteros                     ARGUMENTOS: num1, num2: enteros
RESULTADO: entero.                                  RESULTADO: entero.
VARAUX: result: Entero                              VARAUX: resultado: Entero

resultado <- num1                                   resultado <- calc_Divicion((Calc_Multiplicación(num1,num2),100)
HACER num2 VESES (i=1…num2)                         Calc_Porcentaje <- resultado
   result <- Calc_Multiplicación(result,num1)       FIN_FUNCIÓN
FIN_HACER
Calc_Potencia <- result
FIN_FUNCIÓN

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

*/


#include<stdio.h>

int Calc_Suma(int num1, int num2);
int Calc_Resta(int num1, int num2);
int Calc_Multiplicacion(int num1, int num2);
float Calc_Divición(int num1, int num2);
int Calc_Potencia(int num1, int num2);
int Calc_Porcentaje(int num1, int num2);

int main(void)
{
    int num1, num2, operacion, resultado;
    printf("¿Qué operacion desea realizar? Marque 1 para suma, 2 para resta, 3 para producto, 4 para cosiente, 5 para potencia o 6 para porcentaje: \n");
    scanf("%d",&operacion);
    printf("Ingrese el primer Numero (entero y no negativo): \n");
    scanf("%d",&num1);
    printf("Ingrese el segundo Numero (entero y no negativo): \n");
    scanf("%d",&num2);

    while (num1 <= 0)
    {
        printf("El primer Numero no coincide con lo pedido, por favor, ingrese un Numero entero y no negativo: \n");
        scanf("%d",&num1);
    }
    
    while (num2 <= 0)
    {
        printf("El primer Numero no coincide con lo pedido, por favor, ingrese un Numero entero y no negativo: \n");
        scanf("%d",&num2);
    }

    while (operacion < 0 || operacion > 6)
    {
        printf("La operacion solicitada no corresponde a lo pedido, por favor intente de nuevo\n"); 
        printf("¿Qué operacion desea realizar? Marque 1 para suma, 2 para resta, 3 para producto, 4 para cosiente, 5 para potencia o 6 para porcentaje: \n");
        scanf("%d",&operacion); 
    }
    

    switch (operacion)
    {
    case 1:
        resultado = Calc_Suma(num1, num2);
        break;
    case 2:
        resultado = Calc_Resta(num1, num2);
        break;
    case 3:
        resultado = Calc_Multiplicacion(num1, num2);
        break; 
    case 4:
        resultado = Calc_Divición(num1, num2);
        break;
    case 5:
        resultado = Calc_Potencia(num1, num2);
        break;
    case 6:
        resultado = Calc_Porcentaje(num1, num2);
        break;
    }

    return 0;
}

Calc_Suma(int num1, int num2)
{
    int suma;
    suma = num1 + num2;
    return(suma); 
}

Calc_Resta(int num1, int num2)
{
    int resta;
    resta = num1 - num2;
    return(resta); 
}

Calc_Multiplicacion(int num1, int num2)
{
    int sumatoria;
    for (int i = 0; i < num2; i++)
    {
        sumatoria = sumatoria + num1;
    }
    return(sumatoria); 
}

Calc_Divicion(int num1, int num2)
{
    float cosiente=0;
    while (num1>num2)
    {
        num1 -= num2;
        cosiente++;
    }
    
    return(cosiente); 
}


Calc_Potencia(int num1, int num2)
{
    int result;
    result = num1;
    for (int i = 0; i < num2; i++)
    {
        result = Calc_Multiplicacion(result, num1);   
    }
    return(result);
}

Calc_Porcentaje(int num1, int num2)
{
    float resultado;
    int mult;
    mult = Calc_Multiplicacion(num1, num2);
    resultado = Calc_Divicion(mult, 100);
    return(resultado);
}

