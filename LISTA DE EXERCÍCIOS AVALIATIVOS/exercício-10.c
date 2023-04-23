#include<stdio.h>
#include<conio.h>


int main(){

float numerosInteiros, i, soma;

printf("Digite 10 numero Inteiros: \n");

for(i = 0;i < 10;i++)
{
  scanf("%f",&numerosInteiros);
  soma=soma+numerosInteiros;

}

printf("%f", soma);
printf("\nMedia = %f", (soma / 10));


  return 0;
}