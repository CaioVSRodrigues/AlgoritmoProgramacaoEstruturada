#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



int totalUsuarios = 0;
int ids[1000];
char nomes[1000][50];
char emails[1000][50];
char sexos[1000][50];
char enderecos[1000][100];
float alturas[1000];
char vacinas[1000][50];

int gerarId() {
    srand(time(NULL));
    return rand() % 1000 + 7;
}


int validarEmail(const char* email) {
    int i;
    int atCount = 0;
    int dotCount = 0;

    for (i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            atCount++;
        } else if (email[i] == '.') {
            dotCount++;
        }
    }

    if (atCount == 1 && dotCount >= 1) {
        return 1;
    } else {
        return 0;
    }
}


int validarSexo(const char* sexo) {
    if (strcmp(sexo, "Feminino") == 0 || strcmp(sexo, "Masculino") == 0 || strcmp(sexo, "Indiferente") == 0) {
        return 1;
    } else {
        return 0;
    }
}


int validarAltura(float altura) {
    if (altura >= 1.0 && altura <= 2.0) {
        return 1;
    } else {
        return 0;
    }
}


void adicionarUsuario() {
    if (totalUsuarios == 1000) {
        printf("Limite maximo de usuarios alcancado.\n");
        return;
    }

    int id = gerarId();
    ids[totalUsuarios] = id;

    printf("\n---- Adicionar Usuario ----\n");

    printf("Nome completo: ");
    fgets(nomes[totalUsuarios], 50, stdin);
    nomes[totalUsuarios][strcspn(nomes[totalUsuarios], "\n")] = '\0';

    char email[50];
    do {
        printf("Email: ");
        fgets(email, sizeof(email), stdin);
        email[strlen(email) - 1] = '\0';
        if (!validarEmail(email)) {
            printf("Email invalido. Por favor, insira um email valido.\n");
        }
    } while (!validarEmail(email));
    strcpy(emails[totalUsuarios], email);

    char sexo[50];
    do {
        printf("Sexo (Feminino/Masculino/Indiferente): ");
        fgets(sexo, sizeof(sexo), stdin);
        sexo[strlen(sexo) - 1] = '\0';
        if (!validarSexo(sexo)) {
            printf("Sexo invalido. Por favor, insira um sexo valido.\n");
        }
    } while (!validarSexo(sexo));
    strcpy(sexos[totalUsuarios], sexo);

    printf("Endereco: ");
    fgets(enderecos[totalUsuarios], 100, stdin);
    enderecos[totalUsuarios][strcspn(enderecos[totalUsuarios], "\n")] = '\0';

    float altura;
    do {
        printf("Altura (em metros): ");
        scanf("%f", &altura);
        getchar();  
        if (!validarAltura(altura)) {
            printf("Altura invalida. Por favor, insira uma altura entre 1 e 2 metros.\n");
        }
    } while (!validarAltura(altura));
    alturas[totalUsuarios] = altura;

    printf("Vacina: ");
    fgets(vacinas[totalUsuarios], 50, stdin);
    vacinas[totalUsuarios][strcspn(vacinas[totalUsuarios], "\n")] = '\0';

    totalUsuarios++;
    printf("\nUsuario adicionado com sucesso. ID: %d\n", id);
}


void buscarUsuarioPorEmail(const char* email) {
    int encontrado = 0;
    printf("\n---- Resultado da Busca ----\n");
    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(emails[i], email) == 0) {
            imprimirUsuario(i);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Nenhum usuario encontrado com o email: %s\n", email);
    }
}


void editarUsuario(int id) {
    int indice = -1;
    for (int i = 0; i < totalUsuarios; i++) {
        if (ids[i] == id) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("Usuario com ID %d não encontrado.\n", id);
        return;
    }

    printf("\n---- Editar Usuario ----\n");

    printf("Nome completo [%s]: ", nomes[indice]);
    fgets(nomes[indice], 50, stdin);
    nomes[indice][strcspn(nomes[indice], "\n")] = '\0';

    char email[50];
    do {
        printf("Email [%s]: ", emails[indice]);
        fgets(email, sizeof(email), stdin);
        email[strlen(email) - 1] = '\0';
        if (!validarEmail(email)) {
            printf("Email invalido. Por favor, insira um email valido.\n");
        }
    } while (!validarEmail(email));
    strcpy(emails[indice], email);

    char sexo[50];
    do {
        printf("Sexo (Feminino/Masculino/Indiferente) [%s]: ", sexos[indice]);
        fgets(sexo, sizeof(sexo), stdin);
        sexo[strlen(sexo) - 1] = '\0';
        if (!validarSexo(sexo)) {
            printf("Sexo invalido. Por favor, insira um sexo valido.\n");
        }
    } while (!validarSexo(sexo));
    strcpy(sexos[indice], sexo);

    printf("Endereco [%s]: ", enderecos[indice]);
    fgets(enderecos[indice], 100, stdin);
    enderecos[indice][strcspn(enderecos[indice], "\n")] = '\0';

    float altura;
    do {
        printf("Altura (em metros) [%.2f]: ", alturas[indice]);
        scanf("%f", &altura);
        getchar();  // Limpa o buffer do teclado
        if (!validarAltura(altura)) {
            printf("Altura invalida. Por favor, insira uma altura entre 1 e 2 metros.\n");
        }
    } while (!validarAltura(altura));
    alturas[indice] = altura;

    printf("Vacina [%s]: ", vacinas[indice]);
    fgets(vacinas[indice], 50, stdin);
    vacinas[indice][strcspn(vacinas[indice], "\n")] = '\0';

    printf("\nUsuario editado com sucesso. ID: %d\n", id);
}

void excluirUsuario(int id) {
    int indice = -1;
    for (int i = 0; i < totalUsuarios; i++) {
        if (ids[i] == id) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("Usuario com ID %d nao encontrado.\n", id);
        return;
    }


    for (int i = indice; i < totalUsuarios - 1; i++) {
        ids[i] = ids[i + 1];
        strcpy(nomes[i], nomes[i + 1]);
        strcpy(emails[i], emails[i + 1]);
        strcpy(sexos[i], sexos[i + 1]);
        strcpy(enderecos[i], enderecos[i + 1]);
        alturas[i] = alturas[i + 1];
        strcpy(vacinas[i], vacinas[i + 1]);
    }

    totalUsuarios--;
    printf("Usuario com ID %d excluido com sucesso.\n", id);
}