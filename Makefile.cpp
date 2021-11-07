all:
	gcc -o calculadora Calcular.c funcoes.c funcoes.h
clean:
	rm calculadora
