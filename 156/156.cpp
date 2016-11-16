#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <cctype>

using namespace std;

void to_lower(string& word)
{
    for(unsigned int i = 0; i < word.size(); ++i)
        word[i] = tolower(word[i]);
}

bool is_ananagram(const string& word, const vector<string>& dictionary)
{
    if(word.size() == 1)
        return false;

    string w_tmp_a(word);
    to_lower(w_tmp_a);
    sort(w_tmp_a.begin(), w_tmp_a.end());
    for(unsigned int i = 0; i < dictionary.size(); ++i)
    {
        if(word == dictionary[i])
            continue;

        string w_tmp_b(dictionary[i]);
        to_lower(w_tmp_b);
        sort(w_tmp_b.begin(), w_tmp_b.end());
        if(w_tmp_a == w_tmp_b)
            return true;
    }

    return false;
}

int main()
{
    vector<string> dictionary;
    string word;
    while(cin >> word && word != "#")
        dictionary.push_back(word);

    set<string> ans;
    for(unsigned int i = 0; i < dictionary.size(); ++i)
    {
        if(!is_ananagram(dictionary[i], dictionary))
            ans.insert(dictionary[i]);
    }

    for(set<string>::iterator it = ans.begin(); it != ans.end(); ++it)
        cout << *it << endl;

    return 0;
}
