#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> sentences;
    string line;
    size_t max_len = 0;
    while(getline(cin, line))
    {
        sentences.push_back(line);

        size_t len = line.length();
        if(len > max_len) max_len = len;
    }

    for(size_t i = 0; i < max_len; ++i)
    {
        for(int j = sentences.size() - 1; j >= 0; --j)
        {
            if(i >= sentences[j].size())
                cout << ' ';
            else
                cout << sentences[j][i];
        }
        cout << endl;
    }

    return 0;
}
