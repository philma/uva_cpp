#include <iostream>
#include <vector>

using namespace std;

struct Number
{
    int num;
    char mark;
};

void read_numbers(vector<Number>& numbers, bool& all_zero, int n)
{
    all_zero = true;
    for(int i = 0; i < n; ++i)
    {
        int tmp = 0;
        cin >> tmp;
        Number number;
        number.num = tmp;
        number.mark = '0';
        numbers.push_back(number);
        if(tmp) all_zero = false;
    }
}

void print_hint(vector<Number>& secret, vector<Number>& guess)
{
    int strong = 0, weak = 0;
    for(int i = 0; i < secret.size(); ++i)
    {
        if(secret[i].num == guess[i].num)
        {
            ++strong;
            secret[i].mark = '1';
            guess[i].mark = '1';
        }
    }

    for(int i = 0; i < secret.size(); ++i)
    {
        for(int j = 0; j < guess.size() && secret[i].mark == '0'; ++j)
        {
            if(guess[j].mark == '1')
                continue;
            if(guess[j].num == secret[i].num)
            {
                ++weak;
                secret[i].mark = '1';
                guess[j].mark = '1';
            }
        }
    }
    cout << "    (" << strong 
         << "," << weak << ")" << endl;
}

int main()
{
    int n = 0, case_cnt = 0;
    while(cin >> n && n)
    {
        ++case_cnt;
        bool all_zero = false;
        vector<Number> secret;
        read_numbers(secret, all_zero, n);
        
        vector<Number> guess;
        cout << "Game " << case_cnt << ":" << endl;
        for(;;)
        {
            guess.clear();
            read_numbers(guess, all_zero, n);
            if(all_zero) break;

            vector<Number> secret_dup(secret);
            print_hint(secret_dup, guess);
        }
    }

    return 0;
}
