#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

void generate_words(const string& word, vector<string>& next_words)
{
    if(word.size() > 1)
    {
        for(unsigned int i = 0; i < word.size(); ++i)
        {
            string tmp = word;
            tmp.erase(i, 1);
            if(tmp <= word) continue;
            next_words.push_back(tmp);
        }
    }

    for(unsigned int i = 0; i < word.size(); ++i)
    {
        for(char j = 'a'; j <= 'z'; ++j)
        {
            string tmp = word;
            tmp[i] = j;
            if(tmp <= word) continue;
            next_words.push_back(tmp);
        }
    }

    for(unsigned int i = 0; i < word.size(); ++i)
    {
        for(char j = 'a'; j <= 'z'; ++j)
        {
            string tmp = word;
            tmp.insert(i, 1, j);
            if(tmp <= word) continue;
            next_words.push_back(tmp);
        }
    }

    for(char i = 'a'; i <= 'z'; ++i)
    {
        string tmp = word;
        tmp += i;
        if(tmp <= word) continue;
        next_words.push_back(tmp);
    }
}

void init_indegree(map<string, unsigned short>& words)
{
    map<string, unsigned short>::iterator it = words.begin();
    for(; it != words.end(); ++it)
    {
        const string& word = it->first;
        vector<string> next_words;
        generate_words(word, next_words);

        for(unsigned int i = 0; i < next_words.size(); ++i)
        {
            if(words.find(next_words[i]) != words.end())
               ++(words[next_words[i]]);
        }
    }
}

unsigned int find_answer(map<string, unsigned short>& words, vector<string>& zero_indegree)
{
    unsigned int ans = 0, del_num = 0;
    while(del_num < words.size() && !zero_indegree.empty())
    {
        ++ans;
        vector<string> tmp;
        for(unsigned int i = 0; i < zero_indegree.size(); ++i)
        {
            const string& word = zero_indegree[i];
            vector<string> next_words;
            generate_words(word, next_words);

            for(unsigned int j = 0; j < next_words.size(); ++j)
            {
                if(words.find(next_words[j]) != words.end())
                {
                    --(words[next_words[j]]);
                    if(words[next_words[j]] == 0)
                        tmp.push_back(next_words[j]);
                }
            }

            ++del_num;
        }
        zero_indegree = tmp;
    }

    return ans;
}

int main()
{
    map<string, unsigned short> words;
    string line;
    while(getline(cin, line))
        words.insert(pair<string, unsigned short>(line, 0));

    init_indegree(words);

    vector<string> zero_indegree;
    for(map<string, unsigned short>::iterator it = words.begin(); it != words.end(); ++it)
    {
        if(it->second == 0)
            zero_indegree.push_back(it->first);
    }

    cout << find_answer(words, zero_indegree) << endl;

    return 0;
}
