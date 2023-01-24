/*
Integrantes del grupo 5-------------
>Bobadilla, Juan Pablo.---------------
>Buahl, Paula Florencia.--------------
>Campos, Nestor Nazaret.---------------
*/

/*El punto dos dice lo siguiente: 
Dada una oración terminada en un punto, escriba un algoritmo que cuente la cantidad total de vocales abiertas (a, e, o) y la cantidad por cada una de ellas. Codifique en C.
Por como yo lo entiendo nos pide contar unicamente la cantidad por las vocales a, e, o, no por todas las vocales.*/

/*

ALGORITMO VOCALES
ENTRADAS cc: cadena de caracteres (con MF='.')
SALIDA CantVocales, CantA, CantE, CantO: entros
VAR AUX:

A0. Inicializar.
A1. Leer (cc).
A2. Contar_Vocales.
A3. Escribir (CantVocales, CantA, CantE, CantO).
A4. Parar.


A0. Inicializar.
        CantVocales <- 0
        CantA <- 0
        CantE <- 0
        CantO <- 0


A2. Contar_Vocales.
	MIENTRAS (cc <> MF)
		SEGUN (cc)
		    cc=’a’ || cc='A':  CantA <- CantA +1
		    cc=’e’ || cc='E': CantE <- CantE +1
		    cc=’o’ || cc='O': CantO <- CantO +1 
		FIN_SEGUN
		LEER (cc)
	FIN_MIENTRAS
    CantVocales <- CantA + CantE + CantO


*/

#include <stdio.h>
#include <unistd.h>


int main (){
    char cc;
    int cantVocales, canta, cante, canto;
    printf("Ingrese una Oracion, terminada en un punto. "); 
    scanf ("%c", &cc);
    //Este programa solicita que la oracion termine en un punto, de no ser asi no mostrara resultado alguno hasta que se ingrese un punto.
    
    
    //Inicializo mis contadores:
    cantVocales = 0;
    canta = 0;
    cante = 0;
    canto = 0;

        
    //Cuento las Vocales de la cadena de caracteres, no importa si son mayusculas o minusculas:
    while (cc != '.')
    {                
        switch (cc)
        {
        case 'a':
            canta++;
            break;
        case 'A':
            canta++;
            break;            
        case 'e':
            cante++;
            break;
        case 'E':
            cante++;
            break;
        case 'o':
            canto++;
            break;
        case 'O':
            canto++;
            break;            
        }
        scanf("%c", &cc);
    }
    cantVocales = canta + cante + canto;

    //Muestro los valores obtenidos en mi algoritmo:
    printf("La cantidad de vocales (A, E, O) es de: ( %d ).\n",cantVocales);
    printf("La cantidad de vocal 'A' es: ( %d ).\nLa cantidad de vocal 'E' es: ( %d ).\nLa cantidad de vocal 'O' es: ( %d ).",canta,cante,canto);
    
          
    sleep(12);    
    return 0;

}