#include<stdio.h>

void bfs(int M[21][21], int C[4][21]){
	int c=0;//serve para marcar a posição atual no vetor de vertices
	int cont=0;//conta a quantidade de vertices no vetor de vertices
	for(; c< 21;c++){//aumenta quanto mais vertices entrarem no vetor
		for(int h = 0; h < 21; h++){//percorre as colunas de uma linha e vai adicionando vertices ao vetor
			if(c == 0){
				C[0][0] = 0;
				C[2][0] = -1;
				C[3][0] = 0;
			}else{}
			int j = C[3][c];
			if(M[j][h] == 1){//verifica se há uma ligação e se o vertice ligado é no nimimo branco ou cinza
				
				if(C[2][h] == 0){//verifica se o vertice é branco pra adicioná-lo no vetor
						cont++;
						C[0][h] = C[0][c] + 1;
						C[1][h] = C[3][c];
						C[2][h] = -1;
						C[3][cont] = h;
				}
			}
		}
		//apos verificar todas as opções torna o vertice preto
	}
}

int main(){	
	int C[4][21];
						/*a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  z*/
	int M[21][21] ={/*a*/{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					/*b*/{1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					/*c*/{0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					/*d*/{0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					/*e*/{0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					/*f*/{0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					/*g*/{0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					/*h*/{0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					/*i*/{0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					/*j*/{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
					/*k*/{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
					/*l*/{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
					/*m*/{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
					/*n*/{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
					/*o*/{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},
					/*p*/{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0},
					/*q*/{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0},
					/*r*/{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0},
					/*s*/{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1},
					/*t*/{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
					/*z*/{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0}};

	for(int i = 0; i<=21; i++){
		C[0][i] = 0;
		C[2][i] = 0;
		C[3][i] = -1;
	}

	bfs(M, C);
	puts("Tentativa de printar a tabela de distancia");
	printf("Vertice:   A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | Z  ");
	puts("");
	printf("Distância: ");
	for(int i=0; i<21; i++){
		printf("%d | ", C[0][i]);
	}
	puts("");
	printf("Anterior:  ");
	for(int i=0; i<21; i++){
		if(C[1][i] >= 10)
			printf("%d| ", C[1][i]);
		else
			printf("%d | ", C[1][i]);
	}
	puts("");
	printf("Cor:       ");
	for(int i=0; i<21; i++){
		printf("%d| ", C[2][i]);
	}
	puts("");
	printf("Vetor:     ");
	for(int i=0; i<21; i++){
		if(C[3][i] >= 10)
			printf("%d| ", C[3][i]);
		else
			printf("%d | ", C[3][i]);
	}
	puts("");
	printf("Menor Caminho: ");
	for(int i = 20; i != 0; ){
		printf("%d <- ", i);
		i = C[1][i];
	}
	puts("0");
	
	}
