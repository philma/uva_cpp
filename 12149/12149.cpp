#include <iostream>

using namespace std;

int main()
{
    auto square_sum = [](int n){
        return (n * (n + 1) * (2 * n + 1) / 6);
    };

    int n = 0;
    while(cin >> n && n)
        cout << square_sum(n) << endl;

    return 0;
}
