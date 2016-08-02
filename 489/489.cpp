#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

static const int MAX_WRONG_TIMES = 7;

int main()
{
    int round = 0;
    while(cin >> round && round != -1)
    {
        getchar();
        string puzzle, guess;
        getline(cin, puzzle);
        getline(cin, guess);
        cout << "Round " << round << endl;
        
        string tmp(puzzle.length(), '0');
        int cnt = 0, wrong = 0;
        for(size_t i = 0; i < guess.length(); ++i)
        {
            bool find = false;
            for(size_t j = 0; j < puzzle.length(); ++j)
            {
                if(guess[i] == puzzle[j])
                {
                    find = true;
                    if(tmp[j] == '0')
                    {
                        ++cnt;
                        tmp[j] = '1';
                    }
                }
            }

            if(!find)
            {
                ++wrong;
                if(wrong >= MAX_WRONG_TIMES)
                {
                    cout << "You lose." << endl;
                    break;
                }
            }
            else
            {
                if(cnt == puzzle.length())
                {
                    cout << "You win." << endl;
                    break;
                }
            }
        }

        if(wrong < MAX_WRONG_TIMES && cnt < puzzle.length())
            cout << "You chickened out." << endl;
    }
    
    return 0;
}
