#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int MAX_N = 1000000;
char number_flag[MAX_N + 1] = {0};

void init_prime_table(vector<int>& primes)
{
    int tmp = static_cast<int>(sqrt(MAX_N));
    for(int i = 2; i <= tmp; ++i)
    {
        if(number_flag[i]) continue;
        for(int j = i * i; j <= MAX_N; j += i)
            number_flag[j] = 1;
    }

    primes.clear();
    for(int i = 2; i <= MAX_N; ++i)
    {
        if(number_flag[i] == 0)
            primes.push_back(i);
    }
}

int main()
{
    vector<int> primes;
    init_prime_table(primes);

    int n = 0;
    while(cin >> n && n)
    {
        bool find = false;
        for(unsigned int i = 0; i < primes.size() && primes[i] <= n / 2; ++i)
        {
            if(primes[i] == 2) continue;
            if(number_flag[n - primes[i]] == 0)
            {
                find = true;
                cout << n << " = " << primes[i] << " + " << n - primes[i] << endl;
                break;
            }
        }

        if(!find)
            cout << "Goldbach's conjecture is wrong." << endl;
    }

    return 0;
}
