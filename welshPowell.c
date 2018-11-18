#include<stdio.h>

int main(){
	int M[11][11] ={{0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0},
					{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
					{0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1},
					{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
					{0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1},
					{1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1},
					{0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0},
					{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
					{0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0}};

	int G[2][11];//vertice e grau
	int C[2][11] = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
		 			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};//vertice e cor
	int cont;//grau
	int i, j;

	for(i = 0; i<11; i++){//pega o grau de cada vertice
		for(j = 0, cont=0; j<11; j++){
			if(M[i][j] == 1)
				cont++;
		}
		G[0][i] = i;
		G[1][i] = cont;
	}

	int Go[2][11];//vertices ordenados por grau
	int maior, v;//maior valor a cada interação e auxiliar que guarda a maior coluna

	for(i = 0; i<11; i++){//ordena do maior vertice ao maior
		maior = 0;
		for(j = 0; j<11; j++){
			if(G[1][j] > maior){
				maior = G[1][j];
				v = G[0][j];
			}
		}
		Go[0][i] = v;
		Go[1][i] = maior;
		G[1][v] = 0;//zera o grau do vertice para não pegar ele novamente
	}

	int k = 1;//cor maxima;
	int c = 1;//cor inicial;
	for(i = 0; i<11; i++){
		c = 1;
		for(j = 0; j<11; j++){
			if(M[Go[0][i]][j] == 1){
				if(C[1][j] != 0){//se ja foi colorido
					if(c == C[1][j]){//se a cor atual for igual a do vertice adjacente
						j = 0;
						if(c == k){//incrementa a cor maxima caso a cor atual for igual a maxima
						c++;
						k++;
						}else{
						c++;
					}
					}
				}
			}
		}
		C[1][Go[0][i]] = c;//colore o vertice com a cor atual
	}

	for(i = 0; i<11; i++){
		for(j = 0, cont=0; j<11; j++){
			if(M[i][j] == 1)
				cont++;
		}
		G[0][i] = i;
		G[1][i] = cont;
	}

	for(i = 0; i<11; i++){
		printf("vertice: %d cor: %d grau: %d\n", C[0][i], C[1][i], G[1][i]);
	}
}