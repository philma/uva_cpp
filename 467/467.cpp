#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

enum State
{
    GREEN,
    YELLOW,
    RED
};

struct Signal
{
    Signal(uint8_t cycle_time_)
        :state(GREEN)
        ,cycle_time(cycle_time_)
        ,timer(1)
    {}

    void next_second();

    State state;
    uint8_t cycle_time;
    uint8_t timer;
};

void Signal::next_second()
{
    if(state == GREEN && timer + 5 == cycle_time)
        state = YELLOW;
    else if(state == YELLOW && timer == cycle_time)
        state = RED;
    else if(state == RED && timer == cycle_time)
        state = GREEN;

    if((++timer) > cycle_time)
        timer = 1;
}

int main()
{
    string line;
    int set_cnt = 0;
    while(getline(cin, line))
    {
        ++set_cnt;
        stringstream ss_line(line);
        vector<Signal> signals;
        uint16_t tmp;
        while(ss_line >> tmp)
            signals.push_back(Signal(tmp));

        uint16_t timer = 1;
        bool never = true;
        uint16_t yellow = 0;
        while(timer <= 3600)
        {
            bool all_green = true;
            for(size_t i = 0; i < signals.size(); ++i)
            {
                Signal& signal = signals[i];
                signal.next_second();

                if(signal.state != GREEN)
                    all_green = false;
                if(signal.state == YELLOW)
                    yellow |= 1 << i;
            }

            if(yellow && all_green)
            {
                cout << "Set " << set_cnt << " synchs again at "
                     << timer / 60 << " minute(s) and "
                     << timer % 60 << " second(s) after all turning green."
                     << endl;
                never = false;
                break;
            }

            ++timer;
        }

        if(never)
        {
            cout << "Set " << set_cnt << " is unable to synch after one hour."
                 << endl;
        }
    }

    return 0;
}
