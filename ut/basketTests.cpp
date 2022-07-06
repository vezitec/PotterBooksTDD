#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "basket.hpp"

class BasketTests : public ::testing::Test
{
public:
    std::map<std::string, int> booksCounter{{"1", 0}, {"2", 0}, {"3", 0}, {"4", 0}, {"5", 0}};
    Basket basketTested{booksCounter};
};

TEST_F(BasketTests, Given_NewBasket_When_Initialization_Then_BasketIsEmpty)
{
    for (auto const &m : basketTested.getBooksCounter())
    {
        EXPECT_EQ(m.second, 0);
    }
}

TEST_F(BasketTests, When_AddedOneBook_Expect_BookCounterHasOneBook)
{
    basketTested.addBook("1");
    EXPECT_EQ(basketTested.getBooksCounter().at("1"), 1);
}

// TEST_F(BasketTests, When_Add5BookOneType_Expect_TotalPriceIsEqualForty)
// {
//     for (auto const& m : basketTested.getBooksCounter())
//     {
//         EXPECT_EQ(basketTested.getTotalPrice(), 40);
//     }
// }
