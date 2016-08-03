#include <iostream>
#include <string>

using namespace std;

static const int CH_REVERSE_NUM = 21;
static const char CH_REVERSE[CH_REVERSE_NUM][2] = 
{
    {'A', 'A'}, {'E', '3'}, {'H', 'H'}, {'I', 'I'},
    {'J', 'L'}, {'L', 'J'}, {'M', 'M'}, {'O', 'O'},
    {'S', '2'}, {'T', 'T'}, {'U', 'U'}, {'V', 'V'},
    {'W', 'W'}, {'X', 'X'}, {'Y', 'Y'}, {'Z', '5'},
    {'1', '1'}, {'2', 'S'}, {'3', 'E'}, {'5', 'Z'},
    {'8', '8'}
};

bool palindrome(const string& str)
{
    int len = str.length() / 2;
    for(int i = 0; i < len; ++i)
    {
        if(str[i] != str[str.length() - 1 - i])
            return false;
    }

    return true;
}

bool mirrored(const string& str)
{
    int len = str.length() / 2;
    if(str.length() & 1) len += 1;
    for(int i = 0; i < len; ++i)
    {
        bool reverse = false;
        int index = str.length() - 1 - i;
        for(int j = 0; j < CH_REVERSE_NUM; ++j)
        {
            if(CH_REVERSE[j][0] == str[i]
                    && CH_REVERSE[j][1] == str[index])
            {
                reverse = true;
                break;
            }
        }

        if(!reverse) return false;
    }

    return true;
}

int main()
{
    string line;
    while(getline(cin, line))
    {
        bool is_pal = palindrome(line);
        bool is_mir = mirrored(line);

        cout << line << " -- ";
        if(!is_pal && !is_mir)
            cout << "is not a palindrome.";
        else if(is_pal && !is_mir)
            cout << "is a regular palindrome.";
        else if(!is_pal && is_mir)
            cout << "is a mirrored string.";
        else
            cout << "is a mirrored palindrome.";
        cout << endl;
        cout << endl;
    }

    return 0;
}
