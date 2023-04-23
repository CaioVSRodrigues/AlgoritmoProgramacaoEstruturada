#include<stdio.h>
#include<stdlib.h>

int main(){

double somaMultiplosDe5, somaMultiplosDe3;

printf("Multiplos de 5: \n\n");
  for(int i = 5; i < 1000; i+=5){
    printf("%d ", i);

    somaMultiplosDe5 += i;
  }

printf("\n\nMultiplos de 3: \n\n");
  for(int i = 3; i < 1000; i+=3){
    printf("%d ", i);

     somaMultiplosDe3 += i;
  }

printf("\n\n Soma Total  =  %lf", somaMultiplosDe5 + somaMultiplosDe3);


}

