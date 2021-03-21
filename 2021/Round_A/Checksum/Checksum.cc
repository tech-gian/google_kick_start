#include <iostream>

using namespace std;

struct point {
    int x, y;
};



int main(void) {

    int T;
    cin >> T;
    
    for (int k=0 ; k<T ; ++k) {
        int N;
        cin >> N;

        int** ar = new int*[N];
        for (int i=0 ; i<N ; ++i) {
            ar[i] = new int[N];
            for (int j=0 ; j<N ; ++j) {
                cin >> ar[i][j];
            }
        }

        int** b = new int*[N];
        for (int i=0 ; i<N ; ++i) {
            b[i] = new int[N];
            for (int j=0 ; j<N ; ++j) {
                cin >> b[i][j];
            }
        }

        for (int i=0 ; i<2*N ; ++i) {
            int temp;
            cin >> temp;
        }

        point* points = new point[N*N];
        int m = 0;

        for (int i=0 ; i<N ; ++i) {
            for (int j=0 ; j<N ; ++j) {
                if (ar[i][j] == -1) {
                    points[m].x = i;
                    points[m].y = j;
                    ++m;
                }
            }
        }

        for (int i=1 ; i<m ; ++i) {
            for (int j=m-1 ; j>=i ; --j) {
                if (b[points[j].x][points[j].y] < b[points[j-1].x][points[j-1].y]) {
                    point temp;
                    temp = points[j];
                    points[j] = points[j-1];
                    points[j-1] = temp;
                }
            }
        }

        int counter = 0;
        for (int i=0 ; i<m ; ++i) {
            int counter0 = 0;
            for (int j=0 ; j<N ; ++j) {
                if (ar[points[i].x][j] == -1) {
                    ++counter0;
                }
            }

            int counter1 = 0;
            for (int j=0 ; j<N ; ++j) {
                if (ar[j][points[i].y] == -1) {
                    ++counter1;
                }
            }

            if ((counter0 > 1) && (counter1 > 1)) {
                counter += b[points[i].x][points[i].y];
            }
            ar[points[i].x][points[i].y] = 2;
        }


        cout << "Case #" << k+1 << ": " << counter << endl;
    }


    return 0;
}
