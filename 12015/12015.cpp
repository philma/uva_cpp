#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

struct WebSite
{
	string url;
	int relev;
};

int main()
{
	string line;
	getline(cin, line);
	int t = atoi(line.c_str());
	for(int i = 0; i < t; ++i)
	{
		int relev_max = 0;
		vector<WebSite> web_sites;
		for(int j = 0; j < 10; ++j)
		{
			getline(cin, line);
			size_t pos = line.find(' ');
			
			WebSite web_site;
			web_site.url = line.substr(0, pos);
			web_site.relev = atoi(line.substr(pos + 1, line.size() - pos).c_str());
			web_sites.push_back(web_site);
			if(web_site.relev > relev_max) relev_max = web_site.relev;
		}
		
		cout << "Case #" << i + 1 << ":" << endl;
		for(auto& web_site : web_sites)
		{
			if(web_site.relev == relev_max)
				cout << web_site.url << endl;
		}
	}
	
	return 0;
}