
/**
INTEGRANTES:GRUPO:CINCO:--------------

>Bobadilla, Juan Pablo.---------------
>Buahl, Paula Florencia.--------------
>Campos, Nestor Nazaret.---------------
*/

#include <stdio.h>

int main(void)
{   
    printf("------------------------------   01   ------------------------------\n");
    int a,b;    
    printf("Ingrese un numero\n");
    scanf("%d",&a);
    printf("Ingrese un numero\n");
    scanf("%d",&b);
    printf("Los numeros ingresados son: %d y %d \n \n",a,b);


    printf("------------------------------   02   ------------------------------\n \n");
    int *p;
    int *q;
    p=&a;
    q=&b;

    printf("------------------------------   03   ------------------------------\n");
    printf("Los punteros son: para p--> %d  y para q --> %d \n \n",p,q);


    printf("------------------------------   04   ------------------------------\n");
    printf("El contenido de los punteros es: p--> %d  y de q ---> %d \n \n",*p,*q);


    printf("------------------------------   05   ------------------------------\n");
    printf("Las direcciones de memoria de los punteros son: de p--> %d  y de q--> %d \n \n",&p,&q);


    printf("------------------------------   06   ------------------------------\n");
    int c;
    printf("Ingrese un numero\n");
    scanf("%d",&c);
    printf("La variable c toma el valor de %d y su direccion de memoria es %d \n \n",c,&c);

    
    printf("------------------------------   07   ------------------------------\n");
    *p = c;
    printf("La variable a modificada vale %d y c vale %d \n \n",a,c);


    printf("------------------------------   08   ------------------------------\n");
    c = *p + *q;
    printf("La variable a = %d, la variable b = %d, la variable c = %d \n \n",a,b,c);


    printf("------------------------------   09   ------------------------------\n");
    //¿Qué sucede si ejecutamos *p=*p+1? si ejecutamos este codigo al valor que se encuentra en la direccion del puntero p lo estariamos incrementando en uno.
    *p=*p+1;
    printf("El resultado fue que a tome el valor de %d \n \n",*p);

    *p=*p++;
    printf("el puntero p ahora ahora apunta al dato %d que contiene %d \n",&p,*p);


    printf("------------------------------   10   ------------------------------\n");
    //¿Qué sucede si ejecutamos p=p+1? si ejecutasemos ese codigo estariamos moviendo la direccion de memoria a la que apunta p, o incrementandola (por decirlo de otro modo) segun la cantidad de bytes correspondiente a cada tipo de dato, por ejemplo si el dato es char se incremente en un byte, si es int se incremente de a 4.
    p=p+1;
    printf("Ahora p apunta a %d \n \n",p);


    printf("------------------------------   11   ------------------------------\n");
    // Dada la siguiente asignación: p=&a:
    // ¿Las sentencias *p=*p+1 y *p=a+1 son equivalentes? si, ambas nos quieren decir que al valor de a se lo incremetna en 1.
    // ¿Las sentencias p=p+1 y p=&a+1 son equivalentes? si, ambas nos quieren decir que a la direccion de la variale a la incrementamos.
    p=&a;
    p=p+1;
    q=&a+1;
    printf("P apunta a %d y en esa direccion esta %d \n q apunta a %d y en esa direccion esta %d \n",p,*p,q,*q);

    return 0;
}