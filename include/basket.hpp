#include <map>
#include <string>

class Basket
{
public:
    // constructors
    Basket(std::map<std::string, int>);
    Basket();

    // methods
    // getters
    std::map<std::string, int> getBooksCounter();
    float getTotalPrice();

    // setters
    void addBook(std::string);
    void addBook(std::string, int);

private:
    std::map<std::string, int> m_booksCounter;
    float m_TotalPrice{};
    std::array<int, 5> setCounter = {0, 0, 0, 0, 0};

    // methods
    void optimizePrice();
};