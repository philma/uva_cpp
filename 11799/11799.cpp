#include <iostream>

using namespace std;

int main()
{
	int t = 0;
	cin >> t;
	for(auto i = 0; i < t; ++i)
	{
		int n = 0;
		cin >> n;
		
		int max = 0;
		for(auto j = 0; j < n; ++j)
		{
			int x = 0;
			cin >> x;
			if(x > max) max = x;
		}
		cout << "Case " << i + 1 << ": " 
		     << max << endl;
	}
	
	return 0;
}