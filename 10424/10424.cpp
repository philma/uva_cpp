#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

double name_value(const string& name)
{
    unsigned int sum = 0;
    for(size_t i = 0; i < name.size(); ++i)
    {
        char c = name[i];
        if(c >= 'a' && c <= 'z')
            sum += c - 'a' + 1;
        else if(c >= 'A' && c <= 'Z')
            sum += c - 'A' + 1;
    }

    while(!(sum >= 1 && sum <= 9))
    {
        unsigned int tmp = sum;
        sum = 0;
        while(tmp)
        {
            sum += tmp % 10;
            tmp /= 10;
        }
    }

    return sum;
}

int main()
{
    string name1, name2;
    while(getline(cin, name1)
            && getline(cin, name2))
    {
        double result = name_value(name1) / name_value(name2);
        if(result > 1) result = 1 / result;
        cout << fixed << setprecision(2) << (result * 100) << " %" << endl;
    }

    return 0;
}