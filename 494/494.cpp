#include <iostream>
#include <string>

using namespace std;

int count_word(const string& line)
{
    int state = 0;
    int count = 0;
    for(int i = 0; i < line.size(); ++i)
    {
        switch(state)
        {
            case 0:
            {
                if((line[i] >= 'a' && line[i] <= 'z')
                   || (line[i] >= 'A' && line[i] <= 'Z'))
                {
                    state = 1;
                    if(i == line.size() - 1)
                        ++count;
                }
                break;
            }
            case 1:
            {
                if(!(line[i] >= 'a' && line[i] <= 'z')
                   && !(line[i] >= 'A' && line[i] <= 'Z'))
                {
                    state = 0;
                    ++count;
                }
                else
                {
                    if(i == line.size() - 1)
                        ++count;
                }
            }
            default:
                break;
        }
    }

    return count;
}

int main()
{
    string line;
    while(getline(cin, line))
        cout << count_word(line) << endl;

    return 0;
}
