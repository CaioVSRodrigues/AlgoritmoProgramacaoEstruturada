#include<stdio.h>
#include<string.h>


int main(){


int vetor[80], i = 0, nBusca, posicao[80], contador = 0, numeroValores;
char opcao[3];

do{
  printf("Digite o valor: \n");
scanf("%d", &vetor[i]);
i++;
  printf("Deseja incluir mais um numero ? Sim ou Nao");
    gets(opcao);

}while(strcmp (opcao, "Sim") == 0 && i < 80);

printf("Digite o numero: \n");
  scanf("%d", &nBusca);

numeroValores = i;


for(i = 0; i < numeroValores; i++){
  if(nBusca == vetor[i]){
    posicao[contador] = i;
    contador++;
    //printf("%d", contador);


  }

}

printf("Quantidade de vezes que o numero %d aparece: %d", nBusca, contador);

for(i = 0; i < contador; i++){


}

  printf("%d", posicao);


}