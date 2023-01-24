/**
INTEGRANTES:GRUPO:CINCO:--------------

>Bobadilla, Juan Pablo.---------------
>Buahl, Paula Florencia.--------------
>Campos, Nestor Nazaret.---------------
*/

/**
++++++++++++++++++++++++++++++++++++++++++++++   Algortimo Principal   +++++++++++++++++++++++++++++++++++++++++++

ALGORITMO: Nueva_Documentación
ENTRADAS: dni: Entero Largo
SALIDAS: cc: cadena de carcteres
VARAUX: *p_tabla: Puntero a Caracteres.
        tabla <- {'T','R','W','A','G','M','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E'}: Arreglo de Caracteres.
        letra: Caracter.
        posicion: Entero
CONSTANTES: MIN <- 10000000
            MAX <- 60000000  // No pude encontrar informacion 100% veridica sobre cual era el ultimo DNI dictado, por eso tome como referencia el numero que dijo un profesor en un foro. 

A1. HACER
        p_tabla <- tabla
        LEER(dni)
        SI (dni <> 0)
            SI (dni >= MIN && dni <= MAX)
                posicion <- RESTO(dni,23)     
                letra <- *(p_tabla+posicion); 
                ESCRIVIR(cc)  //La cadena de caracteres concatenaria la letra y el dni formando el NIF
            SINO
                ESCRIVIR('El DNI ingresado no es valido, por favor reviselo e intente de nuevo')    
        FIN_SI
    MIENTRAS (dni <> 0)
A2. PARAR
   

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


*/

#include <stdio.h>
#define MIN 10000000
#define MAX 65000000
int main (void)
{
    char tabla[]={'T','R','W','A','G','M','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E'};
    char *p_tabla, letra;
    long int dni;
    int posicion;     
    
    
    do
    {
        p_tabla = tabla;
        printf("Ingrese el DNI \n");
        scanf("%d",&dni);
        if (dni != 0)
        {
            if (dni >= MIN && dni <= MAX)
            {
                posicion = dni % 23;
                letra = *(p_tabla+posicion);
                printf ("El NIF correspondiente es: %c%d \n",letra,dni);
            } else {
                printf("El DNI ingresado no es valido, por favor reviselo e intente de nuevo \n");
            }            
        }      
    } while (dni != 0);    
    return 0;
}