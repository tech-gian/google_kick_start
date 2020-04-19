#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// For recursion
void rec(int* x, int* y, int i, char* prog, int n_loop, int start) {

    if (i=strlen(prog))
        return;
    
    if (prog[i]=='(') {
        if (n_loop==1)
            rec(x, y, start+1, prog, 1, start);
        else
            rec(x, y, i+1, prog, n_loop, i);
    }
    else if (prog[i]==')') {
        rec(x, y, start, prog, n_loop-1, i);
    }
    else if (prog[i]>='2' && prog[i]<='9') {
        rec(x, y, i+1, prog, prog[i]-'0', start);
    }
    else if (prog[i]=='N') {
        if (*x==1)
            *x = 1000000000;
        else
            *x--;
        rec(x, y, i+1, prog, n_loop, start);
    }
    else if (prog[i]=='S') {
        if (*x==1000000000)
            *x = 1;
        else
            *x++;
        rec(x, y, i+1, prog, n_loop, start);
    }
    else if (prog[i]=='W') {
        if (*y==1)
            *y = 1000000000;
        else
            *y--;
        rec(x, y, i+1, prog, n_loop, start);
    }
    else if (prog[i]=='E') {
        if (*y==1000000000)
            *y = 1;
        else
            *y++;
        rec(x, y, i+1, prog, n_loop, start);
    }
    return;
}


int main(int argc, char* argv[]) {
    int T;
    scanf("%d",&T);

    for (int k=0 ; k<T; k++) {
        char prog[2001];
        scanf("%s", prog);

        int x=1, y=1;
        // For recursion
        // rec(&x, &y, 0, prog, 1, 0);
        int i = 0;
        while (i<strlen(prog)) {
            if (prog[i]>='2' && prog[i]<='9') {
                int counter = 1;
                for (int j=0 ; j<prog[i]-'0' ; j++) {
                    int m = i+2;
                    while (prog[m]!=')') {
                        if (prog[m]=='N') {
                            if (x==1)
                                x = 1000000000;
                            else
                                x--;
                        }
                        else if (prog[m]=='S') {
                            if (x==1000000000)
                                x = 1;
                            else
                                x++;
                        }
                        else if (prog[m]=='W') {
                            if (y==1)
                                y = 1000000000;
                            else
                                y--;
                        }
                        else if (prog[m]=='E') {
                            if (y==1000000000)
                                y = 1;
                            else
                                y++;
                        }

                        m++;
                        if (j==prog[i]-'0'-1)
                            counter++;
                    }
                }
                i += counter;
            }
            else if (prog[i]=='N') {
                if (x==1)
                    x = 1000000000;
                else
                    x--;
            }
            else if (prog[i]=='S') {
                if (x==1000000000)
                    x = 1;
                else
                    x++;
            }
            else if (prog[i]=='W') {
                if (y==1)
                    y = 1000000000;
                else
                    y--;
            }
            else if (prog[i]=='E') {
                if (y==1000000000)
                    y = 1;
                else
                    y++;
            }

            i++;
        }
        // 3/4 correct
        printf("Case #%d: %d %d\n", k+1, y, x);
    }
}