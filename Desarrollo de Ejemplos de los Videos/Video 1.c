/**
Punto 1
    Escriva un algoritomo que lea una cadena de tamaño indefinido. calcule y muestre por pantalla la cantidad de vocales, consonantes y la loguitud. Diseñe una funcion para el analisis de las vocales.

    ALGORITMO: AnalizandoCadena
    ENTRADAS: cc: cadena de caracteres con marca final en "."
    SALIDAS: CantVocales, CantConsonates, CantCaracteres: Enteros U 0
    VARAUX: aux1: Entero
    CONSTANTES:

        a1. CantVocales <- 0
            CantConsonates <- 0
            CantCaracteres <- 0
        a2. LEER( cc )
        a3. ProcesarCadena
        a4. ESCRIBIR( CantVocales, CantConsonantes, CantCaracteres )
        a5. PARAR.

        a3. ProcesarCadena
            MIENTRAS ( cc <> MF )
                aux1 <- EsVocal( cc )
                SI ( aux1 = 1 )
                    ContVocales <- ContVocales + 1
                SINO
                    ContConsonates <- ContConsonantes + 1
                FIN SI
                ContCaracteres <- ContCaracteres + 1
                LEER ( cc )
            FIN MIENTRAS

    FINALGORITMO:
        
    
    FUNSION: EsVocal
    ARGUMENTOS: letra: caracter
    RESULTADO: Entero
    VARAUX: -

        a1. SI ( letra <> "a" o letra <> "e" o letra <> "i" o letra <> "u" o letra <> "A" o letra <> "E" o letra <> "I" o letra <> "O" o letra <> "U") 
                EsVocal <- 0
            SINO
                EsVocal <- 1
            FIN SI

    FINFUNCION: 



Punto 2
    Diseñe una funcion para calcular el indice de masa corporal (IMC) y determinar la compocicion corporal de una persona, realize un algoritmo de prueva para un numero de personas que se desconoce. Por cada persona se deve ingresar el nombre, la edad, su estatura en centimetros, y su peso en kilogramos.

    IMC = (Peso(kg) / estatura(m2))

    Segun el valor obtenido de IMC se tiene que la compocicion corporal es la sigueinte:
        IMC < 18.5 -- Peso inferior al normal
        18.5 < IMC < 24.9 -- Peso normal
        25.0 < IMC < 29.9 --    Peso superior al normal.
        IMC > 30 -- Obecidad

    Muestre por pantalla el nombre, la edad, y la compocicion corporal resultante...



    ALGORITMO: IMC
    ENTRADAS: Nombre: cc. Edad, Estatura, Peso: Reales
    SALIDAS: Nombre, CompociconCorporal: cc. Edad: Real
    VARAUX:

        a1. LEER( Edad )
        a2. MIENTRAS (Edad <> 0)
                LEER (Nombre, Estatura, Peso)
                CompocicionCorporal <- CalcularCompocicionCorporal(Peso, Estatura)
                ESCRIBIR(Nombre, Edad, CompocicionCorporal)
                LEER( Edad )
            FIN MIENTRAS
    
    FINALGORITMO:


    FUNCION: CalcularCompocicionCorporal
    ARGUMENTOS: Peso, Estatura: Reales
    RESULTADO: cc
    VARAUX: imc: Real
        a1. imc <- Peso / Estatura*Estatura
        a2. SEGUN (imc)
                imc < 18.5: CalcularCompocicionCorporal <- "Peso inferior al normal"
                18.5 < imc < 24.9: CalcularCompocicionCorporal <- "Peso normal"
                25.0 < imc < 29.9: CalcularCompocicionCorporal <- "Peso superior al normal"
                imc > 30: CalcularCompocicionCorporal <- "Obecidad"
            FIN SEGUN
    FINFUNCION:

 */