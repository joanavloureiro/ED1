#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define pi 3.14

void calc_esfera (float r, float* area, float* volume){
    *area = 4*pi*r*r;
    *volume = 4*pi*r*r*r/3;
}

int raizes(float a, float b, float c, float* x1, float* x2){
float delta = b*b - 4*a*c;
 *x1 = (-b + (sqrt(delta))) / (2*a);
 *x2 = (-b - (sqrt(delta))) / (2*a);
 
 if(delta < 0) {
    return 0;
 }
 else {
    return 1;
 };
}

int pares(int n, int* vet){
    int j, count=0;
    for(j=0; j<n; j++){
        if(vet[j]%2==0){
            count++;
        }
    }
    return count;
}

void inverte (int n, int* vet){
    int aux, i;

    for(i=0; i<n/2; i++){
        aux = vet[n-1-i];
        vet[n-1-i]=vet[i];
        vet[i]=aux;
    }
}

double avalia(double* poli, int grau, double x){
    double resultado = 0;
    for (int i = 0; i <= grau; i++)
    {
        resultado= resultado + (poli[i]*(pow(x, (i))));
    }

    return resultado;
    
}

// int main(int argc, char** argv){
//     //calc esfera
//     float r, aEsf, v;
//     float *area, *volume;

//     area= &v;
//     volume= &aEsf;

//     printf("Digite o valor do raio de uma esfera, para calcularmos sua superficie e o volume:");
//     scanf("%f", &r);

//     calc_esfera(r, area, volume);

//     printf("A area: %.2f, e o volume: %.2f.", aEsf, v);

//     return 0;
// }


// int main(int argc, char** argv){
//     //raizes
//     float a, b, c, xUm, xDois;
//     float *x1, *x2;

//     x1=&xUm;
//     x2=&xDois;

//     printf("Escolha os valores das variáveis para calcularmos uma função de segundo grau.\na:");
//     scanf("%f", &a);
//     printf("\nb:");
//     scanf("%f", &b);
//     printf("\nc:");
//     scanf("%f", &c);

//     if(raizes(a, b, c, x1, x2)==1){
//         printf("O valor de x1: %.2f\n", xUm);
//         printf("O valor de x2: %.2f", xDois);
//     }
//     else
//     {
//         printf("A equação não possui raízes reais");
//     }

//     return 0;
// }

// int main(int argc, char** argv){
//     //pares
//     int n, vet[10], i, quantPares;

//     printf("Escolha o tamanho do seu vetor (maximo eh 10).\n");
//     scanf("%d", &n);

//     printf("Agora escolha os valores de cada item do vetor:\n");

//     for(i=0; i<n; i++){
//         scanf("%d", &vet[i]);
//     }
    
//     quantPares = pares(n, vet);
//     printf("Você escreveu %d numeros pares no seu vetor.", quantPares);

//     return 0;
// }

// int main(int argc, char** argv){
//     //inverte
//     int n, vet[10], i;

//     printf("Escolha o tamanho do seu vetor (maximo eh 10).\n");
//     scanf("%d", &n);

//     printf("Agora escolha os valores de cada item do vetor:\n");

//     for(i=0; i<n; i++){
//         scanf("%d", &vet[i]);
//     }

//     inverte(n, vet);

//     scanf("Aqui esta seu vetor invertido: ");

//     for(i=0; i<n; i++){
//         printf("%d ", vet[i]);
//     }

//     return 0;
// }

int main(int argc, char** argv){
    //avalia
    double poli[10], x, resultado;
    int grau, i; 

    printf("Escolha o grau da sua função (maximo eh 10).\n");
    scanf("%d", &grau);

    printf("Escolha o coeficiente de cada elemento da função em ordem crescente:\n");
    for(i=0; i<=grau; i++){
        scanf("%lf", &poli[i]);
    }

    printf("Escolha o valor de X:\n");
    scanf("%lf", &x);

    resultado = avalia(poli, grau, x);

    printf("O resultado foi: %lf", resultado);

    return 0;
}