#include "funcoes.h"

//Funcao para criar uma pilha vazia (sem criar nenhuma pilha, apenas devolver NULL)
Stack* create_stack () {
	return NULL;	
   
}

//Funcao para liberar uma pilha por pilha
void free_stack (Stack *s) {
   while (s != NULL) {
		Stack *aux = s->next; //guarda ref. p/ prox
		free(s); //libera a mem´oria
		s = aux; //faz lista apontar p/ o prox. elem
	}
}

//funcao para empilhar valores do tipo caractere
Stack* push (Stack *s, char elem) {
	Stack *novo =(Stack*)malloc(sizeof(Stack));
	
	if(novo){
		novo->info = elem;
		novo->next = s;
		return novo;
	}
	else
		return NULL;
}
//funcao para empilhar valores de ponto flutuante
Stack* pushf (Stack *s, float elem) {
	Stack *novo =(Stack*)malloc(sizeof(Stack));
	
	if(novo){
		novo->num = elem;
		novo->next = s;
		return novo;
	}
	else
		return NULL;
}

//funcao para desempilhar elementos e retornar o resto da pilha sem o elemento cabeca
Stack* pop (Stack *s) {
	Stack *aux;
	aux = s->next;
	free(s);
	return aux;
}

//funcao para desempilhar um elemento da pilha e retornar o resto da pilha sem o elemento cabeca
Stack* popf(Stack **pilha){
    Stack *remover = NULL;

    if(*pilha){
        remover = *pilha;
        *pilha = remover->next;
    }
    else
        printf("\tPilha vazia\n");
    return remover;
}

//Funcao para retornar o elemento no topo da pilha (cabeca da lista encadeada) sem desempilhar!
char top (Stack *s) {
   return s->info;
}

//Funcao para testar se uma pilha esta vazia
int empty_stack (Stack *s) {
   if(s == NULL)
		return 0;
	else
		return 1;
}

//funcao que percorre toda a lista e a imprime, e nesse momento nao esta sendo utilizada
void imprimir (Stack *q) {
	Stack *v; 
	for (v = q; v != NULL; v = v->next) {
		printf("Valor: %c\n", v->info);
	}
}

//funcao que contem as operacoes binarias, que utilizam dos numeros para funcionarem
float operacaoBi(float a, float b, char x){
    switch(x){
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '/':
        return a / b;
        break;
    case '*':
        return a * b;
        break;
    case '^':
    	return pow(a,b);
    	break;
    default:
        return 0.0;
    }
}

//funcao que contem as operacoes unitarias, que utilizam apenas um numeros para funcionar
float operacaoUni(float a, char x){
    switch(x){
    case 's':
        return sin(a);
        break;
    case 'c':
        return cos(a);
        break;
    case 't':
        return tan(a);
        break;
    case 'l':
        return log(a);
        break;
    case 'L':
        return log10(a);
        break;
    case 'v':
    	return sqrt(a);
    	break;
    default:
        return 0.0;
    }
}

//funcao que resolve a expressao matematica
float resolver_expressao(char *x){
	char *op;
	float num, aux;
	Stack *pilha = create_stack();
	Stack *n1, *n2;
	
	op = strtok(x, " ");
	while(op){
		if(op[0] == '+' || op[0] == '-' || op[0] == '/' || op[0] == '*' || op[0] == '^'){
			n1 = popf(&pilha);
            n2 = popf(&pilha);
            
            num = operacaoBi(n2->num, n1->num, op[0]);
            pilha = pushf(pilha, num);
            free(n1);
            free(n2);
        }
        else if(op[0] == 'v' || op[0] == 's' || op[0] == 'c' || op[0] == 't' || op[0] == 'l' || op[0] == 'L'){
        	n1 = popf(&pilha);
        	num = operacaoUni(n1->num, op[0]);
        	pilha = pushf(pilha, num);
        	free(n1);
        }
        else{
        	if(op[0] == '!'){
        		n1 = popf(&pilha);
        		aux = n1->num * -1;
        		pilha = pushf(pilha, aux);
			}else{
				num = atof(op);//strtol(pt, NULL, 10);
            	pilha = pushf(pilha, num);
			}
        }
        op = strtok(NULL," ");
    }
    n1 = popf(&pilha);
    num = n1->num;
    free(n1);
    return num;
}

//funcao que transforma a string(expressao matematica ainda em char) e coloca ela em string mas em NPI
char *NPinversa (char *inf) {
	int n = strlen(inf);
   char *posf;
   posf = malloc ((n+5) * sizeof (char));
   Stack *p = create_stack(); //criapilha ();
   p = push(p, inf[0]); //empilha (inf[0]);       // empilha '('

	int j = 0, i;
	for (i = 1; inf[i] != '\0'; ++i) {
		switch (inf[i]) {
			char x;
			
			case '(':   
				p = push(p, inf[i]);
				break;
			case ')': 	
				x = top(p); p = pop(p);
				while (x != '(') {
					posf[j++] = ' ';
					posf[j++] = x;
					x = top(p); p = pop(p);
				}
				break;

			case '+':
			case '-':	
				x = top(p); p = pop(p);
				while (x != '(') {
					posf[j++] = ' ';
					posf[j++] = x;
					x = top(p); p = pop(p);
				}
				p = push(p,x);
				p = push(p,inf[i]);
				posf[j++] = ' ';
				break;
				
			case '*':
			case '/':	
				x = top(p); p = pop(p);
				while (x != '(' && x != '+' && x != '-') {
					posf[j++] = ' ';
					posf[j++] = x;
					x = top(p); p = pop(p);
				}
				p = push(p,x);
				p = push(p,inf[i]);
				posf[j++] = ' ';
				break;
				
			case '!': 	
				x = top(p); p = pop(p);
				while (x != '(' && x != '+' && x != '-' && x != '*' && x != '/') {
					//posf[j++] = ' ';
					posf[j++] = x;
					x = top(p); p = pop(p);
				}
				p = push(p,x);
				p = push(p,inf[i]);
				break;
				
			case 's':
			case 'c':
			case 't':
			case 'l': 
			case 'L':
			case 'v':	
				x = top(p); p = pop(p);
				while (x != '(' && x != '+' && x != '-') {
					//posf[j++] = ' ';
					posf[j++] = x;
					x = top(p); p = pop(p);
				}
				p = push(p,x);
				p = push(p,inf[i]);
				break;
				
			case '^': 	
				x = top(p); p = pop(p);
				while (x != '(' && x != '+' && x != '-' && x != '*' && x != '/') {
					posf[j++] = ' ';
					posf[j++] = x;
					x = top(p); p = pop(p);
				}
				p = push(p,x);
				p = push(p,inf[i]);
				posf[j++] = ' ';
				break;
						
			default:  
				posf[j++] = inf[i];
      }
   }
   posf[j] = '\0';
   return posf;
}

//funcao para analisar se a sequencia de '(' e '[' na string esta correta, abre e fecha corretamente
int Formada(char *seq){
	//char *seq = "[ ( [  ) ] ) ]";
	int i = 0;

	Stack *p = create_stack();

	while (seq[i] != '\0') {
		if ((seq[i] == '(' ) || (seq[i] == '[') ) {
			p = push (p, seq[i]);
	  	}
	  	else if (seq[i] == ')') {
	 		if (!(empty_stack(p) == 1) || (top(p) != '(')) {
	        	//printf("mal formada\n");
	        	return 0;
	 		}
	 		p = pop(p);
	  	}
	  	else if (seq[i] == ']') {
	 		if (!(empty_stack(p) == 1) || top(p) != '[') {
	    		//printf("mal formada\n");
	        	return 0;
	 		}
	 		p = pop(p);
	  	}
	  	i++;
	}
	if(empty_stack(p) == 0) {
    	//printf("bem formada\n");
    	return 1;
	}
	else {
    	//printf("mal formada\n");
    	return 0;
	}
}
