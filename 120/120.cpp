#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

void flips_sequence(vector<int>& numbers, vector<int>& flips)
{
    for(int i = numbers.size() - 1; i >= 1; --i)
    {
        int max_v = numbers[i];
        int pos = i;
        for(int j = i - 1; j >= 0; --j)
        {
            if(numbers[j] > max_v)
            {
                max_v = numbers[j];
                pos = j;
            }
        }

        if(pos != i)
        {
            if(pos)
            {
                reverse(numbers.begin(), numbers.begin() + pos + 1);
                flips.push_back(numbers.size() - pos);
            }

            reverse(numbers.begin(), numbers.begin() + i + 1);
            flips.push_back(numbers.size() - i);
        }
    }
}

int main()
{
    string line;
    while(getline(cin, line))
    {
        stringstream ss_line(line);
        vector<int> numbers;
        int tmp = 0;
        while(ss_line >> tmp)
            numbers.push_back(tmp);

        vector<int> flips;
        flips_sequence(numbers, flips);

        cout << line << endl;
        for(size_t i = 0; i < flips.size(); ++i)
            cout << flips[i] << ' ';
        cout << 0 << endl;
    }

    return 0;
}
