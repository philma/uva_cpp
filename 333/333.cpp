/*
 * Created on: 2015-04-17
 *     Author: philma
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool judge(const string& isbn)
{
    string s;
    for(int i = 0; i < isbn.size(); ++i)
    {
        if(!(isbn[i] >= '0' && isbn[i] <= '9')
            && isbn[i] != '-' && isbn[i] != 'X')
                return false;
        if(isbn[i] == '-') continue;
        s.push_back(isbn[i]);
    }

    if(s.size() != 10) return false;

    vector<int> tmp;
    int sum = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == 'X' && i != 9)
            return false;
        sum += s[i] == 'X' ? 10 : s[i] - '0';
        tmp.push_back(sum);
    }

    sum = 0;
    for(int i = 0; i < tmp.size(); ++i)
        sum += tmp[i];

    return (sum % 11) ? false : true;
}

void strip(string& isbn)
{
    int begin = isbn.find_first_not_of(' ');
    int end = isbn.find_last_not_of(' ');

    if(begin == string::npos
       || end == string::npos)
    {
        isbn = "";
    }
    else
    {
        string tmp;
        for(int i = begin; i <= end; ++i)
            tmp.push_back(isbn[i]);
        isbn = tmp;
    }
}

int main()
{
    string isbn;
    while(getline(cin, isbn))         //输入的字符串中间可能包含空格
    {
        strip(isbn);
        if(judge(isbn))
            cout << isbn << " is correct." << endl;
        else
            cout << isbn << " is incorrect." << endl;
    }

    return 0;
}
