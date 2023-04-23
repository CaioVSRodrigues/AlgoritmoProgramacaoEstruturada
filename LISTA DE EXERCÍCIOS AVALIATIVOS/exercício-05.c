#include<stdio.h>
#include<conio.h>

int main(){

int numeroPositivo, i, resto;

printf("Digite um numero positivo: ");
  scanf("%d", &numeroPositivo);

  for(i = 1; i < numeroPositivo + 1; i++){
    resto = numeroPositivo % i;
      
      if(resto == 0){
        printf("%d ", i);
      }
  }

getch(); 

 
}