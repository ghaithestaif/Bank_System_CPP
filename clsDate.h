#pragma once
#pragma warning(disable : 4996);
#include "clsString.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


class clsDate
{

private :

	short _year = 1900;
	short _month = 1;
	short _day = 1;

public :

	clsDate() 
	{
		//time_t t = time(0);

		//tm* localTime = localtime(&t);

		//this->_year += localTime->tm_year;
		//this->_month += localTime->tm_mon;
		//this->_day = localTime->tm_mday;

		*this = GetSystemDate();
	}

	clsDate(string date) 
	{
		vector <string> vDate = clsString::split(date, "/");

		this->_day = stoi(vDate[0]);
		this->_month = stoi(vDate[1]);
		this->_year = stoi(vDate[2]);
	}

	clsDate(short day, short month, short year)
	{
		this->_day = day;
		this->_month = month;
		this->_year = year;
	}


	clsDate(short dayOrderInYear, short year) 
	{
		*this = getDateFromDayOrderInYear(dayOrderInYear, year);
	}


	static clsDate GetSystemDate() 
	{

		time_t t = time(0);

		tm* localTime = localtime(&t);
		
		short year, month, day;
		year = localTime->tm_year + 1900;
		month = localTime->tm_mon + 1;
		day = localTime->tm_mday;

		return clsDate(day, month, year);
	}



	void setDay(short day) 
	{
		_day = day;
	}

	short getDay() 
	{
		return _day;
	}

	__declspec(property(get = getDay, put = setDay)) short day;

	void setMonth(short month)
	{
		_month = month;
	}

	short getMonth()
	{
		return _month;
	}

	__declspec(property(get = getMonth, put = setMonth)) short month;

	void setYear(short year)
	{
		_year = year;
	}

	short getYear()
	{
		return _year;
	}

	__declspec(property(get = getYear, put = setYear)) short year;
	
	static bool isLeapYear(short year) 
	{
		return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
	}

	bool isLeapYear() 
	{
		return isLeapYear(_year);
	}

	static short numberOfDaysInYear(short year) 
	{
		return (isLeapYear(year)) ? 366 : 365;
	}

	short numberOfDaysInYear() 
	{
		return numberOfDaysInYear(_year);
	}

	static short numberOfDaysInMonth(short year, short month) 
	{
		if (month < 1 || month > 12)
			return 0;

		bool is30Days = (month == 4 || month == 6 || month == 9 || month == 11);

		return (month == 2) ? (isLeapYear(year)) ? 29 : 28 : (is30Days) ? 30 : 31;
	}

	short numberOfDaysInMonth() 
	{
		return numberOfDaysInMonth(_year, _month);
	}

	static bool isValidDate(clsDate date) 
	{
		short monthDays = date.numberOfDaysInMonth();

		return ((date._month >= 1 && date._month <= 12) && (date._day <= monthDays && date._day >= 1));
	}

	bool isValid() 
	{
		return isValidDate(*this);
	}

	static short numberOfHoursInYear(clsDate date) 
	{
		return date.numberOfDaysInYear() * 24;
	}

	short numberOfHoursInYear() 
	{
		return numberOfHoursInYear(*this);
	}

	static int numberOfMinutesInYear(clsDate date) 
	{
		return date.numberOfHoursInYear() * 60;
	}

	int numberOfMinutesInYear() 
	{
		return numberOfMinutesInYear(*this);
	}

	static int numberOfSecondsInYear(clsDate date) 
	{
		return date.numberOfMinutesInYear() * 60;
	}

	int numberOfSecondsInYear() 
	{
		return numberOfSecondsInYear(*this);
	}

	static short numberOfHoursInMonth(clsDate date) 
	{
		return date.numberOfDaysInMonth() * 24;
	}

	short numberOfHoursInMonth() 
	{
		return numberOfHoursInMonth(*this);
	}

	static unsigned short numberOfMinutesInMonth(clsDate date) 
	{
		return date.numberOfHoursInMonth() * 60;
	}

	unsigned short numberOfMinutesInMonth()
	{
		return numberOfMinutesInMonth(*this);
	}


	static int  numberOfSecondsInMonth(clsDate date)
	{
		return date.numberOfMinutesInMonth() * 60;
	}

	int  numberOfSecondsInMonth()
	{
		return numberOfSecondsInMonth(*this);
	}


	static short dayFromBeginningOfTheYear(clsDate date) 
	{
		short dayCounter = 0;

		for (short i = 1; i < date.month; i++) 
		{
			dayCounter += numberOfDaysInMonth(date._year, i);
		}

		return dayCounter + date.day;
	}

	short dayFromBeginningOfTheYear() 
	{
		return dayFromBeginningOfTheYear(*this);
	}


	static clsDate getDateFromDayOrderInYear(short dayOrderInYear, short year) 
	{
		short remainingDays = dayOrderInYear;
		clsDate date;

		date.year = year;
		date.month = 1;

		short monthDays = 0;

		while (true) 
		{
			monthDays = date.numberOfDaysInMonth();
			if (remainingDays > monthDays) 
			{
				date.month++;
				remainingDays -= monthDays;
			}

			else 
			{
				date.day = remainingDays;
				break;
			}
		}

		return date;
	}

	static short dayOfWeekOrder(short day, short month, short year) 
	{
		short a, y, m, d;

		a = (14 - month) / 12;

		y = year - a;

		m = month + (12 * a) - 2;

		d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

		return d;
	}


	static short dayOfWeekOrder(clsDate date) 
	{
		return date.dayOfWeekOrder(date.day, date.month, date.year);
	}

	short dayOfWeekOrder() 
	{
		return dayOfWeekOrder(*this);
	}

	static string getShortDayName(short day, short month, short year) 
	{
		string dayName[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

		return dayName[dayOfWeekOrder(day, month, year)];
	}

	static string getShortDayName(clsDate date)
	{
		return getShortDayName(date.day, date.month, date.year);
		//string dayName[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

		//return dayName[date.dayOfWeekOrder()];
	}

	static string getShortDayName(short dayWeekOrder)
	{
		string dayName[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

		return dayName[dayWeekOrder];
	}

	string getShortDayName()
	{
		return getShortDayName(*this);
	}

	static string getShortMonthName(short month) 
	{
		string monthName[] = { "Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sep", "Oct", "Nov", "Dec"};

		return monthName[month - 1];
	}

	string getShortMonthName() 
	{
		return getShortMonthName(_month);
	}

	static void printMonthCalendar(short month, short year)
	{
		printf("\n __________________%s________________\n\n" , getShortMonthName(month).c_str());

		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		short i;

		short currentDay = dayOfWeekOrder(1, month, year);

		short monthDays = numberOfDaysInMonth(year, month);

	
		for (i = 0; i < currentDay; i++) 
		{
			printf("     ");
		}


		for (int j = 1; j <= monthDays; j++) 
		{
			printf("%5d", j);


			if (++i == 7) 
			{
				printf("\n");
				i = 0;
			}
		}

		printf("\n _____________________________________\n");
	}


	void printMonthCalendar() 
	{
		printMonthCalendar(_month, _year);
	}


	static void printYearCalendar(short year) 
	{
		printf("\n_______________________________________________\n");
		printf("                   Calendar - %d", year);
		printf("\n_______________________________________________\n");

		for (short i = 1; i <= 12; i++) 
		{
			printMonthCalendar(i, year);
		}
	}

	void printYearCalendar()
	{
		printYearCalendar(_year);
	}


	static bool isDateBeforeDate2(clsDate date1, clsDate date2) 
	{
		return (date1.year < date2.year) ? true : ((date1.year == date2.year) ? (date1.month < date2.month) ? true : ((date1.month == date2.month) ? date1.day < date2.day : false ): false);
	}

	bool isDateBeforeDate2(clsDate date) 
	{
		return isDateBeforeDate2(*this, date);
	}

	static bool isDateEqualDate2(clsDate date1, clsDate date2) 
	{
		return ((date1.year == date2.year) ? ((date1.month == date2.month) ? date1.day == date2.day : false ): false);
	}

	bool isDateEqualDate2(clsDate date) 
	{
		return isDateEqualDate2(*this, date);
	}

	static bool isDateAfterDate2(clsDate date1, clsDate date2) 
	{
		return (!isDateBeforeDate2(date1, date2) && !isDateEqualDate2(date1, date2));
	}

	bool isDateAfterDate2(clsDate date)
	{
		return isDateAfterDate2(*this, date);
	}

	static string dateToString(clsDate date) 
	{
		return to_string(date._day) + "/" + to_string(date._month) + "/" + to_string(date._year);
	}

	static string getSystemDateTimeString() 
	{
		time_t local = time(0);

		tm* localTime = localtime(&local);

		short year, month, day, hour, minute, second;

		year = localTime->tm_year + 1900;
		month = localTime->tm_mon + 1;
		day = localTime->tm_mday;
		hour = localTime->tm_hour;
		minute = localTime->tm_min;
		second = localTime->tm_sec;

		return to_string(day) + "/" + to_string(month) + "/" + to_string(year) + " - " +
			to_string(hour) + ":" + to_string(minute) + ":" + to_string(second);
	} 

	static clsDate addDays(clsDate date, short days) 
	{
		short remainingDays = days + date.dayFromBeginningOfTheYear();

		short monthDays = 0;

		date.month = 1;

		while (true) 
		{
			monthDays = date.numberOfDaysInMonth();

			if (remainingDays > monthDays) 
			{
				remainingDays -= monthDays;
				date.month++;

				if (date.month > 12)
				{
					date.year++;
					date.month = 1;
				}
			}

			else
			{
				date.day = remainingDays;
				break;
			}

		}

		return date;
	}

	void addDays(short days)
	{
		*this = addDays(*this, days);
	}

	static bool isLastDayInMonth(clsDate date) 
	{
		return (date.numberOfDaysInMonth() == date.day);
	}

	bool isLastDayInMonth() 
	{
		return isLastDayInMonth(*this);
	}

	static bool isLastMonthInYear(short month) 
	{
		return (month == 12);
	}

    bool isLastMonthInYear()
	{
		return isLastMonthInYear(_month);
	}
	
	static clsDate addOneDay(clsDate date) 
	{
		if (date.isLastDayInMonth()) 
		{
			if (date.isLastMonthInYear()) 
			{
				date.year++;
				date.month = 1;
				date.day = 1;
			}
			else 
			{
				date.month++;
				date.day = 1;
			}
		}

		else 
		{
			date.day++;
		}

		return date;
	}

	void addOneDay() 
	{
		*this = addOneDay(*this);
	}

	
	static clsDate increaseDateByOneWeek(clsDate & date) 
	{
		for (short i = 1; i <= 7; i++) 
		{
			date.addOneDay();
		}

		return date;
	}

	void increaseDateByOneWeek() 
	{
		increaseDateByOneWeek(*this);
	}


	static clsDate increaseDateByWeeks(clsDate& date, short weeks)
	{
		for (short i = 1; i <= weeks; i++)
		{
			date.increaseDateByOneWeek();
		}

		return date;
	}

	void increaseDateByWeeks(short weeks)
	{
		increaseDateByWeeks(*this, weeks);
	}


	static clsDate increaseDateByOneMonth(clsDate& date)
	{
		if (date.isLastMonthInYear())
		{
			date.year++;
			date.month = 1;
		}

		else 
		{
			date.month++;
		}

		short monthDays = date.numberOfDaysInMonth();

		if (date.day > monthDays) 
		{
			date.day = monthDays;
		}


		return date;
	}


	void increaseDateByOneMonth() 
	{
		increaseDateByOneMonth(*this);
	}

	static clsDate increaseDateByMonths(clsDate &date, short months) 
	{
		for (short i = 1; i <= months; i++) 
		{
			date.increaseDateByOneMonth();
		}

		return date;
	}

	void increaseDateByMonths(short months) 
	{
		increaseDateByMonths(*this, months);
	}


	static clsDate increaseDateByOneYear(clsDate& date) 
	{
		date.year++;

		return date;
	}

	void increaseDateByOneYear() 
	{
		increaseDateByOneYear(*this);
	}

	static clsDate increaseDateByYears(clsDate& date, short years)
	{
		for (short i = 1; i <= years; i++)
		{
			date.increaseDateByOneYear();
		}

		return date;
	}

	void increaseDateByYears(short years)
	{
		increaseDateByYears(*this, years);
	}
	
	static clsDate increaseDateByOneDecade(clsDate &date) 
	{
		date.year += 10;

		return date;
	}

	void increaseDateByOneDecade() 
	{
		increaseDateByOneDecade(*this);
	}

	static clsDate increaseDateByDecades(clsDate &date, short decades) 
	{
		for (short i = 1; i <= decades; i++) 
		{
			date.increaseDateByOneDecade();
		}

		return date;
	}

	void increaseDateByDecades(short decades) 
	{
		increaseDateByDecades(*this, decades);
	}

	static clsDate increaseDateByOneCentury(clsDate& date) 
	{
		date.year += 100;

		return date;
	}

	void increaseDateByOneCentury() 
	{
		increaseDateByOneCentury(*this);
	}


	static clsDate increaseDateByOneMillennium(clsDate& date)
	{
		date.year += 1000;

		return date;
	}

	void increaseDateByOneMillennium()
	{
		increaseDateByOneMillennium(*this);
	}

	static clsDate decreaseDateByOneDay(clsDate date) 
	{
		if (date.day == 1)
		{
			if (date.month == 1)
			{
				date.year--;
				date.month = 12;
				date.day = 31;
			}

			else
			{
				date.month--;
				date.day = date.numberOfDaysInMonth();
			}
		}

		else 
		{
			date.day--;
		}

		return date;
	}

	void decreaseDateByOneDay() 
	{
		*this = decreaseDateByOneDay(*this);
	}

	static clsDate decreaseDateByDays(clsDate date, short days) 
	{
		for (short i = 1; i <= days; i++)
		{
			date.decreaseDateByOneDay();
		}

		return date;
	}

	void decreaseDateByDays(short days) 
	{
		*this = decreaseDateByDays(*this, days);
	}

	static clsDate decreaseDateByOneWeek(clsDate date)
	{
		for (short i = 1; i <= 7; i++)
		{
			date.decreaseDateByOneDay();
		}

		return date;
	}

	void decreaseDateByOneWeek()
	{
		*this = decreaseDateByOneWeek(*this);
	}


	static clsDate decreaseDateByWeeks(clsDate date, short weeks)
	{
		for (short i = 1; i <= weeks; i++)
		{
			date.decreaseDateByOneWeek();
		}

		return date;
	}


	void decreaseDateByWeeks(short weeks)
	{
		*this = decreaseDateByWeeks(*this, weeks);
	}


	static clsDate decreaseDateByOneMonth(clsDate date) 
	{
		if (date.month == 1) 
		{
			date.year--;
			date.month = 12;
		}

		else 
		{
			date.month--;

			short monthDays = date.numberOfDaysInMonth();

			if (date.day > monthDays)
			{
				date.day = monthDays;
			}

		}

		return date;
	}

	void decreaseDateByOneMonth() 
	{
		*this = decreaseDateByOneMonth(*this);
	}


	static clsDate decreaseDateByMonths(clsDate date, short months) 
	{
		for (short i = 1; i <= months; i++) 
		{
			date.decreaseDateByOneMonth();
		}

		return date;
	}


	void decreaseDateByMonths(short months) 
	{
		*this = decreaseDateByMonths(*this, months);
	}


	static clsDate decreaseDateByOneYear(clsDate date) 
	{
		date.year--;

		return date;
	}

	void decreaseDateByOneYear() 
	{
		*this = decreaseDateByOneYear(*this);
	}

	static clsDate decreaseDateByYears(clsDate date, short years) 
	{
		date.year -= years;

		return date;
	}

	void decreaseDateByYears(short years) 
	{
		*this = decreaseDateByYears(*this, years);
	}

	static clsDate decreaseDateByOneDecade(clsDate date) 
	{
		date.year -= 10;

		return date;
	}

	void decreaseDateByOneDecade() 
	{
		*this = decreaseDateByOneDecade(*this);
	}


	static clsDate decreaseDateByDecades(clsDate date, short decades) 
	{
		date.year -= (decades * 10);

		return date;
	}


	void decreaseDateByDecades(short decades) 
	{
		*this = decreaseDateByDecades(*this, decades);
	}

	static clsDate decreaseDateByCentury(clsDate date)
	{
		date.year -= 100;

		return date;
	}

	void decreaseDateByCentury() 
	{
		*this = decreaseDateByCentury(*this);
	}

	static clsDate decreaseDateByMillennium(clsDate date) 
	{
		date.year -= 1000;

		return date;
	}


	void decreaseDateByMillennium() 
	{
		*this = decreaseDateByMillennium(*this);
	}

	static void swapDates(clsDate &date1, clsDate& date2)
	{
		clsDate tempDate;

		tempDate = date1;
		date1 = date2;
		date2 = tempDate;
	}
	
	static int getDifferenceInDays(clsDate date1, clsDate date2, bool includeEndDay = false) 
	{
		short swapFlag = 1;
		int daysCounter = 0;

		if (isDateAfterDate2(date1, date2)) 
		{
			swapDates(date1, date2);

			swapFlag = -1;
		}

		while (isDateBeforeDate2(date1, date2))
		{
			daysCounter++;
			date1.addOneDay();
		}

		return (includeEndDay) ? ++daysCounter * swapFlag : daysCounter * swapFlag;
	}


	int getDifferenceInDays(clsDate date, bool includeEndDay = false)
	{
		return getDifferenceInDays(*this, date, includeEndDay);
	}

	static int calculateMyAge(clsDate dateOfBirth) 
	{
		return dateOfBirth.getDifferenceInDays(clsDate(), true);
	}

	static short dayUntilTheEndOfTheYear(clsDate date) 
	{
		clsDate endOfYearDate;

		endOfYearDate.day = 31;
		endOfYearDate.month = 12;
		endOfYearDate.year = date.year;

		return date.getDifferenceInDays(endOfYearDate, true);
	}

	short dayUntilTheEndOfTheYear() 
	{
		return dayUntilTheEndOfTheYear(*this);
	}

	static short dayUntilTheEndOfMonth(clsDate date)
	{
		clsDate endOfYearDate;

		endOfYearDate.day = date.numberOfDaysInMonth();
		endOfYearDate.month = date.month;
		endOfYearDate.year = date.year;

		return date.getDifferenceInDays(endOfYearDate, true);
	}

	short dayUntilTheEndOfMonth()
	{
		return dayUntilTheEndOfMonth(*this);
	}


	static short dayUntilTheEndOfWeek(clsDate date) 
	{
		return 6 - date.dayOfWeekOrder();
	}

	short dayUntilTheEndOfWeek() 
	{
		return dayUntilTheEndOfWeek(*this);
	}

	static bool isWeekend(clsDate date) 
	{
		return (date.dayOfWeekOrder() == 5 || date.dayOfWeekOrder() == 6);
	}
	
	bool isWeekend() 
	{
		return isWeekend(*this);
	}

	static bool isEndOfWeek(clsDate date) 
	{
		return date.dayOfWeekOrder() == 6;
	}

	bool isEndOfWeek() 
	{
		return isEndOfWeek(*this);
	}

	static bool isBusinessDay(clsDate date) 
	{
		return !isWeekend(date);
	}

	bool isBusinessDay() 
	{
		return isBusinessDay(*this);
	}

	static short calculateBusinessDays(clsDate dateFrom, clsDate dateTo) 
	{
		short countDays = 0;

		while (dateFrom.isDateBeforeDate2(dateTo))
		{
			if (dateFrom.isBusinessDay()) 
			{
				countDays++;
			}

			dateFrom.addOneDay();
		}

		return countDays;
	}


	short calculateBusinessDays(clsDate dateTo) 
	{
		return calculateBusinessDays(*this, dateTo);
	}

	static short calculateVacationDays(clsDate dateFrom, clsDate dateTo)
	{
		short countDays = 0;

		while (dateFrom.isDateBeforeDate2(dateTo))
		{
			if (dateFrom.isWeekend())
			{
				countDays++;
			}

			dateFrom.addOneDay();
		}

		return countDays;
	}


	short calculateVacationDays(clsDate dateTo)
	{
		return calculateVacationDays(*this, dateTo);
	}

	enum enDateCompare { Before = -1, Equal, After};

	static enDateCompare compareDates(clsDate date1, clsDate date2) 
	{
		if (date1.isDateBeforeDate2(date2))
			return enDateCompare::Before;

		if (date1.isDateEqualDate2(date2))
			return enDateCompare::Equal;

		else
			return enDateCompare::After;
	}

	enDateCompare compareDates(clsDate date) 
	{
		return compareDates(*this, date);
	}

	string dateToString() 
	{
		return dateToString(*this);
	}

	void print() 
	{
		cout << dateToString() << endl;
	}

};

