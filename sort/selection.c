#include "xvet.h"
#include "xpaint.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUAPI(a, b, type) do{type aux = a; a = b; b = aux;}while(0)

void show(int vet[], int size){
    int i;

    for(i = 0; i < size; i++){
        printf(" %d ", vet[i]);
    }printf("\n");
}

int achaS(int vet[], int size, int inicio){

    int Imenor = inicio;
    int i = Imenor + 1;
    
    for(; i < size; i++){
        if(vet[i] < vet[Imenor]){
            Imenor = i;
        }
    }
    return Imenor;
}

void selection(int vet[], int size){
    int i = 0;
    for(;i < size ;i++){
        int Imenor = achaS(vet, size, i);
        xd_vet(vet, size, i, "ygr", i, vet, size);
        SUAPI(vet[i], vet[Imenor], int);
        xd_vet(vet, size, i, "ygr", i, vet, size);
    }
}

int main(){
    x_open(600, 300);
    int vet[20];
    int size = sizeof(vet) / sizeof(int);
    srand(time(NULL));
    int i;

    for(i = 0; i < 20; i++){
        vet[i] = rand() % 101;
    }
    selection(vet, size);
    x_close();
}