#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0;
        cin >> n;
        getchar();

        vector<int> instructions;
        for(int i = 0; i < n; ++i)
        {
            string line;
            getline(cin, line);
            if(line == "LEFT")
                instructions.push_back(-1);
            else if(line == "RIGHT")
                instructions.push_back(1);
            else
            {
                size_t pos = line.find_last_of(' ');
                int which = atoi(line.substr(pos + 1).c_str()) - 1;
                instructions.push_back(instructions[which]);
            }
        }

        int pos = 0;
        for(auto offset : instructions)
            pos += offset;
        cout << pos << endl;
    }

    return 0;
}
