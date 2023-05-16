#include<stdio.h>


struct Aluno // dado chamado aluno com variaveis diferentes;
{
  char nome[20];
  char telefone[20];
  char cpf[11];
  double todoDinheiroDisponivel;
  int idade;
};

struct Professor {

char nome[20];
  char telefone[20];
  char cpf[11];
  double todoDinheiroDisponivelParaMim;

};


int main(){

int i;
int j;
struct Aluno aluno1;
struct Professor professor1;

struct Aluno listaAlunos[4];

struct Aluno listaAlunosMatriz[2][2];



printf("Digite o nome do Aluno: ");
  scanf("%d", &aluno1.nome);
printf("Digite o cpf: ");
  fgets(aluno1.cpf, 11, stdin);
printf("Digite o telefone: ");
  gets(aluno1.telefone);
printf("Digite o valor disponivel: ");
  scanf("%lf", &aluno1.todoDinheiroDisponivel);


printf("Digite o nome do Professor: ");
  fgets(professor1.nome, 20, stdin);


for(i = 0; i < 50; i++){

  printf("Digite o nome do aluno: ");
  fgets(listaAlunos[i].nome, 20, stdin);
  printf("Digite a idade: "); 
    scanf("%d", &listaAlunos[i].idade);

}

  

  for(i = 0; i < 2; i++){
    for(j = 0; j < 2; j++){
      printf("Digite o nome do aluno: ");
        fgets(listaAlunosMatriz[i][j].nome,4, stdin);
    }
  }




}