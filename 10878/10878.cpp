#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line;
    while(getline(cin, line))
    {
        if(line[0] != '|')
            continue;
        char ch = 0;
        for(size_t i = 0; i < line.size(); ++i)
        {
            if(line[i] != ' ' && line[i] != 'o')
                continue;
            ch = ch * 2 + (line[i] == 'o' ? 1 : 0);
        }
        cout << ch;
    }
    return 0;
}
