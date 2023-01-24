/**
+++++++++++++++++++++++++++++++++++++++++   ALGORITMO PRINCIPAL   ++++++++++++++++++++++++++++++++++++++++++++

 ALGORITMO: Cadenas_BIS
 ENTRADAS: cc[MAX]: cadena de caracteres
 SALIDAS:  longitud, cantVocales, cantPalabras: enteros
 VARAUX:            
 CONSTANTES: MAX <- 1500
 
 A0. longuitud, cantVocales, cantPalabras <- 0
 A1. LEER(cc)
 A2. ProcesarCadena(cc, &longuitud,&cantVocales, &cantPalabras)
 A3. ESCRIVIR(longitud, cantVocales, cantPalabras)
 A4. PARAR



+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    
++++++++++++++++++++++++++++++++++++++++++++++   FUNCIÓN   ++++++++++++++++++++++++++++++++++++++++++++++++++

    FUNCION: Procesar_Cadena
    ARGUMENTOS: *p_cc: puntero a caracter
                *p_longuitud, *p_cantVocales, *p_cantPalabras: punteros a enteros
    SALIDA: 
    VARAUX: *p:aux: puntero a caracter

        p_aux = p_cc
        MIENTRAS (*p_cc <> '\0')
            *p_longitud = (*p_longuitud) + 1
            
            SI ( *p_cc = 'a' || *p_cc = 'A' || *p_cc = 'e' || *p_cc = 'E' || *p_cc = 'i' || *p_cc = 'I' || *p_cc = 'o' || *p_cc = 'O' || *p_cc = 'U' || *p_cc = 'u')
                *p_cantVocales <- (*p_cantVocales) + 1
            FIN_SI
            p_cc++
        FIN_MIENTRAS

        MIENTRAS (*p_aux <> '\0')
            SI ( EsLetra(*p_aux) )
                p_aux++
                SI (*p_aux = '.' || *p_aux = ',' || *p_aux = ';' || *p_aux = ':' || *p_aux = '!' || *p_aux = ')' || *p_aux = '}' || *p_aux = '?')
                    p_aux++
                    SI (*p_aux = ' ' || *p_aux = '\0')
                        *p_cantPalabras = (*p_cantPalabras) + 1
                    FIN_SI                    
                SINO 
                    SI (*p_aux = ' ' || *p_aux = '\0')
                        *p_cantPalabras = (*p_cantPalabras) + 1
                    SINO 
                        p_aux++
                        SI (*p_aux = ' ' || *p_aux = '\0')
                            *p_cantPalabras = (*p_cantPalabras) + 1
                        FIN_SI
                    FIN_SI
                FIN_SI
            SINO
                p_aux++
            FIN_SI
        FIN_MIENTRAS        
    FIN_FUNCIÓN                

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

*/

#include <stdio.h>
#include <ctype.h>
#define MAX 500
void ProcesarCadena(char *p_cc, int *p_longuitud, int *p_cantVocales, int *p_cantPalabras );

int main(void)
{   
    char cc[MAX];
    int longitud=0, cantVocales=0, cantPalabras =0;

    printf("Ingrese una cadena de caracters \n");
    gets(cc);
    fflush(stdin);
    //printf("LLego aqui");
    ProcesarCadena(cc, &longitud, &cantVocales, &cantPalabras);
    printf("La cadena tiene: \nUna longitud de %d  \n%d vocales \n%d Palabras", longitud, cantVocales, cantPalabras);


    return 0;

}

void ProcesarCadena(char *p_cc, int *p_longuitud, int *p_cantVocales, int *p_cantPalabras )
{
    char *p_aux;
    p_aux = p_cc;
    while (*p_cc != '\0')
    {
        *p_longuitud = (*p_longuitud) + 1;
        if (*p_cc == 'a' || *p_cc == 'A' || *p_cc == 'e' || *p_cc == 'E' || *p_cc == 'i' || *p_cc == 'I' || *p_cc == 'o' || *p_cc == 'O' || *p_cc == 'U' || *p_cc == 'u')
        {
            *p_cantVocales = (*p_cantVocales) + 1;
        }
        p_cc++;        
    }

    while (*p_aux != '\0')
    {
        if (  isalpha(*p_aux))
        {
            p_aux++;
            if (*p_aux == '.' || *p_aux == ',' || *p_aux == ';' || *p_aux == ':' || *p_aux == '!' || *p_aux == ')' || *p_aux == '}' || *p_aux == '?')
            {
                p_aux++;
                if (*p_aux == ' ' || *p_aux == '\0')
                {
                    *p_cantPalabras = (*p_cantPalabras) + 1;
                }
                
            } else {
                //printf("%c es la letra que cuenta la palabra \n",*p_aux);
                
                if (*p_aux == ' ' || *p_aux == '\0')
                {
                    *p_cantPalabras = (*p_cantPalabras) + 1;
                } else {
                    p_aux++;
                    if (*p_aux == ' ' || *p_aux == '\0')
                    {
                        *p_cantPalabras = (*p_cantPalabras) + 1;
                    }
                }            
            }            
        } else {
            p_aux++;
        }       
    }  
}
