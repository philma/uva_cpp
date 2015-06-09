#include <iostream>
#include <vector>

using namespace std;

int str_2_num(const string& str)
{
    int num = 0;
    for(unsigned int i = 0; i < str.size(); ++i)
        num = 10 * num + str[i] - '0';
    return num;
}

void prepare_run(vector<int>& storage, vector<int>& tmp_storage)
{
    for(int i = 0; i < 10; ++i)
        tmp_storage.push_back(0);
    if(storage.size() < 1000)
    {
        int diff = 1000 - storage.size();
        for(int i = 0; i < diff; ++i)
            storage.push_back(0);
    }
}

int run(vector<int>& storage, vector<int>& tmp_storage)
{
    int index = 0;
    int cmd_count = 0;
    bool stop = false;
    while(!stop)
    {
        ++cmd_count;
        int d = storage[index] / 10 % 10;
        int n = storage[index] % 10;
        switch(storage[index] / 100)
        {
            case 0:
            {
                if(tmp_storage[n] != 0)
                    index = tmp_storage[d];
                else
                    ++index;
                break;
            }
            case 1:
            {
                if(storage[index] == 100)
                    stop = true;
                break;
            }
            case 2:
            {
                tmp_storage[d] = n;
                ++index;
                break;
            }
            case 3:
            {
                tmp_storage[d] = (tmp_storage[d] + n) % 1000;
                ++index;
                break;
            }
            case 4:
            {
                tmp_storage[d] = (tmp_storage[d] * n) % 1000;
                ++index;
                break;
            }
            case 5:
            {
                tmp_storage[d] = tmp_storage[n];
                ++index;
                break;
            }
            case 6:
            {
                tmp_storage[d] = (tmp_storage[n] + tmp_storage[d]) % 1000;
                ++index;
                break;
            }
            case 7:
            {
                tmp_storage[d] = (tmp_storage[d] * tmp_storage[n]) % 1000;
                ++index;
                break;
            }
            case 8:
            {
                tmp_storage[d] = storage[tmp_storage[n]];
                ++index;
                break;
            }
            case 9:
            {
                storage[tmp_storage[n]] = tmp_storage[d];
                ++index;
                break;
            }
        }
    }

    return cmd_count;
}

int main()
{
    int count = 0;
    string line;
    vector<int> storage;
    vector<int> tmp_storage;

    getline(cin, line);
    while(getline(cin, line))
    {
        if(line == "")
        {
            ++count;
            if(count > 1)
            {
                prepare_run(storage, tmp_storage);
                cout << run(storage, tmp_storage) << endl;
                cout << endl;
            }

            storage.clear();
            tmp_storage.clear();
        }
        else
            storage.push_back(str_2_num(line));
    }

    prepare_run(storage, tmp_storage);
    cout << run(storage, tmp_storage) << endl;

    return 0;
}
