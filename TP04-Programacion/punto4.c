/**
++++++++++++++++++++++++++++++++++++++++  Algoritmo Principal  ++++++++++++++++++++++++++++++++++++++++++

ALGORITMO:
ENTRADAS: coordenada: entero largo.
SALIDAS: cc: cadena de caracteres.
		 coordenadax, coordenaday: enteros.
VARAUX: X, Y, punto: Entero.
CONSTANTES:

A1. LEER (coordenada)
A2. Verificar_Coordenada.
A3. Procesar_Coordenada.
A5. PARAR.

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

++++++++++++++++++++++++++++++++++++++++++  Refinamientos +++++++++++++++++++++++++++++++++++++++++++++++
A2. Verificar_Coordenada.
 MIENTRAS (coordenada < 1.000.000 && coordenada >10000000)
			LEER(coordenada)
 FIN_MIENTRAS


A3. Procesar_Coordenada.
   x <- (coordenada/10000)
   y <- RESTO(coordenada/10000) 

   Procesar_Digito(coordenada) 
   coordenadax <- Desifrar_Coordenada(x)
   coordenaday <- Desifrar_Coordenada(y)
   ESCRIVIR (coordenadax,coordenaday)

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

++++++++++++++++++++++++++++++++++++++++++++++  Funciones +++++++++++++++++++++++++++++++++++++++++++++++

	FUNCION: Procesar_Digito
	AGUMENTOS: punto: Enero
	SALIDA: Entero
	VARAUX:
 
	punto <- RESTO(coordenada/1000)/10 
    SI (punto=0)
		puntoMedio <- 0
    SINO SI (RESTO(punto/2)=0)
			puntoMedio <- 1
		SINO
			puntoMedio <- 2
		FIN_SI
    FIN_SI
 
	SEGUN (puntoMedio)
				puntoMedio = 0: ESCRIVIR(Proviciones en el Punto)
				puntoMedio = 1: ESCRIVIR(Se realizara un ataque en la coordenada)
				puntiMedio = 2: ESCRIVIR(Se realizara un reagrupamiento defensivo en la.coordenada)
	FIN_SEGUN.


	FUNCION: Desifrar_Coordenada
	ARGUMENTOS: valor: Entero.
	SALIDA: Entero.
	VARAUX: primerDigito, segundoDigito, tercerDigito: Entero

	primerDigito <- (valor/100)//Divicion entera
	segundoDigito <- RESTO((valor/10)/10)
	tercerDigito <- RESTO(valor/10)
	SI (primerDiguito = 0)
		Desifrar_Coordenada <- 0
    SINO SI (RESTO(primerDigito/2)=0)
			Desifrar_Coordenada <- primerDigito * segundoDigito
		SINO
			Desifrar_Coordenada <- primerDigito + segundoDigito
		FIN_SI
    FIN_SI

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

*/

#include<stdio.h>
void Procesar_Digito(long int coordenada);
int Desifrar_Coordenada (int valor);

int main(void)
{
	long int coordenada;
	int coordenadax, coordenaday, x, y;

	printf("Ingrese la coordenada: \n");
	scanf("%d", &coordenada);



	while (coordenada < 1000000 || coordenada > 10000000 )
	{
		printf("coordenada mal ingresada, se esperaba un numero de 7 diguitos, por favor intente de nuevo \n");
		printf("Ingrese la coordenada: \n");
		scanf("%d", &coordenada);
	}

	x = coordenada / 10000;
	y = coordenada % 1000;
	printf("primeros 3 diguitos: %d\n",x);
	printf("segundos 3 diguitos: %d\n",y);

	Procesar_Digito(coordenada); 

	coordenadax = Desifrar_Coordenada(x);
   	coordenaday = Desifrar_Coordenada(y);
	printf(" %d:%d \n",coordenadax,coordenaday);
	
	return 0;
}

void Procesar_Digito(long int coordenada)
{
	int punto, puntoMedio;
	punto = (coordenada/1000)%10;
	printf("el numero de en medio es: %d\n",punto);
	if (punto == 0)
	{
		puntoMedio = 0;
	} else
	{
		if ( (punto%2) == 0)
		{
			puntoMedio = 1;
		} else
		{
			puntoMedio = 2;
		}
	}
	switch (puntoMedio)
	{
	case 0:
		printf("Proviciones en el Punto");
		break;
	case 1:
		printf("Se realizara un ataque en la coordenada");
		break;
	case 2:
		printf("Se realizara un reagrupamiento defensivo en la coordenada");
		break;
	}
	
}

int Desifrar_Coordenada (int valor)
{
	int primerDigito, segundoDigito, tercerDigito, retorno;
	primerDigito = (valor / 100);
	segundoDigito = ((valor/10) % 10);
	tercerDigito = (valor%10);
	if (primerDigito == 0)
	{
		retorno = 0;
	} else
	{
		if ((primerDigito%2) == 0)
		{
			retorno = primerDigito * segundoDigito;
		} else
		{
			retorno = primerDigito + segundoDigito;
		}
	}
	return(retorno);
	
}





 