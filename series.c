#include <stdio.h>
#include "mate.h"

// Función factorial_rec:
/*
Esta función recibe un número y saca su factorial usando recursion
Entradas: un numero entero positivo
Salidas: el factorial del número entero
*/
int factorial_rec(int a)
{
  int res = 0;

  if(a == 0)
  {
    return 1;
  }
  else
  {
    res = factorial_rec(a - 1);

    return a * res;
  }
}

// Función factorial:
/*
Esta función recibe un número y saca su factorial
Entradas: un numero entero positivo
Salidas: el factorial del número entero
*/
int factorial(int a)
{
    // definir res como 1
    int res = 1;
    int i = 0;

    // si el valor dado no es 0
    if(a != 0)
    {
      /*
	Al momento de usar un for, es recomendable asignarle a otra variable el valor que se resta, en este caso, por si es necesario usar más adelante el valor del usuario
      */
      
        // para todos los valores desde el numero dado a 1
        for(i = a; i > 0; i--)
        {
	    // multiplicar res por el valor dado
    	    res = res * i;
	    // restar 1 al valor dado
        }
    }

    // regresar res
    return res;
}

/*
Desarrolla la secuencia de fibonacci hasta el valor indicado y regresa el último valor generado
@param valor -  la cantidad de veces que se realizará la secuencia fibonacci
@param meta  -  la cantidad de veces que se desea repetir la secuencia
@return      -  el ultimo valor que se haya impreso en la última vuelta de la función

@example fibonacci(6)

0
0 1 
0 1 1 
0 1 1 2 
0 1 1 2 3 
0 1 1 2 3 5 
0 1 1 2 3 5 8 

con un valor de retorno 8
*/
int fibonacci(int valor, int meta)
{
  // guardar el ultimo valor de la secuencia fibonacci hasta el valor indicado
  int final = fibonacci_hasta(valor);

  // si no se ha llegado 
  if(valor != meta)
  {
    // sumar 1 a valor
    valor++;
    // guardar el resultado de la función en inicial usando el nuevo valor
    final = fibonacci(valor, meta);
  }

  // se regresa el valor alojado en inicial
  return final;
}

/*
Imprimirá realizará una secuencia fibonacci la cantidad de veces indicada
@param valor - la cantidad de veces que debe realizarse la secuencia fibonacci
@return el ultimo valor de la secuencia generado

@example fibonaccia_hasta(6)
0 1 1 2 3 5 8 

con un valor de retorno 8
*/
int fibonacci_hasta(int valor)
{
  // contador
  int i = 0;

  // los 2 primeros numeros de la secuencia
  int inicial = 0;
  int actual = 1;

  // el valor resultante de la suma de los primeros 2 numeros
  int siguiente = 0;

  // imprimir el primer valor de la secuencia
  printf("%d ", inicial);

  // repetir mientras i sea menor a la cantidad de repeticiones a realizar
  for(i = 0; i < valor; i++)
  {
    // imprimir el valor actual con un espacio
    printf("%d ", actual);
    
    // el siguiente valor será igual al valor anterior mas el actual
    siguiente = inicial + actual;

    // se recorren los valores para la siguiente vuelta
    inicial = actual;
    actual = siguiente;
  }

  // imprimir salto de linea
  printf("\n");

  // regresar el valor de inicial
  return inicial;
}