#include<stdio.h>


int main(){

int numeroInterio;
float numeroRealFloat;
double numeroRealDouble;
char umaLetra;
char umaString[100];


printf("Digite um numero Inteiro: ");
  scanf("%d", &numeroInterio);
printf("Digite um numero real Float: ");
 scanf("%f", &numeroRealFloat);
printf("Digite um numero real Double: ");
  scanf("%lf", &numeroRealDouble);
printf("Digite uma letra: ");
  scanf("%c", &umaLetra);
printf("\nDigite uma palavra: ");
  scanf("%s", &umaString);

printf("--------------------");
printf("-----RESUlTADO------");
printf("--------------------");

printf("\nNumero Inteiro: %3d", numeroInterio);
printf("\nNumero Real Float %3f", numeroRealFloat);
printf("\nNumero Real Double: %3lf", numeroRealDouble);
printf("\nUma letra: %c", umaLetra);
printf("\numa String: %3s", umaString);




  return 0;
}

