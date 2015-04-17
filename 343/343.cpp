/*
 * Created on: 2015-04-17
 *     Author: philma
 *
 * 思路：分别计算出X和Y在每一种进制（位于可能的进制范围）下的十进制值，
 * 在得到的两组值中，按进制从小到大的顺序求解答案。
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

static const int MAX_BASE = 36;
static const int MIN_BASE = 2;

int decimal_value(const string& number, int base)
{
    int value = 0;
    for(int i = 0; i < number.size(); ++i)
    {
        int digit = (number[i] >= '0' && number[i] <= '9') ? number[i] - '0' : 10 + number[i] - 'A';
        value = value * base + digit;
    }

    return value;
}

int possible_min_base(const string& number)
{
    int max_digit = -1;
    for(int i = 0; i < number.size(); ++i)
    {
        int digit = (number[i] >= '0' && number[i] <= '9') ? number[i] - '0' : 10 + number[i] - 'A';
        if(digit > max_digit)
            max_digit = digit;
    }

    return (max_digit + 1) < MIN_BASE ? MIN_BASE : (max_digit + 1);
}

void init(map<int, int>& values, const string& number)
{
    for(int i = possible_min_base(number); i <= MAX_BASE; ++i)
        values.insert(make_pair(i, decimal_value(number, i)));
}

int main()
{
    string number1, number2;
    while(cin >> number1 >> number2)
    {
        map<int, int> values1, values2;                 //以进制为key
        init(values1, number1);
        init(values2, number2);

        bool find = false;
        int base1 = 0, base2 = 0;
        for(map<int, int>::iterator it1 = values1.begin(); it1 != values1.end(); ++it1)
        {
            for(map<int, int>::iterator it2 = values2.begin(); it2 != values2.end(); ++it2)
            {
                if(it1->second == it2->second)
                {
                    find = true;
                    base1 = it1->first;
                    base2 = it2->first;
                    break;
                }
            }

            if(find) break;
        }

        if(find)
        {
            cout << number1 << " (base " << base1 << ") = "
            << number2 << " (base " << base2 << ")" << endl;
        }
        else
        {
            cout << number1 << " is not equal to "
            << number2 << " in any base 2..36" << endl;
        }
    }

    return 0;
}


