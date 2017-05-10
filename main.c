#include <stdio.h>
#include "private.h"

typedef struct{
    int x,y;
}Point;
def(int,A);
def(double,B);
def(Point,C);
def(prvt_type(int,A),D);

void print_int(prvt_type(int,A) A){
    printf("%d\n",A.get());
}
int main(void){
    A.new(10);
    printf("%d\n",A.get());
    A.set(100);
    printf("%d\n",A.get());

    B.new(3.14L);
    printf("%f\n",B.get());
    B.set(2.71828L);
    printf("%f\n",B.get());

    C.new((Point){10,-10});
    printf("%d,%d\n",C.get().x,C.get().y);
    C.set((Point){6,-8});
    printf("%d,%d\n",C.get().x,C.get().y);

    print_int(A);
    D.new(A);
    printf("%d\n",D.get().get());
    return 0;
}
