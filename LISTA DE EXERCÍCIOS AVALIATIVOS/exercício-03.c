#include<stdio.h>
#include <conio.h>
#include <math.h>



int main(){

float raio,volume, area, cubo, quadrado;


printf("-- Calculo da Superficie e o Volume de Uma esfera --\n");

printf("\nDigite o Raio: ");
  scanf("%f", &raio);

  cubo = pow(raio, 3);
  quadrado = pow(raio, 2);

volume = (4/3.0) * 3.14159 * cubo;
area = 4 * 3.14159 * quadrado;



printf("\nVolume da Esfera: %f\n", volume);
printf("Area da Superficie: %f", area);





  return 0;
}