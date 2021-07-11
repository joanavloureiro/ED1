#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct aluno {
    char* nome;
    int matricula;
    float p1;
    float p2;
    float p3;
};

typedef struct aluno Aluno;

char* lelinha (void){
    char linha[121];
    printf("Digite um nome: ");
    scanf(" %120[^\n]", linha);
    
    return strdup(linha);
}

void imprime_aprovados(int n, Aluno** turma){
    printf("Alunos aprovados:\n");
    for(int i=0; i<n; i++){
        if((turma[i]->p1 + turma[i]->p2 +turma[i]->p3)/3 >=5){
            printf("%s\n", turma[i]->nome);
        }
    }
}

float media_turma(int n, Aluno** turma){
    float media=0;
    for(int i=0; i<n; i++){
        media = media + ((turma[i]->p1 + turma[i]->p2 + turma[i]->p3)/3);
    }
    media=media/n;
    
    return media;
}

int main(){
    int n, i, j;

    printf("Qual o numero de alunos da turma?\n");
    scanf("%d", &n);

    Aluno** turma = (Aluno**) malloc (n * sizeof(Aluno*));

    for(i=0; i<n; i++){
        turma[i] = (Aluno*) malloc (sizeof(Aluno));

        turma[i]->nome = lelinha();

        printf("Digite a matricula de %s: ", turma[i]->nome);
        scanf("%d", &turma[i]->matricula);

        printf("Digite as três notas de %s separadas por espaço, respectivamente p1, p2 e p3: ", turma[i]->nome);
        scanf("%f%f%f", &turma[i]->p1, &turma[i]->p2, &turma[i]->p3);
    };

    printf("Lista dos alunos:\n");

    for(j=0; j<n; j++){
        printf("Nome: %s, Matricula: %d, P1: %.2f, P2: %.2f, P3: %.2f\n", turma[j]->nome, turma[j]->matricula, turma[j]->p1, turma[j]->p2, turma[j]->p3);
    };

    imprime_aprovados(n, turma);

    printf("Média da turma: %.2f", media_turma(n, turma));

    for ( i = 0; i < n; i++)
    {
        free(turma[i]->nome);
        free(turma[i]);
    };

    free (turma);

    return 0;
    

}