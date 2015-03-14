#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Guess
{
    string number;
    string feedback;
};

bool judge(const string& lhs, const string& rhs, const string& feedback)
{
    int right_both = 0;
    int len = lhs.size();
    for(int i = 0; i < len; ++i)
    {
        if(lhs[i] == rhs[i])
            ++right_both;
    }

    if(feedback[0] - '0' != right_both)
        return false;

    vector<int> tmp1(10, 0);
    vector<int> tmp2(10, 0);
    for(int i = 0; i < lhs.size(); ++i)
        ++tmp1[lhs[i] - '0'];
    for(int i= 0; i < rhs.size(); ++i)
        ++tmp2[rhs[i] - '0'];

    int number_right = 0;
    for(int i = 0; i < tmp1.size(); ++i)
        number_right += tmp1[i] < tmp2[i] ? tmp1[i] : tmp2[i];

    if(number_right - right_both != feedback[2] - '0')
        return false;

    return true;
}

void number_to_string(int number, string& str)
{
    for(int i = 0; i < 4; ++i)
    {
        str.insert(str.begin(), '0' + (number % 10));
        number /= 10;
    }
}

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int g;
        cin >> g;

        vector<Guess> guesses;
        for(int i = 0; i < g; ++i)
        {
            Guess tmp;
            cin >> tmp.number >> tmp.feedback;
            guesses.push_back(tmp);
        }

        int count = 0;
        string ans;
        for(int i = 0; i <= 9999; ++i)
        {
            string num_str;
            number_to_string(i, num_str);

            bool ok = true;
            for(int j = 0; j < guesses.size(); ++j)
            {
                if(!judge(num_str, guesses[j].number, guesses[j].feedback))
                {
                    ok = false;
                    break;
                }
            }

            if(ok)
            {
                ans = num_str;
                ++count;
                if(count > 1)
                    break;
            }
        }

        if(count == 1)
            cout << ans << endl;
        else if(count == 0)
            cout << "impossible" << endl;
        else
            cout << "indeterminate" << endl;
    }

    return 0;
}
