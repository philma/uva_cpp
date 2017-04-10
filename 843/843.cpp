#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>

static const unsigned int ALPHABET_LEN = 26;

using namespace std;

class StrCmp
{
public:
    bool operator()(const string& lhs, const string& rhs)
    {
        return lhs.size() > rhs.size();
    }
};

void split_by_space(const string& line, vector<string>& words)
{
    size_t pos = 0, begin_pos = 0;
    while((pos = line.find(' ', begin_pos)) 
            != string::npos)
    {
        string tmp = line.substr(begin_pos, pos - begin_pos);
        if(tmp != "")
            words.push_back(tmp);
        begin_pos = pos + 1;
    }

    if(begin_pos < line.size())
        words.push_back(line.substr(begin_pos, line.size() - begin_pos));
}

void decrypt(const vector<string>& dict, const vector<string>& words
        , size_t index, string& alpha_b1, string& alpha_b2, bool& find)
{
    if(index >= words.size())
    {
        if(index) find = true;
        return ;
    }

    for(size_t i = 0; i < dict.size(); ++i)
    {
        size_t word_len = words[index].size();
        size_t d_word_len = dict[i].size();
        if(word_len > d_word_len)
            break;
        else if(word_len < d_word_len)
            continue;

        const string& word = words[index];
        const string& d_word = dict[i];
        string ab1_bak(alpha_b1), ab2_bak(alpha_b2);
        bool match = true;
        for(size_t j = 0; j < word_len; ++j)
        {
            if(ab1_bak[d_word[j] - 'a'] == '0'
                    && ab2_bak[word[j] - 'a'] == '0')
            {
                ab1_bak[d_word[j] - 'a'] = word[j];
                ab2_bak[word[j] - 'a'] = d_word[j];
            }
            else if(ab1_bak[d_word[j] - 'a'] == word[j]
                    && ab2_bak[word[j] - 'a'] != '0')
                continue;
            else
            {
                match = false;
                break;
            }
        }

        if(match)
        {
            swap(ab1_bak, alpha_b1);
            swap(ab2_bak, alpha_b2);
            decrypt(dict, words, index + 1, alpha_b1, alpha_b2, find);
            if(find)
                break;
            else
            {
                swap(ab1_bak, alpha_b1);
                swap(ab2_bak, alpha_b2);
            }
        }
        else
            continue;
    }
}

int main()
{
    vector<string> dict;
    int n = 0;
    cin >> n;
    getchar();
    for(int i = 0; i < n; ++i)
    {
        string tmp;
        getline(cin, tmp);
        dict.push_back(tmp);
    }
    sort(dict.begin(), dict.end(), StrCmp());

    string line;
    while(getline(cin, line))
    {
        string alpha_b1(ALPHABET_LEN, '0');
        string alpha_b2(ALPHABET_LEN, '0');
        bool find = false;

        vector<string> words;
        split_by_space(line, words);
        sort(words.begin(), words.end(), StrCmp());
        decrypt(dict, words, 0, alpha_b1, alpha_b2, find);

        for(size_t i = 0; i < line.size(); ++i)
        {
            if(find)
                cout << (line[i] == ' ' ? ' ' : alpha_b2[line[i] - 'a']);
            else
                cout << (line[i] == ' ' ? ' ' : '*');
        }
        cout << endl;
    }

    return 0;
}
