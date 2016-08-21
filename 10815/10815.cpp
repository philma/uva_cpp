#include <iostream>
#include <string>
#include <set>
#include <cctype>
#include <cstdio>

using namespace std;

void select_distinct_word(const string& text, set<string>& words)
{
    string tmp;
    int state = 0;
    for(size_t i = 0; i < text.size(); ++i)
    {
        char ch = text[i];
        switch(state)
        {
            case 0:
            {
                if(isalpha(ch))
                {
                    state = 1;
                    tmp.clear();
                    tmp += tolower(ch);
                }
                break;
            }
            case 1:
            {
                if(isalpha(ch))
                {
                    tmp += tolower(ch);
                    if(i == text.size() - 1)
                    {
                        if(words.find(tmp) == words.end())
                            words.insert(tmp);
                    }
                }
                else
                {
                    state = 0;
                    if(words.find(tmp) == words.end())
                        words.insert(tmp);
                }
                break;
            }
        }
    }
}

int main()
{
    string text;
    set<string> words;
    char ch;
    while((ch = getchar()) != EOF)
        text += ch;
    select_distinct_word(text, words);

    for(set<string>::iterator it = words.begin(); it != words.end(); ++it)
        cout << *it << endl;

    return 0;
}
