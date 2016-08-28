#include <iostream>
#include <string>
#include <utility>

using namespace std;

class BigUInt
{
    friend ostream& operator<<(ostream& out
            , const BigUInt& rhs);
public:
    BigUInt(const string& s_value)
        :digits(s_value)
    {
    }

    const BigUInt operator*(const BigUInt& rhs) const;

private:
    string digits;
};

ostream& operator<<(ostream& out, const BigUInt& rhs)
{
    out << rhs.digits;
    return out;
}

const BigUInt BigUInt::operator*(const BigUInt& rhs) const
{
    string result(digits.size() + rhs.digits.size(), '0');
    for(int i = digits.size() - 1; i >= 0; --i)
    {
        if(digits[i] == '0') continue;

        int offset = digits.size() - 1 - i;
        int c = 0;
        for(int j = rhs.digits.size() - 1; j >= 0; --j)
        {
            int pos = offset + (rhs.digits.size() - 1 - j);
            int n = (digits[i] - '0') * (rhs.digits[j] - '0')
                + c
                + (result[pos] - '0');
            result[pos] = '0' + n % 10;
            c = n / 10;
        }

        if(c) result[offset + rhs.digits.size()] = '0' + c;
    }

    int pos = result.find_last_not_of('0');
    if(pos == string::npos)
        result = "0";
    else
    {
        result.resize(pos + 1);
        int tmp = result.size() / 2;
        for(int i = 0; i < tmp; ++i)
            swap(result[i]
               , result[result.size() - 1 - i]);
    }

    return result;
}

int main()
{
    string line1, line2;
    while(getline(cin, line1)
            && getline(cin, line2))
    {
        cout << BigUInt(line1) * BigUInt(line2) 
             << endl;
    }

    return 0;
}
