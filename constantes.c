#include "mate.h"

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