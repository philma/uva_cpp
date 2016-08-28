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

    BigUInt& operator+=(const BigUInt& rhs);
    const BigUInt operator*(const BigUInt& rhs) const;
    const BigUInt operator+(const BigUInt& rhs) const;
    
    bool operator>(const BigUInt& rhs) const;

private:
    string digits;
};

ostream& operator<<(ostream& out, const BigUInt& rhs)
{
    out << rhs.digits;
    return out;
}

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

const BigUInt BigUInt::operator+(const BigUInt& rhs) const
{
    return BigUInt(*this) += rhs;
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

bool BigUInt::operator>(const BigUInt& rhs) const
{
    int pos1 = digits.find_first_not_of('0');
    if(pos1 == string::npos) pos1 = digits.size() - 1;
    int pos2 = rhs.digits.find_first_not_of('0');
    if(pos2 == string::npos) pos2 = rhs.digits.size() - 1;

    int len1 = digits.size() - pos1;
    int len2 = rhs.digits.size() - pos2;
    if(len1 != len2)
        return len1 > len2;

    for(int i = 0; i < len1; ++i)
    {
        if(digits[pos1 + i] == rhs.digits[pos2 + i])
            continue;
        return digits[pos1 + i] > rhs.digits[pos2 + i];
    }

    return false;
}

int main()
{
    BigUInt limit("2147483647");

    string s_lhs, s_rhs, s_op;
    while(cin >> s_lhs >> s_op >> s_rhs)
    {
        bool first = false;
        bool second = false;
        bool result = false;

        BigUInt lhs(s_lhs);
        BigUInt rhs(s_rhs);

        if(lhs > limit) first = true;
        if(rhs > limit) second = true;

        BigUInt res = 
            s_op == "*" ? lhs * rhs : lhs + rhs;
        if(res > limit) result = true;

        cout << s_lhs 
             << " " << s_op 
             << " " << s_rhs << endl;
        if(first) cout << "first number too big" << endl;
        if(second) cout << "second number too big" << endl;
        if(result) cout << "result too big" << endl;
    }

    return 0;
}
