#include <stdio.h>
#include <unistd.h>

struct FECHANACIMIENTO
{
    int dia;
    int mes;
    int anio;
}typedef FECHANACIMIENTO;

struct BANCARIA
{
    char cbu[150];
    float saldo;
}typedef BANCARIA;

struct DATOS
{
    char apellido[100];
    char nombre[100];
    char dni[8];
    FECHANACIMIENTO fecNac;
    char contrasenia[100];
    BANCARIA cuenta;
}typedef DATOS;

int main(void)
{   
    
    /* ***************************   INICIOALIZO LAS VARIABLES DE LAS ESTRUCTURAS   *************************** */
    DATOS cliente;
    char nombre[16]="Nestor Nazaret", apellido[7]="Campos", dni[9]="43709119", contrasenia[9]="24mayo09", cbu[15]="00000000004502";
    for (int i = 0; i < 7; i++)
    {
        cliente.apellido[i] = apellido[i];
    }
    for (int i = 0; i < 16; i++)
    {
        cliente.nombre[i] = nombre[i];
    }
    for (int i = 0; i < 9; i++)
    {
        cliente.dni[i] = dni[i];
    }
    for (int i = 0; i < 9; i++)
    {
        cliente.contrasenia[i] = contrasenia[i];
    }
    for (int i = 0; i < 15; i++)
    {
        cliente.cuenta.cbu[i] = cbu[i];
    }
    cliente.fecNac.dia = 28;
    cliente.fecNac.mes = 9;
    cliente.fecNac.anio = 2001;

    cliente.cuenta.saldo = 50000;  

    /* ******************************************************************************************************** */


    int salir=0,accion,bandera=0;    
    float aux1, aux2;

    while(salir == 0)
    {
        printf("\n**************************     MENU    *************************\n\nIndique mediante los numeros de referencia la accion que desea realizar\n\n");
        printf("1...Cambiar Clave\n2...Depositar un Monto\n3...Retirar Dinero\n4...Consultar Saldo\n5...Mostrar Datos de la Cuenta\n6...Salir\n");
        printf("\n****************************************************************\n");
        scanf("%d",&accion);
        if (accion == 6)
        {
            salir = 1;
        }

        if (accion == 1)
        {   
            printf("\n\n+++++++++   CAMBIAR CLAVE   +++++++++\n\n");
            do 
            {
                printf("Seguro que desea establecer una nueva clave\? (1 para si, 0 para no)\n");
                scanf("%d",&accion);
                if (accion == 1 || accion == 0)
                {
                    bandera = 1;
                }  else {
                    bandera = 0;
                    printf("Deve seleccionara una opcion valida (0 o 1), por favor intente de nuevo\n");
                }                
            } while(bandera==0);
            if (accion == 0)
            {
                salir = 0;
            }
            if (accion == 1)
            {
                
                printf("Ingrese la nueva clave:\n");
                fflush(stdin);
                gets(cliente.contrasenia);
                printf("Se genero la clave\n\n");
                bandera = 0;
                sleep(5);
            }
            
        }

        if(accion ==2){
            printf("\n\n+++++++++   DEPOSITAR   +++++++++\n\n");
            do 
            {
                printf("Seguro que desea depositar dinero\? (1 para si, 0 para no)\n");
                scanf("%d",&accion);
                if (accion == 1 || accion == 0)
                {
                    bandera = 1;
                }  else {
                    bandera = 0;
                    printf("Deve seleccionara una opcion valida (0 o 1), por favor intente de nuevo\n");
                }                
            } while(bandera==0);
            if (accion == 0)
            {
                salir = 0;
            }
            if (accion == 1)
            {
                
                printf("Ingrese la cantidad que desea depositar en la cuenta:\n");
                fflush(stdin);
                scanf("%f",&aux1);
                aux2 = cliente.cuenta.saldo;                
                cliente.cuenta.saldo = cliente.cuenta.saldo + aux1;
                if (aux2 < cliente.cuenta.saldo)
                {
                    printf("Se realizo la operacion con exito\n\n");
                    printf("Saldo anterior %.2f\n",aux2);
                    printf("Saldo actual %.2f\n\n",cliente.cuenta.saldo);
                }
                bandera = 0;                
                sleep(5);
                salir = 0;
            }
        }

        if (accion == 3)
        {
            printf("\n\n+++++++++   EXTRACCIONES   +++++++++\n\n");
            do 
            {
                printf("Seguro que desea extraer dinero\? (1 para si, 0 para no)\n");
                scanf("%d",&accion);
                if (accion == 1 || accion == 0)
                {
                    bandera = 1;
                }  else {
                    bandera = 0;
                    printf("Deve seleccionara una opcion valida (0 o 1), por favor intente de nuevo\n");
                }                
            } while(bandera==0);
            if (accion == 0)
            {
                salir = 0;
            }
            if (accion == 1)
            {
                printf("Saldo actual %.2f\n",cliente.cuenta.saldo);
                printf("Ingrese la cantidad que desea extraer de la cuenta:\n");
                fflush(stdin);
                scanf("%f",&aux1);
                aux2 = cliente.cuenta.saldo; 
                while (aux2<aux1)
                {
                    printf("No tiene el saldo suficiente para realizar esta operacion, por favor intente ingresar otro monto\n");
                    printf("Ingrese la cantidad que desea extraer de la cuenta (para no realizar la extraccion ingrese 0)\n");                   
                    scanf("%f",&aux1);
                }                               
                cliente.cuenta.saldo = cliente.cuenta.saldo - aux1;
                if (aux2 > cliente.cuenta.saldo)
                {
                    printf("Se realizo la operacion con exito\n\n");
                    printf("Saldo anterior %.2f\n",aux2);
                    printf("Saldo actual %.2f\n\n",cliente.cuenta.saldo);
                }
                bandera = 0;                
                sleep(5);
                salir = 0;
            }

            
            

        }
        if (accion == 4)
        {
            printf("\n\n+++++++++   SALDOS   +++++++++\n\n");
            printf("Sr. ");
            puts(cliente.apellido);
            printf("En su cuenta, actualmente, alverga %.2f \n",cliente.cuenta.saldo);
            sleep(10);
            salir = 0;
        }
        if (accion == 5)
        {
            printf("\n\n+++++++++   DATOS DE LA CUENTA   +++++++++\n\n");
            printf("Sr: ");
            puts(cliente.apellido);
            printf("    ");
            puts(cliente.nombre);
            printf("\nSu correspondiente CBU es: \n");
            puts(cliente.cuenta.cbu);
            sleep(20);                       
            salir = 0;
        }
        
        
    }
    
}

