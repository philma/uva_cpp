/*
 * Created on: 2015-04-18
 *     Author: philma
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> text;

    string line;
    while(getline(cin, line))
        text.push_back(line);

    int count = 0;
    for(int i = 0; i < text.size(); ++i)
    {
        for(int j = 0; j < text[i].size(); ++j)
        {
            if(text[i][j] == '"')
            {
                ++count;
                if(count & 1)
                    cout << "``";
                else
                    cout << "''";
            }
            else
                cout << text[i][j];
        }
        cout << endl;
    }

    return 0;
}
