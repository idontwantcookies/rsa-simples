/*Esse modulo contem funcoes associadas a conversao de char[] para 
int[] (e vice-versa) onde os valores do vetor de inteiros equivalem aos valores 
ASCII de cada caractere em char[] */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "basemath.h"

int max_vetor_positivos(int *vetor, int tamanho){
	//retorna o maior valor para um vetor de inteiros positivos
	int max = 0;
	for(int i = 0; i < tamanho; i++){
		if(vetor[i] > max) max = vetor[i];
	}
	return max; 
}

void imprimir_vetor(int *vetor, int tamanho){
	//imprime um vetor de inteiros para propósitos de debugging
	for(int i = 0; i < tamanho; i++){
		printf("%d ", vetor[i]);
	}
	printf("\n");
}

void resetar_vetor(int *ascii, int tamanho, int base){
	// coloca todos os valores de um vetor como "base" (ex: -1)
	// para "resetar" o vetor para o padrão
	for (int i = 0; i < tamanho; i++){
		ascii[i] = base;
	}
}

int *str_to_ascii(char *mensagem) {
	//transforma a mensagem em um vetor com valores ASCII
	int tamanho = strlen(mensagem);
	int *ascii = (int*) malloc(tamanho * sizeof(int));
	for(int i = 0; i < tamanho; i++){
		ascii[i] = (int) mensagem[i];
	}
	return ascii;
}

char *ascii_to_str(int *ascii, int tamanho) {
	//transforma de volta um vetor ASCII em uma mensagem char[]
	char *mensagem_saida = (char*) malloc((tamanho + 1)* sizeof(char));
	for(int i = 0; i < tamanho; i++) {
		mensagem_saida[i] = (char)ascii[i];
	}
	mensagem_saida[tamanho] = '\0';	//garante que a mensagem termine onde deveria
	return mensagem_saida;
}

char *strslice(char *texto, int inicio, int fim) {
	/* modifica slice para ser uma parte da string texto que começa em inicio (inclusivo) 
	e termina em fim (exclusivo) */
	char *slice = malloc((fim - inicio + 1) * sizeof(char));
	for(int i = inicio; i < fim; i++){
		slice[i - inicio] = texto[i];
	}
	slice[fim - inicio] = '\0';
	return slice;
}

char *concatenar_vetor(int *vetor, int tamanho, int invalido){
	/* transforma uma sequencia de numeros (vetor) em uma string, que é armazenada
	em texto_saida */
	char *texto_saida = (char*) malloc(tamanho * ndigitos(max_vetor_positivos(vetor, tamanho) + 1)
			 * sizeof(char));
	for(int i = 0; i < tamanho && vetor[i] != invalido; i++){
		sprintf(texto_saida, "%s%i", texto_saida, vetor[i]);
	}
	return texto_saida;
}

int *split_ascii(char *mensagem, int totiente, int vector_terminator) {
	int tamanho = strlen(mensagem);
	int *ascii = (int*) malloc((tamanho) * sizeof(int));
	int cont = 0;
	int slice;
	int i = 0, j = 0;

	// resetar_vetor(ascii, tamanho, vector_terminator);
	// printf("Tamanho: %d\n", tamanho);
	while(i < tamanho){
		for(j = i+1; j < tamanho + 1; j++){
			// printf("%d,%d\n", i, j);
			slice = strslice(mensagem, i, j);
			if(slice >= totiente){
				ascii[cont] = strslice(mensagem, i, j - 1);
				cont++;
				i = j - 1;
				break;
			} else if (strlen(strslice(mensagem, i, tamanho)) < ndigitos(totiente)) {
				ascii[cont] = strslice(mensagem, i, tamanho);
				cont++;
				i = tamanho;
				break;
			}
		}
	}
	ascii[cont] = vector_terminator;
	return ascii;
}
