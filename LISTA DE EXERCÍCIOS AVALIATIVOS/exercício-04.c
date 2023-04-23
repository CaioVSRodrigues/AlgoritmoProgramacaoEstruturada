#include<stdio.h>
#include<stdlib.h>


int main(){

int x, y;

printf("Digite o Valor de X: ");
  scanf("%d", &x);
printf("Digite o Valor de Y: ");
  scanf("%d", &y);  


  if(x == 0 && y == 0){
    printf("ORIGEM");
  } else if(x > 0 && y > 0){
    printf("PRIMEIRO QUADRANTE");
  }else if(x < 0 && y > 0){
    printf("SEGUNDO QUADRANTE");
  }else if(x < 0 && y < 0){
    printf("TERCEIRO QUADRANTE");
  }else if(x > 0 && y < 0){
    printf("QUARTO QUADRANTE");

  }



  return 0;
}