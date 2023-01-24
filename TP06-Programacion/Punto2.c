/**
INTEGRANTES:GRUPO:CINCO:--------------

>Bobadilla, Juan Pablo.---------------
>Buahl, Paula Florencia.--------------
>Campos, Nestor Nazaret.---------------
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100


int main(void)
{   
    char cad[MAX];
    char letra,vocal;
    int num,consonantes,i;

    printf("------------------------------   01   ------------------------------\n");
    char *p_cadena;

    printf("Ingrese una oracion \n");
    gets(cad);
    puts(cad);
    
    printf("------------------------------   02   ------------------------------\n \n");
    //p_cadena = &cad[0];
    p_cadena = cad;

    
    printf("------------------------------   03   ------------------------------\n");
    printf("la direccion del puntero p_cad es %d \n",&p_cadena);
    printf("La direccion de la primera componente del arreglo cad es de %d \n \n",&cad[0]);

    
    printf("------------------------------   04   ------------------------------\n");
    printf("La quinta componente del arreglo cad es de %c \n",cad[4]);
    printf("La quinta componente del arreglo cad es de %c \n \n", p_cadena[4]); 


    printf("------------------------------   05   ------------------------------\n");
    p_cadena = p_cadena+3;
    printf("La direccion referenciada por p_cadena + 3 es %d \n",&p_cadena);
    printf("y en ese lugar esta: %c \n \n",*p_cadena); 


    

    printf("------------------------------   06   ------------------------------\n");
    p_cadena = cad;
    consonantes = 0;
    while (*p_cadena != '\0')
    {
        i=0;       
            if (*p_cadena == 'a' || *p_cadena == 'A' || *p_cadena == 'e' || *p_cadena == 'E' || *p_cadena == 'i' || *p_cadena == 'I' || *p_cadena == 'o' || *p_cadena == 'O' || *p_cadena == 'U' || *p_cadena == 'u' || *p_cadena == ' ')
            {
                vocal = 1;
            } else {
                vocal = 0;
            }
            if (vocal == 0)
            {
                consonantes++;
                *p_cadena = toupper(*p_cadena);
                printf("la letra es %c \n",*p_cadena);                
            }    
        p_cadena++;
    }
    puts(cad);
    printf("cantidad de consonantes en la oracion es de %d \n \n",consonantes);


    printf("------------------------------   07   ------------------------------\n");
    int cantidad; 
    p_cadena = cad;
    cantidad = strlen(cad);
    for (int j = 0; j < cantidad; j++)
    {
        printf("Cad[%d] =  %c  \n",j, p_cadena[j]);
    }
    
    return 0;
}
