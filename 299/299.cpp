#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N = 0;
    cin >> N;
    while(N--)
    {
        int L = 0;
        cin >> L;

        vector<int> carriage;
        for(int i = 0; i < L; ++i)
        {
            int x = 0;
            cin >> x;
            carriage.push_back(x);
        }

        int ans = 0;
        for(int i = 0; i < L; ++i)
        {
            for(int j = i + 1; j < L; ++j)
            {
                if(carriage[i] > carriage[j])
                    ++ans;
            }
        }

        cout << "Optimal train swapping takes " << ans << " swaps." << endl;
    }

    return 0;
}
