#include <iostream>
#include <string>

using namespace std;

class BigUInt
{
    friend ostream& operator<< (ostream& out
            , const BigUInt& rhs);
public:
    BigUInt(const string& s_value)
        :digits(s_value)
    {
    }

    BigUInt& operator+=(const BigUInt& rhs);

private:
    string digits;
};

BigUInt& BigUInt::operator+=(const BigUInt& rhs)
{
    string result;
    int i = digits.size() - 1;
    int j = rhs.digits.size() - 1;
    int c = 0;
    while(i >= 0 || j >= 0)
    {
        int n = (i >= 0 ? digits[i] - '0' : 0) 
              + (j >= 0 ? rhs.digits[j] - '0' : 0) 
              + c;
        c = n / 10;
        n %= 10;
        result += '0' + n;

        if(i >= 0) --i;
        if(j >= 0) --j;
    }

    if(c) result += '0' + c;
    int pos = result.find_last_not_of('0');
    if(pos == string::npos)
        digits = "0";
    else
    {
        digits = "";
        for(; pos >= 0; --pos)
            digits += result[pos];
    }

    return *this;
}

ostream& operator<< (ostream& out
        , const BigUInt& rhs)
{
    out << rhs.digits;
    return out;
}

int main()
{
    BigUInt sum("0");
    string line;
    while(getline(cin, line) && line != "0")
        sum += BigUInt(line);

    cout << sum << endl;

    return 0;
}
