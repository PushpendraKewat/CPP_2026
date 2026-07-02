
#include <iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }

        return true;
    }

    int gd(int n) {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return n / i;
        }
        return 1;
    }

    int minSteps(int n) {
        if (n == 1) return 0;

        int minOperation = 0;

        while (n > 1) {
            if (isPrime(n)) {
                minOperation += n;
                break;
            }

            int hf = gd(n);
            minOperation += (n / hf);
            n = hf;
        }

        return minOperation;
    }
};