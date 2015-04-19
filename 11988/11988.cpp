/*
 * Created on: 2015-04-19
 *     Author: philma
 */

#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
    string line;
    while(getline(cin, line))
    {
        list<char> tmp;
        list<char>::iterator it = tmp.end();
        for(int i = 0; i < line.size(); ++i)
        {
            if(line[i] == '[')
            {
                it = tmp.begin();
                continue;
            }
            else if(line[i] == ']')
            {
                it = tmp.end();
                continue;
            }

            tmp.insert(it, line[i]);
        }

        for(it = tmp.begin(); it != tmp.end(); ++it)
            cout << *it;
        cout << endl;
    }

    return 0;
}
