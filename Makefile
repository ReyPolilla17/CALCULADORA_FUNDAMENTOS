calculadora.out: calculadora.o aritmetica.o constantes.o series.o
	gcc -o calculadora.out calculadora.o aritmetica.o constantes.o series.o -lm

calculadora.o: calculadora.c
	gcc -c calculadora.c

aritmetica.o: aritmetica.c
	gcc -c aritmetica.c

constantes.o: constantes.c
	gcc -c constantes.c

series.o: series.c
	gcc -c series.c

clean:
	rm *.o
	rm *.out