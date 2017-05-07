#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    getchar();
    
    int sum = 0;
    while(t--)
    {
        string line;
        getline(cin, line);
        string sb_str = line.substr(0, 6);
        if(sb_str == "report")
            cout << sum << endl;
        else
            sum += atoi(line.substr(7).c_str());
    }
    return 0;
}
