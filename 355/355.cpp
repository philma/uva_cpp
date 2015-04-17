#include <iostream>
#include <string>

using namespace std;

int main()
{
    int src_base = 0, dst_base = 0;
    string number;

    while(cin >> src_base >> dst_base >> number)
    {
        bool illegal = false;
        for(int i = 0; i < number.size(); ++i)
        {
            int digit = (number[i] >= '0' && number[i] <= '9') ? number[i] - '0' : number[i] - 'A' + 10;
            if(digit >= src_base)
            {
                illegal = true;
                break;
            }
        }

        if(!illegal)
        {
            long long x = 0;
            for(int i = 0; i < number.size(); ++i)
            {
                int digit = (number[i] >= '0' && number[i] <= '9') ? number[i] - '0' : number[i] - 'A' + 10;
                x = x * src_base + digit;
            }
            string ans;
            while(x)
            {
                int digit = x % dst_base;
                ans.insert(ans.begin(), (digit >= 10 ? 'A' + (digit - 10) : '0' + digit));
                x /= dst_base;
            }
            if(ans.empty()) ans.push_back('0');

            cout << number << " base " << src_base << " = " << ans << " base " << dst_base << endl;
        }
        else
        {
            cout << number << " is an illegal base " << src_base << " number" << endl;
        }
    }

    return 0;
}
