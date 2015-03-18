#include <iostream>
#include <string>

using namespace std;

static const int MAX_K = 1000000000;
static const int MIN_K = 1;

void multiply(const string& lhs, const string& rhs, string& res)
{
    string tmp;
    int begin = 0;
    for(int i = rhs.size() - 1; i >= 0; --i)
    {
        int c = 0;
        for(int j = lhs.size() - 1; j >= 0; --j)
        {
            int pos = begin + (lhs.size() - 1 - j);
            if(pos >= tmp.size())
                tmp.push_back('0');
            int x = (tmp[pos] - '0') + c + (rhs[i] - '0') * (lhs[j] - '0');
            tmp[pos] = x % 10 + '0';
            c = x / 10;
        }
        tmp.push_back(c + '0');
        ++begin;
    }

    res.clear();
    bool flag = false;
    for(int i = tmp.size() - 1; i >= 0; --i)
    {
        if(flag)
            res.push_back(tmp[i]);
        else
        {
            if(tmp[i] == '0')
                continue;
            else
            {
                flag = true;
                res.push_back(tmp[i]);
            }
        }
    }

    if(res.empty())
        res = "0";
}

void number_to_string(int x, string& res)
{
    res.clear();
    while(x)
    {
        res.insert(res.begin(), (x % 10) + '0');
        x /= 10;
    }

    if(res.empty())
        res = "0";
}

void power(string& number, int n, string& res)
{
    res = "1";
    for(; n; n >>= 1)
    {
        if(n & 1)
        {
            string tmp;
            multiply(number, res, tmp);
            res = tmp;
        }

        string tmp;
        multiply(number, number, tmp);
        number = tmp;
    }
}

int number_cmp(const string& lhs, const string& rhs)
{
    if(lhs.size() > rhs.size())
        return 1;
    else if(lhs.size() < rhs.size())
        return -1;
    else
    {
        return lhs > rhs ? 1 : (lhs == rhs ? 0 : -1);
    }
}

int binary_search(int n, const string& p)
{
    int low = MIN_K;
    int high = MAX_K;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        string s_mid;
        number_to_string(mid, s_mid);

        string res;
        power(s_mid, n, res);

        int cmp_res = number_cmp(res, p);
        if(cmp_res == 0)
            return mid;
        else if(cmp_res > 0)
            high = mid - 1;
        else
            low = mid + 1;
    }
}

int main()
{
    int n = 0;
    string p;

    while(cin >> n >> p)
    {
        cout << binary_search(n, p) << endl;
    }

    return 0;
}
