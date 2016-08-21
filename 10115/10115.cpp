#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

struct Rule
{
    string find;
    string replace;
};

int main()
{
    int rule_num = 0;
    while(cin >> rule_num && rule_num)
    {
        getchar();
        
        vector<Rule> rules;
        for(int i = 0; i < rule_num; ++i)
        {
            Rule rule;
            getline(cin, rule.find);
            getline(cin, rule.replace);
            rules.push_back(rule);
        }

        string text;
        getline(cin, text);

        for(size_t i = 0; i < rules.size(); ++i)
        {
            size_t pos = 0;
            while((pos = text.find(rules[i].find)) 
                    != string::npos)
            {
                text.replace(pos
                        , rules[i].find.size()
                        , rules[i].replace);
            }
        }
        cout << text << endl;
    }

    return 0;
}
