#include <iostream>

using namespace std;

int main()
{
	int t = 0;
	cin >> t;
	
	cout << "Lumberjacks:" << endl;
	for(auto i = 0; i < t; ++i)
	{
		int prev = 0, trend = 0;
		bool ordered = true;
		for(auto i = 0; i < 10; ++i)
		{
			int x = 0;
			cin >> x;
			if(!ordered) continue;
			
			if(prev)
			{
				if(x > prev)
				{
					if(trend != 0 && trend != 1)
						ordered = false;
					trend = 1;
				}
				else
				{
					if(trend != 0 && trend != -1)
						ordered = false;
					trend = -1;
				}
			}
			prev = x;
		}
		cout << (ordered ? "Ordered" : "Unordered") << endl;
	}
	
	return 0;
}