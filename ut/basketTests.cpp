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
    for (auto const& m : basketTested.getBooksCounter())
    {
        EXPECT_EQ(m.second, 0);
    }
}
