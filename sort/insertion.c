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

void insertion_sort(int vet[], int size){
    int i;
    int j;

    for(i = 0; i < size; i++){
        for(j = i; j > 0; j--)
            if(vet[j] < vet[j-1]){
		        xd_vet(vet, size, "ygr", i, vet, size);
                SUAPI(vet[j], vet[j-1], int);
		        xd_vet(vet, size, "ygr", i, vet, size);
                //show(vet, size);
	    }
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
    insertion_sort(vet, size);
    x_close();
}