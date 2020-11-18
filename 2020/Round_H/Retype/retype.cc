#include <iostream>

using namespace std;

int main(void) {

    int T;
    cin >> T;
    for (int l=0; l<T ; l++) {
        int n, k, s;
        cin >> n >> k >> s;

        int mina, minb;

        mina = k - 1;
        minb = k - 1;

        mina += n + 1;

        minb += k - s;
        minb += n - s + 1;

        if (mina < minb) {
            cout << "Case #" << l+1 << ": " << mina << endl;
        }
        else {
            cout << "Case #" << l+1 << ": " << minb << endl;
        }
    }

    return 0;
}
