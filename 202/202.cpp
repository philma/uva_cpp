#include <iostream>
#include <string>
#include <map>

using namespace std;

void process(int a, int b)
{
    int times = a / b;
    int reminder = a % b;

    map<int, int> m_tmp;
    string s;
    int count = 0;

    ++count;
    m_tmp.insert(make_pair(reminder * 10, count));
    s.push_back('0' + reminder * 10 / b);
    reminder = reminder * 10 % b;

    while(m_tmp.find(reminder * 10) == m_tmp.end())
    {
        ++count;
        m_tmp.insert(make_pair(reminder * 10, count));
        s.push_back('0' + reminder * 10 / b);
        reminder = reminder * 10 % b;
    }

    map<int, int>::iterator it = m_tmp.find(reminder * 10);
    int cycle = count - it->second + 1;

    cout << a << "/" << b << " = " << times << ".";
    for(int i = 1; i < it->second; ++i)
        cout << s[i - 1];
    cout << "(";
    for(int i = it->second; i <= s.size() && (i - it->second + 1) <= 50; ++i)
        cout << s[i - 1];
    if(s.size() - it->second + 1 > 50)
        cout << "...";
    cout << ")" << endl;
    cout << "   " << cycle << " = number of digits in repeating cycle" << endl << endl;
}

int main()
{
    int a = 0, b = 0;
    while(cin >> a >> b)
        process(a, b);

    return 0;
}
