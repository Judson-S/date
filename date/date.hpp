#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <vector>

namespace util {
	class Date {
	public:
		Date();
		Date(int day, int month, int year);

		int day() const;
		void day(int value);

		int month() const;
		void month(int value);

		int year() const;
		void year(int value);

		void advance();
		void advance(int value);

		enum class Order {
			MonthDayYear,
			DayMonthYear,
			YearMonthDay
		};
		
		void print(std::ostream& out) const;

		static Date now();
		
		struct Invalid {
			time_t day, month, year;
		};

		std::vector<std::string> monthNames{
			"January",
			"February",
			"March",
			"April",
			"May",
			"June",
			"July",
			"August",
			"September",
			"October",
			"November",
			"December"
		};
		std::vector<std::string> dayNames{
			"Sunday",
			"Monday",
			"Tuesday",
			"Wednesday",
			"Thursday",
			"Friday",
			"Saturday"
		};

		std::string monthName() const;
		std::string dayName() const;

		static Order order;
		static char separator;
	private:
		int _day, _month, _year;
		tm full_date;
		void is_Valid(tm tm_value);
	};
}
