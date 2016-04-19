#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Elephant
{
    int w;
    int s;
    int pos;
};

struct EndPoint
{
    int prev;
    int max_len;
};

class Cmp
{
public:
    bool operator()(const Elephant& lhs, const Elephant& rhs)
    {
        return (lhs.s > rhs.s
                || (lhs.s == rhs.s && lhs.w < rhs.w));
    }
};

void OutputSeq(const vector<Elephant>& elephants
        , const vector<EndPoint>& endpoints
        , int pos)
{
    if(endpoints[pos].prev != pos)
        OutputSeq(elephants, endpoints, endpoints[pos].prev);
    cout << elephants[pos].pos << endl;
}

int main()
{ 
    int cnt = 0;
    vector<Elephant> elephants;
    vector<EndPoint> endpoints;

    Elephant elephant;
    while(cin >> elephant.w >> elephant.s)
    {
        ++cnt;
        elephant.pos = cnt;
        elephants.push_back(elephant);

        EndPoint endpoint;
        endpoint.prev = cnt - 1;
        endpoint.max_len = 1;
        endpoints.push_back(endpoint);
    }
    sort(elephants.begin(), elephants.end(), Cmp());

    for(unsigned int i = 1; i < elephants.size(); ++i)
    {
        for(int j = i - 1; j >= 0; --j)
        {
            if(elephants[j].w < elephants[i].w
                    && elephants[j].s > elephants[i].s
                    && (endpoints[j].max_len + 1) > endpoints[i].max_len)
            {
                endpoints[i].max_len = endpoints[j].max_len + 1;
                endpoints[i].prev = j;
            }
        }
    }

    int max_len = endpoints[0].max_len;
    int pos = 0;
    for(unsigned int i = 1; i < elephants.size(); ++i)
    {
        if(endpoints[i].max_len > max_len)
        {
            max_len = endpoints[i].max_len;
            pos = i;
        }
    }

    cout << max_len << endl;
    OutputSeq(elephants, endpoints, pos);

    return 0;
}
