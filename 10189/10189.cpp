#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int field_count = 0;
    int row = 0, col = 0;
    while(cin >> row >> col && row && col)
    {
        ++field_count;

        vector<string> matrix;
        for(int i = 0; i < row; ++i)
        {
            string line;
            cin >> line;
            matrix.push_back(line);
        }

        if(field_count > 1) cout << endl;
        cout << "Field #" << field_count << ":" << endl;

        int delta[8][2] = {{-1, -1},{-1, 0},{0, -1},{0, 1},{1, 0},{1, 1},{-1, 1},{1, -1}};
        for(unsigned int i = 0; i < matrix.size(); ++i)
        {
            for(unsigned int j = 0; j < matrix[i].size(); ++j)
            {
                if(matrix[i][j] == '*')
                    cout << '*';
                else
                {
                    int count = 0;
                    for(int k = 0; k < 8; k++)
                    {
                        int x = i + delta[k][0];
                        int y = j + delta[k][1];
                        if(!(x >= 0 && x < matrix.size() && y >= 0 && y < matrix[i].size()))
                            continue;
                        if(matrix[x][y] == '*') ++count;
                    }
                    cout << count;
                }
            }
            cout << endl;
        }
    }

    return 0;
}
