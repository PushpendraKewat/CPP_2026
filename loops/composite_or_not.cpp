#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // 0 and 1 are neither prime nor composite
    if(n <= 1){
        cout << n << " is neither Prime nor Composite";
        return 0;
    }

    bool isComposite = false;

    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            isComposite = true;
            break;
        }
    }

    if(isComposite)
        cout << n << " : is a Composite number";
    else
        cout << n << " : is NOT a Composite number (it is Prime)";

    return 0;
}
