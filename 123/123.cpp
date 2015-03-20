#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cctype>
#include <algorithm>

using namespace std;

struct WordPos
{
    WordPos():row(0), col(0){}
    WordPos(int x, int y):row(x), col(y){}

    int row;
    int col;
};

void split_to_lower_word(const string& str, vector<string>& words)
{
    words.clear();
    for(int pos = 0; ;)
    {
        int space_pos = str.find_first_of(' ', pos);
        if(space_pos == string::npos)
        {
            string tmp = str.substr(pos, str.size() - pos);
            transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
            words.push_back(tmp);
            break;
        }
        else
        {
            string tmp = str.substr(pos, space_pos - pos);
            transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
            words.push_back(tmp);
            pos = space_pos + 1;
        }
    }
}

void input(set<string>& ignore_words, vector<vector<string> >& titles)
{
    string line;
    bool is_title = false;
    while(getline(cin, line))
    {
        if(line == "::")
        {
            is_title = true;
            continue;
        }

        if(!is_title)
            ignore_words.insert(line);
        else
        {
            vector<string> tmp;
            split_to_lower_word(line, tmp);
            titles.push_back(tmp);
        }
    }
}

void generate_keyword_pos_map(const set<string>& ignore_words, const vector<vector<string> >& titles, map<string, vector<WordPos> >& keywords)
{
    for(int i = 0; i < titles.size(); ++i)
    {
        for(int j = 0; j < titles[i].size(); ++j)
        {
            if(ignore_words.find(titles[i][j]) != ignore_words.end())
                continue;

            map<string, vector<WordPos> >::iterator it = keywords.find(titles[i][j]);
            if(it == keywords.end())
                keywords.insert(make_pair(titles[i][j], vector<WordPos>(1, WordPos(i, j))));
            else
                it->second.push_back(WordPos(i, j));
        }
    }
}

void output_ans(const vector<vector<string> >& titles, const map<string, vector<WordPos> >& keywords)
{
    for(map<string, vector<WordPos> >::const_iterator it = keywords.begin(); it != keywords.end(); ++it)
    {
        for(int i = 0; i < it->second.size(); ++i)
        {
            for(int j = 0; j < titles[it->second[i].row].size(); ++j)
            {
                if(j != 0) cout << " ";
                string tmp = titles[it->second[i].row][j];
                if(j == it->second[i].col)
                    transform(tmp.begin(), tmp.end(), tmp.begin(), ::toupper);
                cout << tmp;
            }
            cout << endl;
        }
    }
}

int main()
{
    set<string> ignore_words;
    vector<vector<string> > titles;
    input(ignore_words, titles);

    map<string, vector<WordPos> > keywords;
    generate_keyword_pos_map(ignore_words, titles, keywords);

    output_ans(titles, keywords);

    return 0;
}
