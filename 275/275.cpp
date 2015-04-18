/*
 * Created on: 2015-04-18
 *     Author: philma
 */

#include <iostream>
#include <string>
#include <map>

using namespace std;

void process(int a, int b)
{
    string output = ".";
    map<int, int> numbers;
    int count = 1;
    int reminder = a;

    while(reminder && numbers.find(reminder) == numbers.end())
    {
        numbers.insert(make_pair(reminder, count));
        char digit = (reminder * 10 / b) + '0';
        reminder = reminder * 10 % b;
        ++count;
        output.push_back(digit);
    }

    bool terminate = false;
    if(reminder == 0) terminate = true;

    for(int i = 0; i < output.size(); ++i)
    {
        cout << output[i];
        if((i + 1) % 50 == 0)
            cout << endl;
    }
    if(output.size() % 50)
        cout << endl;

    if(terminate)
        cout << "This expansion terminates." << endl;
    else
        cout << "The last " << count - numbers[reminder] << " digits repeat forever." << endl;
    cout << endl;
}

int main()
{
    int a = 0, b = 0;
    while(cin >> a >> b && !(a == 0 && b == 0))
        process(a, b);

    return 0;
}
