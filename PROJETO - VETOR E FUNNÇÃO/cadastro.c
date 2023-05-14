#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char verificaEmail(char email[50]){
if(strstr(email, "@")){
    printf("");
}else{
    printf("caracteres Invalidos");
}

}


char verificaSexo(char sexo[12]){
if(strcmp(sexo, "Feminino")){
  printf("Sexo Valido");
} else{
  printf("Sexo Invalido");
}
}

int main(){

char nome[200], email[50], sexo[12];


 
printf("----------------\n");
printf("--- CADASTRO ---\n");
printf("----------------\n");

 
printf("Nome Completo: \n");
  gets(nome);
printf("E-mail: \n");
  gets(email);
printf("Sexo: \n");
  gets(sexo);
    

printf(verificaEmail(email));
printf(verificaSexo(sexo));




  return 0;
}