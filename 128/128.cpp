#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

const unsigned int MOD_NUM = 34943;

void num_to_hex_str(unsigned int x, string& str)
{
    stringstream tmp;
    tmp << hex << uppercase << setfill('0') << setw(2) << x;
    str = tmp.str();
}

int main()
{
    string line;
    while(getline(cin, line) && line != "#")
    {
        unsigned int tmp = 0;
        for(unsigned int i = 0; i < line.size(); ++i)
            tmp = (tmp * 256 + static_cast<unsigned int>(line[i])) % MOD_NUM;
        
        unsigned int ans = MOD_NUM - ((tmp * 65536) % MOD_NUM);
        if(ans == MOD_NUM) ans = 0;

        string output;
        num_to_hex_str(ans/256, output);
        cout << output << ' ';
        num_to_hex_str(ans % 256, output);
        cout << output << endl; 
    }

    return 0;
}
