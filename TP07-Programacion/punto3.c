/**
+++++++++++++++++++++++++++++++++++++++++   ALGORITMO PRINCIPAL   ++++++++++++++++++++++++++++++++++++++++++++

 ALGORITMO: Ayudando_al_profe_Hugo
 ENTRADAS: *p_primerParcial, *p_segundoParcial, *p_exFinal, *p_trabFinal: punteros a reales
           cantAlumnos: entero
 SALIDAS:  *p_notasFinales: arreglo de reales.
           notaMenor: real
 VARAUX:  
 CONSTANTES: 
 

 A0. LEER(cantAlumnos)
 A1. controlar
 A2. Crear_Arreglos
 A3. Cargar_Arreglos
 A4. Procesar_Notas
 A5. Mostrar_Resultados
 A6. liberar_Memoria
 A7. PARAR


+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


+++++++++++++++++++++++++++++++++++++++++++   REFINAMIENTOS   +++++++++++++++++++++++++++++++++++++++++++++++

A1. controlar
    notaMenor <- 10

    MIENTRAS(cantAlumnos < 0)
        LEER(cantAlumnos)
    FIN_MIENTRAS
    

A2. Crear_Arreglos
    p_primerParcial <- Reservar(cantAlumnos * Dato(entero))  //la funcion reservar entraria siendo  como la representación algoritmica de la función malloc; y la función dato representaria a la función sizeof
    p_segundoParcial <- Reservar(cantAlumnos * Dato(entero))
    p_exFinal <- Reservar(cantAlumnos * Dato(entero))
    p_trabFinal <-  Reservar(cantAlumnos * Dato(entero))
    p_notasFinales <- Reservar(cantAlumnos * Dato(entero))

 A3. Cargar_Arreglos
    HACER (cantAlumnos) VESES (i=0...cantAlumnos)
        LEER(p_primerParcial[i])
        LEER(p_segundoParcial[i])
        LEER(p_exFinal[i])
        LEER(p_trabFinal[i])
    FIN_HACER

A4. Procesar_Notas
    HACER (cantAlumnos) VESES (i=0...cantAlumnos)
        p_notasFinales[i] <- Calcular_Nota(&p_primerParcial[i], &p_segundoParcial[i], &p_exFinal[i], &p_trabFinal[i], &notaMenor)
    FIN_HACER 

A5. Mostrar_Resultados
    HACER (cantAlumnos) VESES (i=0...cantAlumnos)
        ESCRIVIR(p_notasFinales[i], notaMenor) 
    FIN_HACER 

    SI (cantAlumnos = 0)
        ESCRIVIR('No se calcularan notas')
    SINO
        ESCRIVIR(notaMenor)
    FIN_SI

A6. liberar_Memoria
    Liberar(p_primerParcial)
    Liberar(p_segundoParcial)
    Liberar(p_exFinal)
    Liberar(p_trabFinal)
    Liberar(p_notasFinales)
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    
++++++++++++++++++++++++++++++++++++++++++++++   FUNCIÓN   ++++++++++++++++++++++++++++++++++++++++++++++++++

    FUNCION: Calcular_Nota
    ARGUMENTOS: *p_primerParcial, *p_segundoParcial, *p_exFinal, *p_trabFinal, *p_notaMenor: punteros a reales
    RESULTADO: real
    VARAUX: valor, notaParciales, promParciales, porcFinal, porcTrabFinal: reales            

        notaParciales <- ((*p_primerParcial) + (*p_segundoParcial)) / 2
        promParciales <- (notaParciales * 55) / 100
        porcFinal <- ((*p_exFinal) *30 ) / 100
        porcTrabFinal <- ((*p_trabFinal) * 15) / 100
        valor <- promParciales + porcFinal + porcTrabFinal
        SI (valor < *p_notaMenor)
            *p_notaMenor <- valor
        FIN_SI

        Calcular_Nota <- valor      
    FIN_FUNCIÓN   

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

*/

#include <stdio.h>
#include <stdlib.h>
float Calcular_Nota(float *p_primerParcial, float *p_segundoParcial, float *p_exFinal, float *p_trabFinal, float *p_notaMenor);

int main(void)
{   
    float *p_primerParcial, *p_segundoParcial, *p_exFinal, *p_trabFinal, *p_notasFinales, notaMenor=10;
    int cantAlumnos;

    printf("Ingrese la cantidad de alumnos con la que desea trabajar \n");
    scanf("%d",&cantAlumnos);

    while (cantAlumnos < 0)
    {
        printf("La Cantidad de alumnos no puede ser negativa, por favor intente de nuevo \n");
        printf("Ingrese la cantidad de alumnos con la que desea trabajar \n");
        scanf("%d",&cantAlumnos);
    }
    

    p_primerParcial = malloc(cantAlumnos * sizeof(int));
    p_segundoParcial = malloc(cantAlumnos * sizeof(int));
    p_exFinal = malloc(cantAlumnos * sizeof(int));
    p_trabFinal = malloc(cantAlumnos * sizeof(int));
    p_notasFinales = malloc(cantAlumnos * sizeof(int));

    for (int i = 0; i < cantAlumnos; i++)
    {
        printf("Ingrese la nota del primer parcial del alumno numero %d \n",i+1);
        scanf("%f",&p_primerParcial[i]);
        printf("Ingrese la nota del segundo parcial del alumno numero %d \n",i+1);
        scanf("%f",&p_segundoParcial[i]);
        printf("Ingrese la nota del examen final del alumno numero %d \n",i+1);
        scanf("%f",&p_exFinal[i]);
        printf("Ingrese la nota del trabajo grupal del alumno numero %d \n",i+1);
        scanf("%f",&p_trabFinal[i]);
    }    

    for (int i = 0; i < cantAlumnos; i++)
    {
        p_notasFinales[i] = Calcular_Nota(&p_primerParcial[i], &p_segundoParcial[i], &p_exFinal[i], &p_trabFinal[i], &notaMenor);
    }

    for (int i = 0; i < cantAlumnos; i++)
    {
       printf("La nota final del alumnmo numero %d es de %.2f \n",i+1, p_notasFinales[i]);
    }

    if (cantAlumnos == 0)
    {
        printf("No se calcularan notas\n");
    } else {
        printf("La menor calificacion es de %.2f \n",notaMenor);
    }
    free(p_primerParcial);
    free(p_segundoParcial);
    free(p_exFinal);
    free(p_trabFinal);
    free(p_notasFinales);
    

    return 0;
}

float Calcular_Nota(float *p_primerParcial, float *p_segundoParcial, float *p_exFinal, float *p_trabFinal, float *p_notaMenor)
{   
    float valor, notaParciales, promParciales, porcFinal, porcTrabFinal;
    notaParciales = ((*p_primerParcial) + (*p_segundoParcial)) / 2;
    promParciales = (notaParciales * 55) / 100;
    porcFinal = ((*p_exFinal) *30 ) / 100;
    porcTrabFinal = ((*p_trabFinal) * 15) / 100;
    valor = promParciales + porcFinal + porcTrabFinal;
    if (valor < *p_notaMenor)
    {
        *p_notaMenor = valor;
    }    
    return valor;
}
