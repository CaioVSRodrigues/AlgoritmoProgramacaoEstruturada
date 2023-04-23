#include<stdio.h>
#include <conio.h>
#include <math.h>

int main(){


float x1, x2, y1, y2, raiz, quadrado1, quadrado2;

printf("Digite o valor de x1: ");
  scanf("%3f", &x1);
printf("Digite o valor de x2: ");
  scanf("%3f", &x2);

printf("Digite o valor de y1: ");
  scanf("%3f", &y1);
printf("Digite o valor de y2: ");
  scanf("%3f", &y2);

quadrado1 = pow((x2 - x1),2);
quadrado2 = pow((y2 - y1), 2);

raiz=sqrt(quadrado1 + quadrado2);

printf("Distancia: %3f", raiz);


  return 0;
}