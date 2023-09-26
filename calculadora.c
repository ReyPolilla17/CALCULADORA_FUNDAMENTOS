#include <stdio.h>

/*
Este programa solicita al usuario un operador matemático e indica que es lo que hace
Entradas: un caracter
Salidas: su función
*/

int main(void)
{
// definir operar
  char operar = 0;

// guardar el valor del usuario en operar
  printf("Introduce un operador matematico: ");
  scanf("%c", &operar);

// determinar la acción que realiza el caracter
  switch(operar)
  {
    case '+':
    {
      printf("Suma\n");
      break;
    }
    case '-':
    {
      printf("Resta\n");
      break;
    }
    case '*':
    {
      printf("Multiplicacion\n");
      break;
    }
    case '/':
    {
      printf("Division\n");
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
