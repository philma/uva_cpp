/*
 * Created on: 2015-04-18
 *     Author: philma
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct CommandParam
{
    string from;
    string to;
};

void parse_command(const string& command, CommandParam& command_param)
{
    int begin = command.find_first_of(' ') + 1;
    int end = command.find_first_of(' ', begin);
    command_param.from = command.substr(begin, end - begin);

    begin = end + 1;
    command_param.to = command.substr(begin);
}

void parse_param(const string& param, string& prefix, string& suffix)
{
    int star_pos = param.find_first_of('*');

    prefix = "";
    if(*(param.begin()) != '*')
        prefix = param.substr(0, star_pos);
    suffix = "";
    if(*(param.rbegin()) != '*')
        suffix = param.substr(star_pos + 1);
}

bool rename_file(const CommandParam& command_param, const string& file, string& new_name)
{
    string from_prefix;
    string from_suffix;
    parse_param(command_param.from, from_prefix, from_suffix);

    string to_prefix;
    string to_suffix;
    parse_param(command_param.to, to_prefix, to_suffix);

    if(from_prefix.size() + from_suffix.size() > file.size())
        return false;

    int begin = 0, end = 0;
    if(from_prefix == "")
        begin = 0;
    else
    {
        int prefix_pos = file.find(from_prefix);
        if(prefix_pos != 0)
            return false;
        begin = prefix_pos + from_prefix.size();
    }

    if(from_suffix == "")
        end = file.size() - 1;
    else
    {
        int suffix_pos = file.rfind(from_suffix);
        if(suffix_pos + from_suffix.size() != file.size())
            return false;
        end = suffix_pos - 1;
    }

    string star_str = (begin <= end) ? file.substr(begin, end - begin + 1) : "";
    new_name = to_prefix + star_str + to_suffix;

    return true;
}

void convert_command(const vector<string>& files, const vector<CommandParam>& command)
{
    for(int i = 0; i < command.size(); ++i)
    {
        const CommandParam& command_param = command[i];
        cout << "rename " << command_param.from << " " << command_param.to << endl;
        for(int j = 0; j < files.size(); ++j)
        {
            const string& file = files[j];
            string new_name;
            if(rename_file(command_param, file, new_name))
                cout << "mv " << file << " " << new_name << endl;
        }
    }
}

int main()
{
    string line;
    int end_count = 0;
    vector<string> files;
    vector<CommandParam> command;

    while(getline(cin, line))
    {
        if(line == "end")
        {
            ++end_count;
            if(end_count == 2)
            {
                convert_command(files, command);
                cout << endl;
                files.clear();
                command.clear();
                end_count = 0;
            }
            continue;
        }

        if(end_count == 0)
            files.push_back(line);
        else
        {
            CommandParam command_param;
            parse_command(line, command_param);
            command.push_back(command_param);
        }
    }

    return 0;
}
