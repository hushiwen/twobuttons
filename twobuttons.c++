#include <iostream>

using namespace std;

int main(void) {

    unsigned n, m;

    cin >> n >> m;

    unsigned c = 0;
    while(m > n) {
        c += (m & 1);
        m += (m & 1);
        m >>= 1;
        c ++;
    }

    cout << n-m+c << endl;

    return 0;
}
