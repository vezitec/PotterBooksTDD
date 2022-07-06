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
    m_booksCounter.at(bookName) += count;
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
            setCounter[4]++;
            m_TotalPrice += 40 * 0.75;
            break;
        case 4:
            setCounter[3]++;
            m_TotalPrice += 32 * 0.8;
            break;
        case 3:
            setCounter[2]++;
            m_TotalPrice += 24 * 0.9;
            break;
        case 2:
            setCounter[1]++;
            m_TotalPrice += 16 * 0.95;
            break;
        case 1:
            setCounter[0]++;
            m_TotalPrice += 8 * 1;
            break;
        case 0:
            notEmpty = false;
            break;

        default:
            break;
        }
    }

    optimizePrice();
    return m_TotalPrice;
}

void Basket::optimizePrice()
{
    while (setCounter[4]>0 && setCounter[2]>0 )
    {
        setCounter[3] += 2;
        setCounter[4]--;
        setCounter[2]--;
    }

    m_TotalPrice =  setCounter[0] * 8 * 1 * 1.00 + 
                    setCounter[1] * 8 * 2 * 0.95 +
                    setCounter[2] * 8 * 3 * 0.90 +
                    setCounter[3] * 8 * 4 * 0.80 +
                    setCounter[4] * 8 * 5 * 0.75;
}