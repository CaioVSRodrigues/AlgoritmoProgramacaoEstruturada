#include <stdio.h>
#include <string.h>

#define MAX_USERS 1000
#define MAX_NAME_SIZE 100
#define MAX_EMAIL_SIZE 100
#define MAX_PHONE_SIZE 20

char name[MAX_USERS][MAX_NAME_SIZE];
char email[MAX_USERS][MAX_EMAIL_SIZE];
char phone[MAX_USERS][MAX_PHONE_SIZE];

int num_users = 0;

void print_menu(){
    printf("\n\n");
    printf("1 - Adicionar usuario\n");
    printf("2 - Editar usuario\n");
    printf("3 - Excluir usuario\n");
    printf("4 - Buscar usuario por email\n");
    printf("5 - Imprimir todos os usuarios\n");
    printf("6 - Fazer backup\n");
    printf("7 - Restaurar backup\n");
    printf("0 - Sair\n");
    printf("\n\n");
}

int get_option(){
    int option;
    printf("Digite a opcao desejada: ");
    scanf("%d", &option);
    return option;
}

void add_user(){
    if(num_users == MAX_USERS){
        printf("Nao e possivel adicionar mais usuarios.\n");
        return;
    }
    printf("Digite o nome do usuario: ");
    scanf("%s", name[num_users]);
    printf("Digite o email do usuario: ");
    scanf("%s", email[num_users]);
    printf("Digite o telefone do usuario: ");
    scanf("%s", phone[num_users]);
    num_users++;
    printf("Usuario adicionado com sucesso!\n");
}

void edit_user(){
    char search_email[MAX_EMAIL_SIZE];
    printf("Digite o email do usuario que deseja editar: ");
    scanf("%s", search_email);
    for(int i=0; i<num_users; i++){
        if(strcmp(email[i], search_email) == 0){
            printf("Digite o novo nome do usuario: ");
            scanf("%s", name[i]);
            printf("Digite o novo email do usuario: ");
            scanf("%s", email[i]);
            printf("Digite o novo telefone do usuario: ");
            scanf("%s", phone[i]);
            printf("Usuario editado com sucesso!\n");
            return;
        }
    }
    printf("Usuario nao encontrado.\n");
}

void delete_user(){
    char search_email[MAX_EMAIL_SIZE];
    printf("Digite o email do usuario que deseja excluir: ");
    scanf("%s", search_email);
    for(int i=0; i<num_users; i++){
        if(strcmp(email[i], search_email) == 0){
            for(int j=i; j<num_users-1; j++){
                strcpy(name[j], name[j+1]);
                strcpy(email[j], email[j+1]);
                strcpy(phone[j], phone[j+1]);
            }
            num_users--;
            printf("Usuario excluido com sucesso!\n");
            return;
        }
    }
    printf("Usuario nao encontrado.\n");
}

void search_user(){
    char search_email[MAX_EMAIL_SIZE];
    printf("Digite o email do usuario que deseja buscar: ");
    scanf("%s", search_email);
    for(int i=0; i<num_users; i++){
        if(strcmp(email[i], search_email) == 0){
            printf("Nome: %s\n", name[i]);
            printf("Email: %s\n", email[i]);
            printf("Telefone: %s\n", phone[i]);
            return;
        }
    }
    printf("Usuario nao encontrado.\n");
}

void print_users(){
    if(num_users == 0){
        printf("Nenhum usuario cadastrado.\n");
        return;
    }
    printf("Usuarios cadastrados:\n");
    for(int i=0; i<num_users; i++){
        printf("Nome: %s\n", name[i]);
        printf("Email: %s\n", email[i]);
        printf("Telefone: %s\n", phone[i]);
        printf("\n");
    }
}

void backup(){
    FILE *file = fopen("backup.txt", "w");
    if(file == NULL){
        printf("Erro ao criar arquivo de backup.\n");
        return;
    }
    fprintf(file, "%d\n", num_users);
    for(int i=0; i<num_users; i++){
        fprintf(file, "%s\n%s\n%s\n", name[i], email[i], phone[i]);
    }
    fclose(file);
    printf("Backup feito com sucesso!\n");
}

void restore(){
    FILE *file = fopen("backup.txt", "r");
    if(file == NULL){
        printf("Arquivo de backup nao encontrado.\n");
        return;
    }
    fscanf(file, "%d", &num_users);
    for(int i=0; i<num_users; i++){
        fscanf(file, "%s", name[i]);
        fscanf(file, "%s", email[i]);
        fscanf(file, "%s", phone[i]);
    }
    fclose(file);
    printf("Backup restaurado com sucesso!\n");
}

int main(){
    int option;
    do{
        print_menu();
        option = get_option();
        switch(option){
            case 1:
                add_user();
                break;
            case 2:
                edit_user();
                break;
            case 3:
                delete_user();
                break;
            case 4:
                search_user();
                break;
            case 5:
                print_users();
                break;
            case 6:
                backup();
                break;
            case 7:
                restore();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    }while(option != 0);
    return 0;
}