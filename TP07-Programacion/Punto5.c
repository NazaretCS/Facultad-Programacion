/**
 
+++++++++++++++++++++++++++++++++++++++++   ALGORITMO PRINCIPAL   ++++++++++++++++++++++++++++++++++++++++++++

 ALGORITMO: Acertando_El_Número
 ENTRADAS: cantJugadores, cantCartas: enteros
 SALIDAS: ganador: entero
 VARAUX: numero, sumaCartas, distancia: entero
         *p_cartas,*p_resultados: punteros a enteros
         
 CONSTANTES:
 
 A1. LEER(cantJugadores)
 A2. numero <- Aleatoreo(40, 100)  //Aleatoreo seria una funcion que me devuelve un valor aleatoreo encontrado entre los valores indicados en los parametros.
 A3. Procesar_Jugada
 A4. Sacar_Ganador
 A5. PARAR


+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


+++++++++++++++++++++++++++++++++++++++++++   REFINAMIENTOS   +++++++++++++++++++++++++++++++++++++++++++++++

A3. Procesar_Jugada
    p_resultados <- Reservar(cantJugadores * Dato(entero))  //la funcion reservar entraria siendo  como la representación algoritmica de la función malloc; y la función dato representaria a la función sizeof
    HACER (cantJugadores) VESES (i=0...cantJugadores)
        LEER(cantCartas)
        p_cartas <- Reservar(cantCartas * Dato(entero)) 
        sumaCartas <- 0
        MIENTRAS (*p_cartas <> '\0')
            *p_cartas <- Aleatoreo(1,12)
            sumaCartas <- sumaCartas + (*p_carta)
            p_cartas++
        FIN_MIENTRAS
        distancia <- Distancia(sumaCartas, numero)
        p_resultados[i] <- distancia
        Liberar(p_cartas)
    FIN_HACER


A4. Sacar_Ganador
    ganador <- Ganador(&p_resultados[0], cantJugadores)
    ESCRIVIR(ganadores)

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    
++++++++++++++++++++++++++++++++++++++++++++++   FUNCIÓN   ++++++++++++++++++++++++++++++++++++++++++++++++++

    FUNCION: Ganador
    ARGUMENTOS: *p_resultados: puntero a entero 
                jugadores: entero
    RESULTADO: entero
    VARAUX: distMenor: entero           

         distMenor <- 312  //312 es la suma de todas las cartas de una baraja española, asi que si o si la distancia me deveria dar un numero menor a 312.
        MIENTRAS(*p_resultados <> '\0')
            SI (*p_resultados < distMenor)
                distMenor <- *p_resultados
            FIN_SI
            p_resultados++
        FIN_MIENTRAS
        Ganador <- distMenor
    FIN_FUNCIÓN 


    FUNCION: Distancia
    ARGUMENTOS: valor1, valor2: enteros
    RESULTADO: entero
    VARAUX: minuendo, sustraendo, dist: entero            

        SI (valor1 > valor2)
            minuendo <- valor1
            sustraendo <- valor2
        FIN_SI
        SI (valor1 = valor2)
            dist <- 0
        FIN_SI
        SI (valor1 < valor2)
            minuendo <- valor2
            sustraendo <- valor1
        FIN_SI
        dist <- minuendo - sustraendo
        Distancia <- dist        
    FIN_FUNCIÓN   

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

 A2. numero <- Aleatoreo(40, 100)  //Aleatoreo seria una funcion que me devuelve un valor aleatoreo encontrado entre los valores indicados en los parametros.
 A3. Procesar_Jugada
 A4. Sacar_Ganador
 A5. PARAR
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int Ganador(int *p_resultados, int jugadores);
int Distancia(int valor1, int valor2);


int main(void)
{   
    int cantJugadores, cantCartas, ganador, numero, sumaCartas, *p_cartas, *p_resultados, distancia;
    
    printf("Ingrese la cantidad de jugadores que participaran \n");
    scanf("%d",&cantJugadores);
    numero = rand() % 60 + 40;
    printf("El valor a aproximarse es:  %d \n",numero);
    p_resultados = malloc(cantJugadores * sizeof(int));
    for (int i = 0; i < cantJugadores; i++)
    {
        printf("------   JUGADOR  %d   ------ \n",i+1);
        printf("Ingrese la cantidad de cartas que quiere mostrar:\n");
        scanf("%d", &cantCartas);
        p_cartas = malloc(cantCartas*sizeof(int));
        
        sumaCartas = 0;
        srand(time(NULL));
        /*while (*p_cartas != '\0')
        {
           *p_cartas = rand()%11+1;
           printf("Carta barajada:  %d  ",*p_cartas);
           sumaCartas = sumaCartas + (*p_cartas);
           p_cartas++;
        }*/
        for (int a = 0; a < cantCartas; a++)
        {
            p_cartas[a] = rand()%11+1;
            printf("Carta barajada:  %d  \n",p_cartas[a]);
            sumaCartas = sumaCartas + (p_cartas[a]);
            p_cartas++;
        }
        
        distancia = Distancia(sumaCartas, numero);
        printf("\n---------------------------\n\n");
        p_resultados[i] = distancia;
        
        printf("LLEgo hasta aqui \n");
        free(p_cartas);
        printf("LLEgo hasta aqui \n");
        
    }
    ganador = Ganador(&p_resultados[0], cantJugadores);
    printf("----------   PUNTAJES   ---------\n");
    for (int j = 0; j < cantJugadores; j++)
    {
        printf("Jugador %d)  %d\n",j+1,p_resultados[j]);
    }
    printf("---------------------------------\n");
    printf("El ganador es el jugador con una distancia de %d \n",ganador);
    return 0;
}

int Ganador(int *p_resultados, int jugadores)
{
    int distMenor;
    distMenor = 312;
    while (*p_resultados != '\0')
    {
        if (*p_resultados < distMenor)
        {
            distMenor = *p_resultados;
        }
        p_resultados++;
    }
    return distMenor;
}

int Distancia(int valor1, int valor2)
{
    int minuendo, sustraendo, dist;
    if (valor1 > valor2)
    {
        minuendo = valor1;
        sustraendo = valor2;
    }
    if (valor1 == valor2)
    {
        dist = 0;
    }
    if (valor1 < valor2)
    {
        minuendo = valor2;
        sustraendo = valor1;
    }
    dist = minuendo - sustraendo;
    return dist;
}
/*
FUNCION: Distancia
    ARGUMENTOS: valor1, valor2: enteros
    RESULTADO: entero
    VARAUX: minuendo, sustraendo, dist: entero            

        SI (valor1 > valor2)
            minuendo <- valor1
            sustraendo <- valor2
        FIN_SI
        SI (valor1 = valor2)
            dist <- 0
        FIN_SI
        SI (valor1 < valor2)
            minuendo <- valor2
            sustraendo <- valor1
        FIN_SI
        dist <- minuendo - sustraendo
        Distancia <- dist        
    FIN_FUNCIÓN   
*/