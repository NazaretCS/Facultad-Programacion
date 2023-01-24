/**
 
+++++++++++++++++++++++++++++++++++++++++   ALGORITMO PRINCIPAL   ++++++++++++++++++++++++++++++++++++++++++++

 ALGORITMO: Verdulería
 ENTRADAS: cantKilos, precioKilos, nproducto: reales
 SALIDAS: total, totalCompra, descuento, totalConDescuento: real
 VARAUX:  
 CONSTANTES: 
 
 A0. LEER(nproducto)
 A1. total, totalCompra,descuento,totalConDescuento <- 0
 A2. Calcular_Valores
 A3. PARAR

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


+++++++++++++++++++++++++++++++++++++++++++   REFINAMIENTOS   +++++++++++++++++++++++++++++++++++++++++++++++

A2. Calcular_Valores
    MIENTRAS (nproducto <> 0)
        LEER(cantKilos, precioKilos)
        CalculoVerduleria(cantKilos, precioKilos, &total, &totalCompra, &descuento, &totalConDescuento)
        ESCRIVIR(total,descuento,totalConDescuento)
        LEER(nproducto)
    FIN_MIENTRAS
    ESCRIVIR(totalCompra)

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    
++++++++++++++++++++++++++++++++++++++++++++++   FUNCIÓN   ++++++++++++++++++++++++++++++++++++++++++++++++++

    FUNCION: CalculoVerduleria
    ARGUMENTOS: cantKilos, precioKilos: reales
                *p_total, *p_totalCompra, *p_descuento: puntero a reales
    RESULTADO:
    VARAUX:  aux: entero         

  
    *p_total = cantKilos * precioKilos
    *p_totalCompra = *p_totalCompra + p_total
    SI (*p_totalCompra > 1000)
        *p_descuento <- ((*p_totalCompra) * 10 ) / 100
    SINO
        *p_descuento <- 0
    FIN_SI
    *p_totalConDescuento <- (*p_totalCompra) - (*p_descuento)
       
    FIN_FUNCIÓN   

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



*/

#include <stdio.h>
void CalculoVerduleria(float cantKilos, float precioKilos, float *p_total, float *p_totalCompra, float *p_descuento, float *p_totalConDescuento);

int main(void)
{   
    float cantKilos=0, precioKilos=0, total=0, totalCompra=0, descuento=0, totalConDescuento=0;
    int nproducto;
    printf("Desea ingresar un producto, marque 0 para no, y 1 para si  \n");
    scanf("%c",&nproducto);
    while (nproducto != '0')
    {
       printf("Ingrese la cantidad de kilos que lleva del producto \n") ;
       scanf("%f",&cantKilos);
       printf("Ingrese el precio por kilos del producto \n") ;
       scanf("%f",&precioKilos);
       CalculoVerduleria(cantKilos, precioKilos, &total, &totalCompra, &descuento, &totalConDescuento);
       printf("----------   RECIVO DEL PRODUCTO   -------- \n\n");
       printf("Total del producto -------------- %f \n",total);
       printf("Descuento ----------------------- %f \n",descuento);
       printf("Total Con Descuento ------------- %f \n\n",totalConDescuento);
       fflush(stdin);
       printf("Desea ingresar un producto, marque 0 para no, y distinto de 0 para si  \n");
       scanf("%c",&nproducto);
      
    }
    printf("Total final abonar ------------ %.2f \n",totalCompra);
    
    return 0;
}

void CalculoVerduleria(float cantKilos, float precioKilos, float *p_total, float *p_totalCompra, float *p_descuento, float *p_totalConDescuento)
{
    *p_total = cantKilos * precioKilos;
    if ( *p_total > 1000 )
    {
        *p_descuento = ((*p_total) * 10 ) / 100;
    } else {
        *p_descuento = 0;
    }
    *p_totalConDescuento = (*p_total) - (*p_descuento);
    *p_totalCompra = (*p_totalCompra) + (*p_totalConDescuento);

}