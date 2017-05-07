#include <iostream>
#include <string>

using namespace std;

int main()
{
    int cnt = 0;
    string line;
    while(getline(cin, line) && line != "*")
    {
        ++cnt;
        cout << "Case " << cnt << ": ";
        if(line == "Hajj")
            cout << "Hajj-e-Akbar";
        else
            cout << "Hajj-e-Asghar";
        cout << endl;
    }

    return 0;
}
