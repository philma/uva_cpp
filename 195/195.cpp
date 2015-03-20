#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

struct LetterCmp
{
    bool operator()(char lhs, char rhs)
    {
        char lower_lhs = tolower(lhs);
        char lower_rhs = tolower(rhs);
        if(lower_lhs == lower_rhs)
            return lhs < rhs;
        else
            return lower_lhs < lower_rhs;
    }
};

bool next_permu(string& str)
{
    if(str.size() <= 1) return false;

    for(int i = str.size() - 2; i >= 0; --i)
    {
        //if(str[i] >= str[i + 1]) continue;
        if(!LetterCmp()(str[i], str[i + 1])) continue;
        for(int j = str.size() - 1; j > i; --j)
        {
            //if(str[j] > str[i])
            if(!LetterCmp()(str[j], str[i])
               && !(!LetterCmp()(str[j], str[i]) && !LetterCmp()(str[i], str[j])))
            {
                swap(str[i], str[j]);
                break;
            }
        }

        string tmp;
        for(int j = 0; j <= i; ++j)
            tmp.push_back(str[j]);
        for(int j = str.size() - 1; j > i; --j)
            tmp.push_back(str[j]);
        str = tmp;

        return true;
    }

    return false;
}

int main()
{
    int n = 0;
    cin >> n;

    while(n--)
    {
        string str;
        cin >> str;
        sort(str.begin(), str.end(), LetterCmp());

        cout << str << endl;
        while(next_permu(str))
            cout << str << endl;
    }

    return 0;
}
