#include "date.hpp"

util::Date::Date()
{
	tm new_date{};
	new_date.tm_mday = 1;
	new_date.tm_mon = 0;
	new_date.tm_year = 1970;

	full_date = new_date;
}



util::Date::Date(int day, int month, int year)
{
	tm new_date{};
	new_date.tm_mday = day;
	new_date.tm_mon = month;
	new_date.tm_mon = year;
	new_date.tm_isdst = -1;
	util::Date::is_Valid(new_date);
	full_date = new_date;
}

int  util::Date::day() const
{
	return full_date.tm_mday;
}
void util::Date::day(int value)
{
	time_t curr_time = 0;
	tm tm_day = *localtime(&curr_time);
	tm_day.tm_mday = value;
	tm_day.tm_isdst = -1;
	time_t new_day = mktime(&tm_day);

	util::Date::is_Valid(*localtime(&new_day));

	_day = new_day;
}

int util::Date::month() const
{
	return full_date.tm_mon;
}
void util::Date::month(int value)
{
	time_t curr_time = 0;
	tm tm_month = *localtime(&curr_time);
	tm_month.tm_mon = value;
	tm_month.tm_isdst = -1;
	time_t new_month = mktime(&tm_month);

	util::Date::is_Valid(*localtime(&new_month));

	_day = new_month;
}

int util::Date::year() const
{
	return full_date.tm_year;
}
void util::Date::year(int value)
{
	time_t curr_time = 0;
	tm tm_year = *localtime(&curr_time);
	tm_year.tm_year = value;
	tm_year.tm_isdst = -1;
	time_t new_year = mktime(&tm_year);

	util::Date::is_Valid(*localtime(&new_year));

	_day = new_year;
}

//void util::Date::advance()
//{
//	full_date.tm_mday += 24 * 60 * 60;
//}
void util::Date::advance(int value = 1)
{
	full_date.tm_mday += value;
}

void util::Date::print(std::ostream& out) const
{
	switch (order)
	{
	case Order::MonthDayYear:
	{
		out << full_date.tm_mon << separator << full_date.tm_mday << separator << full_date.tm_year;
		break;
	}
	case Order::DayMonthYear:
	{
		out << full_date.tm_mday << separator << full_date.tm_mon << separator << full_date.tm_year;
		break;
	}
	case Order::YearMonthDay:
	{
		out << full_date.tm_year << separator << full_date.tm_mon << separator << full_date.tm_mday;
		break;
	}
	}
}

util::Date util::Date::now()
{
	time_t now_t = time(nullptr);
	tm tm_now = *localtime(&now_t);
	Date today{ tm_now.tm_mday, tm_now.tm_mon, tm_now.tm_year };
	return today;
}

std::string util::Date::monthName() const
{
	return monthNames[full_date.tm_mon];
}
std::string util::Date::dayName() const
{
	return dayNames[full_date.tm_wday];
}
util::Date::Order util::Date::order = Order::DayMonthYear;
char util::Date::separator = '/';