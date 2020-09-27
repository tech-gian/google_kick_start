#include <stdio.h>
#include <stdlib.h>

int main (void) {

    int T;
    scanf("%d", &T);

    for (int k=0 ; k<T ; k++) {
        int N, K;
        scanf("%d%d", &N, &K);

        int* s = malloc(N * sizeof(int));
        int* e = malloc(N * sizeof(int));


        for (int i=0 ; i<N ; i++) {
            scanf("%d%d", &s[i], &e[i]);
        }

        for (int i=1 ; i<N ; i++) {
            for (int j=i ; j>0 ; j--) {
                if (s[j] < s[j-1]) {
                    int temp = s[j];
                    s[j] = s[j-1];
                    s[j-1] = temp;
                    int tem = e[j];
                    e[j] = e[j-1];
                    e[j-1] = tem;
                }
            }
        }


        int counter = 0;
        int temp = -1;
        for (int i=0 ; i<N ; i++) {
            if (temp <= s[i]) {
                temp = s[i];

                while (1) {
                    counter++;
                    temp += K;

                    if (e[i] <= temp) {
                        break;
                    }
                }
            }
        }

        printf("Case #%d: %d\n", k+1, counter);
    }

    return 0;
}
