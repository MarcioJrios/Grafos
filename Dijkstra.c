#include <stdio.h>
#include <stdlib.h>

void dijkstra(int M[7][7], int v[7], int C[3][7])
{
    int atual= 0;
    for(int i = 0; i<7; i++){
    	for(int j = 0; j<7;j++){
    		if(M[atual][j] > 0){
    			if(C[1][atual]+M[atual][j] < C[1][j]){
    				C[1][j] = C[1][atual]+M[atual][j];
    				C[2][j] = atual;
    			}
    		}
    }

    	for(int h = 0; h<7; h++){
    		if(atual+1 == v[h])
    			v[h] = 0;
 	   }
  	  for(int h = 0, menor = 1000; h<7; h++){
    		if(C[1][h] < menor){
    			if(h+1 == v[h]){
    				menor = C[1][h];
    				atual = h;
    			}
    		}

		}
    }

    
}

int main(){
	int v[7] = {1, 2, 3, 4, 5, 6, 7};
	int M[7][7] =/*a*/{{0, 7, 0, 5, 0, 0, 0},
                  /*b*/{7, 0, 8, 9, 7, 0, 0},
                  /*c*/{0, 8, 0, 0, 5, 0, 0},
                  /*d*/{5, 9, 0, 0,15, 6, 0},
                  /*e*/{0, 7, 5,15, 0, 8, 9},
                  /*f*/{0, 0, 0, 6, 8, 0,11},
                  /*g*/{0, 0, 0, 0, 9,11, 0}};
    int C[3][7];
	for(int i=0;i<7;i++){
			C[0][i] = i+1;
			C[2][i] = -1;
	}
	C[1][0] = 0;
	for(int i=1;i<7;i++){
			C[1][i] = 1000;
	}

	dijkstra(M, v, C);

	printf(" ");
	for(int i = 0; i<7;i++){
		printf("%d  ", C[0][i]);
	}puts("");
	printf(" ");
	for(int i = 0; i<7;i++){
		if(C[1][i] >= 10)
			printf("%d ", C[1][i]);
		else
			printf("%d  ", C[1][i]);
	}puts("");
	for(int i = 0; i<7;i++){
		if(C[2][i] >= 10)
			printf("%d ", C[2][i]);
		else
			printf("%d  ", C[2][i]);
	}puts("");

	/*for(int i = 6; i!=0; ){
		printf("%d\n", C[]);
	}*/
}
