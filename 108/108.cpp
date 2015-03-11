#include <iostream>

using namespace std;

static const int MAX_N = 100;

void init(int sum[][MAX_N], int matrix[][MAX_N], int n)
{
    for(int col = 0; col < n; ++col)
    {
        int tmp = 0;
        for(int row = 0; row < n; ++row)
        {
            tmp += matrix[row][col];
            sum[row][col] = tmp;
        }
    }
}

int max_section_sum(int* p, int n)
{
    int ans = p[0];
    for(int i = 1; i < n; ++i)
    {
        p[i] = p[i - 1] + p[i] > p[i] ? p[i - 1] + p[i] : p[i];
        if(ans < p[i])
            ans = p[i];
    }

    return ans;
}

int max_matrix_sum(int sum[][MAX_N], int matrix[][MAX_N], int n)
{
    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = i; j < n; ++j)
        {
            int tmp[MAX_N];
            for(int k = 0; k < n; ++k)
                tmp[k] = i == 0 ? sum[j][k]: sum[j][k] - sum[i - 1][k];
            
            int max_ss = max_section_sum(tmp, n);
            if(i == 0 && j == 0)
                ans = max_ss;
            else
                ans = ans < max_ss ? max_ss : ans;
                
        }
    }

    return ans;
}

int main()
{
    int matrix[MAX_N][MAX_N];
    int n;

    while(cin >> n)
    {
        for(int row = 0; row < n; ++row)
        {
            for(int col = 0; col < n; ++col)
                cin >> matrix[row][col];
        }
        
        int sum[MAX_N][MAX_N];
        init(sum, matrix, n);

        cout << max_matrix_sum(sum, matrix, n) << endl; 
    }

    return 0;
}
