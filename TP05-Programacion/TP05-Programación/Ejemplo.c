/**
++++++++++++++++++++++++++++++++++  ALGORITMO PRICNIPAL  +++++++++++++++++++++++++++++++++++++++++++++++++++++++ 

PROGRAMA: FIEBRE_DE_DESCUENTOS
ENTRADAS: montoBasePrenda: Entero
          categoria (1=invierno, 2=verano, 3=Multiestacion): Real
          formaPago (1=efectivo, 2=Débito, 3=Targeta de crédito)
          mesCompra (1= Enero, 2=Febrero, 3=Marso, 4=Abril, 5=mayo, 6=Jumio, 7=Julio, 8=Agosto, 9=Septiembre, 10=Octubre, 11=Noviemre, 12=Diciembre): Entero.
SALIDAS: totaPagar: Real.
VARAUX: descontar1, descontar2:enteros
CONSTANTES:

A1. LEER (montoBasePrenda, categoria, formaPago, mesCompra)
A2. Verificar_Datos.
A3. Calcular_Monto
A4. ESCRIVIR (totalPagar)
A5. PARAR

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


+++++++++++++++++++++++++++++++++++++  REFINAMIENTOs  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

A2. Verificar_Datos.
MIENTRAS (montBasePrenda < 0)
    LEER (montoBasePrenda)
FIN_MIENTRAS
MIENTRAS (categoria < 1 || categoria > 3)
    LEER (categoria)
FIN_MIENTRAS
MIENTRAS (formaPago < 1 || formaPago > 3)
    LEER (formaPago)
FIN_MIENTRAS
MIENTRAS (mesCompra < 1 || mesCompra > 12)
    LEER (mesCompra)
FIN_MIENTRAS

A3. Calcular_Monto
    SI (categoria = 1)
        SI (mesCompra = 9 || mesComra = 10 || mesComra = 11 || mesComra = 12 || mesComra = 1 || mesComra = 2 || mesComra = 3)
            descontar1 = Calc_Descuento(montoPrenda, categoria)
        FIN_SI
    FIN_SI
    SI (categoria = 2)
        SI (mesCompra = 4 || mesCompra = 5 || mesCompra = 6 || mesCompra = 7 || mesCompra = 8)
            descontar1 = Calc_Descuento_Por_Categoria(montoPrenda, categoria)
        FIN_SI
    FIN_SI
    SI (categoria = 3)
        descontar1 = Calc_Descuento(montoPrenda, categoria)
    FIN_SI

    descontar2 = Calc_Descuento_Por_Pago(formaPago)

    SEGUN (formaPago)
        formaPago = 1:  totalPagar = montoBasePrenda - descontar1 - decontar2
        formaPago = 2:  totalPagar = montoBasePrenda - descontar1 - decontar2
        formaPago = 3:  totalPagar = montoBasePrenda - descontar1 + decontar2
    FIN_SEGUN

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

+++++++++++++++++++++++++++++++++++++++++  FUNCIONES  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

FUNCION: Calc_Descuento_Por_Categoria
ARGUMENTOS: montoPrenda, categoria: Entero.
RESULTADO: Real.
VARAUX: 
COSTANTES: descuentoInvierno% = 30, descuentoVerano% = 35, decuentoMultiestacion% = 20.

SEGUN (categoria)
    categoria = 1: Calc_DescuentoPor_Categoria <- (montoPrenda * Inviero) / 100
    categoria = 2: Calc_DescuentoPor_Categoria <- (montoPredna * Verano) / 100
    categoria = 3: Calc_DescuentoPor_Categoria <- (montoPrenda * Multiestacion) / 100
FIN_SEGUN
FIN_FUNCIÓN


FUNCION: Calc_Descuento_Por_Pago
ARGUMENTOS: formaPago, montoBasePrenda: Entero.
RESULTADO: Real.
VARAUX:  

SEGUN (formaPago)
    Calc_Descuento_Por_Pago = 1: Calc_Descuento <- (montoPrenda * 10) / 100
    Calc_Descuento_Por_Pago = 2: Calc_Descuento <- (montoPredna * 5) / 100
    Calc_Descuento_Por_Pago = 3: Calc_Deceunto <- (montoPrenda * 5) / 100
FIN_SEGUN
FIN_FUNCIÓN

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

*/
/*
#include<stdio.h>

float Calc_Descuento_Por_Pago(int formaPago, int montoBasePrenda);
float Calc_Descuento_Por_Categoria (int montoBasePrenda, int categoria);


int main(void){
    int montoBasePrenda, categoria, formaPago, mesCompra;
    float descontar1, descontar2, totalPagar;

    printf("Ingrese el precio de la prenda: \n");
    scanf("%d", &montoBasePrenda);
    printf("Ingrese la categoria de la prenda (1 para categoria de invierno, 2 para verano y 3 para prendas multicategoria)\n");
    scanf("%d", &categoria);
    printf("Indique su forma de pago, ( 1 ) para efectivo, ( 2 ) para Débito, o ( 3 ) para Targeta de Credito\n");
    scanf("%d", &formaPago);
    printf("Indique el mes (numerico) en el que realizo la compra: \n");
    scanf("%d", &mesCompra);




    while (montoBasePrenda < 0)
    {
        printf("El precio ingresado no corresponde, por favor intente de nuevo \n");
        printf("Ingrese el precio de la prenda: \n");
        scanf("%d",&montoBasePrenda);
    }

    while (categoria < 1 || categoria > 3)
    {
        printf("La categoria seleccionada no es correcta, por favor intente de nuevo \n");
        printf("Ingrese la categoria de la prenda (1 para categoria de invierno, 2 para verano y 3 para prendas multicategoria)\n");
        scanf("%d", &categoria);
    }

    while (formaPago < 1 || formaPago > 3)
    {
        printf("La forma de pago ingresada no corresponde a lo solicitado, por favor intete de nuevo \n");
        printf("Indique su forma de pago, ( 1 ) para efectivo, ( 2 ) para Débito, o ( 3 ) para Targeta de Credito\n");
        scanf("%d", &formaPago);
    }

    while (mesCompra < 1 || mesCompra > 12)
    {
        printf ("El dato correspondiente al mes no se reconoce, por favor ingreslo de nuevo \n");
        printf("Indique el mes (numerico) en el que realizo la compra: \n");
        scanf("%d", &mesCompra);
    }
    
    if (categoria == 1)
    {
        if ( mesCompra == 9 || mesCompra == 10 || mesCompra == 11 || mesCompra == 12 || mesCompra == 1 || mesCompra == 2 || mesCompra == 3)
        {
            descontar1 = Calc_Descuento_Por_Categoria(montoBasePrenda, categoria);
        }  
    }
    if (categoria == 2)
    {
        if (mesCompra == 4 || mesCompra == 5 || mesCompra == 6 || mesCompra == 7 || mesCompra == 8)
        {
            descontar1 = Calc_Descuento_Por_Categoria(montoBasePrenda, categoria);
        }
    }
    if (categoria == 3)
    {
        descontar1 = Calc_Descuento_Por_Categoria(montoBasePrenda, categoria);
    }
    
    descontar2 = Calc_Descuento_Por_Pago(formaPago, montoBasePrenda);

    switch (formaPago)
    {
    case 1:
        totalPagar = montoBasePrenda - descontar1 - descontar2;
        printf("Su Total a Pagar es %.2f",totalPagar);
        break;
    case 2:
        totalPagar = montoBasePrenda - descontar1 - descontar2;
        printf("devera avonar %.2f",totalPagar);
        break;
    case 3:
        totalPagar = montoBasePrenda - descontar1 + descontar2; 
        printf("Usted deve pagar %.2f",totalPagar);  
    }
    
    
    
    return 0;
}

float Calc_Descuento_Por_Categoria (int montoBasePrenda, int categoria)
{
    float descuento;
    switch (categoria)
    {
    case 1:
        descuento = (montoBasePrenda * 30) / 100;
        break;
    case 2:
        descuento = (montoBasePrenda * 35) / 100;
        break;
    case 3: 
        descuento = (montoBasePrenda * 20) / 100;
        break;
    }
    return(descuento);
}

float Calc_Descuento_Por_Pago(int formaPago, int montoBasePrenda)
{
    float descuento;
    switch (formaPago)
    {
    case 1:
        descuento = (montoBasePrenda * 10) / 100;
        break;
    case 2:
        descuento = (montoBasePrenda * 5) / 100;
        break;
    case 3:
        descuento = (montoBasePrenda * 5) / 100;
        break;
    }
    return(descuento);
}   
*/



#include <stdio.h>
#include <string.h>
#define MAX 50 

int main(void)
{   
    char caracter;
    for (int i = 32; i <= 126; i++)
    {
        caracter=i;
        printf("El caracater es: *%c* y el numero que le corresponde es: %d \n",caracter,i);
    }
    
    return 0;
}