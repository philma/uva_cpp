#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
    vector<string> table = {"one", "two", "three"};
    auto judge = [](const string& lhs, const string& rhs){
        if(lhs.size() != rhs.size())
            return false;

        int cnt = 0;
        for(size_t i = 0; i < lhs.size(); ++i)
            if(lhs[i] != rhs[i]) ++cnt;

        return cnt <= 1;
    };

    int n = 0;
    cin >> n;
    getchar();
    for(int i = 0; i < n; ++i)
    {
        string word;
        getline(cin, word);
        for(int j = 0; j < table.size(); ++j)
        {
            if(judge(word, table[j]))
            {
                cout << j + 1 << endl;
                break;
            }
        }
    }

    return 0;
}
