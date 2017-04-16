#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    auto decimal = [](const string& str){
        auto sum = 0;
        auto len = str.length();
        
        for(auto i = 0; i < len; ++i)
            sum += ((1 << (len - i)) - 1) * (str[i] - '0');
        
        return sum;
    };
    
    string skew_b;
    while(getline(cin, skew_b) && skew_b != "0")
        cout << decimal(skew_b) << endl;
    
    return 0;
}
