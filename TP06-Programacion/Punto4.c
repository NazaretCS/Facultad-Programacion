/**
INTEGRANTES:GRUPO:CINCO:--------------

>Bobadilla, Juan Pablo.---------------
>Buahl, Paula Florencia.--------------
>Campos, Nestor Nazaret.---------------
*/
/**
++++++++++++++++++++++++++++++++++++++++++++++   Algortimo Principal   +++++++++++++++++++++++++++++++++++++++++++

ALGORITMO: Mezclando_Cadenas
ENTRADAS: cadena1, cadena2 : Arreglos de Caracteres
          posicion: Entero
SALIDAS:  cadena1
VARAUX:  auxiliar: arreglo de Caracteres
         *p_cadena1,*p_cadena2, *p_aux: Punteros a Caracter
         *p_posicio: Puntero a Entero
         cantidad1,cantidad2, lugar, ultimo: Enteros         
CONSTANTE: MAX 250

A1. Cargar_Valores
A2. Controlar
A3. Crear_Aux.
A4. Mezclar_Cadenas
A5. ESCRIVIR(cadena1)
A6. PARAR
    
    

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

++++++++++++++++++++++++++++++++++++++++++++++++   Refinamientos   +++++++++++++++++++++++++++++++++++++++++++++++

A1. Cargar_Valores
    LEER(cadena1, cadena2, posicion)
    p_cadena1 <- cadena1
    p_cadena2 <- cadena2
    p_posicion <- Direccion_de_Memoria(posicion)


A2. Controlar
    SI (*p_posicion < 0)
        LEER(posicion)
    FIN_SI

    SI (posicion = 0)
        posicion <- 1
    FIN_SI

    cantidad1 <- Longirud(cadena1)   //longuitud seria una funcin que me devuelve la longuitud del argumento (cadena1 en este caso)
    cantidad1 <- Longirud(cadena2)

    MIENTRAS (*p_posicion > cantidad1)
        LEER(posicion)
    FIN_MIENTRAS

A3. Crear_Aux.
    p_aux <- auxiliar
    HACER (cantidad1) VESES (i= 0...cantidad1)
        p_aux[i] <- p_cadena[i]
    FIN_HACER


A4. Mezclar_Cadenas
    lugar <- posicion + cantidad2
    posicion <- posicion -1
    lugar <- lugar -1
    p_cadena1 <- Direccion_de_Mermoria(cadena1[posicion])
    MIENTRAS (*p_cadena2 <> '\0')
        *p_cadena1 <- *p_cadena2;
        p_cadena1++
        p_cadena2++
    FIN_MIENTRAS
    p_cadena1 <- Direccion_de_Memoria(cadena1[lugar])
    p_aux <- Direccion_de_Memoria8auxiliar[posicion])
    MIENTRAS (*p_aux != '\0')
        *p_cadena1 <- *p_aux
        p_aux++
        p_cadena1++
    FIN_MIENTRAS

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


*/


#include <stdio.h>
#include <string.h>
#define MAX 250

int main(void)
{
    char cadena1[MAX] = {' '}, cadena2[MAX] = {' '}, auxiliar[MAX] = {' '}, *p_cadena1,*p_cadena2, *p_aux;
    int cantidad1,cantidad2, lugar; //ultimo;
    int posicion, *p_posicion;

    printf("Ingrese la cadena \n");
    gets(cadena1);
    p_cadena1 = cadena1;    

    printf("Ingrese la cadena \n");
    gets(cadena2);
    p_cadena2 = cadena2;

    printf("Ingrese la posicion de la primera cadena donde quiere insertar la segunda\n");
    scanf("%d",&posicion);
    p_posicion = &posicion;

    
    
    if (*p_posicion < 0)
    {
        printf("La posicion indicada no puede tomar un valor negativo\nPor favor intente ingresar la posicion nuevamente \n");
        printf("Ingrese la posicion de la primera cadena donde quiere insertar la segunda \n");
        scanf("%d",&posicion);
    }

    if (posicion == 0)
    {
        posicion = 1;
    }  // realizo este control ya que sin el si ingreso la posicion 0 (podria darse el caso de que un usuario quiera referenciar el principio del arreglo mediante ella) me quita una componente  de cadena2
    
    
    cantidad1 = strlen(cadena1);
    cantidad2 = strlen(cadena2);
    //printf("La cantida de los arreglos es de %d y de  %d",cantidad1,cantidad2);

    while (*p_posicion > cantidad1)
    {
        printf("No podemos realizar la insercion en la poscicion indicada por ser mayor a la longitud de la primer cadena \nPor favor, intente nuevamente\n");
        printf("Ingrese la posicion de la primera cadena donde quiere insertar la segunda\n");
        scanf("%d",&posicion);
    }
    
    p_aux = auxiliar;
    for (int i = 0; i < cantidad1; i++)  
    {
        p_aux[i] = p_cadena1[i];
        //printf("La cadena es %c \n",auxiliar[i]);
        //ultimo = i;
    }

    //auxiliar[ultimo+1] = '\0';  
    //puts(auxiliar);
     
    lugar = posicion + cantidad2;  
    posicion--; 
    lugar--;
    p_cadena1 = &cadena1[posicion];

    while (*p_cadena2 != '\0')
    {
        *p_cadena1 = *p_cadena2;
        p_cadena1++;
        p_cadena2++; 
        
    }
    
    p_cadena1 = &cadena1[lugar];
    p_aux = &auxiliar[posicion];
    //puts(cadena1);
    
    while (*p_aux != '\0')
    {
        *p_cadena1 = *p_aux;
        p_aux++;
        p_cadena1++;    
    }
    puts(cadena1);
       
    return 0;
}


