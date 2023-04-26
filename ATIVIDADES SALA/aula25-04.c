#include<stdio.h>

// vetor ; resultado par ou impar da soma

int main(){

int n1[5], n2[5], soma[5];
int i;


for(i = 0; i < 5; i++){
  
  printf("Digite a posicao %d do vetor1:\n", i);
    scanf("%d", &n1[i]);

  scanf("%d", &n1[i], &n2[i]);

  soma[i] = (n1[0] + n2[0]);


}

for(i = 0; i < 5; i++){
  printf("%d",soma[i]);

}


}



