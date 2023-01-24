/**
 
+++++++++++++++++++++++++++++++++++++++++   ALGORITMO PRINCIPAL   ++++++++++++++++++++++++++++++++++++++++++++

 ALGORITMO: Cadenas_A
 ENTRADAS: cc: cadena de caracteres
            c: caracter
 SALIDAS: mesaje: cc 
          cant: int
 VARAUX:  valor: boleano          
          *p_bandera: puntero a entero
          bandera: entero
 CONSTANTES: MAX <- 300
 


A1. LEER(cc,c)
A2. Procesar_Cadena
A3. Mostrar_Resultados
A4. PARAR

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


+++++++++++++++++++++++++++++++++++++++++++   REFINAMIENTOS   +++++++++++++++++++++++++++++++++++++++++++++++

A2. Procesar_Cadena
    bandera = 0
    cant = 0
    valor = Buscar(&cadena[0], c, &cant)
    SI (valor)
        bandera = bandera + 1
    FIN_SI
    FIN_MIENTRAS

    
A3. Mostrar_Resultados
    SI (*p_bandera <> 0)
        ESCRIVIR ('El caracter si se encontraba', cant)
    SINO
        ESCRIVIR('El caracter no se encontraba')
    FIN_SI

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    
++++++++++++++++++++++++++++++++++++++++++++++   FUNCIÓN   ++++++++++++++++++++++++++++++++++++++++++++++++++

    FUNCION: Buscar
    ARGUMENTOS: *cad: puntero a caracter
                c: caracter      
                *cant: puntero a entero    
    RESULTADO: boleano
    VARAUX:             

        MIENTRAS (*cad <> '\0')
            SI (*cad = c)
                *cant = *cant + 1
            FIN_SI            
            *cad++
        FIN_MIENTRAS
        SI (*cant > 0)
            valor = true
        SINO
            valor = false
        FIN_SI
        Buscar <- valor
    FIN_FUNCIÓN   

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

*/

/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 500
int Buscar(char *cad, char c, int *cant);
int main(void)
{       
    char cc[MAX], c;
    int  cant, bandera, *p_bandera, valor;

    printf("Ingrese la cadena de caracteres \n");
    gets(cc);
    fflush(stdin);
    printf("Ingrese el caracter que desea buscar \n");
    scanf("%c",&c);

    bandera = 0;
    cant = 0;
    
    valor = Buscar(&cc[0], c, &cant);
    if (valor)
    {
        bandera = bandera + 1;
    }     
    p_bandera = &bandera;
    if (*p_bandera != 0)
    {
        printf("El caracter  %c  si se encontraba en la cadena. Numero de veses: %d \n",c,cant);
    } else 
    {
        printf("El caracter no se ecnontraba en la cadena \n");
    }
    
    
    
    return 0;
}

int Buscar(char *cad, char c, int *cant)
{
    int valor;    
    puts(cad);       
    while (*cad != '\0')
    {
        if (*cad == c)
        {
            *cant= *cant+1;
            //printf("paso por aqui \n\n");
        }
        cad++;
    }
    if (*cant > 0)
    {
        valor = 1;
    } else {
        valor = 0;
    }
    return (valor);
    
}
*/

/**
+++++++++++++++++++++++++++++++++++++++++   ALGORITMO PRINCIPAL   ++++++++++++++++++++++++++++++++++++++++++++

 ALGORITMO: Cadenas_B
 ENTRADAS: cc[MAX]: cadena de caracteres
            c: caracter
            posicion: entero
 SALIDAS: mesaje
 CONSTANTES: MAX <- 300
 


A1. LEER(cc,c, pos)
A2. Insertar(&cc[0], pos, c)
A3. ESCRIVIR(cc)
A4. PARAR

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    
++++++++++++++++++++++++++++++++++++++++++++++   FUNCIÓN   ++++++++++++++++++++++++++++++++++++++++++++++++++

    FUNCION: Insertar
    ARGUMENTOS: *cad: puntero a caracter
                pos: entero
                c: caracter
    RESULTADO: ---
    VARAUX: i: entero             

    MIENTRAS (*cad <> '\0')
        SI (i = pos)
            *cad = c
        FIN_SI        
        i++
        cad++
    FIN_MIENTRAS
        
    FIN_FUNCIÓN  

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

*/

#include <stdio.h>
#define MAX 300
void insertar (char *cad, int pos, char c);
int main(void)
{   
    char cc[MAX], c;
    int posicion;

    printf("Ingrese la cadena de caracteres a trabajar \n");
    gets(cc);
    fflush(stdin);
    printf("ingrese la posicion del caracter que desea reemplazar\n");
    scanf("%d", &posicion);
    fflush(stdin);
    printf("Ingrese el caracter por el cual le gustaria reemplazarlo \n");
    scanf("%c", &c);

    printf("%c \n",c);
    insertar (cc, posicion, c);
    puts(cc);
    return 0;
}

void insertar (char *cad, int pos, char c)
{
    int i=1;       
   while (*cad != '\0')
    {
        if (i == pos)
        {
            *cad = c;
        }
        i++;        
        cad++;       
    }
    
}
