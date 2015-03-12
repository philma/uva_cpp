#include <iostream>
#include <vector>

using namespace std;

static const int MAX_NUMBER = 1500;

int binary_search(const vector<int>& number, int x)
{
    int low = 0;
    int high = number.size() - 1;
    int ans = 0;
    int tmp = number[high];
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(number[mid] * x > tmp)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return number[ans] * x;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    vector<int> number;
    number.reserve(MAX_NUMBER);
    number.push_back(1);

    while(number.size() < MAX_NUMBER)
    {
        int tmp1 = binary_search(number, 2);
        int tmp2 = binary_search(number, 3);
        int tmp3 = binary_search(number, 5);

        number.push_back(min(tmp1, min(tmp2, tmp3)));
    }

    cout << "The 1500'th ugly number is ";
    cout << *(number.rbegin()) << "."<< endl;

    return 0;
}
