#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line;
    while(getline(cin, line))
    {
        int times = 0;
        for(size_t i = 0; i < line.length(); ++i)
        {
            if(line[i] >= '0' && line[i] <= '9')
                times += line[i] - '0';
            else
            {
                if(line[i] == '!')
                    cout << endl;
                else
                {
                    char tmp = line[i];
                    if(tmp == 'b') tmp = ' ';
                    for(int j = 0; j < times; ++j)
                        cout << tmp;
                }
                times = 0;
            }
        }
        cout << endl;
    }

    return 0;
}
