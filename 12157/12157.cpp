#include <iostream>

using namespace std;

int main()
{
    int case_num = 0;
    cin >> case_num;
    for(int i = 0; i < case_num; ++i)
    {
        int n = 0;
        cin >> n;
        int m_cost = 0, j_cost = 0;
        for(int j = 0; j < n; ++j)
        {
            int dura = 0;
            cin >> dura;
            m_cost += dura / 30 + 1;
            j_cost += dura / 60 + 1;
        }
        m_cost *= 10;
        j_cost *= 15;

        cout << "Case " << i + 1 << ": ";
        if(m_cost < j_cost)
            cout << "Mile " << m_cost;
        else if(m_cost > j_cost)
            cout << "Juice " << j_cost; 
        else
            cout << "Mile Juice " << m_cost;
        cout << endl;
    }

    return 0;
}
