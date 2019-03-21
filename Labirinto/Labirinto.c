#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


int Numero_C[] = {1, 0, -1, 0};
int Numero_L[] = {0, -1, 0, 1};
int neibs[4] = {0, 1, 2, 3};

void shuffle(int vet[]){
    for(int i = 0; i < 4; i++){//funcão para embaralhar as direções na criação do labirinto
        int pos = rand() % 4;
        int aux = vet[i];
        vet[i] = vet[pos];
        vet[pos] = aux;
    }
}

bool eh_furavel(int nl, int nc, int l, int c, char mat[nl][nc]){
    int cont = 0;

    if(mat[l][c + 1] == ' '){
        cont++;
    }
    if(mat[l - 1][c] == ' '){
        cont++;
    }
    if(mat[l][c - 1] == ' '){
        cont++;
    }
    if(mat[l + 1][c] == ' '){
        cont++;
    }

    if(cont >= 2){
        return false;
    }

    return true;
}
void show(int nl, int nc, char mat[nl][nc]){
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
                printf("%c", mat[l][c]);

        }
        puts("");
    }
}

void furar(int nl, int nc, int l, int c, char mat[nl][nc]){
    if((l < 1) || (l >= nl - 1) || (c < 1) || (c >= nc - 1)){
        return;
    }
    if(mat[l][c] == ' '){
        return;
    }
    if(!eh_furavel(nl, nc, l , c, mat)){
        return;
    }

    mat[l][c] = ' ';
    getchar();
    show(nl, nc, mat);
    shuffle(neibs);

    int i;
    for(i = 0; i < 4; i++){
        int auxiliar = neibs[i];

        furar(nl, nc, Numero_L[auxiliar] + l, Numero_C[auxiliar] + c, mat);    
    }


}
//marco como visitado
//    poe '.'
//bool procurar_saida(nl, nc, mat, mvis, l, c, lsaida, csaida)
void ja_visitei(int nl, int nc, int l, int c, char mat[nl][nc]){
    int cont = 0;

    if(mat[l][c + 1] == '.'){
        return;
    }
    if(mat[l - 1][c] == '.'){
        return;
    }
    if(mat[l][c - 1] == '.'){
        return;
    }
    if(mat[l + 1][c] == '.'){
        return;
    }
}
bool procura_caminho(int nl, int nc, int l, int c, int l_saida, int c_saida, char mat[nl][nc]){
    
    mat[l_saida][c_saida] = 'x';
    bool p_desgracado = false;
    //mostra_labirinto(num_linhas, num_colunas, mat);
    if ((mat[l][c] != ' ') && (mat[l][c] != 'x') && (mat[l][c] == '#'))//se nao for ' '
        return false;
    if(mat[l][c] == '.') //se ja foi visitado
        return false;
    if(mat[l][c] == 'x'){//se sou saida
        mat[l][c] = '0';
        return true;
    }
    
    mat[l][c] = '.'; //marco como visitado
    show(nl, nc, mat);
    getchar();
    int i = 0;
    
    for(i = 0; i < 4; i++)
        p_desgracado = procura_caminho(nl, nc, l + Numero_L[i], c + Numero_C[i], l_saida, c_saida, mat);//para cada vizinho
    
    if(p_desgracado)//se alguem retornar verdadeiro
        return true;
    
    //(mat[linhas][colunas + 1] == 'x') || (mat[linhas + 1][colunas] == 'x') || (mat[linhas - 1][colunas] == 'x') || mat[linhas][colunas - 1])
    else if(!p_desgracado)
        mat[l][c] = ' ';
    
        
    else  
        return false;
    
}

int main(){
    
    srand(time(NULL));
    int nl = 0;
    int nc = 0;

    printf("Digite o numero de linhas: ");
    scanf("%d", &nl);
    printf("Digite o numero de colunas: ");
    scanf("%d", &nc);

    char mat[nl][nc];
    
    for(int i = 0; i < nl; i++){
        for(int j = 0; j < nc; j++){
            mat[i][j] = '#';
        }
        
    }
    printf("%d %d\n", nl, nc);

    furar(nl, nc, 1, 1, mat);
    show(nl, nc, mat);

    int l_saida = 0;
    int c_saida = 0;
    printf("Digite a linha de saida: ");
    scanf("%d", &l_saida);
    printf("Digite a coluna de saida: ");
    scanf("%d", &c_saida);
    procura_caminho(nl, nc, 1, 1, l_saida, c_saida, mat);

    return 0;
}