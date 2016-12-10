#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

static const char VOWEL[5] = {'A','U','E','O','I'};
static const char CONSONANT[21] = {'J','S','B','K','T','C','L','D','M','V','N','W','F','X','G','P','Y','H','Q','Z','R'};

void generate_str(string& str, int len, bool odd)
{
    const char* p = odd ? VOWEL : CONSONANT;
    int limit = odd ? 21 : 5;
    int cnt = 0;
    while(str.size() < len)
    {
        str += *p;
        ++cnt;
        if(cnt == limit)
        {
            cnt = 0;
            ++p;
        }
    }
    sort(str.begin(), str.end());
}

int main()
{
    int case_num = 0;
    cin >> case_num;
    for(int i = 0; i < case_num; ++i)
    {
        int len = 0;
        cin >> len;
        int odd_len = len / 2 + (len & 1 ? 1 : 0);
        int even_len = len / 2;
        string odd_str, even_str;
        generate_str(odd_str, odd_len, true);
        if(even_len)
            generate_str(even_str, even_len, false);
        cout << "Case " << i + 1 << ": ";
        for(int odd_p = 0, even_p = 0
                ; (odd_p < odd_str.size() || even_p < even_str.size())
                ; ++odd_p, ++even_p)
        {
            if(odd_p < odd_str.size())
                cout << odd_str[odd_p];
            if(even_p < even_str.size())
                cout << even_str[even_p];
        }
        cout << endl;
    }

    return 0;
}
