#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;

static const unsigned int LINE_SIZE = 60;

void unix_ls(const vector<string>& filenames, size_t max_len)
{
    int col_num = 1 + (LINE_SIZE - max_len) / (max_len + 2);
    int row_num = filenames.size() / col_num + (filenames.size() % col_num ? 1 : 0);

    for(unsigned int i = 0; i < LINE_SIZE; ++i)
        cout << '-';
    cout << endl;

    for(int i = 0; i < row_num; ++i)
    {
        for(int j = 0; j < col_num; ++j)
        {
            size_t pos = j * row_num + i;
            if(pos >= filenames.size())
                continue;
            cout << filenames[pos];

            size_t width = j + 1 == col_num ? max_len : max_len + 2;
            int space_num = width - filenames[pos].size();
            for(int k = 0; k < space_num; ++k)
                cout << ' ';
        }
        cout << endl;
    }
}

int main()
{
    int n = 0;
    while(cin >> n)
    {
        getchar();
        vector<string> filenames;
        size_t max_len = 0;
        for(int i = 0; i < n; ++i)
        {
            string line;
            getline(cin, line);
            filenames.push_back(line);
            if(line.size() > max_len)
                max_len = line.size();
        }
        sort(filenames.begin(), filenames.end());
        unix_ls(filenames, max_len);
    }

    return 0;
}
