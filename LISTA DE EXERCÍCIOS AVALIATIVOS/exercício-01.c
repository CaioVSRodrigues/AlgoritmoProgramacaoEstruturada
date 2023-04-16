#include<stdio.h>

int main(){

int a, b, c, d, produtoAeB, produtoCeD, diferencaDosProdutos;

printf("Digite o Primeiro valor: ");
  scanf("%d", &a);
printf("Digite o Segundo valor: ");
  scanf("%d", &b);
printf("Digite o Terceiro valor: ");
  scanf("%d", &c);
printf("Digite o Quarto valor: ");
  scanf("%d", &d);

produtoAeB = a * b;
produtoCeD = c * d;
diferencaDosProdutos = (a * b - c * d);


printf("Produto de A e B = %d", produtoAeB);
printf("\nProduto de C e D = %d", produtoCeD);
printf("\n A diferenca dos produtos e de = %d", diferencaDosProdutos);


  return 0;
}