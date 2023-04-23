#include<stdio.h>
#include<stdlib.h>

int main(){

int numeroFinal, sequencia;
int numero1DaSequencia = 1; int numero2DaSequencia = 0; 

printf("Digite um numero Inteiro maior ou Igual a 0: ");
  scanf("%d", &numeroFinal);

printf(" 0 ");

while(numero1DaSequencia <= numeroFinal){
  sequencia = numero1DaSequencia + numero2DaSequencia;
  printf("%d ",sequencia );

  numero1DaSequencia = numero2DaSequencia;
  numero2DaSequencia = sequencia;
}


return 0;
}