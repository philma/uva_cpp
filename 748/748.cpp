#include <iostream>
#include <string>
#include <utility>

using namespace std;

class BigDecimal
{
    friend istream& operator>>(istream& in, BigDecimal& rhs);
    friend ostream& operator<<(ostream& out, const BigDecimal& rhs);
public:
    BigDecimal()
        :digits("0")
        ,dp_num(0)
    {}

    BigDecimal(const string& s_value)
    {
        size_t pos = s_value.find('.');
        if(pos == string::npos)
        {
            digits = s_value;
            dp_num = 0;
        }
        else
        {
            dp_num = s_value.length() - 1 - pos;
            digits.append(s_value, 0, pos);
            digits.append(s_value, pos + 1, dp_num);
        }
    }

    BigDecimal& operator*=(const BigDecimal& rhs);

private:
    string digits;
    int dp_num;
};

istream& operator>>(istream& in, BigDecimal& rhs)
{
    in >> rhs.digits;
    BigDecimal tmp(rhs.digits);
    rhs.digits = tmp.digits;
    rhs.dp_num = tmp.dp_num;
    
    return in;
}

ostream& operator<<(ostream& out, const BigDecimal& rhs)
{
    string result(rhs.digits);
    if(result.size() >= rhs.dp_num)
        result.insert(result.size() - rhs.dp_num, 1, '.');
    else
    {
        result.insert(0, rhs.dp_num - result.size(), '0');
        result.insert(0, 1, '.');
    }

    size_t pos1 = result.find_first_not_of('0');
    size_t pos2 = result.find_last_not_of('0');
    if(pos1 == pos2)
        out << "0";
    else if(result[pos2] == '.')
        out << result.substr(pos1, pos2 - pos1);
    else
        out << result.substr(pos1, pos2 - pos1 + 1);

    return out;
}

BigDecimal& BigDecimal::operator*=(const BigDecimal& rhs)
{
    dp_num += rhs.dp_num;

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
    digits = result;

    return *this;
}

int main()
{
    BigDecimal r;
    int n = 0;
    while(cin >> r >> n)
    {
        BigDecimal result("1");
        for(int i = 0; i < n; ++i)
            result *= r;

        cout << result << endl;
    }

    return 0;
}
