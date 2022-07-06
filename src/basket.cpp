#include "basket.hpp"
// constructors
Basket::Basket(std::map<std::string, int> booksCounter)
    : m_booksCounter{booksCounter} {};
Basket::Basket(){};

// methods
std::map<std::string, int> Basket::getBooksCounter()
{
    return m_booksCounter;
}

void Basket::addBook(std::string bookName)
{
    m_booksCounter.at(bookName)++;
}