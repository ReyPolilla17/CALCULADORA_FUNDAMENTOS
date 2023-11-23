#include <stdio.h>
#include <stdlib.h>

// libreria de funciones matemáticas, necesita encadenar de una manera diferente: gcc -o <destino> <origen> -lm
#include <math.h>
#include <string.h>

// librería propia
#include "mate.h"

typedef struct
{
  char operacion;
  double resultadoD1;
  double resultadoD2;
  double resultadoD3;
  int resultadoI;
  int operando1;
  int operando2;
  int operando3;
} OPERACION;

/*
  Este programa solicita al usuario un operador matemático y realiza la operación solicitada
  Entradas: un caracter y 2 enteros
  Salidas: su función
*/

int leer(int mayorA, int divisible, int primero);
void leer_arreglo(int arr[]);
void calcular(OPERACION ultimas[], int *veces, char operar, int a, int b, int c, int imprimir, int solicitar);
int sumar_arreglo(int arr[]);
void eq_cuadr(double a, double b, double c, double *r1, double *r2);
void estadistica(int arr[], int size, double *media, double *mediana, int *moda);
void circulo_esfera(double r, int p, double *peri, double *area, double *vol);

int main(int argc, char *argv[])
{
  char operar = 0;

  int a = 0;
  int b = 0;
  int c = 0;

  int veces = 0;
  OPERACION ultimas[10];

  char line[100];

  int arch = 0;
  FILE *archivo;

  int i = 0;

  for (i = 1; i < argc; i++)
  {
    if (!strcmp(argv[i], "-f"))
    {
      if (i + 1 < argc)
      {
        archivo = fopen(argv[i + 1], "r");

        if (archivo == NULL)
        {
          printf("No se encontro el archivo %s...\n", argv[i + 1]);
        }
        else if (archivo != NULL)
        {
          while (fscanf(archivo, " %[^\n]", line) != EOF)
          {
            sscanf(line, "%c %d %d %d", &operar, &a, &b, &c);
            calcular(ultimas, &veces, operar, a, b, c, 1, 0);

            operar = 0;
            a = 0;
            b = 0;
            c = 0;
          }
        }

        fclose(archivo);
      }
      else
      {
        printf("Debes mencionar un archivo...\n");
      }
    }
    else
    {
      if (i + 1 < argc)
      {
        sscanf(argv[i + 1], "%d", &a);
      }
      if (i + 2 < argc)
      {
        sscanf(argv[i + 2], "%d", &b);
      }
      if (i + 3 < argc)
      {
        sscanf(argv[i + 3], "%d", &c);
      }

      calcular(ultimas, &veces, argv[i][0], a, b, c, 0, 0);

      a = 0;
      b = 0;
      c = 0;
    }
  }

  while (1)
  {
    printf("Introduce un operador: ");
    scanf("%c", &operar);
    getchar();

    calcular(ultimas, &veces, operar, a, b, c, 1, 1);
  }

  return 0;
}

void calcular(OPERACION ultimas[], int *veces, char operar, int a, int b, int c, int imprimir, int solicitar)
{
  int nums[10];

  // resultados
  double res1 = 0;
  double res2 = 0;
  double res3 = 0;

  int res = 0;

  int add = 1;
  int i = 0;

  if (*veces > 9)
  {
    for (i = 1; i < 10; i++)
    {
      ultimas[i - 1] = ultimas[i];
    }

    *veces -= 1;
  }

  switch (operar)
  {
  case '+':
  {
    if (solicitar)
    {
      a = leer(-1, -1, 1);
      b = leer(-1, -1, 0);
    }

    res = suma(a, b);

    printf("%d\n", res);
    break;
  }
  case '-':
  {
    if (solicitar)
    {
      a = leer(-1, -1, 1);
      b = leer(-1, -1, 0);
    }

    res = resta(a, b);

    printf("%d\n", res);
    break;
  }
  case '*':
  {
    if (solicitar)
    {
      a = leer(-1, -1, 1);
      b = leer(-1, -1, 0);
    }

    res = multiplicacion(a, b);

    printf("%d\n", res);
    break;
  }
  case '/':
  {
    if (solicitar)
    {
      a = leer(-1, -1, 1);
      b = leer(-1, -1, 0);
    }

    res1 = division(a, b);

    printf("%f\n", res1);
    break;
  }
  case 'f':
  {
    if (solicitar)
    {
      a = leer(0, -1, 1);
    }

    res = factorial(a);

    printf("%d\n", res);
    break;
  }
  case 'F':
  {
    if (solicitar)
    {
      a = leer(0, -1, 1);
    }

    res = factorial_rec(a);

    printf("%d\n", res);
    break;
  }
  case 'i':
  {
    if (solicitar)
    {
      a = leer(0, -1, 1);
    }

    res = fibonacci(0, a);

    printf("El numero en f(%d) es %d\n", a, res);
    break;
  }
  case 'p':
  {
    if (solicitar)
    {
      a = leer(0, 2, 1);
    }

    res1 = pi(a);

    // el formato %1.30f imprime un valor flotante usando hasta un valor entero y 30 valores decimales
    // siendo el valor antes del punto la cantidad de valores enteros y desues del punto la cantidad de valores decimales
    printf("Pi evaluado hasta %d es %1.30f\n", a, res1);
    break;
  }
  case 'e':
  {
    if (solicitar)
    {
      a = leer(0, -1, 1);
    }

    res1 = euler(a);

    printf("%f\n", res1);
    break;
  }
  // si se escoje a, se sumaran 10 numeros usando arreglos
  case 'a':
  {
    printf("Introduce 10 numeros:\n");

    leer_arreglo(nums);
    // res será igual a la suma de los 10 numeros
    res = sumar_arreglo(nums);

    printf("El resultado de la suma es %d\n", res);

    break;
  }
  case 'c':
  {
    if (solicitar)
    {
      a = leer(0, -1, 1);
      b = leer(0, -1, 0);
      c = leer(0, -1, 0);
    }

    // %p imprime una dirección de memoria, & es usado para referirse al espacio de memoria del elemento
    printf("%p\n", &res1);

    // se pasa la dirección de memoria de res1 y res2
    eq_cuadr((double)a, (double)b, (double)c, &res1, &res2);

    printf("%lf\n", res1);
    printf("%lf\n", res2);
    break;
  }
  case 'v':
  {
    if (solicitar)
    {
      a = leer(0, -1, 1);

      printf("Para evaluar pi:\n");
      b = leer(0, 2, 1);
    }

    circulo_esfera((double)a, b, &res1, &res2, &res3);

    printf("Area: %lf\n", res1);
    printf("Perimetro: %lf\n", res2);
    printf("Volumen: %lf\n", res3);
    break;
  }
  case 'm':
  {
    printf("Introduce 10 numeros:\n");

    leer_arreglo(nums);

    estadistica(nums, 10, &res1, &res2, &res);

    printf("Media: %f\n", res1);
    printf("Mediana: %f\n", res2);
    printf("Moda: %d\n", res);
    break;
  }
  case 'h':
  {
    add = 0;
    printf("%d\n", *veces);
    for (i = 0; i < *veces; i++)
    {
      printf("\nOperacion #%d \nTipo: %c \nOperandos: %d, %d, %d \nResultado int: %d \nResultados float: %lf, %lf, %lf\n\n", i + 1, ultimas[i].operacion, ultimas[i].operando1, ultimas[i].operando2, ultimas[i].operando3, ultimas[i].resultadoI, ultimas[i].resultadoD1, ultimas[i].resultadoD2, ultimas[i].resultadoD3);
    }
    break;
  }
  case 's':
  {
    exit(0);
    break;
  }
  // si no está la acción, regresa error
  default:
  {
    if (imprimir)
    {
      printf("Operador desconocido...\n");
    }

    add = 0;
    break;
  }
  }

  if (add)
  {
    ultimas[*veces].operacion = operar;
    ultimas[*veces].resultadoD1 = res1;
    ultimas[*veces].resultadoD2 = res2;
    ultimas[*veces].resultadoD3 = res3;
    ultimas[*veces].resultadoI = res;
    ultimas[*veces].operando1 = a;
    ultimas[*veces].operando2 = b;
    ultimas[*veces].operando3 = c;
  }
  else
  {
    *veces -= 1;
  }

  // por alguna razón no me funcionó *veces++ o *veces--
  *veces += 1;

  return;
}

int leer(int mayorA, int divisible, int primero)
{
  int num = 0;
  int count = 0;

  do
  {
    count = 0;

    if (primero == 1)
    {
      printf("Introduce un numero: ");
    }
    else
    {
      printf("Introduce otro numero: ");
    }

    scanf("%d", &num);

    if (num != -1 && num < mayorA)
    {
      printf("Debes introducir un valor mayor a %d...\n", mayorA);
      count = 1;
    }

    if (divisible != -1 && num % divisible == 0)
    {
      printf("debes introducir un numero que no sea divisible entre %d...\n", divisible);
      count = 1;
    }
  } while (count != 0);

  getchar();

  return num;
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
  for (i = 0; i < 10; i++)
  {
    // pedir un numero y guardarlo en la siguiente posición
    printf("Introduce un numero: ");
    scanf("%d", &arr[i]);
  }

  getchar();

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
  for (i = 0; i < 10; i++)
  {
    // sumarle a res el valor del arreglo actual
    res = res + arr[i];
  }

  // reglresar res
  return res;
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
Regresa el area y perímetro de un círculo y el volumen de una esfera, dado un radio y una evaluación de pi
@param r el readio por el que evaluar los valores
@param p el valor hasta el que evaluar pi
@param *peri apuntador a un valor doble para guardar el perimetro
@param *peri apuntador a un valor doble para guardar el area
@param *peri apuntador a un valor doble para guardar el volumen

@return nada (cambia el valor alojado en la posicion de memoria de los apuntadores)
*/
void circulo_esfera(double r, int p, double *peri, double *area, double *vol)
{
  double num_pi = pi(p);

  *peri = (2 * r) * num_pi;
  *area = (r * r) * num_pi;
  *vol = (4 / 3) * (r * r * r) * num_pi;

  return;
}

void estadistica(int arr[], int size, double *media, double *mediana, int *moda)
{
  int valor_actual = 0;
  int valor_reemplazar = 0;

  int i = 0;
  int j = 0;

  // acomoda los valores de mayor a menor
  // para todos los elementos del arreglo
  for (i = 0; i < size; i++)
  {
    // evaluar cada número del arreglo comenzando por el elemento i del arreglo + 1
    for (j = i + 1; j < size; j++)
    {
      // definir el valor_actual como el elemento i del arreglo y valor_reemplazar por el elemento j del arreglo
      valor_actual = arr[i];
      valor_reemplazar = arr[j];

      // si el elemento i del arreglo es menor o igual al elemento j del arreglo
      if (arr[i] <= arr[j])
      {
        // intercambiar los valores
        arr[i] = valor_reemplazar;
        arr[j] = valor_actual;
      }
    }
  }

  // una vez acomodados, saca la dediana (el valor de en medio)
  if (size % 2 != 0)
  {
    // si la cantidad de numeros no es par, saca el valor de en medio
    *mediana = (double)arr[size / 2];
  }
  else
  {
    // si es par, saca el promedio de los dos valores de en medio
    *mediana = (double)(arr[size / 2] + arr[(size / 2) - 1]) / 2;
  }

  // calcula la media (promedio) y moda a la vez
  // reinicia valor_actual, valor_reemplazar y comienza con la moda siendo el primer elemento del arreglo
  for (i = 0, valor_actual = 0, valor_reemplazar = 0, *moda = arr[0]; i < size; i++)
  {
    // suma cada elemento del arreglo
    *media += arr[i];

    // si el valor que se esta evaluando es más grande que el valor actual más grande, lo reemplaza y la moda se cambia por el numero que se estpa evaluando
    if (valor_reemplazar > valor_actual)
    {
      valor_actual = valor_reemplazar;
      *moda = arr[i];
    }

    // cuneta cuantas veces se repite el numero en el arreglo|
    for (j = i, valor_reemplazar = 0; j < size; j++)
    {
      if (arr[j] == arr[i])
      {
        valor_reemplazar++;
      }
    }
  }

  *media /= (double)size;

  return;
}