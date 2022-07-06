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
void Basket::addBook(std::string bookName, int count)
{
    m_booksCounter.at(bookName) +=count;
}

float Basket::getTotalPrice()
{
    bool notEmpty = true;

    while (notEmpty)
    {
        int bookSetSize = 0;
        for (auto &&i : m_booksCounter)
        {
            if (i.second > 0)
            {
                bookSetSize++;
                i.second--;
            }
        }

        switch (bookSetSize)
        {
        case 5:
            m_TotalPrice+=40*0.75;
            break;
        case 4:
            m_TotalPrice+=32*0.8;
            break;
        case 3:
            m_TotalPrice+=24*0.9;
            break;
        case 2:
            m_TotalPrice+=16*0.95;
            break;
        case 1:
            m_TotalPrice+=8*1;
            break;
        case 0:
            notEmpty = false;
            break;

        default:
            break;
        }
    }

    return m_TotalPrice;
}