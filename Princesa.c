#include <stdio.h>

/*Rece um vetor de 0 a total - 1, e uma posição do atual vetor
* e retorna a proxima posição que for diferente de zero.
*/
int prox_p(int vetor[],int total,int atual)
{
	do
	{
		atual = (atual+1)%total;
	}
	while(vetor[atual] == 0);

	return atual;
}

/*Rece um vetor de 0 a total - 1, e uma posição do atual vetor
* e retorna a proxima posição que for diferente de zero.
*/
int prox_n(int vetor[],int total,int atual)
{
	do
  {
        if(atual == 0)
        {
            atual = total - 1;
        }
        else
        {
            atual--;
        }
    }while(vetor[atual] == 0);

    return atual;
}

int main()
{
	int total;
	int atual;
	int op;

	scanf("%d", &total);
	scanf("%d", &atual);
	scanf("%d", &op);

	int vetor[total];
	int i;

	for(i = 0; i < total; i++)
	{

		vetor[(atual + i) % total] = op; // A contage deve começar do atual , então a posição deve ser atual + 1, e deve tirar o mudulo para tornar ciclica ou seja de atual até atual - 1

		op = -1*op;//inverte
	}

	int mortos;
	int tmp;

	atual--;

	mortos = 0;
	while(mortos < total - 1)
	{
		for(i = 0; i < total; i++)
		{
			if(vetor[i] != 0)
			{
				printf("%d ",(i+1)*vetor[i]);
			}
		}

		if(vetor[atual] == 1)
		{
			tmp = 1;
			atual = prox_p(vetor, total, atual);
		}
		else
		{
			tmp = -1;
			atual = prox_n(vetor, total, atual);
		}

		vetor[atual] = 0;

		if(tmp == 1)
		{
			atual = prox_p(vetor, total, atual);
		}
		else
		{
			atual = prox_n(vetor, total, atual);
		}

		printf("\n");
		mortos++;
	}

	printf("%d\n", (atual + 1)*vetor[atual]);
}
