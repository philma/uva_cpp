#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cctype>

using namespace std;

void search(const vector<string>& letters, const string& word, int& row, int& col)
{
    int direction[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}
                         , {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    bool find = false;
    for(int i = 0; i < letters.size() && !find; ++i)
    {
        for(int j = 0; j < letters[i].size() && !find; ++j)
        {
            for(int k = 0; k < 8; ++k)
            {
                bool match = true;
                for(int index = 0; index < word.size(); ++index)
                {
                    int x = i + direction[k][0] * index;
                    int y = j + direction[k][1] * index;
                    if(x < 0 || x >= letters.size()
                       || y < 0 || y >= letters[i].size())
                    {
                        match = false;
                        break;
                    }

                    if(tolower(word[index]) != tolower(letters[x][y]))
                    {
                        match = false;
                        break;
                    }
                }
                if(match) 
                {
                    find = true;
                    row = i + 1;
                    col = j + 1;
                    break;
                }
            }
        }
    }
}

int main()
{
    int cases = 0;
    cin >> cases;
    for(int i = 0; i < cases; ++i)
    {
        if(i) cout << endl;

        int m = 0, n = 0;
        cin >> m >> n;
        getchar();

        vector<string> letters;
        for(int i = 0; i < m; ++i)
        {
            string line;
            getline(cin, line);
            letters.push_back(line);
        }

        int k = 0;
        cin >> k;
        getchar();
        for(int i = 0; i < k; ++i)
        {
            string word;
            getline(cin, word);

            int row = 0, col = 0;
            search(letters, word, row, col);
            cout << row << ' ' << col << endl;
        }
    }

    return 0;
}
