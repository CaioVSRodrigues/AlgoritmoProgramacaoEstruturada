#include<stdio.h>

float calculaFuncaox(float k, float f){
  float result;
  result = k - f + 273.15;
  return result;
}


int main(){

float k, f, result;

printf("Digite um Valor: ");
  scanf("%f", &k);
printf("Digite outro valor: ");
  scanf("%f", &f);

result = calculaFuncaox(k, f);

printf("O seu valor e de: %f", result);


  return 0;
}