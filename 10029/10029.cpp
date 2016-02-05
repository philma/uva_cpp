#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

void init_indegree(map<string, unsigned short>& words)
{
    map<string, unsigned short>::iterator it = words.begin();
    for(; it != words.end(); ++it)
    {
        const string& word = it->first;

        if(word.size() > 1)
        {
            for(unsigned int i = 0; i < word.size(); ++i)
            {
                string tmp = word;
                tmp.erase(i, 1);
                if(tmp <= word) continue;
                if(words.find(tmp) != words.end())
                    ++(words[tmp]);
            }
        }

        for(unsigned int i = 0; i < word.size(); ++i)
        {
            for(char j = 'a'; j <= 'z'; ++j)
            {
                string tmp = word;
                tmp[i] = j;
                if(tmp <= word) continue;
                if(words.find(tmp) != words.end())
                    ++(words[tmp]);
            }
        }

        for(unsigned int i = 0; i < word.size(); ++i)
        {
            for(char j = 'a'; j <= 'z'; ++j)
            {
                string tmp = word;
                tmp.insert(i, 1, j);
                if(tmp <= word) continue;
                if(words.find(tmp) != words.end())
                    ++(words[tmp]);
            }
        }

        for(char i = 'a'; i <= 'z'; ++i)
        {
            string tmp = word;
            tmp += i;
            if(tmp <= word) continue;
            if(words.find(tmp) != words.end())
               ++(words[tmp]);
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
            if(word.size() > 1)
            {
                for(unsigned int pos = 0; pos < word.size(); ++pos)
                {
                    string tmp_word = word;
                    tmp_word.erase(pos, 1);
                    if(tmp_word <= word) continue;
                    if(words.find(tmp_word) != words.end())
                    {
                        --(words[tmp_word]);
                        if(words[tmp_word] == 0)
                            tmp.push_back(tmp_word);
                    }
                }
            }

            for(unsigned int pos = 0; pos < word.size(); ++pos)
            {
                for(unsigned char j = 'a'; j <= 'z'; ++j)
                {
                    string tmp_word = word;
                    tmp_word[pos] = j;
                    if(tmp_word <= word) continue;
                    if(words.find(tmp_word) != words.end())
                    {
                        --(words[tmp_word]);
                        if(words[tmp_word] == 0)
                            tmp.push_back(tmp_word);
                    }
                }
            }

            for(unsigned int pos = 0; pos < word.size(); ++pos)
            {
                for(unsigned char j = 'a'; j <= 'z'; ++j)
                {
                    string tmp_word = word;
                    tmp_word.insert(pos, 1, j);
                    if(tmp_word <= word) continue;
                    if(words.find(tmp_word) != words.end())
                    {
                        --(words[tmp_word]);
                        if(words[tmp_word] == 0)
                            tmp.push_back(tmp_word);
                    }
                }
            }

            for(unsigned char j = 'a'; j <= 'z'; ++j)
            {
                string tmp_word = word;
                tmp_word += j;
                if(tmp_word <= word) continue;
                if(words.find(tmp_word) != words.end())
                {
                    --(words[tmp_word]);
                    if(words[tmp_word] == 0)
                        tmp.push_back(tmp_word);
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
