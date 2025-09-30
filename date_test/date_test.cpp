#include <gtest/gtest.h>
#include "date.hpp"

TEST(DefaultCtor, HasCorrectValue)
{
	util::Date date;
	time_t year = date.year();
	ASSERT_EQ(date.year(), 70);
	ASSERT_EQ(year, 70);
}
