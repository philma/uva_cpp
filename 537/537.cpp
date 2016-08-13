#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

struct DataField
{
    char type;
    double value;
};

void parse_data_field(const string& line, size_t pos, DataField& data)
{
    data.type = line[pos - 1];
    data.value = 0;

    string tmp;
    bool dot = false;
    bool negative = false;
    for(++pos; ; ++pos)
    {
        if((line[pos] < '0' || line[pos] > '9')
                && line[pos] != '.'
                && line[pos] != '-')
            break;

        if(line[pos] == '.')
        {
            dot = true;
            continue;
        }

        if(line[pos] == '-')
        {
            negative = true;
            continue;
        }

        if(!dot)
            data.value = data.value * 10 + line[pos] - '0';
        else
            tmp += line[pos];
    }

    double tmp_value = 0;
    for(int i = tmp.size() - 1; i >= 0; --i)
        tmp_value = (tmp_value + (tmp[i] - '0')) / 10;
    data.value += tmp_value;

    if(negative) data.value *= -1;

    if(line[pos] == 'm')
        data.value *= 0.001;
    else if(line[pos] == 'k')
        data.value *= 1000;
    else if(line[pos] == 'M')
        data.value *= 1000000;
}

void caculate(const DataField& data1, const DataField& data2, DataField& result)
{
    if(data1.type != 'P' && data2.type != 'P')
    {
        result.type = 'P';
        result.value = data1.value * data2.value;
    }
    else if(data1.type != 'U' && data2.type != 'U')
    {
        result.type = 'U';
        if(data1.value == 0 || data2.value == 0)
            result.value = 0;
        else
            result.value = 
                data1.type == 'P' ? 
                data1.value / data2.value : data2.value / data1.value;
    }
    else
    {
        result.type = 'I';
        if(data1.value == 0 || data2.value == 0)
            result.value = 0;
        else
            result.value = 
                data1.type == 'P' ?
                data1.value / data2.value : data2.value / data1.value;
    }
}

int main()
{
    int n = 0;
    cin >> n;
    getchar();

    for(int i = 0; i < n; ++i)
    {
        string line;
        getline(cin, line);

        DataField data1, data2;
        size_t pos = line.find_first_of('=');
        parse_data_field(line, pos, data1);
        pos = line.find_last_of('=');
        parse_data_field(line, pos, data2);

        DataField result;
        caculate(data1, data2, result);
        cout << "Problem #" << i + 1 << endl;
        cout << result.type << '=';
        printf("%.2lf", result.value);
        
        if(result.type == 'P')
            cout << 'W';
        else if(result.type == 'U')
            cout << 'V';
        else
            cout << 'A';
        cout << endl << endl;
    }

    return 0;
}
