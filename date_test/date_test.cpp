#include <gtest/gtest.h>
#include "date.hpp"

TEST(DefaultCtor, HasCorrectValue)
{
	util::Date date;
	ASSERT_EQ(date.day(), 1);
	ASSERT_EQ(date.month(), 1);
	ASSERT_EQ(date.year(), 1970);
}

TEST(ValueCtor, ThrowsInvalid)
{
	ASSERT_THROW(util::Date d(1970,1970,1970), util::Date::Invalid);
}
