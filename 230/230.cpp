#include <iostream>
#include <set>
#include <string>
#include <functional>
#include <map>

using namespace std;
using BookMap = map<string, string>;

struct Book
{
    Book(const string& author_, const string& title_)
        :author(author_), title(title_)
    {}

    string author;
    string title;
};
using BookSet = set<Book, function<bool (const Book&, const Book&)>>;

enum InputBlock
{
    BOOKS,
    RECORDS
};

void handle_end_line(BookMap& book_map, BookSet& shelf, BookSet& desk, InputBlock& input_block
                    , const string& line)
{
    switch(input_block)
    {
        case BOOKS:
        {
            input_block = RECORDS;
            break;
        }
        case RECORDS:
        {
            book_map.clear();
            shelf.clear();
            desk.clear();
            input_block = BOOKS;
            break;
        }
    }
}

void handle_normal_line(BookMap& book_map, BookSet& shelf, BookSet& desk, InputBlock& input_block
                        , const string& line)
{
    switch(input_block)
    {
        case BOOKS:
        {
            size_t pos = line.find_last_of('"');
            string title = line.substr(1, pos - 1);
            string author = line.substr(pos + 5, line.size() - pos - 6);
            shelf.insert(Book(author, title));
            book_map.insert(make_pair(title, author));
            break;
        }
        case RECORDS:
        {
            string op_name = line.substr(0, 6);
            string op_title = op_name == "SHELVE" ? "" : line.substr(8, line.size() - 9);
            if(op_name == "BORROW")
                shelf.erase(Book(book_map[op_title], op_title));
            else if(op_name == "RETURN")
                desk.insert(Book(book_map[op_title], op_title));
            else
            {
                for(auto& book : desk)
                {
                    auto it = shelf.insert(book).first;
                    cout << "Put \"" << book.title;
                    if(it == shelf.begin())
                        cout << "\" first";
                    else
                        cout << "\" after \"" << (*(--it)).title << "\"";
                    cout << endl;
                }
                cout << "END" << endl;
                desk.clear();
            }
            break;
        }
    }
}

int main()
{
    auto set_cmp = [](const Book& lhs, const Book& rhs){
        return (lhs.author < rhs.author
        || (lhs.author == rhs.author && lhs.title < rhs.title));
    };

    BookMap book_map;
    BookSet shelf(set_cmp);
    BookSet desk(set_cmp);
    InputBlock input_block = BOOKS;

    string line;
    while(getline(cin, line))
    {
        if(line == "END")
            handle_end_line(book_map, shelf, desk, input_block, line);
        else
            handle_normal_line(book_map, shelf, desk, input_block, line);
    }

    return 0;
}
