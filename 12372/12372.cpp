#include <iostream>

using namespace std;

int main()
{
	int t = 0;
	cin >> t;
	for(int i = 0; i < t; ++i)
	{
		int l = 0, w = 0, h = 0;
		cin >> l >> w >> h;
		cout << "Case " << i + 1 << ": ";
		cout << ((l <= 20 && w <= 20 && h <= 20) ? "good" : "bad");
		cout << endl;
	}
	
	return 0;
}