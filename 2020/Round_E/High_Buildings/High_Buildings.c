#include <stdio.h>

int main(void) {

    int T;
    scanf("%d", &T);

    for (int k=0 ; k<T ; k++) {

        int N, A, B, C;
        scanf("%d%d%d%d", &N, &A, &B, &C);
        int array[N];

        if (N < A || N < B || N < C || (C > A && C > B)) {
            printf("Case #%d: IMPOSSIBLE\n", k+1);
        }
        // wrong algorithm
        else {
            for (int i=0 ; i<N ; i++) {
                array[i] = -1;
            }
            for (int i=0 ; i<C ; i++) {
                if (i%2 == 0) {
                    array[N/2 + i] = N;
                }
                else {
                    array[N/2 - i] = N;
                }
            }
            for (int i=N/2 ; i>=0 ; i--) {
                if (array[i] != N) {
                    array[i] = N - (N/2 - i + 1);
                }
            }
            for (int i=N/2 ; i<N ; i++) {
                if (array[i] != N) {
                    array[i] = N - (i - N/2 + 1);
                }
            }
            
            printf("Case #%d:", k+1);
            for (int i=0 ; i<N ; i++) {
                printf(" %d", array[i]);
            }
            printf("\n");
        }


    }

    return 0;
}
