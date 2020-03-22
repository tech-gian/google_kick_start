#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int T;
    scanf("%d", &T);

    int** cases = malloc(T*sizeof(int*));

    for (int i=0 ; i<T ; i++) {
        int N, B;
        scanf("%d", &N);
        scanf("%d", &B);

        cases[i] = malloc((N+2)*sizeof(int));
        cases[0] = N;
        cases[1] = B;
        for (int j=2 ; j<cases[0] ; j++) {
            scanf("%d", &cases[j]);
        }
    }

    
}