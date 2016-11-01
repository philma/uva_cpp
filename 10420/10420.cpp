#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main()
{
    int n = 0;
    while(cin >> n)
    {
        map<string, set<string> > countries;
        
        getchar();
        for(int i = 0; i < n; ++i)
        {
            string line;
            getline(cin, line);
            
            size_t pos = line.find(' ');
            string country = line.substr(0, pos);
            string name = line.substr(pos + 1);
            countries[country].insert(name);
        }

        map<string, set<string> >::iterator it = countries.begin();
        for(; it != countries.end(); ++it)
            cout << it->first << " " << it->second.size() << endl;
    }

    return 0;
}
