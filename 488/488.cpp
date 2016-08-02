#include <iostream>

using namespace std;

void print_wave(int height)
{
    int line_cnt = 2 * height - 1;
    for(int i = 0; i < line_cnt; ++i)
    {
        int len = (i + 1) > height ? 2 * height - (i + 1) : i + 1;
        for(int j = 0; j < len; ++j)
            cout << len;
        cout << endl;
    }
}

int main()
{
    int cases = 0;
    cin >> cases;
    while(cases--)
    {
        int height = 0, freq = 0;
        cin >> height >> freq;

        for(int i = 0; i < freq; ++i)
        {
            if(i) cout << endl;
            print_wave(height);
        }

        if(cases) cout << endl;
    }

    return 0;
}
