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

TEST_F(BasketTests, When_AddFiveBookOneType_Expect_TotalPriceIsEqualForty)
{
    basketTested.addBook("1");
    basketTested.addBook("1");
    basketTested.addBook("1");
    basketTested.addBook("1");
    basketTested.addBook("1");

    EXPECT_EQ(basketTested.getTotalPrice(), 40);
}

TEST_F(BasketTests, When_AddedFiveBookDiffType_TotalPrice_Should_BeEqualThirty)
{
    basketTested.addBook("1");
    basketTested.addBook("2");
    basketTested.addBook("3");
    basketTested.addBook("4");
    basketTested.addBook("5");

    EXPECT_EQ(basketTested.getTotalPrice(), 30);
}

TEST_F(BasketTests, When_AddedTwoSetsOfFiveBooksDiffType_TotalPrice_Should_BeEqualSixty)
{
    basketTested.addBook("1", 2);
    basketTested.addBook("2", 2);
    basketTested.addBook("3", 2);
    basketTested.addBook("4", 2);
    basketTested.addBook("5", 2);

    EXPECT_EQ(basketTested.getTotalPrice(), 60);
}

TEST_F(BasketTests, When_AddedSetsOfBooks_Expect_TotalPrice_IsEqual_CorrectValue)
{
    basketTested.addBook("1", 2);
    basketTested.addBook("2", 2);
    basketTested.addBook("3", 2);
    basketTested.addBook("4", 1);
    basketTested.addBook("5", 1);

    EXPECT_FLOAT_EQ(basketTested.getTotalPrice(), 51.2);
}