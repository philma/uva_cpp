#include <iostream>
#include <map>

using namespace std;

int main()
{
    int Z = 0, I = 0, M = 0, L = 0;
    int case_count = 0;
    while(cin >> Z >> I >> M >> L)
    {
        if(Z == 0 && I == 0 && M == 0 && L == 0)
            break;
        ++case_count;

        int num_count = 1;
        map<int, int> numbers;
        while(numbers.find(L) == numbers.end())
        {
            numbers.insert(make_pair(L, num_count));
            L = (Z * L + I) % M;
            ++num_count;
        }

        cout << "Case " << case_count << ": " << num_count - numbers[L] << endl;
    }

    return 0;
}
