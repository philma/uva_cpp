#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int MAX_N = 100;
const int LINE_LIMIT = 15;

void prime_table(vector<int>& table)
{
    char flag[MAX_N + 1] = {0};
    for(int i = 2; i * i <= MAX_N; ++i)
    {
        if(flag[i]) continue;
        for(int j = i * i; j <= MAX_N; j += i)
            flag[j] = 1;
    }

    table.clear();
    for(int i = 2; i <= MAX_N; ++i)
    {
        if(!flag[i]) 
            table.push_back(i);
    }
}

int count(int n, int prime)
{
    int ans = 0;
    while(!(n % prime))
    {
        ++ans;
        n /= prime;
    }

    return ans;
}

int main()
{
    vector<int> primes;    
    prime_table(primes);

    int n = 0;
    while(cin >> n && n)
    {
        vector<int> ans;
        for(unsigned int i = 0; i < primes.size() && primes[i] <= n; ++i)
        {
            int tmp = 0;
            for(int j = 2; j <= n; ++j)
                tmp += count(j, primes[i]);
            
            ans.push_back(tmp);
        }

        cout << right << setw(3) << n << "! =";
        for(unsigned i = 0; i < ans.size(); ++i)
        {
            cout << right << setw(3) << ans[i];
            if((i + 1) % LINE_LIMIT == 0 && (i + 1) < ans.size())
                cout << endl << "      ";
        }
        cout << endl;
    }

    return 0;
}
