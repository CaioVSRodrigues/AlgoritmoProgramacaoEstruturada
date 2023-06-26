#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USUARIOS 1000
#define MAX_NOME 50
#define MAX_EMAIL 50
#define MAX_SEXO 50
#define MAX_ENDERECO 100
#define MAX_VACINA 50

typedef struct {
int id;
char nome[MAX_NOME];
char email[MAX_EMAIL];
char sexo[MAX_SEXO];
char endereco[MAX_ENDERECO];
float altura;
char vacina[MAX_VACINA];
} Usuario;

Usuario usuarios[MAX_USUARIOS];
int totalUsuarios = 0;

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
if (totalUsuarios == MAX_USUARIOS) {
printf("Não é possível adicionar mais usuários.\n");
return;
}

int id = gerarId();
usuarios[totalUsuarios].id = id;

printf("\n---- Adicionar Usuario ----\n");

printf("Nome completo: ");
fgets(usuarios[totalUsuarios].nome, MAX_NOME, stdin);
usuarios[totalUsuarios].nome[strcspn(usuarios[totalUsuarios].nome, "\n")] = '\0';

char email[MAX_EMAIL];
do {
    printf("Email: ");
    fgets(email, sizeof(email), stdin);
    email[strlen(email) - 1] = '\0';
    if (!validarEmail(email)) {
        printf("Email inválido. Por favor, insira um email válido.\n");
    }
} while (!validarEmail(email));
strcpy(usuarios[totalUsuarios].email, email);

char sexo[MAX_SEXO];
do {
    printf("Sexo (Feminino/Masculino/Indiferente): ");
    fgets(sexo, sizeof(sexo), stdin);
    sexo[strlen(sexo) - 1] = '\0';
    if (!validarSexo(sexo)) {
        printf("Sexo inválido. Por favor, insira um sexo válido.\n");
    }
} while (!validarSexo(sexo));
strcpy(usuarios[totalUsuarios].sexo, sexo);

printf("Endereco: ");
fgets(usuarios[totalUsuarios].endereco, MAX_ENDERECO, stdin);
usuarios[totalUsuarios].endereco[strcspn(usuarios[totalUsuarios].endereco, "\n")] = '\0';

float altura;
do {
    printf("Altura (em metros): ");
    scanf("%f", &altura);
    getchar();  
    if (!validarAltura(altura)) {
        printf("Altura inválida. Por favor, insira uma altura entre 1 e 2 metros.\n");
    }
} while (!validarAltura(altura));
usuarios[totalUsuarios].altura = altura;

printf("Vacina: ");
fgets(usuarios[totalUsuarios].vacina, MAX_VACINA, stdin);
usuarios[totalUsuarios].vacina[strcspn(usuarios[totalUsuarios].vacina, "\n")] = '\0';

totalUsuarios++;
printf("\nUsuário adicionado com sucesso. ID: %d\n", id);

}

void imprimirUsuario(const Usuario* usuario) {
printf("\n---- Usuario ID: %d ----\n", usuario->id);
printf("Nome: %s\n", usuario->nome);
printf("Email: %s\n", usuario->email);
printf("Sexo: %s\n", usuario->sexo);
printf("Endereço: %s\n", usuario->endereco);
printf("Altura: %.2f\n", usuario->altura);
printf("Vacina: %s\n", usuario->vacina);
}

void imprimirUsuarios() {
printf("\n---- Lista de Usuarios ----\n");
for (int i = 0; i < totalUsuarios; i++) {
imprimirUsuario(&usuarios[i]);
}
}

void buscarUsuarioPorEmail(const char* email) {
int encontrado = 0;
printf("\n---- Resultado da Busca ----\n");
for (int i = 0; i < totalUsuarios; i++) {
if (strcmp(usuarios[i].email, email) == 0) {
imprimirUsuario(&usuarios[i]);
encontrado = 1;
break;
}
}
if (!encontrado) {
printf("Nenhum usuário encontrado com o email: %s\n", email);
}
}

void editarUsuario(int id) {
int indice = -1;
for (int i = 0; i < totalUsuarios; i++) {
if (usuarios[i].id == id) {
indice = i;
break;
}
}

if (indice == -1) {
    printf("Usuário com ID %d não encontrado.\n", id);
    return;
}

printf("\n---- Editar Usuario ----\n");

printf("Nome completo [%s]: ", usuarios[indice].nome);
fgets(usuarios[indice].nome, MAX_NOME, stdin);
usuarios[indice].nome[strcspn(usuarios[indice].nome, "\n")] = '\0';

char email[MAX_EMAIL];
do {
    printf("Email [%s]: ", usuarios[indice].email);
    fgets(email, sizeof(email), stdin);
    email[strlen(email) - 1] = '\0';
    if (!validarEmail(email)) {
        printf("Email inválido. Por favor, insira um email válido.\n");
    }
} while (!validarEmail(email));
strcpy(usuarios[indice].email, email);

char sexo[MAX_SEXO];
do {
    printf("Sexo (Feminino/Masculino/Indiferente) [%s]: ", usuarios[indice].sexo);
    fgets(sexo, sizeof(sexo), stdin);
    sexo[strlen(sexo) - 1] = '\0';
    if (!validarSexo(sexo)) {
        printf("Sexo inválido. Por favor, insira um sexo válido.\n");
    }
} while (!validarSexo(sexo));
strcpy(usuarios[indice].sexo, sexo);

printf("Endereco [%s]: ", usuarios[indice].endereco);
fgets(usuarios[indice].endereco, MAX_ENDERECO, stdin);
usuarios[indice].endereco[strcspn(usuarios[indice].endereco, "\n")] = '\0';

float altura;
do {
    printf("Altura (em metros) [%.2f]: ", usuarios[indice].altura);
    scanf("%f", &altura);
    getchar();  
    if (!validarAltura(altura)) {
        printf("Altura inválida. Por favor, insira uma altura entre 1 e 2 metros.\n");
    }
} while (!validarAltura(altura));
usuarios[indice].altura = altura;

printf("Vacina [%s]: ", usuarios[indice].vacina);
fgets(usuarios[indice].vacina, MAX_VACINA, stdin);
usuarios[indice].vacina[strcspn(usuarios[indice].vacina, "\n")] = '\0';

printf("\nUsuário editado com sucesso. ID: %d\n", id);

}

void excluirUsuario(int id) {
int indice = -1;
for (int i = 0; i < totalUsuarios; i++) {
if (usuarios[i].id == id) {
indice = i;
break;
}
}

if (indice == -1) {
    printf("Usuário com ID %d não encontrado.\n", id);
    return;
}

for (int i = indice; i < totalUsuarios - 1; i++) {
    usuarios[i] = usuarios[i + 1];
}

totalUsuarios--;
printf("Usuário com ID %d excluído com sucesso.\n", id);

}

void exibirMenu() {
printf("----- CADASTRO UCB -----\n");
printf("1. Adicionar Usuário\n");
printf("2. Editar Usuário\n");
printf("3. Excluir Usuário\n");
printf("4. Buscar Usuário por Email\n");
printf("5. Imprimir Todos os Usuários\n");
printf("6. Sair\n");
printf("------------------------\n");
printf("Digite a opção desejada: ");
}

int main() {
int opcao;

do {
    exibirMenu();
    scanf("%d", &opcao);
    getchar();  

    switch (opcao) {
        case 1:
            adicionarUsuario();
            break;
        case 2:
            if (totalUsuarios == 0) {
                printf("Nenhum usuário cadastrado.\n");
            } else {
                int id;
                printf("Digite o ID do usuário a ser editado: ");
                scanf("%d", &id);
                getchar();  
                editarUsuario(id);
            }
            break;
        case 3:
            if (totalUsuarios == 0) {
                printf("Nenhum usuário cadastrado.\n");
            } else {
                int id;
                printf("Digite o ID do usuário a ser excluído: ");
                scanf("%d", &id);
                getchar();  
                excluirUsuario(id);
            }
            break;
        case 4:
            if (totalUsuarios == 0) {
                printf("Nenhum usuário cadastrado.\n");
            } else {
                char email[MAX_EMAIL];
                printf("Digite o email do usuário a ser buscado: ");
                fgets(email, sizeof(email), stdin);
                email[strlen(email) - 1] = '\0';
                buscarUsuarioPorEmail(email);
            }
            break;
        case 5:
            if (totalUsuarios == 0) {
                printf("Nenhum usuário cadastrado.\n");
            } else {
                imprimirUsuarios();
            }
            break;
        case 6:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida. Por favor, escolha uma opção válida.\n");
            break;
    }

    printf("\n");
} while (opcao != 6);

return 0;

}