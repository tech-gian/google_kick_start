#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int t;
    scanf("%d", &t);

    for (int k=0 ; k<t ; k++) {
        int n;
        scanf("%d", &n);

        int** arr = malloc(n * sizeof(int*));
        for (int i=0 ; i<n ; i++) {
            arr[i] = malloc(n * sizeof(int));
        }

        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<n ; j++) {
                scanf("%d", &arr[i][j]);
            }
        }

        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<n ; j++) {
                int a = -1;
                int b = -1;
                if (i-1 >= 0 && j-1 >= 0) a = arr[i-1][j-1];
                if (i+1 < n && j+1 < n) b = arr[i+1][j+1];

                if (a > b) arr[i][j] += a;
                else arr[i][j] += b;
            }
        }

        int max = -1;
        int posi, posj;
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<n ; j++) {
                if (arr[i][j] > max) {
                    max = arr[i][j];
                    posi = i;
                    posj = j;
                }
            }
        }

        int sum = 0;
        while (posi > 0 && posi < n-1 && posj > 0 && posj < n-1) {
            sum += arr[posi][posj];
            if (arr[posi-1][posj-1] > arr[posi+1][posj+1]) {
                posi--;
                posj--;
            }
            else {
                posi++;
                posj++;
            }
        }

        printf("Case #%d: %d\n", k+1, sum);
        for (int i=0 ; i<n ; i++) free(arr[i]);
        free(arr);
    }


    return 0;
}
