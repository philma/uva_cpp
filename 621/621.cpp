#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    getchar();
    for(int i = 0; i < n; ++i)
    {
        string line;
        getline(cin, line);
        if(line == "1" || line == "4" || line == "78")
            cout << '+';
        else if(line.size() >= 2 
                && line[line.size() - 1] == '5' && line[line.size() - 2] == '3')
            cout << '-';
        else if(line.size() >= 2 
                && line[0] == '9' && line[line.size() - 1] == '4')
            cout << '*';
        else if(line.size() >= 3 
                && line[0] == '1' && line[1] == '9' && line[2] == '0')
            cout << '?';
        cout << endl;
    }

    return 0;
}
