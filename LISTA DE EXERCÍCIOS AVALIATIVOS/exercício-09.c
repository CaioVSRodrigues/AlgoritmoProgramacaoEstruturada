#include<stdio.h>
#include<locale.h>
#include<string.h>

---- INCOMPLETA --- 


int main (){
    

printf("--------------------\n");
printf("-- MERCADINHO UCB --\n");
printf("--------------------\n");


    char login[15] = "user01";
    char login1[15];
    char senha[15] = "123";
    char senha1[15];        
    int login_efetuado = 0; 
    int opcao, codigo;
    char novoProduto;

    while(!login_efetuado){
        printf("Digite o Login: ");
        scanf("%s", login1);

        printf("Digite a Senha: ");
        scanf("%s", senha1);

        if (strcmp(login, login1) == 0 && strcmp(senha, senha1) == 0){
            printf("\n\nLOGADO!\n\n");
            login_efetuado = 1;
        }
        else
            printf("\n\nDados Incorretos!\n\n");    
    }


    printf("-- Selecione a opcao desejada --\n");
    printf(" - 1 - Promocoes\n");
    printf(" - 2 - Visualizar produtos\n");
    printf(" - 3 - Realizar Compra\n");
    printf(" - 4 - Ver carrinho\n");
      scanf("%d", &opcao);

    switch(opcao){
      case 1: {
      printf("------- PROMOCOES --------\n");
      printf("ABACAXI - 5,00 a unidade\n"); 
      printf("MACA - 1,00 a unidade\n");
      printf("PERA - 4,00 a unidade\n");

      break;
      }
      case 2: {
        printf("------- PRODUTOS --------\n");
      printf("ABACAXI - 5,00 a unidade\n"); 
      printf("MACA - 1,00 a unidade\n");
      printf("PERA - 4,00 a unidade\n");
      printf("BANANA - 2,00 a unidade\n");
      printf("ABACATE - 3,00 a unidade\n");
      printf("UVA - 2,30 a unidade\n");
      printf("PERA - 4,00 a unidade\n");
      printf("KIWI - 6,00 a unidade\n");
      break;
      }
      case 3: {
         
    printf ("Deseja adicionar um novo produto ao carrinho? \n");
      gets(novoProduto);



    if(novoProduto == "s"){

    printf("Digite o codigo do produto que deseja adicionar ao carrinho: \n");
         scanf ("%d", &codigo);
    }

        


     
        
  

      }
    }




}