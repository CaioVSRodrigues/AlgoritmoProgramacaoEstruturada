#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[100];
    int idade;
} Usuario;

Usuario* cadastrarUsuario() {
    
    Usuario* novoUsuario = (Usuario*) malloc(sizeof(Usuario));

    if (novoUsuario == NULL) {
        printf("Erro ao alocar memória!\n");
        return NULL;
    }

    novoUsuario->id = 1; 
    printf("Digite o nome do usuário: ");
    fgets(novoUsuario->nome, sizeof(novoUsuario->nome), stdin);
    novoUsuario->nome[strcspn(novoUsuario->nome, "\n")] = '\0'; 

    printf("Digite a idade do usuário: ");
    scanf("%d", &(novoUsuario->idade));

    return novoUsuario;
}

void editarUsuario(Usuario* usuario) {
    printf("Digite o novo nome do usuário: ");
    fgets(usuario->nome, sizeof(usuario->nome), stdin);
    usuario->nome[strcspn(usuario->nome, "\n")] = '\0'; 

    printf("Digite a nova idade do usuário: ");
    scanf("%d", &(usuario->idade));
}

void excluirUsuario(Usuario* usuario) {
    free(usuario); 
    printf("Usuário excluído com sucesso!\n");
}

void listarUsuarios(Usuario** usuarios, int count) {
    printf("Usuários cadastrados:\n");
    for (int i = 0; i < count; i++) {
        printf("Usuário %d:\n", usuarios[i]->id);
        printf("Nome: %s\n", usuarios[i]->nome);
        printf("Idade: %d\n", usuarios[i]->idade);
        printf("\n");
    }
}

int main() {
    Usuario* usuarios[100]; 
    int count = 0; 
    int proximoId = 1; 

    char opcao;
    do {
        printf("Opções:\n");
        printf("1 - Cadastrar usuário\n");
        printf("2 - Editar usuário\n");
        printf("3 - Excluir usuário\n");
        printf("4 - Listar usuários\n");
        printf("5 - Sair\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &opcao);
        getchar(); 

        printf("\n");

        switch (opcao) {
            case '1': {
                Usuario* novoUsuario = cadastrarUsuario();
                if (novoUsuario != NULL) {
                    novoUsuario->id = proximoId++; 
                    usuarios[count] = novoUsuario;
                    count++;
                    printf("Usuário cadastrado com sucesso! ID: %d\n", novoUsuario->id);
                }
                break;
            }
            case '2': {
                int index;
                printf("Digite o ID do usuário que deseja editar: ");
                scanf("%d", &index);
                if (index >= 1 && index <= count) {
                    editarUsuario(usuarios[index - 1]);
                    printf("Usuário editado com sucesso!\n");
                } else {
                    printf("ID de usuário inválido!\n");
                }
                break;
            }
            case '3': {
                int index;
                printf("Digite o ID do usuário que deseja excluir: ");
                scanf("%d", &index);
                if (index >= 1 && index <= count) {
                    excluirUsuario(usuarios[index - 1]);
                    for (int i = index - 1; i < count - 1; i++) {
                        usuarios[i] = usuarios[i + 1];
                    }
                    count--;
                    printf("Usuário excluído com sucesso!\n");
                } else {
                    printf("ID de usuário inválido!\n");
                }
                break;
            }
            case '4': {
                listarUsuarios(usuarios, count);
                break;
            }
            case '5':
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }

        printf("\n");
    } while (opcao != '5');

   
    for (int i = 0; i < count; i++) {
        free(usuarios[i]);
    }

    return 0;
}