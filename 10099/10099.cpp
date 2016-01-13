#include <iostream>
#include <vector>

using namespace std;

struct Road
{
    int city1;
    int city2;
    int capacity;
};

bool confirm(const vector<Road>& roads, int city_num, int guide_num, int start, int dest)
{
    vector<int> citys(city_num, 0);
    int cnt = 1;
    for(unsigned int i = 0; i < roads.size(); ++i)
    {
        if(roads[i].capacity < (guide_num + 1))
            continue;
        
        if(citys[roads[i].city1] == 0 && citys[roads[i].city2] == 0)
        {
            citys[roads[i].city1] = cnt;
            citys[roads[i].city2] = cnt;
            ++cnt;
        }
        else if(citys[roads[i].city1] != 0 && citys[roads[i].city2] != 0)
        {
            if(citys[roads[i].city1] != citys[roads[i].city2])
            {
                for(unsigned int j = 0; j < city_num; ++j)
                {
                    if(citys[j] == citys[roads[i].city2])
                        citys[j] = citys[roads[i].city1];
                }
            }
        }
        else
        {
            if(citys[roads[i].city1] == 0)
                citys[roads[i].city1] = citys[roads[i].city2];
            else
                citys[roads[i].city2] = citys[roads[i].city1];
        }
    }

    if(citys[start] == citys[dest] && citys[start])
        return true;
    else
        return false;
}

int binary_search(const vector<Road>& roads, int city_num, int tourists, int start, int dest)
{
    int begin = 1, end = tourists;
    int ans = -1;
    while(begin <= end)
    {
        int mid = (begin + end) / 2;
        if(confirm(roads, city_num, mid, start, dest))
        {
            ans = mid;
            begin = mid + 1;
        }
        else
            end = mid - 1;
    }

    return ans;
}

int main()
{
    int case_cnt = 0;
    int city_num = 0, road_num = 0;
    while(cin >> city_num >> road_num)
    {
        ++case_cnt;
        if(city_num == 0 && road_num == 0)
            break;
        
        vector<Road> roads;
        for(unsigned int i = 0; i < road_num; ++i)
        {
            Road road;
            cin >> road.city1 >> road.city2 >> road.capacity;
            --road.city1, --road.city2;
            roads.push_back(road);
        }

        int start = 0, dest = 0, tourists = 0;
        cin >> start >> dest >> tourists;
        --start, --dest;

        int max_guide_num = binary_search(roads, city_num, tourists, start, dest);

        int ans = tourists / max_guide_num;
        cout << "Scenario #" << case_cnt << endl;
        cout << "Minimum Number of Trips = "
             << (tourists % max_guide_num ? ans + 1 : ans)
             << endl << endl;
    }

    return 0;
}
