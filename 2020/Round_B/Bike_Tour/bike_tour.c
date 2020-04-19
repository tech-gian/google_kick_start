#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

    int T;
    scanf("%d", &T);

    for (int k=0 ; k<T ; k++) {
        int N;
        scanf("%d", &N);
        
        int* array = malloc(N*sizeof(int));
        for (int i=0 ; i<N ; i++) {
            scanf("%d", &array[i]);
        }

        int sum = 0;
        for (int i=1 ; i<N-1 ; i++) {
            if (array[i]>array[i-1] && array[i]>array[i+1])
                sum++;
        }
        printf("Case #%d: %d\n", k+1, sum);
    }

}