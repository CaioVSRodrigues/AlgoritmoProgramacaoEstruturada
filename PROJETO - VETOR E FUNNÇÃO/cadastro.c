
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 1000
#define MAX_STRING_SIZE 100

int user_id[MAX_USERS] = {0};
char user_name[MAX_USERS][MAX_STRING_SIZE];
char user_email[MAX_USERS][MAX_STRING_SIZE];
char user_sex[MAX_USERS][MAX_STRING_SIZE];
char user_address[MAX_USERS][MAX_STRING_SIZE];
double user_height[MAX_USERS] = {0.0};
int user_vaccine[MAX_USERS] = {0};
int num_users = 0;

int generate_user_id() {
    srand(time(NULL));
    int id = rand();
    for (int i = 0; i < num_users; i++) {
        if (user_id[i] == id) {
            id = generate_user_id();
            break;
        }
    }
    return id;
}

void add_user() {
    if (num_users == MAX_USERS) {
        printf("Limite de usuarios atingido.\n");
        return;
    }
    int id = generate_user_id();
    user_id[num_users] = id;

    printf("Digite o nome completo: ");
    fgets(user_name[num_users], MAX_STRING_SIZE, stdin);
    fflush(stdin);
    printf("Digite o email: ");
    scanf("%s", user_email[num_users]);
    printf("Digite o sexo (Feminino/Masculino/Indiferente): ");
    scanf("%s", user_sex[num_users]);
    printf("Digite o endereco: ");
    scanf("%s", user_address[num_users]);
    printf("Digite a altura (em metros): ");
    scanf("%lf", &user_height[num_users]);
    printf("Usuário vacinado? (1 para sim, 0 para não): ");
    scanf("%d", &user_vaccine[num_users]);
    num_users++;

}

void edit_user() {
    int id;
    printf("Digite o ID do usuario a ser editado: ");
    scanf("%d", &id);
    int index = -1;
    for (int i = 0; i < num_users; i++) {
        if (user_id[i] == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Usuario nao encontrado.\n");
        return;
    }
    printf("Digite o novo nome completo: ");
    fgets( user_name[num_users], MAX_STRING_SIZE, stdin);
    printf("Digite o novo email: ");
    scanf("%s", user_email[index]);
    printf("Digite o novo sexo (Feminino/Masculino/Indiferente): ");
    scanf("%s", user_sex[index]);
    printf("Digite o novo endereço: ");
    scanf("%s", user_address[index]);
    printf("Digite a nova altura (em metros): ");
    scanf("%lf", &user_height[index]);
    printf("Usuário vacinado? (1 para sim, 0 para não): ");
    scanf("%d", &user_vaccine[index]);
}

void delete_user() {
    int id;
    printf("Digite o ID do usuario a ser excluido: ");
    scanf("%d", &id);
    int index = -1;
    for (int i = 0; i < num_users; i++) {
        if (user_id[i] == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Usuario não encontrado.\n");
        return;
    }
    for (int i = index; i < num_users - 1; i++) {
        user_id[i] = user_id[i+1];
        strcpy(user_name[i], user_name[i+1]);
        strcpy(user_email[i], user_email[i+1]);
        strcpy(user_sex[i], user_sex[i+1]);
        strcpy(user_address[i], user_address[i+1]);
        user_height[i] = user_height[i+1];
        user_vaccine[i] = user_vaccine[i+1];
    }
    num_users--;
}

void search_user() {
    char email[MAX_STRING_SIZE];
    printf("Digite o email do usuario a ser buscado: ");
    scanf("%s", email);
    int index = -1;
    for (int i = 0; i < num_users; i++) {
        if (strcmp(user_email[i], email) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Usuario nao encontrado.\n");
        return;
    }
    printf("ID: %d\n", user_id[index]);
    printf("Nome completo: %s\n", user_name[index]);
    printf("Email: %s\n", user_email[index]);
    printf("Sexo: %s\n", user_sex[index]);
    printf("Endereco: %s\n", user_address[index]);
    printf("Altura: %.2lf m\n", user_height[index]);
    printf("Vacinado? %s\n", user_vaccine[index] ? "Sim" : "Não");
}

void print_all_users() {
    for (int i = 0; i < num_users; i++) {
        printf("ID: %d\n", user_id[i]);
        printf("Nome completo: %s\n", user_name[i]);
        printf("Email: %s\n", user_email[i]);
        printf("Sexo: %s\n", user_sex[i]);
        printf("Endereço: %s\n", user_address[i]);
        printf("Altura: %.2lf m\n", user_height[i]);
        printf("Vacinado? %s\n\n", user_vaccine[i] ? "Sim" : "Não");
    }
}



int main() {

    int escolha;



    printf("\t\t\t\t----------------------\n");
    printf("\t\t\t\t---- CADASTRO UCB ----\n");
    printf("\t\t\t\t----------------------\n");

    do {
        printf("\t\t\t\tEscolha uma opcaoo:\n");
        printf("\t\t\t\t1. Adicionar usuario\n");
        printf("\t\t\t\t2. Editar usuario\n");
        printf("\t\t\t\t3. Excluir usuario\n");
        printf("\t\t\t\t4. Buscar usuario pelo email\n");
        printf("\t\t\t\t5. Imprimir todos os usuarios cadastrados\n");
        printf("\t\t\t\t0. Sair\n");
        scanf("\t\t\t\t%d", &escolha);
        switch (escolha) {
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
                print_all_users();
                break;
            case 0:
                printf("Encerrando programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (escolha != 0);
    return 0;
}