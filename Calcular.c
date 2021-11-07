#include "funcoes.h"

//LINK DA EXPLICAÇÃO DO CODIGO -> https://youtu.be/AEKFJB5vEbs

int main(){
	
	printf("\t\t\tCALCULADORA DE EXPRESSOES NUMERICAS\n\n");
	printf("Operacoes disponiveis e como usalas na calculadora: \n");
	printf("Usar '!' quando quiser se referir a um numero negativo, apenas colocar na frente como se fosse um '-'\n");
	printf("Soma = +\nSubtracao = -\nMultiplicacao = *\nDivisao = / \n");
	printf("Potencia = ^\n");
	printf("Seno = s\nCosseno = c\nTangente = t\nLogaritmo Natural = l\nLogaritmo na Base 10 = L\n\n\n");
	printf("\tEXIBINDO RESPOSTA: \n");
	char *v = "(12+!4)"; /*TROCAR PELA EXPRESSAO QUE DESEJAR*/
	int aux = Formada(v);
	if(aux){
		printf("\tString bem formada, sequindo calculo . . .\n");
		printf("\tExpressao a ser calculada:        %s\n", v);
		v = NPinversa(v);
		printf("\tExpressao a ser calculada em NPI: %s\n", v);
		printf("\tResposta = %.2f\n", resolver_expressao(v));
	}
		
	else{
		printf("String mal formada encerrando!!!\n");
	}
	return 0;


}

