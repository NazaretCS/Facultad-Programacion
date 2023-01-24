/**
 
   Ejercicio 1
        En una escuela rural se desea analizar a que distancia en kms del establecimiento viven los alumnos y cual es el medio de trasporte que usan para llegar, a los efectos de otorgarles una ayuda economica. Los alumnos alumnos pueden ir a la escuela en omnibus (se les da un subsidio de $1000 al mes), trasporte escolar (se les da un subsidio de $500 al mes), o a pie. Si los alumnos de esta ultima categoria viven a mas de 3km de la escuela, habra que analizar si los padres estan desocupados, si no lo estan, si el numero de hijos en edad escolar es mayor a 3 se les concede una beca de 3000 por mes. Si son desocupados, reciven directamente el plan ESTUDIAR valuado en 5000 al mes. Los directivos de la escuela nesesitan saber en base a la situacion de cada chico si les corresponde la ayuda y cual, para ello se deven analizar los datos de los 250 chicos. 

            ALGORITMO: AyudaEconomicaEstudiantil
            ENTRADAS: MedioTrasporte (1 = omnibus, 2 = Trasporte Escolar , 3 = A Pie): Entero
            SALIDAS:
            VARAUX:
            CONSTANTES:

            FINALGORITMO: 

            PA DESPUES

    Ejercicio 2
        Dada una oracion terminada en un punto, escriva un algoritmo que calcule la cantidad de palabras que tienen al menos 3 vocales diferentes. Ademas, devolver la frase ingresada sustituyendo los espacios en blanco por *. Implemente en C

            ALGORITMO: AnalizandoCadena
            ENTRADA: cc: cadena de caracteres (terminada en punto)
            SALIDA: Palabras: Entero, cc: cadena de carcteres
            VARAUX: canta, cante, canti, canto, cantu, vocales: Enteros

                a0. Palabras <- 0
                a1. LEER(cc)
                a2. Analizar Frase
                a3. ESCRIVIR(Palabras)
                a4. PARAR

            FIN: ALGORITMO:

            a2. Analizar Frase
                MIENTRAS ( cc <> "." )
                    MIENTRAS ( cc <> " " and cc <> "." )
                        canta, cante, canti, canto, cantu <- 0
                        SEGUN ( cc )
                            a: canta <- canta + 1 
                            e: cante <- cante + 1 
                            i: canti <- canti + 1 
                            o: canto <- canto + 1 
                            u: cantu <- cantu + 1 
                        FIN SEGUN

                        ESCRIBIR(cc)
                        LEER(cc)

                    FIN MIENTRAS 

                    SI (canta > 0 ) Vocales <- Vocales +1 
                    SI (cante > 0 ) Vocales <- Vocales +1 
                    SI (canti > 0 ) Vocales <- Vocales +1 
                    SI (canto > 0 ) Vocales <- Vocales +1 
                    SI (cantu > 0 ) Vocales <- Vocales +1 

                    SI ( Vocales >= 3 ) Palabras <- Palbras + 1

                    SI ( cc = " ") ENTONCES
                            ESCRIBIR(*)
                            LEER(cc)
                    FIN SI
                FIN MIENTRAS

            El Mate esta rico.
            El*Mate*esta*rico
 */