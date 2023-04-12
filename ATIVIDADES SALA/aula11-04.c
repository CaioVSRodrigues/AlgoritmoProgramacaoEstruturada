
#include<stdio.h>

int convertTempCelsius(int graus){
  int convert;
  convert = (9 * graus / 5) + 32;
  return (convert);

}

int convertTempFahrenheit(int fah){
  int convert2;
  convert2 = (fah - 32) * 5 /9;
  return (convert2);
}

int main(){

    int graus, fah, convert2, convert;

    printf("Digite quantos graus deseja converter de Celsius para Fah: ");
      scanf("%d", &graus);

  convert = convertTempCelsius(graus);

  printf("O resultado da sua conversao e de: %d", convert);

    printf("\nDigite quantos graus deseja converter de Fah para C: ");
      scanf("%d", &fah);

  convert2 = convertTempCelsius(fah);

  printf("O resultado da sua conversao e de: %d", convert2);

  

    return 0;
}

