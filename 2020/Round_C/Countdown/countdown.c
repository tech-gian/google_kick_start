#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int T;
    scanf("%d", &T);

    for (int l=0 ; l<T ; l++) {
        int n, k;
        scanf("%d%d", &n, &k);

        int* array = malloc(n*sizeof(int));

        for (int i=0 ; i<n ; i++) {
            scanf("%d", &array[i]);
        }

        int sum = 0;

        for (int i=0 ; i<n-k+1 ; i++) {
            if (array[i] == k) {
                int counter = 1;
                int flag = 1;
                for (int j=k-1 ; j>0 ; j--) {
                    if (array[i+counter] != j) {
                        flag = 0;
                        break;
                    }
                    counter++;
                }
                if (flag == 1)
                    sum++;
            }
        }

        printf("Case #%d: %d\n", l+1, sum);
    }

    return 0;
}