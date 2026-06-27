#include <iostream>
#include <vector>

using namespace std;

vector<int> factorial(int n) {
    const int MOD = 1000000007;
    vector<int> fact(n + 1, 1);

    for (int i = 2; i <= n; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }

    return fact;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> res = factorial(n);

    for (int i = 0; i <= n; i++) {
        cout << i << "! = " << res[i] << endl;
    }

    return 0;
}