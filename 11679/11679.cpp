#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int b = 0, n = 0;
    while(cin >> b >> n
            && !(b == 0 && n == 0))
    {
        vector<int> bank_reserve(b, 0);
        for(int i = 0; i < b; ++i)
            cin >> bank_reserve[i];

        vector<int> bank_debt(b, 0);
        vector<int> bank_credit(b, 0);
        for(int i = 0; i < n; ++i)
        {
            int debtor = 0, creditor = 0, deb_v = 0;
            cin >> debtor >> creditor >> deb_v;
            bank_debt[debtor - 1] += deb_v;
            bank_credit[creditor - 1] += deb_v;
        }

        bool liq = true;
        for(int i = 0; i < b; ++i)
        {
            if(bank_reserve[i] + bank_credit[i] < bank_debt[i])
            {
                liq = false;
                break;
            }
        }

        cout << (liq ? 'S' : 'N') << endl;
    }

    return 0;
}
