#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int t;
    scanf("%d", &t);

    for (int k=0 ; k<t ; k++) {

        char* s = malloc(100000 * sizeof(char));
        scanf("%s", s);

        int len = 0;
        for (int i=0 ; s[i]!='\0' ; i++) len++;


        int counter = 0;
        for (int i=0 ; i<len-3 ; i++) {
            if (s[i] == 'K' && s[i+1] == 'I' && s[i+2] == 'C' && s[i+3] == 'K') {
                for (int j=i+4 ; j<len-4 ; j++) {
                    if (s[j] == 'S' && s[j+1] == 'T' && s[j+2] == 'A' && s[j+3] == 'R' && s[j+4] == 'T') {
                        counter++;
                    }
                }
            }
        }

        printf("Case #%d: %d\n", k+1, counter);

        free(s);
    }

    return 0;
}
