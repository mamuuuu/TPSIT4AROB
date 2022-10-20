#include <stdlib.h>
#include <stdio.h>

#define DIM 6

void bubbleSort1(int vett[], int n) {
    int sup, t;
    int *p;

    p = vett;
    int* a = p;

    int k=0;

    for (sup = n-1; sup > 0; sup--) {

        p = a;
        
        for (k=0; k<sup; k++) {
            
            if (*(p) > *(p+1)){
                t=*(p);
                *(p)=*(p+1);
                *(p+1)=t;
            }

            p += 1;
        }
    }

    return;
}

int main(){

    int v[DIM]={2,1,6,4,0,8};
    bubbleSort1(v,DIM);

    for (int c=0; c<DIM; c++){
        printf("%d", v[c]);
    }

    return 0;
}
