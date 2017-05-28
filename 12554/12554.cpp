#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    vector<string> song_words = 
    {
        "Happy", "birthday", "to", "you",
        "Happy", "birthday", "to", "you",
        "Happy", "birthday", "to", "Rujia",
        "Happy", "birthday", "to", "you",
    };

    int n = 0;
    cin >> n;
    getchar();

    vector<string> names;
    for(int i = 0; i < n; ++i)
    {
        string line;
        getline(cin, line);
        names.push_back(line);
    }

    int pos1 = 0, pos2 = 0;
    int end = (n / 16 + 1) * 16;
    for(int i = 0; i < end; ++i)
    {
        cout << names[pos1] << ": ";
        cout << song_words[pos2] << endl;
        pos1 = (pos1 + 1) % names.size();
        pos2 = (pos2 + 1) % 16;
    }

    return 0;
}
