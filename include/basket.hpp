#include <map>
#include <string>

class Basket
{
public:
    // constructors
    Basket(std::map<std::string, int>);
    Basket();

    // methods
    std::map<std::string, int> getBooksCounter();
    void addBook(std::string);

private:
    std::map<std::string, int> m_booksCounter;
};