#include <stdio.h>
#include <stdlib.h>

#define INT_MIN -2147483648

// int main(int argc, char* argv[]) {
//     int T;
//     scanf("%d", &T);

//     for (int k=0 ; k<T ; k++) {
//         int n, D;
//         scanf("%d%d", &n, &D);
//         int* array = malloc(n*sizeof(int));

//         for (int i=0 ; i<n ; i++) {
//             scanf("%d", &array[i]);
//         }

//         int M = INT_MIN;
//         int mul = 1, max;

//         for (int i=0 ; i<n ; i++) {
//             while (mul*array[i] <= D) {
//                 max = mul*array[i];
//                 for (int j=0 ; j<n ; j++) {
//                     if (i != j) {
//                         int div = D / array[j];
//                         int flag = 0;

//                         for (int m=1 ; m<=div ; m++) {
//                             if (div * array[j] >= max)
//                                 flag = 1;
//                                 break;
//                         }
//                         if (flag == 0) {
//                             max = INT_MIN;
//                             break;
//                         }
//                     }
//                 }
//                 if (max>M)
//                     M = max;
                
//                 mul++;
//             }   
//         }
//         printf("Case #%d: %d\n", k+1, M);
//     }
// }




int rec(int max, int D, int* array, int pos, int n);

int main(int argc, char* argv[]) {
    int T;
    scanf("%d", &T);

    for (int k=0 ; k<T ; k++) {
        int n, D;
        scanf("%d%d", &n, &D);
        int* array = malloc(n*sizeof(int));

        for (int i=0 ; i<n ; i++) {
            scanf("%d", &array[i]);
        }

        int M = INT_MIN;
        int mul = 1, max;

        // for (int i=0 ; i<n ; i++) {
            while (mul*array[0] <= D) {
                max = mul*array[0];
                // for (int j=1 ; j<n ; j++) {
                //     // if (i != j) {
                //         int div = D / array[j];
                //         int flag = 0;

                //         for (int m=1 ; m<=div ; m++) {
                //             if (div * array[j] >= max)
                //                 flag = 1;
                //                 break;
                //         }
                        // if (flag == 0) {
                        //     max = INT_MIN;
                        //     break;
                        // }
                    // }

                if (rec(max, D, array, 1, n) == 0) {
                    max = INT_MIN;
                }
                mul++;
            // }
                if (max>M)
                    M = max;
                
                // mul++;
            }   
        // }
        printf("Case #%d: %d\n", k+1, M);
    }
}


int rec(int max, int D, int* array, int pos, int n) {
    if (pos == n)
        return 1;
    else if ((D/array[pos]) * array[pos] >= max) {
        return rec((D/array[pos]) * array[pos], D, array, pos+1, n);
    }
    else
        return 0;
}