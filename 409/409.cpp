#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cctype>

using namespace std;

void parse_words(const string& excuse, vector<string>& words)
{
    string word;
    int state = 0;
    for(size_t i = 0; i < excuse.size(); ++i)
    {
        char ch = tolower(excuse[i]);
        switch(state)
        {
            case 0:
            {
                if((ch >= 'a' && ch <= 'z')
                        || (ch >= 'A' && ch <= 'Z'))
                {
                    state = 1;
                    word.clear();
                    word += ch;
                }
                break;
            }
            case 1:
            {
                if((ch >= 'a' && ch <= 'z')
                        || (ch >= 'A' && ch <= 'Z'))
                {
                    word += ch;
                    if(i == excuse.size() - 1)
                        words.push_back(word);
                }
                else
                {
                    state = 0;
                    words.push_back(word);
                }
                break;
            }
        }
    }
} 

void output_worst_excuses(const vector<string>& keywords, const vector<string>& excuses)
{
    vector<int> incidences(excuses.size(), 0);
    int max_incidences = 0;
    for(size_t i = 0; i < excuses.size(); ++i)
    {
        vector<string> words;
        parse_words(excuses[i], words);
        
        for(size_t j = 0; j < keywords.size(); ++j)
        {
            for(size_t k = 0; k < words.size(); ++k)
            {
                if(keywords[j] == words[k])
                    ++incidences[i];
            }
        }

        if(incidences[i] > max_incidences)
            max_incidences = incidences[i];
    }

    for(size_t i = 0; i < incidences.size(); ++i)
    {
        if(incidences[i] == max_incidences)
            cout << excuses[i] << endl;
    }
}

int main()
{
    int key_num = 0, ex_num = 0;
    int cnt = 0;
    while(cin >> key_num >> ex_num)
    {
        getchar();
        ++cnt;

        vector<string> keywords;
        for(int i = 0; i < key_num; ++i)
        {
            string line;
            getline(cin, line);
            keywords.push_back(line);
        }

        vector<string> excuses;
        for(int i = 0; i < ex_num; ++i)
        {
            string line;
            getline(cin, line);
            excuses.push_back(line);
        }
        
        cout << "Excuse Set #" << cnt << endl;
        output_worst_excuses(keywords, excuses);
        cout << endl;
    }
    
    return 0;
}
