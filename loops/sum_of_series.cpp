#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number : ";
    cin >> n;

    int sum;
    if(n % 2 == 0)
        sum = -n / 2;
    else
        sum = (n + 1) / 2;

    cout << "sum of series is: " << sum << endl;
    return 0;
}
