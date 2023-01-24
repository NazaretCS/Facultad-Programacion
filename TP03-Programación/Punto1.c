/*
Integrantes del grupo 5--------------

>Bobadilla, Juan Pablo.---------------
>Buahl, Paula Florencia.--------------
>Campos, Nestor Nazaret.---------------
*/


/*
    ALGORITMO: Horas
    ENTRADAS: horas, minutos, segundos: entro(+)
    SALIDA: CantSeg: Entero(+).
            cc:Cadena de caracteres
    VAR AUX: horasSegundos, minutosSegundos: enteros(+)

    A1. Leer (horas, minutos, segundos)
    A2. Verifica_Datos
    A3. Calcular_Segundos
    A4. Mostrar (CantSeg)
    A5. Parar


    A2. Verificar_Datos
            MIENTRAS (horas>23 o horas<0)
                ESCRIVIR (hora mal ingresada, trate de nuevo)
                LEER (hora)
            FIN_MIENTRAS
            MIENTRAS (minutos>=60 o minutos<0)
                ESCRIVIR (minutos mal ingresados, trate de nuevo)
                LEER (minutos)
            FIN_MIENTRAS
            MIENTRAS (segundos>=60 o Segundos<0)
                ESCRIVIR (Segundos mal ingresados, trate de nuevo)
                LEER (segundos)
            FIN_MIENTRAS


    A3. Calcular_Segundos
        horasSegundos <- horas * 3600
        minutosSegundos <- minutos * 60
        CantSeg <- horasSegundos + minutosSegundos + segundos

*/

#include <stdio.h>
#include <unistd.h>

int main (){
    int horas, minutos, segundos, cantSeg, horasSeg, minutosSeg;

    //Bien ingreso los datos verifico que sean los correctos:
    printf("Especifique la Hora: ");
    scanf ("%d",&horas);

    while (horas>23 || horas<0)
    {
        printf("Hora mal especificada, intente de nuevo: ");
        scanf("%d",&horas);
    }

    printf("Especifique los Minutos: ");
    scanf ("%d",&minutos);

    while (minutos>=60 || minutos<0)
    {
        printf("Minutos mal especificados, intente de nuevo: ");
        scanf("%d",&minutos);
    }
    printf("Especifique los Segundos: ");
    scanf ("%d",&segundos);

     while (segundos>=60 || segundos<0)
    {
        printf("Segundos mal especificados, intente de nuevo: ");
        scanf("%d",&segundos);
    }

    //Ahora que se que mis datos son correctos realizo las operaciones con los mimso
    horasSeg = horas * 3600;
    minutosSeg = minutos * 60;
    cantSeg = horasSeg + minutosSeg + segundos;
    printf("Su tiempo, en segundos, es ( %d ).\n",cantSeg);
    
    sleep(5);
    return 0;
    
    
}