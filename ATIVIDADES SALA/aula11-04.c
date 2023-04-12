
#include<stdio.h>

int convertTempCelsius(int graus){
  int convert;
  convert = (9 * graus / 5) + 32;
  return (convert);

}



int main(){

    int graus, convert;

    printf("Digite quantos graus deseja converter de Celsius para Fah: ");
      scanf("%d", &graus);

  convert = convertTempCelsius(graus);

  printf("O resultado da sua conversao e de: %d", convert);

  
  

    return 0;
}

