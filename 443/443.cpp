#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

const unsigned int MAX_N = 5842;

void humble_number_table(vector<long long>& table)
{
    set<long long> tmp;
    tmp.insert(1);
    int factors[4] = {2, 3, 5, 7};

    while(table.size() < MAX_N)
    {
        set<long long>::iterator it = tmp.begin();
        table.push_back(*it);

        for(int i = 0; i < 4; ++i)
        {
            long long number = factors[i] * (*it);
            if(tmp.find(number) == tmp.end())
                tmp.insert(number);
        }

        tmp.erase(it);
    }
}

int main()
{
    vector<long long> table;
    humble_number_table(table);

    int n = 0;
    while(cin >> n && n)
    {
        string suffix;
        int tmp = n % 10;
        if(tmp >= 1 && tmp <= 3 && (n / 10 % 10) != 1)
        {
            if(tmp == 1)
                suffix = "st";
            else if(tmp == 2)
                suffix = "nd";
            else
                suffix = "rd";
        }
        else
            suffix = "th";

        cout << "The " << n << suffix 
             << " humble number is " 
             << table[n - 1] << "." << endl;
    }

    return 0;
}
