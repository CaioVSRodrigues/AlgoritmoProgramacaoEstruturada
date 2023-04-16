#include<stdio.h>

int main(){

int numeroInteiro;
int maiorNumero = 0, menorNumero = 0;

do{

  printf("Digite um numero inteiro: ");
  scanf("%d", &numeroInteiro);

}while(numeroInteiro > 0);

if(numeroInteiro == 0){
  maiorNumero = numeroInteiro;
  menorNumero = numeroInteiro;
}else if(numeroInteiro > maiorNumero){
  maiorNumero = numeroInteiro;
}else if(numeroInteiro < maiorNumero){
  menorNumero = numeroInteiro;
}

printf("Menor valor: %d", menorNumero);
printf("\nMaior valor: %d", maiorNumero);



  return 0;
}