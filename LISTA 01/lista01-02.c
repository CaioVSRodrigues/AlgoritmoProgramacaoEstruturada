// Quantidade de caracteres em uma String:

#include<stdio.h> //Biblioteca de entrada e Saída;
#include<string.h> // Biblioteca para manipular 

int main(){

char primeiroNome[100];
char segundoNome[100];

printf("Digite o Primeiro nome: ");
scanf("%s", primeiroNome);

printf("Digite o Segundo nome: ");
scanf("%s", segundoNome);



if(strlen(primeiroNome) == strlen(segundoNome)){
  printf("Mesma quantidade de caracteres!")
;}else{
  printf("Quantidade de caracteres diferentes!");
}



return 0;


}



// Compare se a quantidade for igual imprimir uma mensagem;





