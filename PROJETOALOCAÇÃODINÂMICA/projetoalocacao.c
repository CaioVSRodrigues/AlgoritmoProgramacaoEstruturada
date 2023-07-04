#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
} Usuario;

Usuario* cadastrarUsuario() {
    // Aloca memória para a estrutura Usuario
    Usuario* novoUsuario = (Usuario*) malloc(sizeof(Usuario));

    if (novoUsuario == NULL) {
        printf("Erro ao alocar memória!\n");
        return NULL;
    }

    printf("Digite o nome do usuario: ");
    fgets(novoUsuario->nome, sizeof(novoUsuario->nome), stdin);
    novoUsuario->nome[strcspn(novoUsuario->nome, "\n")] = '\0'; // Remove o caractere de nova linha

    printf("Digite a idade do usuario: ");
    scanf("%d", &(novoUsuario->idade));

    return novoUsuario;
}

int main() {
    Usuario* usuario = cadastrarUsuario();

    if (usuario != NULL) {
        printf("Usuário cadastrado:\n");
        printf("Nome: %s\n", usuario->nome);
        printf("Idade: %d\n", usuario->idade);

        free(usuario); // Libera a memória alocada para o usuário
    }

    return 0;
}