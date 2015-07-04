#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class Poker
{
public:
    Poker():value(0), suit(' ')
    {
    }

    Poker(int v, char s):value(v), suit(s)
    {
    }

    int value;      //牌大小
    char suit;      //牌花色
};

class HandPoker
{
public:
    static const int HIGH_CARD = 0;             //高牌
    static const int PAIR = 1;                  //一对
    static const int TWO_PAIRS = 2;             //两对
    static const int THREE_OF_A_KIND = 3;       //三条
    static const int STRAIGHT = 4;              //顺子
    static const int FLUSH = 5;                 //同花
    static const int FULL_HOUSE = 6;            //葫芦
    static const int FOUR_OF_A_KIND = 7;        //四条
    static const int STRAIGHT_FLUSH = 8;        //同花顺

    HandPoker():poker_pattern(HIGH_CARD), poker_init(false)
    {
    }

    void init(const vector<Poker>& pokers);

private:
    void parse_poker_pattern();

public:
    vector<Poker> hand_poker;   //一手牌
    int poker_pattern;          //牌型
    bool poker_init;
};

class PokerCnt
{
public:
    PokerCnt():value(0), cnt(0)
    {
    }

    PokerCnt(int v, int c):value(v), cnt(c)
    {
    }

    int value;
    int cnt;
};

class Cmp
{
public:
    bool operator()(const Poker& lhs, const Poker& rhs)
    {
        return lhs.value > rhs.value;
    }

    bool operator()(const PokerCnt& lhs, const PokerCnt& rhs)
    {
        return (lhs.cnt == rhs.cnt ? lhs.value > rhs.value : lhs.cnt > rhs.cnt);
    }
};

void HandPoker::init(const vector<Poker>& pokers)
{
    hand_poker = pokers;
    poker_init = true;
    parse_poker_pattern();
}

void HandPoker::parse_poker_pattern()
{
    if(!poker_init) return ;

    map<int, int> value_count;
    set<char> suit_count;
    for(unsigned int i = 0; i < hand_poker.size(); ++i)
    {
        if(suit_count.find(hand_poker[i].suit) == suit_count.end())
            suit_count.insert(hand_poker[i].suit);

        map<int, int>::iterator it = value_count.find(hand_poker[i].value);
        if(it == value_count.end())
            value_count.insert(make_pair(hand_poker[i].value, 1));
        else
            ++(it->second);
    }

    bool flush = (suit_count.size() == 1 ? true : false);       //是同花
    bool straight = false;
    if(value_count.size() == hand_poker.size()
       && (value_count.rbegin()->first - value_count.begin()->first + 1) == hand_poker.size())
        straight = true;                                        //是顺子

    if(flush && straight)
        poker_pattern = STRAIGHT_FLUSH;
    else if(flush)
        poker_pattern = FLUSH;
    else if(straight)
        poker_pattern = STRAIGHT;
    else
    {
        map<int, int> tmp;
        for(map<int, int>::iterator it = value_count.begin(); it != value_count.end(); ++it)
        {
            if(tmp.find(it->second) == tmp.end())
                tmp.insert(make_pair(it->second, 1));
            else
                ++(tmp[it->second]);
        }

        if(tmp.find(4) != tmp.end())
            poker_pattern = FOUR_OF_A_KIND;
        else if(tmp.find(3) != tmp.end() && tmp.find(2) != tmp.end())
            poker_pattern = FULL_HOUSE;
        else if(tmp.find(3) != tmp.end())
            poker_pattern = THREE_OF_A_KIND;
        else if(tmp.find(2) != tmp.end() && tmp[2] == 2)
            poker_pattern = TWO_PAIRS;
        else if(tmp.find(2) != tmp.end() && tmp[2] == 1)
            poker_pattern = PAIR;
        else
            poker_pattern = HIGH_CARD;
    }
}

bool same_pattern_cmp1(const HandPoker& lhs, const HandPoker& rhs, unsigned int flag)
{
    vector<Poker> lhs_pokers(lhs.hand_poker);
    vector<Poker> rhs_pokers(rhs.hand_poker);
    sort(lhs_pokers.begin(), lhs_pokers.end(), Cmp());
    sort(rhs_pokers.begin(), rhs_pokers.end(), Cmp());

    if(!flag)
    {
        for(unsigned int i = 0; i < lhs_pokers.size(); ++i)
        {
            if(lhs_pokers[i].value == rhs_pokers[i].value)
                continue;
            return lhs_pokers[i].value < rhs_pokers[i].value;
        }
        return false;
    }
    else
        return lhs_pokers[0].value < rhs_pokers[0].value;
}

bool same_pattern_cmp2(const HandPoker& lhs, const HandPoker& rhs, unsigned int flag)
{
    map<int, int> lhs_value_cnt;
    map<int, int> rhs_value_cnt;
    for(unsigned int i = 0; i < lhs.hand_poker.size(); ++i)
    {
        if(lhs_value_cnt.find(lhs.hand_poker[i].value)
            == lhs_value_cnt.end())
            lhs_value_cnt.insert(make_pair(lhs.hand_poker[i].value, 1));
        else
            ++(lhs_value_cnt[lhs.hand_poker[i].value]);

        if(rhs_value_cnt.find(rhs.hand_poker[i].value)
            == rhs_value_cnt.end())
            rhs_value_cnt.insert(make_pair(rhs.hand_poker[i].value, 1));
        else
            ++(rhs_value_cnt[rhs.hand_poker[i].value]);
    }

    if(!flag)
    {
        int lhs_max_more_cnt = -1, rhs_max_more_cnt = -1;
        int lhs_max_more_value = 0, rhs_max_more_value = 0;
        for(map<int, int>::iterator it = lhs_value_cnt.begin(); it != lhs_value_cnt.end(); ++it)
        {
            if(it->second > lhs_max_more_cnt)
            {
                lhs_max_more_value = it->first;
                lhs_max_more_cnt = it->second;
            }
        }

        for(map<int, int>::iterator it = rhs_value_cnt.begin(); it != rhs_value_cnt.end(); ++it)
        {
            if(it->second > rhs_max_more_cnt)
            {
                rhs_max_more_value = it->first;
                rhs_max_more_cnt = it->second;
            }
        }

        return lhs_max_more_value < rhs_max_more_value;
    }
    else
    {
        vector<PokerCnt> lhs_tmp;
        vector<PokerCnt> rhs_tmp;
        for(map<int, int>::iterator it = lhs_value_cnt.begin(); it != lhs_value_cnt.end(); ++it)
        {
            PokerCnt poker_cnt(it->first, it->second);
            lhs_tmp.push_back(poker_cnt);
        }

        for(map<int, int>::iterator it = rhs_value_cnt.begin(); it != rhs_value_cnt.end(); ++it)
        {
            PokerCnt poker_cnt(it->first, it->second);
            rhs_tmp.push_back(poker_cnt);
        }

        sort(lhs_tmp.begin(), lhs_tmp.end(), Cmp());
        sort(rhs_tmp.begin(), rhs_tmp.end(), Cmp());

        for(unsigned int i = 0; i < lhs_tmp.size(); ++i)
        {
            if(lhs_tmp[i].value == rhs_tmp[i].value)
                continue;
            return lhs_tmp[i].value < rhs_tmp[i].value;
        }
        return false;
    }
}

bool operator<(const HandPoker& lhs, const HandPoker& rhs)
{
    if(lhs.poker_pattern != rhs.poker_pattern)
        return lhs.poker_pattern < rhs.poker_pattern;
    else
    {
        if(lhs.poker_pattern == HandPoker::HIGH_CARD
           || lhs.poker_pattern == HandPoker::FLUSH)
        {
            return same_pattern_cmp1(lhs, rhs, 0);
        }
        else if(lhs.poker_pattern == HandPoker::STRAIGHT
                || lhs.poker_pattern == HandPoker::STRAIGHT_FLUSH)
        {
            return same_pattern_cmp1(lhs, rhs, 1);
        }
        else if(lhs.poker_pattern == HandPoker::THREE_OF_A_KIND
                || lhs.poker_pattern == HandPoker::FULL_HOUSE
                || lhs.poker_pattern == HandPoker::FOUR_OF_A_KIND)
        {
            return same_pattern_cmp2(lhs, rhs, 0);
        }
        else
        {
            return same_pattern_cmp2(lhs, rhs, 1);
        }
    }
}

bool operator>(const HandPoker& lhs, const HandPoker& rhs)
{
    return rhs < lhs;
}

bool operator==(const HandPoker& lhs, const HandPoker& rhs)
{
    if(!(lhs < rhs) && !(lhs > rhs))
        return true;
    else
        return false;
}

int main()
{
    char dot[] = {'2', '3', '4', '5', '6', '7', '8',
                  '9', 'T', 'J', 'Q', 'K', 'A'};
    map<char, int> dict;
    for(int i = 0; i < 13; ++i)
        dict.insert(make_pair(dot[i], i));

    string line;
    while(getline(cin, line))
    {
        int count = 0, pos = -1;
        int len = line.size();

        vector<Poker> black_tmp;
        vector<Poker> white_tmp;
        while(pos < len)
        {
            int v = dict[line[++pos]];
            char s = line[++pos];
            Poker poker(v, s);
            ++pos;
            ++count;
            if(count <= 5)
                black_tmp.push_back(poker);
            else
                white_tmp.push_back(poker);
        }

        HandPoker black;
        HandPoker white;
        black.init(black_tmp);
        white.init(white_tmp);

        if(black < white)
            cout << "White wins." << endl;
        else if(black > white)
            cout << "Black wins." << endl;
        else
            cout << "Tie." << endl;
    }

    return 0;
}

