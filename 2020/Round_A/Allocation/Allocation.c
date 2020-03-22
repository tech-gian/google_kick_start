#include <stdio.h>
#include <stdlib.h>

void swapd(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort_body(int* x, int up, int down) {
    int start, end;
    start = up;
    end = down;
    while (up < down) {
        while (x[down] >= x[up] && up < down)
            down--;
        if (up != down) {
            swapd(&x[up], &x[down]);
            up++;
        }
        while (x[up] <= x[down] && up < down)
        up++;
        if (up != down) {
            swapd(&x[up], &x[down]);
            down--;
        }
    }
    if (start < up-1)
        quicksort_body(x, start, up-1);
    if (end > down+1)
        quicksort_body(x, down+1, end);
}

void quicksort(int n, int* x) {
    quicksort_body(x, 0, n-1);
}


int main(void) {

    int T;
    scanf("%d", &T);

    int** cases = malloc(T*sizeof(int*));

    for (int i=0 ; i<T ; i++) {
        int N, B;
        scanf("%d", &N);
        scanf("%d", &B);

        cases[i] = malloc((N+2)*sizeof(int));
        cases[i][0] = N;
        cases[i][1] = B;
        for (int j=2 ; j<cases[i][0]+2 ; j++) {
            scanf("%d", &cases[i][j]);
        }
    }


    for (int i=0 ; i<T ; i++) {
        quicksort(cases[i][0], cases[i]+2);

        // bubblesort

        // for (int j=3 ; j<cases[i][0]+2 ; j++) {
        //     for (int k=cases[i][0]+2-1 ; k>=j ; k--) {
        //         if (cases[i][k]<cases[i][k-1]) {
        //             int temp = cases[i][k];
        //             cases[i][k] = cases[i][k-1];
        //             cases[i][k-1] = temp;
        //         }
        //     }
        // }

        int max = 0;
        int sum = 0;
        for (int j=2 ; j<cases[i][0]+2 ; j++) {
            if (sum+cases[i][j]<=cases[i][1]) {
                sum += cases[i][j];
                max++;
            }
            else break;
        }

        printf("Case #%d: %d\n", i+1, max);
    }
}