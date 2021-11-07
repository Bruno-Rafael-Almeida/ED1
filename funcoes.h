#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct stack {
  char info;
  float num;
  struct stack *next;
} Stack;

Stack* create_stack ();

void free_stack (Stack *s);

Stack* push (Stack *s, char elem);

Stack* pushf (Stack *s, float elem);

Stack* pop (Stack *s);

Stack* popf(Stack **s);

char top (Stack *s);

int empty_stack (Stack *s);

void imprimir (Stack *s);

float operacaoBi(float a, float b, char x);

float operacaoUni(float a, char x);

float resolver_expressao(char *x);

int Formada(char *seq);

char *NPinversa (char *inf);
