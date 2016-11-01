#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search(const vector<int>& numbers, int query)
{
    int begin = 0, end = numbers.size() - 1;
    int pos = 0;
    while(begin <= end)
    {
        int mid = (begin + end) / 2;
        if(numbers[mid] >= query)
        {
            if(numbers[mid] == query)
                pos = mid + 1;
            end = mid - 1;
        }
        else
            begin = mid + 1;
    }

    return pos;
}

int main()
{
    int n = 0, q = 0;
    int case_cnt = 0;
    while(cin >> n >> q)
    {
        if(n == 0 && q == 0)
            break;
        ++case_cnt;
        
        vector<int> numbers;
        for(int i = 0; i < n; ++i)
        {
            int tmp = 0;
            cin >> tmp;
            numbers.push_back(tmp);
        }
        sort(numbers.begin(), numbers.end());

        cout << "CASE# " << case_cnt << ":" << endl;
        for(int i = 0; i < q; ++i)
        {
            int tmp = 0;
            cin >> tmp;
            int pos = binary_search(numbers, tmp);
            if(pos)
                cout << tmp << " found at " << pos;
            else
                cout << tmp << " not found";
            cout << endl;
        }
    }

    return 0;
}
