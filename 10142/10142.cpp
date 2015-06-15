#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>

using namespace std;

int str_2_num(const string& str)
{
    int num = 0;
    for(size_t i = 0; i < str.size(); ++i)
        num = num * 10 + str[i] - '0';
    return num;
}

void split_number(const string& str, list<int>& numbers)
{
    numbers.clear();
    string tmp = str;
    while(tmp != "")
    {
        size_t pos = tmp.find(' ');
        if(pos == string::npos)
        {
            numbers.push_back(str_2_num(tmp));
            tmp = "";
        }
        else
        {
            numbers.push_back(str_2_num(tmp.substr(0, pos)));
            tmp = tmp.substr(pos + 1);
        }
    }
}

void elect(map<int, string>& names, vector<list<int> >& votes)
{
    while(true)
    {
        map<int, int> result;
        for(map<int, string>::iterator it = names.begin(); it != names.end(); ++it)
            result.insert(make_pair(it->first, 0));

        for(size_t i = 0; i < votes.size(); ++i)
            result[votes[i].front()]++;

        int max_v = -1, min_v = 10000;
        int winner = -1;
        for(map<int, int>::iterator it = result.begin(); it != result.end(); ++it)
        {
            if(it->second > max_v)
            {
                max_v = it->second;
                winner = it->first;
            }

            if(it->second < min_v)
                min_v = it->second;
        }

        if(max_v * 2 > votes.size())
        {
            cout << names[winner] << endl;
            break;
        }

        vector<int> knock_out;
        for(map<int, int>::iterator it = result.begin(); it != result.end(); ++it)
        {
            if(it->second == min_v)
                knock_out.push_back(it->first);
        }

        if(knock_out.size() == names.size())
        {
            for(map<int, string>::iterator it = names.begin(); it != names.end(); ++it)
                cout << it->second << endl;
            break;
        }

        for(size_t i = 0; i < knock_out.size(); ++i)
        {
            names.erase(knock_out[i]);
            for(size_t j = 0; j < votes.size(); ++j)
            {
                for(list<int>::iterator it = votes[j].begin(); it != votes[j].end(); ++it)
                {
                    if(*it == knock_out[i])
                    {
                        votes[j].erase(it);
                        break;
                    }
                }
            }
        }
    }
}

int main()
{
    string line;
    getline(cin, line);
    getline(cin, line);

    bool stop = false;
    while(!stop)
    {
        getline(cin, line);
        int cd_num = str_2_num(line);

        map<int, string> names;
        for(int i = 0; i < cd_num; ++i)
        {
            getline(cin, line);
            names.insert(make_pair(i + 1, line));
        }

        vector<list<int> > votes;
        bool input_end = true;
        while(getline(cin, line))
        {
            if(line == "")
            {
                input_end = false;
                break;
            }

            list<int> tmp;
            split_number(line, tmp);
            votes.push_back(tmp);
        }
        stop = input_end;

        elect(names, votes);
        if(!input_end)
            cout << endl;
    }

    return 0;
}
