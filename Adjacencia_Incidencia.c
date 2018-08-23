#include <stdio.h>

/*int copiaMatrizA(int M[5][5]){
	int Mc[5][5];
	for(int i = 0; i<5;i++){
		for(int j = 0; j<5;j++){
			Mc[i][j] = M[i][j];
		}
	}
	return Mc;
}*/

/*int copiaMatrizI(int M[5][8]){
	int Mc[5][8];
	for(int i = 0; i<5;i++){
		for(int j = 0; j<8;j++){
			Mc[i][j] = M[i][j];
		}
	}
	return Mc;
}*/

void G_adj1(int M[5][5]){
	int I=0;

	int Mc[5][5];
	for(int i = 0; i<5;i++){
		for(int j = 0; j<5;j++){
			Mc[i][j] = M[i][j];
		}
	}

	for(int cont = 1; cont <5; cont++){
		int aux = 60;
		int auxj=0;
		for(int i=I, j=0; j<=5; j++){
			if(Mc[i][j] < aux && Mc[i][j] != 0){
				aux = Mc[i][j];
				auxj = j;
			}
		}if(aux == 0){
			printf("Nenhuma aresta disponivel para prosseguir!\n");
			return;
		}
		for(int m = 0; m<5; m++){
			M[I][m] = 0;
			M[m][I];
		}
		
		printf("Caminho precorrido: %d a %d      valor: %d\n\n", I+1, auxj+1, aux);
		I = auxj;
	}
}

void G_inc1(int M[5][8]){
	int I=0;

	int Mc[5][8];
	for(int i = 0; i<5;i++){
		for(int j = 0; j<8;j++){
			Mc[i][j] = M[i][j];
		}
	}
}

void G_adj2(int M[7][7]){
	int I=0;

	int Mc[7][7];
	for(int i = 0; i<7;i++){
		for(int j = 0; j<7;j++){
			Mc[i][j] = M[i][j];
		}
	}

	while(I != 6){
		int aux = 60;
		int auxj=0;
		for(int i=I, j=0; j<=7; j++){
			if(Mc[i][j] < aux && Mc[i][j] != 0){
				aux = Mc[i][j];
				auxj = j;
			}
		}if(aux == 0){
			printf("Nenhuma aresta disponivel para prosseguir!\n");
			return;
		}
		for(int m = 0; m<7; m++){
			M[I][m] = 0;
			M[m][I];
		}
		
		printf("Caminho precorrido: %d a %d      valor: %d\n\n", I+1, auxj+1, aux);
		I = auxj;
	}
}

int main(){
	int MA1[5][5] = {{0,30, 0, 0,20},
				    { 0, 0, 0,50, 0},
		 		    {15,10, 0, 5, 0},
			   	    { 0,50, 0, 0, 0},
					{ 0, 0,10,30, 0}};
	int MI1[5][8] = {{20, 0,30, 0, 0, 0, 0, 0},
		  			{  0, 0, 0, 0, 0, 0, 0,50},
		  			{  0,15, 0, 0,10, 0, 5, 0},
		  			{  0, 0, 0, 0, 0, 0, 0,50},
		  			{  0, 0, 0,10, 0,30, 0, 0}};
	int MA2[7][7]={{ 0, 2, 0, 6,12, 0, 0},
				   { 0, 0, 1, 0, 0, 6, 0},
				   { 0, 0, 0, 0, 0, 0,40},
				   { 0, 0, 0, 0, 0, 4, 0},
				   { 0, 0, 0, 0, 0, 0,30},
				   { 0, 0, 0, 0, 0, 0, 8},
				   { 0, 0, 0, 0, 0, 0, 0}};
	int MI2[7][9]={{  2,  0,  0, 6, 12, 0, 0, 0, 0},
				   { -2,  1,  0, 0,  0, 5, 0, 0, 0},
				   {  0, -1, 40, 0,  0, 0, 0, 0, 0},
				   {  0,  0,  0,-6,  0, 0, 4, 0, 0},
				   {  0,  0,  0, 0,-12, 0, 0, 0, 30},
				   {  0,  0,  0, 0,  0,-5,-4, 8, 0},
				   {  0,  0,-40, 0,  0, 0, 0,-8,-30}};

	int n;
		 do{
		 	
		 	printf("\tDigite uma opção\t\n");
		 	printf("1:Resolver problema 1 com matriz de adjacência\n");
		 	printf("2:Resolver problema 1 com matriz de incidência\n");
		 	printf("3:Resolver problema 2 com matriz de adjacência\n");
		 	printf("4:Resolver problema 2 com matriz de incidência\n");
		 	printf("0:Sair\n\n");
		 	scanf("%d", &n);
		 	switch(n){
		 		case 1:
		 			G_adj1(MA1);
		 			break;
		 		case 2:
		 			//G_inc1(MI1);
		 			break;
		 		case 3:
		 			G_adj2(MA2);
		 			break;
		 		case 4:
		 			//G_inc2(MI2);
		 			break;
		 		case 0:
		 			break;
		 		default:
		 			printf("Opção inválida!\n");
		 			break;
		 	}
		 }while(n != 0);

}