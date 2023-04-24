#include<stdio.h>
#include<locale.h>
#include<string.h>




int main (){
    

printf("--------------------\n");
printf("-- MERCADINHO UCB --\n");
printf("--------------------\n");


    char login[15] = "user01";
    char login1[15];
    char senha[15] = "123";
    char senha1[15];        
    int login_efetuado = 0; 
    int opcao, quantidade, continuar = 1;;
    char novoProduto;
    float total = 0;

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


    while (continuar) {
        printf("\n------- Menu de Frutas ------\n");
        printf("1 - Abacaxi - R$ 5,00 a unidade\n");
        printf("2 - Maca - R$ 1,00 a unidade\n");
        printf("3 - Pera - R$ 4,00 a unidade\n");
        printf("4 - Finalizar Compra!\n");
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Quantidade: ");
                scanf("%d", &quantidade);
                total += 5.0 * quantidade;
                printf("%d unidade(s) acrescentadas com sucesso.\n", quantidade);
                break;
            case 2:
                printf("Quantidade: ");
                scanf("%d", &quantidade);
                total += 1.0 * quantidade;
                printf("%d unidade(s) acrescentadas com sucesso.\n", quantidade);
                break;
            case 3:
                printf("Quantidade: ");
                scanf("%d", &quantidade);
                total += 4.0 * quantidade;
                printf("%d unidade(s) acrescentadas com sucesso.\n", quantidade);
                break;
            case 4:
                continuar = 0;
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    }

    printf("\nValor Total: R$ %.2f\n", total);

    return 0;
}
