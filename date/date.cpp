#include "date.hpp"

util::Date::Date()
{
	time_t default_t = 0;
	full_date = *localtime(&default_t);
	_day = full_date.tm_mday;
	_month = full_date.tm_mon + 1;
	_year = full_date.tm_year + 1900;
}
util::Date::Date(int day, int month, int year)
{
	if (day > 31 || day < 1)
	{
		throw util::Date::Invalid{ day, month + 1, year + 1900};
	}
	else if (month > 12 || month < 1)
	{
		throw util::Date::Invalid{ day, month + 1, year + 1900};
	}
	else if (year < 1970)
	{
		throw util::Date::Invalid{ day, month + 1, year + 1900};
	}
	full_date = {
		0,
		0,
		0,
		day,
		month,
		year,
		0,
		0,
		-1
	};
}

void is_Valid(tm tm_value, char v, int value)
{
	switch (tolower(v))
	{
		case 'd':
		{
			if (tm_value.tm_mday != value)
			{
				throw util::Date::Invalid{ value, tm_value.tm_mon + 1, tm_value.tm_year + 1900 };
			}
			break;
		}
		case 'm':
		{
			if (tm_value.tm_mon != value)
			{
				throw util::Date::Invalid{ tm_value.tm_mday + 1, value, tm_value.tm_year + 1900 };
			}
		}
		case 'y':
		{
			if (tm_value.tm_year != value)
			{
				throw util::Date::Invalid{ tm_value.tm_mday + 1, tm_value.tm_mon + 1, value };
			}
		}
	}
}


time_t  util::Date::day()
{
	return _day;
}
void util::Date::day(int value)
{
	time_t curr_time = 0;
	tm tm_day = *localtime(&curr_time);
	tm_day.tm_mday = value;
	tm_day.tm_isdst = -1;
	time_t new_day = mktime(&tm_day);

	is_Valid(*localtime(&new_day), 'd', value);

	_day = new_day;
}

time_t util::Date::month()
{
	return _month;
}
void util::Date::month(int value)
{
	time_t curr_time = 0;
	tm tm_month = *localtime(&curr_time);
	tm_month.tm_mon = value;
	tm_month.tm_isdst = -1;
	time_t new_month = mktime(&tm_month);

	is_Valid(*localtime(&new_month), 'm', value);

	_day = new_month;
}

time_t util::Date::year()
{
	return _year;
}
void util::Date::year(int value)
{
	time_t curr_time = 0;
	tm tm_year = *localtime(&curr_time);
	tm_year.tm_year = value;
	tm_year.tm_isdst = -1;
	time_t new_year = mktime(&tm_year);

	is_Valid(*localtime(&new_year), 'y', value);

	_day = new_year;
}

void util::Date::advance()
{
	_day += 24 * 60 * 60;
}
void util::Date::advance(int value)
{
	_day += value * 24 * 60 * 60;
}

void util::Date::print(std::ostream& out)
{
	switch (_order)
	{
	case Order::MonthDayYear:
	{
		out << full_date.tm_mon << full_date.tm_mday << full_date.tm_year << "\n";
		break;
	}
	case Order::DayMonthYear:
	{
		out << full_date.tm_mday << full_date.tm_mon << full_date.tm_year << "\n";
		break;
	}
	case Order::YearMonthDay:
	{
		out << full_date.tm_year << full_date.tm_mon << full_date.tm_mday << "\n";
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

util::Date::monthNameClass util::Date::monthName()
{
	return static_cast<monthNameClass>(full_date.tm_mon);
}
util::Date::dayNameClass util::Date::dayName()
{
	return static_cast<dayNameClass>(full_date.tm_wday);
}