#include <iostream>

using namespace std;

int main()
{
    int cases = 0;
    cin >> cases;
    while(cases--)
    {
        int n = 0;
        cin >> n;

        int64_t sum = 0;
        for(int i = 0; i < n; ++i)
        {
            int64_t a = 0, b = 0, c = 0;
            cin >> a >> b >> c;
            sum += a * c;
        }
        cout << sum << endl;
    }

    return 0;
}
