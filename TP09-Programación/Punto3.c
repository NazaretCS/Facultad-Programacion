#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX 200
#define ANIO 2021
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


void CargarCuentas(DATOS *p_cliente, int *p_cant);
void MostrarDatos(DATOS *p_cliente, int *p_cant);
void OperacionCliente(DATOS *p_cliente, int *p_numeroCliente, DATOS *p_aux, int *p_cant);
void RealizarTrasferencia(DATOS *p_aux, int *p_montoTrasferir);
int main(void)
{   
    DATOS cliente[200], *p_cliente, *p_aux;
    int cant, clienteaOperar, accion=2342, bandera=0;  // a accion le tuve que dar un valor como ese ya que al parecer en la porcion de memoria que le correspondia habia justo un 0, razon por la cual nunca me entraba en el while de la linea 49

    printf("Ingrese la cantida de clientes que desea Cargar\n");
    scanf("%d",&cant);
    fflush(stdin);
    
    p_cliente = cliente;
    p_cliente = malloc(cant * sizeof(DATOS));
    
    p_aux = p_cliente;
    CargarCuentas(p_aux, &cant);


    while(accion != 0)
    {   

        printf("\n=============   M  E  N  U     P  R  I  N  C I  P  A  L =================\n\nIndique mediante los numeros de referencia la accion que desea realizar\n\n");
        while(bandera==0)
        {
            
            printf("1.... Mostrar Datos de los Clientes\n2.... Seleccionar Cliente para Operar\n3.... Salir del Programa\n");
            scanf("%d",&accion);
            if(accion == 1 || accion == 2 || accion == 3)
            {
                bandera = 1;
            } else {
                bandera = 0;
                printf("El numero ingresado no corresponde a ninguna accion, por favor intente nuevamente\n");
            }
            printf("\n==========================================================================\n");
        }
        
        
        if(accion == 1)
        {   
            //printf("LLego askldnkjnksdsjdksjdkjsdkjaskdljkasjd");
            p_aux = p_cliente;
            MostrarDatos(p_aux, &cant);
            sleep(12);
        }

        if(accion == 2)
        {
            printf("\nIngrese el cliente que desea operar: ");
            scanf("%d",&clienteaOperar);
            p_aux = p_cliente;
            OperacionCliente(&p_aux[clienteaOperar-1], &clienteaOperar, p_aux, &cant);
            p_aux = p_cliente;
        }

        if(accion == 3)
        {
            accion = 0;
            printf("Esta Saliendo del banco");
        }
        bandera = 0;
    }
    return 0;
}


void CargarCuentas(DATOS *p_cliente, int *p_cant)
{
    int bandera=0;
    for(int i=0 ; i < *p_cant ; i++)
    {
        printf("\n------------------------   CARGADO DE CUENTA = Cliente %d   ------------------\n",i+1);
        printf("Ingrese El apellido del Cliente:\n");
        gets(p_cliente->apellido);
        printf("Ingrese El nombre del Cliente\n");
        gets(p_cliente->nombre);
        printf("Ingrese El DNI del Cliente\n");
        gets(p_cliente->dni);
        printf("Ingrese la fecha de nacimiento del CLiente\n  Dia: ");
        scanf("%d",&p_cliente->fecNac.dia);
        fflush(stdin);
        
        while (bandera == 0)
        {
            if (p_cliente->fecNac.dia > 0 || p_cliente->fecNac.dia <= 31)
            {
                bandera = 1;
            } else {
                printf("Dia mal ingresado, se solicita ingresar un valor no menor de 1 y menor de 31");
                printf("\n  Dia: ");
                scanf("%d",&p_cliente->fecNac.dia);
                fflush(stdin);
                bandera = 0;
            }
        }
        bandera = 0;
        printf("  Mes: ");
        scanf("%d",&p_cliente->fecNac.mes);
        while (bandera == 0)
        {
            if (p_cliente->fecNac.mes > 0 || p_cliente->fecNac.mes <= 12)
            {
                bandera = 1;
            } else {
                printf("Mes mal ingresado, se solicita ingresar un valor no menor de 1 y menor de 12");
                printf("\n  Mes: ");
                scanf("%d",&p_cliente->fecNac.mes);
                fflush(stdin);
                bandera = 0;
            }
        }
        bandera = 0;

        printf("  Year: ");
        scanf("%d",&p_cliente->fecNac.anio);
        fflush(stdin);
        while (bandera == 0)
        {
            if (p_cliente->fecNac.anio > 1900 || p_cliente->fecNac.anio <= ANIO)
            {
                bandera = 1;
            } else {
                printf("Anio mal ingresado, se solicita ingresar un valor logicamente aceptable\n");
                printf("\n  Year: ");
                scanf("%d",&p_cliente->fecNac.anio);
                fflush(stdin);
                bandera = 0;
            }
        }
        bandera = 0;

        printf("Ingrese la clave de la cuenta\n");
        gets(p_cliente->contrasenia);
        fflush(stdin);

        printf("Ingrese el CBU de la cuenta\n");
        gets(p_cliente->cuenta.cbu);
        fflush(stdin);

        printf("Ingrese el saldo de la cuenta\n");
        scanf("%f",&p_cliente->cuenta.saldo);
        fflush(stdin);
        p_cliente++;
        printf("\n-------------------------------------------------------------------------------\n");
    }

}


void MostrarDatos(DATOS *p_cliente, int *p_cant)
{
    for(int j=0; j<*p_cant;j++)
    {   
        printf("\n----------------------   MUESTRA DE DATOS DE LOS CLIENTES = Cliente %d  ----------------------\n\n",j+1);
        printf("Apellido:                          ");
        puts(p_cliente->apellido);
        printf("Nombre:                            ");
        puts(p_cliente->nombre);
        printf("DNI:                               ");
        puts(p_cliente->dni);
        printf("Fecha de Nacimiento:               %d/%d/%d",p_cliente->fecNac.dia, p_cliente->fecNac.mes, p_cliente->fecNac.anio);
        printf("\n\nDATOS DE LA CUENTA--------------------\n");
        printf("Clave de la cuenta                 ");
        puts(p_cliente->contrasenia);
        printf("CBU                                ");
        puts(p_cliente->cuenta.cbu);
        printf("Saldo de la cuenta:                %.2f",p_cliente->cuenta.saldo);
        printf("\n----------------------------------------\n");       


        printf("-----------------------------------------------------------------------------------------------------\n\n");
        p_cliente++;
    }
}


void OperacionCliente(DATOS *cliente, int *p_numeroCliente, DATOS *p_aux, int *p_cant)
{
    int salir=0,accion,bandera=0;    
    float aux1, aux2;
    while(salir == 0)
    {
        printf("\n**************************     MENU DEL CLIENTE  [%d]   *************************\n\nIndique mediante los numeros de referencia la accion que desea realizar\n\n", (*p_numeroCliente));
        printf("1...Cambiar Clave\n2...Depositar un Monto\n3...Retirar Dinero\n4...Transferiri dinero a otro cliente del banco\n5...Consultar Saldo\n6...Mostrar Datos de la Cuenta\n7...Volver al menu principal\n");
        printf("\n*******************************************************************************\n");
        scanf("%d",&accion);
        if (accion == 7)
        {
            salir = 1;
            printf("Regrasara al menu principal\n");
            fflush(stdin);
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
                gets(cliente->contrasenia);
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
                aux2 = cliente->cuenta.saldo;                
                cliente->cuenta.saldo = cliente->cuenta.saldo + aux1;
                if (aux2 < cliente->cuenta.saldo)
                {
                    printf("Se realizo la operacion con exito\n\n");
                    printf("Saldo anterior %.2f\n",aux2);
                    printf("Saldo actual %.2f\n\n",cliente->cuenta.saldo);
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
                printf("Saldo actual %.2f\n",cliente->cuenta.saldo);
                printf("Ingrese la cantidad que desea extraer de la cuenta:\n");
                fflush(stdin);
                scanf("%f",&aux1);
                aux2 = cliente->cuenta.saldo; 
                while (aux2<aux1)
                {
                    printf("No tiene el saldo suficiente para realizar esta operacion, por favor intente ingresar otro monto\n");
                    printf("Ingrese la cantidad que desea extraer de la cuenta (para no realizar la extraccion ingrese 0)\n");                   
                    scanf("%f",&aux1);
                }                               
                cliente->cuenta.saldo = cliente->cuenta.saldo - aux1;
                if (aux2 > cliente->cuenta.saldo)
                {
                    printf("Se realizo la operacion con exito\n\n");
                    printf("Saldo anterior %.2f\n",aux2);
                    printf("Saldo actual %.2f\n\n",cliente->cuenta.saldo);
                }
                bandera = 0;                
                sleep(5);
                salir = 0;
            }

            
            

        }

        if(accion ==4)
        {
            int usuarioaTrasnferir, montoTrasferir;
            do 
            {
                printf("Ingrese el numero correspondiente al usuario que le quiere trasferir (actualemte hay %d usuarios): ",*p_cant);
                scanf("%d",&usuarioaTrasnferir);
                if (usuarioaTrasnferir <= *p_cant)
                {
                    bandera = 1;
                }  else {
                    bandera = 0;
                    printf("\nEl usuario solicitado no existe, por favor controle que el usuario al cual le quiera realizar la trasferencia no sea mayo a %d, que es la cantidad de usuarios que el banco posee actualemte\n", *p_cant);
                }                
            } while(bandera==0);

            bandera=0;
            do 
            {
                printf("Ingrese el monto que desea transferir: ");
                scanf("%d",&montoTrasferir);
                if (montoTrasferir <= cliente->cuenta.saldo )
                {
                    bandera = 1;
                    printf("Saldo disponible, se procedera a hacer la trasferecnia\n");
                }  else {
                    bandera = 0;
                    printf("\nNo posee el saldo suficiente en la cuenta como para realizar esta trasferencia, pr favor ingrese un nuevo monto a trasferir\nEn caso de querer canselar ingrese el valor 0\n");
                }                
            } while(bandera==0);

            cliente->cuenta.saldo = cliente->cuenta.saldo - montoTrasferir;
            
            RealizarTrasferencia(&p_aux[usuarioaTrasnferir-1], &montoTrasferir);
            sleep(5);
            bandera=0;
        }

        if (accion == 5)
        {
            printf("\n\n+++++++++   SALDOS   +++++++++\n\n");
            printf("Sr. ");
            puts(cliente->apellido);
            printf("En su cuenta, actualmente, alverga %.2f \n",cliente->cuenta.saldo);
            sleep(10);
            salir = 0;
        }
        if (accion == 6)
        {
            printf("\n\n+++++++++   DATOS DE LA CUENTA   +++++++++\n\n");
            printf("Sr: ");
            puts(cliente->apellido);
            printf("    ");
            puts(cliente->nombre);
            printf("\nSu correspondiente CBU es: \n");
            puts(cliente->cuenta.cbu);
            sleep(10);                       
            salir = 0;
        }
        
        
    }
}



void RealizarTrasferencia(DATOS *p_aux, int *p_montoTrasferir){
    p_aux->cuenta.saldo = p_aux->cuenta.saldo + *p_montoTrasferir;
}