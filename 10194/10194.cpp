#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

class Team
{
    friend class Cmp;
public:
    Team(const string& t_name)
        :name(t_name)
        ,points_earned(0)
        ,games_played(0)
        ,wins(0)
        ,ties(0)
        ,losses(0)
        ,goal_diff(0)
        ,goals_scored(0)
        ,goals_against(0)
    {
    }

    void win(int myself, int oponent);
    void tie(int score);
    void lose(int myself, int oponent);
    void to_string(int rank);

private:
    string name;
    int points_earned;
    int games_played;
    int wins;
    int ties;
    int losses;
    int goal_diff;
    int goals_scored;
    int goals_against;
};

void Team::to_string(int rank)
{
    cout << rank << ") ";
    cout << name << " ";
    cout << points_earned << "p, ";
    cout << games_played << "g ";
    cout << "(" << wins << "-" << ties << "-" << losses << "), ";
    cout << goal_diff << "gd ";
    cout << "(" << goals_scored << "-" << goals_against << ")";
    cout << endl;
}

void Team::win(int myself, int oponent)
{
    points_earned += 3;
    games_played += 1;
    wins += 1;
    goal_diff += myself - oponent;
    goals_scored += myself;
    goals_against += oponent;
}

void Team::tie(int score)
{
    points_earned += 1;
    games_played += 1;
    ties += 1;
    goals_scored += score;
    goals_against += score;
}

void Team::lose(int myself, int oponent)
{
    games_played += 1;
    losses += 1;
    goal_diff += myself - oponent;
    goals_scored += myself;
    goals_against += oponent;
}

bool cmp_str_no_case(const string& lhs, const string& rhs)
{
    string tmp1(lhs), tmp2(rhs);
    for(size_t i = 0; i < tmp1.size(); ++i)
        tmp1[i] = tolower(tmp1[i]);
    for(size_t i = 0; i < tmp2.size(); ++i)
        tmp2[i] = tolower(tmp2[i]);
    return tmp1 < tmp2;
}

class Cmp
{
public:
    bool operator()(const Team& lhs, const Team& rhs)
    {
        return (lhs.points_earned > rhs.points_earned
                || (lhs.points_earned == rhs.points_earned && lhs.wins > rhs.wins)
                || (lhs.points_earned == rhs.points_earned && lhs.wins == rhs.wins
                    && lhs.goal_diff > rhs.goal_diff)
                || (lhs.points_earned == rhs.points_earned && lhs.wins == rhs.wins
                    && lhs.goal_diff == rhs.goal_diff && lhs.goals_scored > rhs.goals_scored)
                || (lhs.points_earned == rhs.points_earned && lhs.wins == rhs.wins
                    && lhs.goal_diff == rhs.goal_diff && lhs.goals_scored == rhs.goals_scored
                    && lhs.games_played < rhs.games_played)
                || (lhs.points_earned == rhs.points_earned && lhs.wins == rhs.wins
                    && lhs.goal_diff == rhs.goal_diff && lhs.goals_scored == rhs.goals_scored
                    && lhs.games_played == rhs.games_played && cmp_str_no_case(lhs.name, rhs.name)));
    }
};

void handle_game_result(const string& info
        , map<string, int>& name_index
        , vector<Team>& teams)
{
    size_t pos = info.find('#');
    string t_a_name = info.substr(0, pos);

    size_t index = pos + 1;
    pos = info.find('@', pos + 1);
    int a_score = 0;
    for(; index < pos; ++index)
        a_score = a_score * 10 + info[index] - '0';

    index = pos + 1;
    pos = info.find('#', pos + 1);
    int b_score = 0;
    for(; index < pos; ++index)
        b_score = b_score * 10 + info[index] - '0';

    string t_b_name = info.substr(pos + 1, info.size() - 1 - pos);

    int win_score = a_score > b_score ? a_score : b_score;
    int lose_score = a_score < b_score ? a_score : b_score;
    Team& team_win = teams[name_index[a_score > b_score ? t_a_name : t_b_name]];
    Team& team_lose = teams[name_index[b_score < a_score ? t_b_name : t_a_name]];
    if(win_score != lose_score)
    {
        team_win.win(win_score, lose_score);
        team_lose.lose(lose_score, win_score);
    }
    else
    {
        team_win.tie(win_score);
        team_lose.tie(lose_score);
    }
}

int main()
{
    int n = 0;
    cin >> n;
    getchar();
    while(n--)
    {
        string tournament;
        getline(cin, tournament);

        int t = 0;
        cin >> t;
        getchar();
        vector<Team> teams;
        map<string, int> name_index;
        for(int i = 0; i < t; ++i)
        {
            string t_name;
            getline(cin, t_name);
            teams.push_back(Team(t_name));
            name_index[t_name] = i;
        }

        int game_num = 0;
        cin >> game_num;
        getchar();
        for(int i = 0; i < game_num; ++i)
        {
            string game_result;
            getline(cin, game_result);
            handle_game_result(game_result, name_index, teams);
        }
        sort(teams.begin(), teams.end(), Cmp());

        cout << tournament << endl;
        for(int i = 0; i < teams.size(); ++i)
            teams[i].to_string(i + 1);
        if(n) cout << endl;
    }

    return 0;
}
