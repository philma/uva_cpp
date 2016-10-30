#include <iostream>
#include <string>

using namespace std;

void division(const string& num1, uint64_t num2
        , string& result, uint64_t& remainder)
{
    result.clear();
    remainder = 0;
    for(size_t i = 0; i < num1.size(); ++i)
    {
        remainder = remainder * 10 + num1[i] - '0';
        if(remainder >= num2)
        {
            result += '0' + remainder / num2;
            remainder = remainder % num2;
        }
        else if(!result.empty())
            result += '0';
    }

    if(result.empty()) result = "0";
}

int main()
{
    string num1, op_symbol;
    uint64_t num2 = 0;
    while(cin >> num1 >> op_symbol >> num2)
    {
        string result;
        uint64_t remainder = 0;
        division(num1, num2, result, remainder);
        if(op_symbol == "/")
            cout << result;
        else
            cout << remainder;
        cout << endl;
    }

    return 0;
}
