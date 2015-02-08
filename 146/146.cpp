#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string line;
    while((cin >> line) && line != "#")
    {
        int len = line.size();
        int i = len - 1; 
        for(; i >= 0; --i)
        {
            if(i == len - 1)
                continue;
            if(line[i] < line[i + 1])
                break;
        }

        if(i < 0)
            cout << "No Successor" << endl;
        else
        {
            int j = len - 1;
            for(; j > i; --j)
            {
                if(line[j] > line[i])
                    break;
            }
            swap(line[i], line[j]);        

            string ans;
            for(j = 0; j <= i; ++j)
                ans.push_back(line[j]);
            for(j = len -1; j > i; --j)
                ans.push_back(line[j]);

            cout << ans << endl;
        }
    }

    return 0;
}
