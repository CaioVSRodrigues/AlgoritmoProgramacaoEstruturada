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
