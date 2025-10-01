#include <gtest/gtest.h>
#include "date.hpp"

TEST(DefaultCtor, HasCorrectValue)
{
	util::Date date;
	ASSERT_EQ(date.day(), 1);
	ASSERT_EQ(date.month(), 1);
	ASSERT_EQ(date.year(), 1970);
}


TEST(ValueCtor, HasCorrectValue)
{
	util::Date d(4, 19, 2006);

	ASSERT_EQ(d.day(), 4);
	ASSERT_EQ(d.month(), 19);
	ASSERT_EQ(d.year(), 2006);

}
TEST(ValueCtor, ThrowsInvalid)
{
	util::Date d(19, 4, 2006);

	ASSERT_THROW(util::Date d(1970, 1970, 1970), util::Date::Invalid);
}

TEST(SetterTest, SetterWorks)
{
	util::Date d;
	d.day(1);
	d.month(2);
	d.year(1980);

	ASSERT_EQ(d.day(), 1);
	ASSERT_EQ(d.month(), 2);
	ASSERT_EQ(d.year(), 1980);
}
TEST(SetterTest, SetterThrowsInvalid)
{
	util::Date d;

	ASSERT_THROW(d.day(123), util::Date::Invalid);
	ASSERT_THROW(d.month(123), util::Date::Invalid);
	ASSERT_THROW(d.year(-6), util::Date::Invalid);
}

TEST(PropertyTest, HasCorrectValue)
{
	util::Date d(19, 4, 2006);

	ASSERT_EQ(d.monthName(), "April");
	ASSERT_EQ(d.dayName(), "Wednesday");
}