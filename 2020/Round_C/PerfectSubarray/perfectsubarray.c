#include <stdio.h>

int main(void) {
    int T;
    scanf("%d", &T);

    for (int l=0 ; l<T ; l++) {
        int n;
        scanf("%d", &n);

        int array[n];

        for (int i=0 ; i<n ; i++) {
            scanf("%d", &array[i]);
        }

        int sum = 0;

        for (int i=0 ; i<n ; i++) {
            int temp_sum = 0;
            for (int j=i ; j<n ; j++) {
                temp_sum += array[j];
             
                for (int m=0 ; m<=temp_sum ; m++) {
                    if (m*m == temp_sum) {
                        sum++;
                        break;
                    }
                    else if (m*m > temp_sum)
                        break;
                }
            }
        }

        printf("Case #%d: %d\n", l+1, sum);
    }


    return 0;
}