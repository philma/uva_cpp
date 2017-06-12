#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n = 0, r = 0;
    while(cin >> n >> r)
    {
        map<string, vector<int>> arrays;
        for(int i = 0; i < n; ++i)
        {
            getchar();
            string name;
            int base_addr = 0, elem_size = 0, dimen = 0;
            cin >> name >> base_addr >> elem_size >> dimen;
            vector<pair<int, int>> lu_bounds;
            for(int j = 0; j < dimen; ++j)
            {
                pair<int, int> tmp;
                cin >> tmp.first >> tmp.second;
                lu_bounds.push_back(tmp);
            }
            
            vector<int> c_values(dimen + 1, 0);
            c_values[dimen] = elem_size;
            int sum = c_values[dimen] * lu_bounds[dimen - 1].first;
            for(int j = dimen - 1; j >= 1; --j)
            {
                c_values[j] = c_values[j + 1] * (lu_bounds[j].second - lu_bounds[j].first + 1);
                sum += c_values[j] * lu_bounds[j - 1].first;
            }
            c_values[0] = base_addr - sum;
            arrays.insert(make_pair(name, c_values));
        }

        for(int i = 0; i < r; ++i)
        {
            getchar();
            string name;
            cin >> name;
            cout << name << "[";
            int sum = arrays[name][0];
            for(int j = 1; j <= arrays[name].size() - 1; ++j)
            {
                int tmp = 0;
                cin >> tmp;
                sum += tmp * arrays[name][j];
                cout << tmp;
                if(j < arrays[name].size() - 1)
                    cout << ", ";
                else
                    cout << "]";
            }
            cout << " = " << sum << endl;
        }
    }

    return 0;
}