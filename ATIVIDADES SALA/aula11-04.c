
#include<stdio.h>

float convertTempCelsius(float graus){
  float convert;
  convert = (9 * graus / 5) + 32;
  return (convert);

}



int main(){

    float graus, convert;

    printf("Digite quantos graus deseja converter de Celsius para Fah: ");
      scanf("%f", &graus);

  convert = convertTempCelsius(graus);

  printf("O resultado da sua conversao e de: %f", convert);

  
  

    return 0;
}

