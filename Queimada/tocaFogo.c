#include <stdio.h>
#include<stdlib.h>
#include<time.h>


int descolamento_linhas[] = {0, -1, 0, 1};//indica as possições que vai percorrer na matrix
int deslocamento_colunas[] = {-1, 0, 1, 0};//indica as possições que vai percorrer na matrix
int qtd_lados = sizeof(descolamento_linhas) / sizeof(int);// facilita andar pelas diagonais e tambem quantas posições tem no vetor

void embaralhar(int vetor[], int size){

	int i = 0;
	
	for(i = 0; i < size; i++){
		int esc = rand() % size;// randomizar um numero 
		int temp = vetor[i];
		vetor[i] = vetor[esc];
		vetor[i] = temp;
	}
}

void show(int nl, int nc, char mat[nl][nc]){

    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++)
            printf("%c", mat[l][c]);
        puts("");
    }
}

int tocar_fogo(int nl, int nc, char mat[nl][nc], int l, int c){

    if((l < 0) || (l >= nl) || (c < 0) || (c >= nc))
        return 0;
    if(mat[l][c] != '#')
        return 0;
    mat[l][c] = 'o';
    getchar();
    show(nl, nc, mat);
    
    int v = 0;
    int cont = 1;
	int vizin[] = {0, 1, 2, 3};

	embaralhar(vizin, qtd_lados);
	for(v = 0; v < qtd_lados; v++){
		int i = vizin[v];// para o jovem dinâmico compreender melhor
		cont += tocar_fogo(nl, nc, mat,  l + descolamento_linhas[i], c + deslocamento_colunas[i]);
	}

	mat[l][c] = 'x';
	getchar();
	show(nl, nc, mat);
	

	return cont;
   
}

int main(){

    int nl = 0;
    int nc = 0;
    int l = 0;
    int c = 0;
    int espaco = 0;
    int j;

    srand(time(NULL));
    puts("Digite a dimensao da matrix: ");
    scanf("%d %d", &nl, &nc);
    char mat[nl][nc];
    puts("Digite a porcentagem de espacos vazios: ");
    scanf("%d", &espaco);

    for(l = 0; l < nl; l++)
        for(j = 0; j < nc; j++)
            if(rand() % 101 <= espaco) //bugou o jovem dinâmico
            	mat[l][j] = '.';
            else
            	mat[l][j] = '#';

    show(nl, nc, mat);

    printf("Digite a posicao na qual quer iniciar: ");
    scanf("%d %d", &l, &c);

    int cont = tocar_fogo(nl, nc, mat, l, c);
    getchar();
    show(nl, nc, mat);
    printf("%d", cont);

}