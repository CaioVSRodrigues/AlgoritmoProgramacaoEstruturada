#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char verificaEmail(char email[50]){
if(strstr(email, "@")){
    printf("");
}else{
    printf("\t\t\t\tEmail Invalido\n");
}

}

char verificaSexo(char sexo[20]){
    
    if(strcmp(sexo, "Masculino")){
    printf("\t\t\t\tSexo Invalido\n");
}else{
    printf("");
}

}

double verificaAltura( double altura){
    if(altura >= 1 && altura <=2 ){
  printf("");
}else{
  printf("\t\t\t\tAltura Invalida");
}

}




int main(){



char nome[100], email[50], sexo[20];
char retorno;
char endereco[100];
double altura;
int vacina;
int opcao;


printf("\t\t\t\t----------------------\n");
printf("\t\t\t\t--- SEJA BEM VINDO ---\n");
printf("\t\t\t\t----------------------\n");

printf("\t\t\t\t1 - Iniciar\n");
printf("\t\t\t\t0 - Sair\n");
  scanf("%d", &opcao);

  switch(opcao){
    case 1:  
printf("\t\t\t\t----------------\n");
printf("\t\t\t\t--- CADASTRO ---\n");
printf("\t\t\t\t----------------\n");

 
printf("\t\t\t\tNome Completo: \n");
  gets(nome);
printf("\t\t\t\tE-mail: \n");
  gets(email);
printf("\t\t\t\tSexo: \n");
  gets(sexo);
printf("\t\t\t\tEndereco: \n");
  gets(endereco);
printf("\t\t\t\tAltura: ");
  scanf("%.2f", &altura);
printf("\t\t\t\tVacina: \n");
  printf("\t\t\t\t1 - Sim; 2 - Nao: \n");
    scanf("%d", &vacina);
    


retorno = verificaSexo(sexo);
    printf("%c", retorno);

printf(verificaEmail(email));

printf("%.2f", verificaAltura(altura));;

    break;
case 0: ;
break;
  } 






  return 0;
}




.