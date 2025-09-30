#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>

namespace util {
	class Date {
	public:
		Date();
		Date(int day, int month, int year);

		time_t day();
		void day(int value);

		time_t month();
		void month(int value);

		time_t year();
		void year(int value);

		void advance();
		void advance(int value);

		enum class Order {
			MonthDayYear,
			DayMonthYear,
			YearMonthDay
		};
		
		void print(std::ostream& out);

		static Date now();
		enum class monthNameClass {
			January,
			February,
			March,
			April,
			May,
			June,
			July,
			August,
			September,
			October,
			November,
			December
		};
		enum class dayNameClass {
			Sunday,
			Monday,
			Tuesday,
			Wednesday,
			Thursday,
			Friday,
			Saturday
		};
		struct Invalid {
			time_t day, month, year;
		};

		monthNameClass monthName();
		dayNameClass dayName();
		static Order order;
		static char separator;
	private:
		time_t _day, _month, _year;
		tm full_date;
	};
}
