#include <stdio.h>

int main(){
    int a=1,b=2,c=3,d=4;
    int *pa, *pb, *pc, *pd;

    pa=&a;
    pb=&b;
    pc=&c;
    pd=&d;

    *pa = *pa + 1;

    *pb = (*pc) * (*pd);

    *pc = 10;

    printf("de um valor para a variavel d:");
    scanf("%d", pd);

    printf("%d %d %d %d\n", a, b, c, d);

    return 0;

}