#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

vector<int> factor(int n) {
    vector<int> ans;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans.push_back(i);

            // Avoid duplicate for perfect squares
            if (i != n / i) {
                ans.push_back(n / i);
            }
        }
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> ans = factor(n);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}