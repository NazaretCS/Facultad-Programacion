/**
++++++++++++++++++++++++++++++++++++++++++++++  ALGORITMO PRINCIPAL  ++++++++++++++++++++++++++++++++++++++++++++

 PROGRAMA: Verificador_De_Contraseñas 
 ENTRADAS: contraseña: cadena de caracteres con Marca final en un punto "."
 SALIDAS: cc: cadenad de caracetres
 VARAUX: contadorCaracteres, contieneMinuscula, contieneMayuscula, contieneNumero, contieneCaracterEspecial: Entero.

 A1. LEER(contraseña)
 A2. Verificar_Contraseña
 A3. PARAR

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


++++++++++++++++++++++++++++++++++++++++++++++++  Refinamiento  +++++++++++++++++++++++++++++++++++++++++++++++++
 A2. Verificar_Contraseña
    MIENTRAS (contraseña <> ".")
        contadorCaracteres <- contadorCaracteres + 1
        SI (Minuscula(contraseña))    // --------> Función de Biblioteca que me asegura si mi caracter es minuscula
            contieneMinuscula <- 1
        FIN_SI
        SI (Matuscula(contraseña))   // --------> Función de Biblioteca que me asegura si mi caracter es mayuscula
            contieneMayuscula <- 1
        FIN_SI
        SI (EsNumero(contraseña)) // --------> Función de Biblioteca que me asegura si mi caracter es un numero
            contieneNumero <- 1
        FIN_SI
        SI (EsCaracterEspecial(contraseña)) // --------> Función predefinida
            contieneCaracterEspecial <- 1
        FIN_SI
        LEER(contraseña)
    FIN_MIENTRAS

    SI (contadorCaracteres >= 8 && contadorCaracteres <= 16)
        SI (contieneMinuscula=1 && contieneMayuscula=1 && contieneNumero=1 && contieneCaracterEspecial=1)
            ESCRIVIR(La contraseña es Valida)
        SINO
            ESCRIVIR(La contraseña es Invalida)
        FIN_SI
    SINO 
        ESCRIVIR(La contraseña es Invalida)
    FIN_SI

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


+++++++++++++++++++++++++++++++++++++++++++++++++  Función  +++++++++++++++++++++++++++++++++++++++++++++++++++++
   
    FUNCION: contieneCaracterEspecial
    ARGUMENTOS: caracter: caracter
    SALIDA: Verdadero o Falso
    VARAUX:

    SI (contraseña ='!' || contraseña ='@' || contraseña ='#' || contraseña ='$' || contraseña ='%' || contraseña ='&' || contraseña ='/' || contraseña ='(' || contraseña =')' || contraseña ='=' || contraseña ='?' || contraseña ='¡' || contraseña ='¿' || contraseña ='*' || contraseña ='+' || contraseña ='-' || contraseña ='\' || contraseña ='{' || contraseña ='}' || contraseña ='[' || contraseña =']' || contraseña ='<' || contraseña ='>' || contraseña ='|' || contraseña ='°' || contraseña ='¬' || contraseña ='_' || contraseña ='-' || contraseña =';' || contraseña =':' || contraseña ='!' ||)
        contieneCaracterEspecial <- Verdadero
    SINO
        contieneCaracterEspecial <- Falso
    FIN_SI
    FIN_FUNCIÓN

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/


#include<stdio.h>
#include<ctype.h>

int main(void){
    char contrasena; 
    int contadorCaracteres, contieneMinuscula, contieneMayuscula, contieneNumero, contieneCaracterEspecial;
    printf("Ingrese la clave (terminela con un punto)\n");
    scanf("%c",&contrasena);
    while (contrasena != '.')
    {
        contadorCaracteres++;
        if (islower(contrasena))
        {
           contieneMinuscula = 1;
        }
        if (tolower(contrasena))
        {
           contieneMayuscula = 1;
        }
        if (isdigit(contrasena))
        {
           contieneNumero = 1;
        }
        if (contrasena =='!' || contrasena =='@' || contrasena =='#' || contrasena =='$' || contrasena =='%' || contrasena =='&' || contrasena =='/' || contrasena =='(' || contrasena ==')' || contrasena =='=' || contrasena =='?' || contrasena =='¡' || contrasena =='¿' || contrasena =='*' || contrasena =='+' || contrasena =='-' || contrasena ==' \ ' || contrasena =='{' || contrasena =='}' || contrasena =='[' || contrasena ==']' || contrasena =='<' || contrasena =='>' || contrasena =='|' || contrasena =='°' ||  contrasena =='-' || contrasena ==';' || contrasena ==':' || contrasena =='!')
        {
           contieneCaracterEspecial = 1;
        }
        scanf("%c",&contrasena);
        
    }
    printf("los numeros son %d \n",contieneMinuscula);
    printf("los numeros son %d \n",contieneMayuscula);
    printf("los numeros son %d \n",contieneNumero);
    printf("los numeros son %d \n",contadorCaracteres);
    if (contadorCaracteres >= 8 && contadorCaracteres <= 16)
        {
            if (contieneMinuscula == 1 && contieneMayuscula == 1 && contieneNumero == 1 && contieneCaracterEspecial ==1)
            {
                printf("La clave es valida\n");
            }  else {
               printf("La clave es invalida\n"); 
            }
        } else
        {
            printf("La clave es invalida\n");
        }
        
    
    return 0;
}

/*

*/

