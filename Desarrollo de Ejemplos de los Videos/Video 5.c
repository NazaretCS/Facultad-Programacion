/**
 
 Cargue un arreglo con 20 números enteros aleatorios comprendidos en el intervalo
[150,250], luego calcule y muestre por pantalla la suma de los valores que hay en
posiciones pares del mismo (0,2,..) y cuente cuántos números pares hay en las
posiciones impares (1,3,...).

Luego, modifique el programa para que el número de valores aleatorios no sea fijo
sino que se lea como entrada y sea como máximo 20. ¿Qué ocurre si indicamos más
de 20?

    ALGORITMO: NumerosYArreglos
    ENTRADAS: -
    SALIDA: CantNumPares, ParesEnImpares: Enteros U 0.
    VARAUX: Arre[20]: Arreglo de enteros, i: entero

        A0. Inicializar
        A1. CargarArreglo
        A2. CalcularSumaDePares
        A3. ContarParesEnImapres
        A4. ESCRIBIR(CantNumPares, ParesEnImpares)
        A5. PARAR.

    FIN: ALGORITMO:


    REFINAMIENTOS:
            A0. Inicializar
                CantNumPares <- 0 
                ParesEnImpares <- 0


            A1. CargarArreglo
                HACER (20) VECES (i <- 0...20)
                    Arre[i] <- Aleatoreo(150, 250)
                FIN HACER


            A2. CalcularSumaDePares
                
                HACER (20) VECES (i <- 0 ... 20)
                    SI (RESTO(Arre[i]/2 = 0)) ENTONCES
                        CantNumPares <- CantNumPares + Arre[i]
                    FIN SI
                FIN HACER
            
            A3. ContarParesEnImapres
                HACER (20) VECES (i <- 0 ... 20)
                    SI (i / 2 = 0 AND RESTO(Arre[i]/2 = 0)) ENTONCES
                        ParesEnImpares <- ParesEnImpares + 1
                    FIN SI
                FIN HACER




2. Amigas Vocales
Escriba un programa que lea un nombre completo y cuente la cantidad de vocales que hay
en el mismo. Una vez que su programa funcione, modifique el código de modo que haga la
misma tarea con los nombres de todos los integrantes del grupo de trabajo y determine
quién es el que mayor cantidad de vocales tiene en su nombre.



 */

int main(){

    switch (expression)
    {
    case /* constant-expression */:
        /* code */
        break;
    
    default:
        break;
    }
    return 0;
}