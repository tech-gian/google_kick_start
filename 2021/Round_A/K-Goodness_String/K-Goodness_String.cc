#include <iostream>
#include <string>

using namespace std;

int main(void) {

    int T;
    cin >> T;

    for (int k=0 ; k<T ; ++k) {
        int N, K;
        cin >> N >> K;

        string s;
        cin >> s;

        int counter = 0;
        for (int i=0 ; i<N/2 ; ++i) {
            if (s[i] != s[N-i-1]) {
                ++counter;
            }
        }

        cout << "Case #" << k+1 << ": " << abs(counter - K) << endl;
    }

    return 0;
}
