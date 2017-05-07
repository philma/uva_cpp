#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<string, string> lan_table = {
        {"HELLO", "ENGLISH"}, {"HOLA", "SPANISH"}
        , {"HALLO", "GERMAN"}, {"BONJOUR", "FRENCH"}
        , {"CIAO", "ITALIAN"}, {"ZDRAVSTVUJTE", "RUSSIAN"}
    };

    int cnt = 0;
    string line;
    while(getline(cin, line) && line != "#")
    {
        ++cnt;
        cout << "Case " << cnt << ": ";
        auto it = lan_table.find(line);
        if(it == lan_table.end())
            cout << "UNKNOWN";
        else
            cout << it->second;
        cout << endl;
    }

    return 0;
}
