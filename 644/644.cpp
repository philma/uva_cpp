#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    int cnt = 0;
    string line;
    set<string> codes;
    while(getline(cin, line))
    {
        if(line == "9")
        {
            ++cnt;
            bool immediate = true;
            set<string>::iterator it = codes.begin();
            for(; it != codes.end(); ++it)
            {
                if(line != "9")
                {
                    if(it->find(line) == 0)
                    {
                        immediate = false;
                        break;
                    }
                }
                line = *it;
            }
            cout << "Set " << cnt << " is";
            if(!immediate) cout << " not";
            cout << " immediately decodable" << endl;

            codes.clear();
        }
        else
            codes.insert(line);
    }

    return 0;
}
