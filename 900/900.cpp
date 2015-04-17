#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<long long> ans;
    ans.push_back(1);
    ans.push_back(2);
    for(int i = 2; i < 50; ++i)
        ans.push_back(ans[i - 2] + ans[i - 1]);

    int n = 0;
    while(cin >> n && n)
        cout << ans[n - 1] << endl;

    return 0;
}
