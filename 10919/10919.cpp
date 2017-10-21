#include <iostream>
#include <set>

using namespace std;

int main()
{
    int k = 0, m = 0;
    while(cin >> k && k)
    {
        cin >> m;
        
        set<int> selects;
        for(int i = 0; i < k; ++i)
        {
            int course = 0;
            cin >> course;
            selects.insert(course);
        }

        bool meet = true;
        for(int i = 0; i < m; ++i)
        {
            int c = 0, r = 0;
            int cnt = 0;
            cin >> c >> r;
            for(int j = 0; j < c; ++j)
            {
                int tmp = 0;
                cin >> tmp;
                if(selects.find(tmp) != selects.end())
                    ++cnt;
            }
            if(cnt < r) meet = false;
        }

        cout << (meet ? "yes" : "no") << endl;
    }

    return 0;
}