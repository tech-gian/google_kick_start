#include <iostream>

using namespace std;

int main(void) {

    int T;
    cin >> T;

    for (int k=0 ; k<T ; ++k) {
        int R, C;
        cin >> R >> C;

        int** array = new int*[R];

        for (int i=0 ; i<R ; ++i) {
            array[i] = new int[C];
            for (int j=0 ; j<C ; ++j) {
                cin >> array[i][j];
            }
        }

        int counter = 0;
        bool flag = true;

        while (flag) {
            flag = false;

            for (int i=0 ; i<R ; ++i) {
                for (int j=0 ; j<C ; ++j) {

                    if (i-1 >= 0) {
                        if (abs(array[i][j]-array[i-1][j]) > 1) {
                            flag = true;
                            counter += abs(array[i][j]-array[i-1][j]) - 1;
                            if (array[i][j] < array[i-1][j]) {
                                array[i][j] = array[i-1][j] - 1;
                            }
                            else {
                                array[i-1][j] = array[i][j] - 1;
                            }
                        }
                    }
                    if (i+1 < R) {
                        if (abs(array[i][j]-array[i+1][j]) > 1) {
                            flag = true;
                            counter += abs(array[i][j]-array[i+1][j]) - 1;
                            if (array[i][j] < array[i+1][j]) {
                                array[i][j] = array[i+1][j] - 1;
                            }
                            else {
                                array[i+1][j] = array[i][j] - 1;
                            }
                        }
                    }
                    if (j-1 >= 0) {
                        if (abs(array[i][j]-array[i][j-1]) > 1) {
                            flag = true;
                            counter += abs(array[i][j]-array[i][j-1]) - 1;
                            if (array[i][j] < array[i][j-1]) {
                                array[i][j] = array[i][j-1] - 1;
                            }
                            else {
                                array[i][j-1] = array[i][j] - 1;
                            }
                        }
                    }
                    if (j+1 < C) {
                        if (abs(array[i][j]-array[i][j+1]) > 1) {
                            flag = true;
                            counter += abs(array[i][j]-array[i][j+1]) - 1;
                            if (array[i][j] < array[i][j+1]) {
                                array[i][j] = array[i][j+1] - 1;
                            }
                            else {
                                array[i][j+1] = array[i][j] - 1;
                            }
                        }
                    }

                }
            }

        }

        cout << "Case #" << k+1 << ": " << counter << endl;
    }


    return 0;
}
