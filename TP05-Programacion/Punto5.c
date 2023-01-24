/**
+++++++++++++++++++++++++++++++++++++++++++++   Algortimo Principal   +++++++++++++++++++++++++++++++++++++++++++++

ALGORITMO: Adivinando_la_palabra
ENTRADA: palabra: arreglo de caracteres
         letra: caracter.
SALIDAS: 
VARAUX: copia: arreglo de caracteres
        canIntetos, cantidad, seEncuentra,i, j, x, guion: entero
CONTANTES:

A1. LEER(palabra)
A2. Crear_Arreglo
A3. Jugar
A4. PARAR

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

+++++++++++++++++++++++++++++++++++++++++++++++   Refinamientos   +++++++++++++++++++++++++++++++++++++++++++++++++
A2. Crea_Arreglo
    cantidad <- Tamaño_Arreglo(palabra) - 1-------> //Funcion que me devuelve la cantidad de componentes que contiene el arreglo.
    HACER (cantidad) VESES (i=0...cantidad)
        copia[i] <- "-"
    FIN_HACER

A3. Jugar
    
    canIntentos <- 3
    MIENTRAS (cantIntentos > 0)
        seEncuentra  <- 0
        
        LEER(letra)
        HACER (cantidad) VESES (j=0 ... cantidad)
            SI (letra = palabra[j])
                guion <- 0
                seEncuentra <- 1
                copia[j] <- palabra[j]
                HACER (cantidad) VESES (x=0...cantidad)
                    SI (copia[x] = "-")
                        guion <- 1
                    FIN_SI
                FIN_HACER
                SI (guion = 0)
                    ESCRIVIR("ADIVINASTE LA PALABRA!!")
                    canIntentos <- 0
                FIN_SI
            FIN_SI
        FIN_HACER
        SI (seEncuentra = 0)
            canIntentos <- canIntentos - 1
            ESCREVIR(La letra no esta, tiene una oportunidad menos)
            guion <- 1
        FIN_SI
    FIN_MIENTRAS
    SI (canIntetnos = 0 && guion = 1)
        ESCRIVIR("Agoto sus intetntos y no adivino la palabra")
    FIN_SI
    
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#include <stdio.h>
#include <string.h>
#define MAX 50

int main(void) {

    int cantidad,seEncuentra;
    char palabra[MAX];
    char copia[MAX];
    char letra;
    int canIntentos=3;
    int guion;
    printf("Ingrese la palabra a adivinar: \n");
    gets(palabra);
    fflush(stdin);
    cantidad = strlen(palabra) - 1;
    for (int i = 0; i <= cantidad; i++)
    {
        copia[i] = 45;
    }
    
    while (canIntentos > 0)
    {
        seEncuentra = 0;
        printf("Ingrese una letra:  ");
        scanf("%c",&letra);
        fflush(stdin);
        for (int j = 0; j <= cantidad; j++)
        {
            if (letra == palabra[j])
            {
                guion = 0;
                seEncuentra = 1;
                copia[j] = palabra[j];
                puts(copia);
                for (int x = 0; x <= cantidad; x++)
                {
                    if (copia[x] == 45)
                    {
                        guion = 1;
                        
                    }
                }
                if (guion == 0)
                {
                    printf("ADIVINASTE LA PALABRA! \n");
                    canIntentos = 0;
                }  
            }
        }
        if (seEncuentra == 0)
        {
            canIntentos = canIntentos - 1;
            printf("la letra %c no esta, le quedan: %d oportunidad/des \n",letra,canIntentos);
            guion=1;
        }
    }
    if (canIntentos == 0 && guion==1)
    {
        printf("Agoto sus intentos, la palabra era: ");
        puts(palabra); 
    }
    
    return 0;
}


