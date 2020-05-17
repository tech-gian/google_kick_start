#include <stdio.h>
#include <string.h>

int main(void) {

    int T;
    scanf("%d", &T);

    for (int l=0 ; l<T ; l++) {
        int n, q;
        scanf("%d%d", &n, &q);

        int array[n];

        for (int i=0 ; i<n ; i++) {
            scanf("%d", &array[i]);
        }

        int sum = 0;
        for (int m=0 ; m<q ; m++) {
            int temp_sum = 0;

            char t1[1];
            int t2, t3;
            scanf("%s", t1);
            scanf("%d%d", &t2, &t3);

            if (strcmp(t1, "U") == 0) {
                array[t2-1] = t3;
            }
            else {
                int prod = 1;
                int counter = 1;
                for (int j=t2-1 ; j<t3 ; j++) {
                    temp_sum += array[j]*prod*counter;
                    prod *= -1;
                    counter++;
               }
               sum += temp_sum;
            }
        }

        printf("Case #%d: %d\n", l+1, sum);
    }


    return 0;
}