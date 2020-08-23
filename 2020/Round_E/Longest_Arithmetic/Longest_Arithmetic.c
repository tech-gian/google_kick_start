#include <stdio.h>

int main(void) {

    int T;
    scanf("%d", &T);


    for (int z=0 ; z<T ; z++) {

        int N;
        scanf("%d", &N);
        int array[N];


        for (int i=0 ; i<N ; i++) {
            scanf("%d", &array[i]);
        }

        int dif = array[0] - array[1];
        int max = 0, counter = 1;

        for (int i=1 ; i<N-1 ; i++) {
            if (dif != array[i] - array[i+1]) {
                dif = array[i] - array[i+1];
                if (max < counter) {
                    max = counter;
                }
                counter = 1;
            }
            else {
                counter++;
            }
        }

        if (max < counter) {
            max = counter;
        }

        printf("Case #%d: %d\n", z+1, max+1);


    }


    return 0;
}
