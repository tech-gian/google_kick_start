#include <stdio.h>
#include <stdlib.h>

#define LONG_MAX 9223372036854775807


int main(void) {

    long T;
    scanf("%ld", &T);

    for (long k=0 ; k<T; k++) {

        long N, X;
        scanf("%ld%ld", &N, &X);

        long* arr = malloc(N * sizeof(long));
        for (long i=0 ; i<N ; i++) {
            scanf("%ld", &arr[i]);
        }

        long* test = malloc(N * sizeof(long));
        for (long i=0 ; i<N ; i++) {
            test[i] = 1;
        }

        long* final = malloc(N * sizeof(long));
        long j = 0;


        while (1) {
            long flag = 1;

            for (long i=0 ; i<N ; i++) {
                if ((arr[i] <= 0) && (test[i] == 1)) {
                    final[j] = i + 1;
                    j++;
                    test[i] = 0;
                }
                else if (test[i] == 1) {
                    flag = 0;
                    arr[i] -= X;
                }
            }

            if (flag == 1) {
                break;
            }
        }

        printf("Case #%ld:", k+1);

        for (long i=0 ; i<N ; i++) {
            printf(" %ld", final[i]);
        }
        printf("\n");


        free(test);
        free(final);
        free(arr);
    }


    return 0;
}
