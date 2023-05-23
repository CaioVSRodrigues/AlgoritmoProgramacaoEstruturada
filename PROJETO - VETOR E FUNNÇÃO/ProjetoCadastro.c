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
}