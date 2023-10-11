#include <stdio.h>

/*
Este programa solicita al usuario un operador matemático y realiza la operación solicitada
Entradas: un caracter y 2 enteros
Salidas: su función
*/

void leer_arreglo(int arr[]);
int sumar_arreglo(int arr[]);
int factorial(int a);
int suma(int a, int b);
int resta(int a, int b);
int multiplicacion(int a, int b);
double division(int a, int b);

int main(void)
{
// definir operar
  char operar = 0;
  int a = 0;
  int b = 0;
  
  int res = 0;
  double resDec = 0;
  int nums[10];

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

// Función factorial:
/*
Esta función recibe un número y saca su factorial
Entradas: un numero entero positivo
Salidas: el factorial del número entero
*/
int factorial(int a)
{
  int res = 0;

  if(a == 0)
  {
    return 1;
  }
  else
  {
    res = factorial(a - 1);

    return a * res;
  }
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
