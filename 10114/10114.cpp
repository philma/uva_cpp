#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int durat = 0, d_record = 0;
    double down_pay = 0, owe = 0;
    while(cin >> durat >> down_pay >> owe >> d_record
            && durat >= 0)
    {
        vector<pair<int, double>> d_records;
        for(int i = 0; i < d_record; ++i)
        {
            pair<int, double> tmp;
            cin >> tmp.first >> tmp.second;
            d_records.push_back(tmp);
        }

        vector<double> rates;
        for(int i = 0; i < d_records.size(); ++i)
        {
            int end = i == d_records.size() - 1 ? durat : d_records[i + 1].first - 1;
            for(int j = d_records[i].first; j <= end; ++j)
                rates.push_back(d_records[i].second);
        }

        if(durat == 0)
        {
            cout << "0 months" << endl;
            continue;
        }

        double month_pay = owe / durat;
        double car = down_pay + owe;
        for(int i = 0; i <= durat; ++i)
        {
            car *= 1 - rates[i];
            if(i) owe -= month_pay;
            if(owe < car)
            {
                cout << i << " month";
                if(i != 1) cout << "s";
                cout << endl;
                break;
            }
        }
    }

    return 0;
}
