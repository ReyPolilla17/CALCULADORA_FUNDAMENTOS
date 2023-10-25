#include <stdio.h>

// libreria de funciones matemáticas, necesita encadenar de una manera diferente: gcc -o <destino> <origen> -lm
#include <math.h>

/*
  Este programa solicita al usuario un operador matemático y realiza la operación solicitada
  Entradas: un caracter y 2 enteros
  Salidas: su función
*/

void leer_arreglo(int arr[]);
void eq_cuadr(double a, double b, double c, double *r1, double *r2);
void circulo_esfera(double r, int p, double *peri, double *area, double *vol);
int sumar_arreglo(int arr[]);
int factorial_rec(int a);
int factorial(int a);
int suma(int a, int b);
int resta(int a, int b);
int multiplicacion(int a, int b);
double division(int a, int b);
double euler(int a);
int fibonacci(int valor, int meta);
int fibonacci_hasta(int valor);
double pi (int valor);

int main(void)
{
  // definir operar
  char operar = 0;
  
  // numeros a operar
  int nums[10];

  int a = 0;
  int b = 0;

  double v1 = 0; 
  double v2 = 0;
  double v3 = 0;
  double res1 = 0;
  double res2 = 0;
  double res3 = 0;

  // resultados
  int res = 0;
  double resDec = 0;

  // guardar el valor del usuario en operar
  printf("Introduce un operador matematico: ");
  scanf("%c", &operar);

  // determinar la acción que realiza el caracter
  switch(operar)
  {
    case '+':
    {
      printf("Introduce un valor: ");
      scanf("%d", &a);
      
      printf("Introduce otro valor: ");
      scanf("%d", &b);
      
      res = suma(a, b);

      printf("%d\n", res);
      break;
    }
    case '-':
    {
      printf("Introduce un valor: ");
      scanf("%d", &a);
      
      printf("Introduce otro valor: ");
      scanf("%d", &b);
      
      res = resta(a, b);
      
      printf("%d\n", res);
      break;
    }
    case '*':
    {
      printf("Introduce un valor: ");
      scanf("%d", &a);
      
      printf("Introduce otro valor: ");
      scanf("%d", &b);
      
      res = multiplicacion(a, b);
      
      printf("%d\n", res);
      break;
    }
    case '/':
    {
      printf("Introduce un valor: ");
      scanf("%d", &a);
      
      printf("Introduce otro valor: ");
      scanf("%d", &b);
      
      resDec = division(a, b);
      
      printf("%f\n", resDec);
      break;
    }
    case 'f':
    {
      printf("Introduce un valor: ");
      scanf("%d", &a);
      
      if(a < 0)
      {
	      printf("Debes introducir un valor positivo...\n");
      }
      else
      {
      	res = factorial(a);

        printf("%d\n", res);
      }
      
      break;
    }
    case 'F':
    {
      printf("Introduce un valor: ");
      scanf("%d", &a);
      
      if(a < 0)
      {
	      printf("Debes introducir un valor positivo...\n");
      }
      else
      {
	      res = factorial_rec(a);

        printf("%d\n", res);
      }
      
      break;
    }
    case 'i':
    {
      printf("Introduce un valor: ");
      scanf("%d", &a);

      if(a < 0)
      {
	      printf("Debes introducir un valor positivo...\n");
      }
      else
      {
	      b = fibonacci(0, a);

	      printf("El numero en f(%d) es %d\n", a, b);
      }
      
      break;
    }
    case 'p':
    {
      printf("Introduce un valor: ");
      scanf("%d", &a);

      if(a < 0)
      {
	      printf("Debes introducir un valor positivo...\n");
      }
      else if(a % 2 == 0)
      {
	      printf("Debes introducir un numero non...\n");
      }
      else
      {
	      res1 = pi(a);

        // el formato %1.30f imprime un valor flotante usando hasta un valor entero y 30 valores decimales
        // siendo el valor antes del punto la cantidad de valores enteros y desues del punto la cantidad de valores decimales
        printf("Pi evaluado hasta %d es %1.30f\n", a, res1);
      }
      
      break;
    }
    case 'e':
    {
      printf("Introduce un valor: ");
      scanf("%d", &a);
      
      if(a < 0)
      {
	      printf("Debes introducir un valor positivo...\n");
      }
      else
      {
	      resDec = euler(a);

        printf("%f\n", resDec);
      }
      
      break;
    }
    // si se escoje a, se sumaran 10 numeros usando arreglos
    case 'a':
    {
      // guardar 1 numeros
      printf("Introduce 10 numeros:\n");
      
      leer_arreglo(nums);
      // res será igual a la suma de los 10 numeros
      res = sumar_arreglo(nums);

      printf("El resultado de la suma es %d\n", res);

      break;
    }
    case 'c':
    {
      printf("Dame a: ");
      scanf("%lf", &v1);

      printf("Dame b: ");
      scanf("%lf", &v2);

      printf("Dame c: ");
      scanf("%lf", &v3);

      // %p imprime una dirección de memoria, & es usado para referirse al espacio de memoria del elemento
      printf("%p\n", &res1);

      // se pasa la dirección de memoria de res1 y res2
      eq_cuadr(v1, v2, v3, &res1, &res2);

      printf("%lf\n", res1);
      printf("%lf\n", res2);
      break;
    }
    case 'v':
    {
      printf("Introduce un valor: ");
      scanf("%lf", &v1);

      printf("Introduce el valor al que evaluar pi: ");
      scanf("%d", &a);

      if(a < 0)
      {
	      printf("Debes introducir un valor positivo...\n");
      }
      else if(a % 2 == 0)
      {
	      printf("Debes introducir un numero non...\n");
      }
      else
      {
	circulo_esfera(v1, a, &res1, &res2, &res3);

             printf("Area: %lf\n", res1);
             printf("Perimetro: %lf\n", res2);
             printf("Volumen: %lf\n", res3);	      
      }

      
      break;
    }
    // si no está la acción, regresa error
    default:
    {
      printf("Operador desconocido...\n");
      break;
    }
  }

  return 0;
}

/*
Esta función leerá 10 numeros y los guardará en un arreglo
Entradas: 10 numeros
Salidas: los 10 numeros guardados en el arreglo
*/
void leer_arreglo(int arr[])
{
  // contador
  int i = 0;

  // repetir 10 veces
  for(i = 0; i < 10; i++)
    {
      // pedir un numero y guardarlo en la siguiente posición
      printf("Introduce un numero: ");
      scanf("%d", &arr[i]);
    }

  return;
}

/*
Esta función suma los 10 numeros dentro de un arreglo
Entradas: 1 arreglo con 10 numeros
Salidas: la suma de los 10 numeros del arreglo
*/
int sumar_arreglo(int arr[])
{
  // contador y variable del resultado
  int i = 0;
  int res = 0;

  // repetir 10 veces
  for(i = 0; i < 10; i++)
    {
      // sumarle a res el valor del arreglo actual
      res = res + arr[i];
    }

  // reglresar res
  return res;
}

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

int suma(int a, int b)
{
  return a + b;
}

int resta(int a, int b)
{
  return a - b;
}

int multiplicacion(int a, int b)
{
  return a * b;
}

double division(int a, int b)
{
  double res = (double)a / (double)b;

  return res;
}

double euler(int a)
{
  // definicion de entero res y doubles res2 y e
  int res = 0;
  double res2 = 0;
  int i = 0;
  double e = 0;

  // para todos los valores de el numero dado hasta 0
  for(i = a; i >= 0; i--)
  {
    // guardar el factorial de a en res
    res = factorial(i);

    // dividir 1/res usando cast para cambiar res de entero a double y guardarlo en res2
    res2 = 1/(double)res;

    // sumar a e res2
    e = e + res2;
    //  restarle 1 a a
  }

  // regresa e
  return e;
}

// al dar el tipo de variable al lado del apuntador, se declara el apuntador, ej: int *nombre
// si no viene el tipo, se habla del contenido del apuntador
// si intentas cambiar el apuntador sin el * salta error al compilar porque se intenta modificar la dirección de memoria

void eq_cuadr(double a, double b, double c, double *r1, double *r2)
{
  // se modifica el valor de la dirección de memoria a la que apunta el apuntador
  *r1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
  *r2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);

  // como r1 es un apuntador, al imprimirlo como espacio de memoria, imprime el espacio de memoria al que apunta, que en este caso es el mismo que res1
  printf("%p\n", r1);

  return;
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

/*
Evalua pi hasta un valor dado
@param valor - el numero hasta el que evaluar pi

@return el numero obtenido de la evaluación
*/
double pi(int valor)
{
  // contador y desición de la operación
  int i = 0;
  int operar = 1;

  // lugar en el que guardar el resultado
  double res = 0;

  // mientras i sea menor o igual al valor dado
  // operar se alterna entre 1 y -1, ya que la secuencia funciona de esa manera
  for(i = 1; i <= valor; i += 2, operar *= -1)
  {
    // sumar al resultado 1/i*operar (como operar se va alternando, al final la suma se convierte en una resta al volver negarivo el valor dentro del parentesis)
    res = res + ((1 / (double)i) * (double)operar);
  }

  // como el algoritmo anterior solo adquiere 1/4 de pi, regresa el valor multiplicado por 4
  return res * 4;
}

void circulo_esfera(double r, int p, double *peri, double *area, double *vol)
{
  double num_pi = pi(p);
  
  *peri = (2 * r) * num_pi;
  *area = (r * r) * num_pi;
  *vol = (4/3) * (r * r * r) * num_pi;
  
  return;
}
