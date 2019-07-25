#include<iostream>
#include<math.h>
#include<string>
#include "Worker.h"
using std::cout;
using std::cin;


void enterTheText(char *&mas)
{
	char str[256];
	cin >> str;
	int size = strlen(str) + 1;
	if (mas != nullptr)
	{
		delete mas;
	}
	mas = new char[size];
	for (int i = 0; i < size; i++)
	{
		mas[i] = str[i];
	}
}


Time::Time()
{
	hour = 0;
	minute = 0;
}

Time::Time(int hour, int minute)
{
	this->hour = hour;
	this->minute = minute;
}

int Time::getHour()
{
	return hour;
}

int Time::getMinute()
{
	return minute;
}

void Time::setHour(int hour)
{
	this->hour = hour;
}

void Time::setMinute(int minute)
{
	this->minute = minute;
}

Time Time::operator+(const Time &obj)
{
	Time tmp;
	tmp.minute = minute + obj.minute;
	tmp.hour = hour + obj.hour+tmp.minute/60;
	tmp.minute %= 60;
	return tmp;
}

Time Time:: operator-(const Time &obj)
{
	Time tmp;
	int adjustment = 1;
	if (*this > obj)
	{
		adjustment = -1;
	}
	if (adjustment*minute>adjustment*obj.minute)
	{
		tmp.hour = obj.hour*adjustment - hour*adjustment - 1;
		tmp.minute = 60-(minute * adjustment - obj.minute*adjustment);
	}
	else
	{
		tmp.hour = obj.hour*adjustment - hour*adjustment;
		tmp.minute = obj.minute * adjustment - minute*adjustment;
	}
	return tmp;
}

bool Time:: operator>(const Time &obj)
{
	if ((hour * 60 + minute) > (obj.hour * 60 + obj.minute))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Time:: operator<(const Time &obj)
{
	if ((hour * 60 + minute) < (obj.hour * 60 + obj.minute))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Time::operator==(const Time &obj)
{
	if (hour == obj.hour && minute == obj.minute)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Time::operator>=(const Time &obj)
{
	if ((hour * 60 + minute) >= (obj.hour * 60 + obj.minute))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Time::operator<=(const Time &obj)
{
	if ((hour * 60 + minute) <= (obj.hour * 60 + obj.minute))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Time::Print()
{
	if (hour < 10)
	{
		cout << "0" << hour;
	}
	else
	{
		cout << hour;
	}
	cout << ":";
	if (minute < 10)
	{
		cout << "0" << minute;
	}
	else
	{
		cout << minute;
	}
}

float Time::convertInHour()
{
	float tmp;
	tmp = hour + minute / 60.0;
	return tmp;
}

Time::~Time(){}


WorkDay::WorkDay()
{
	double_work_day=0;
	work_day_before_holiday=0;
	work_day_holiday=0; 
	work_hours=0;
	work_evening_hours=0;
	work_nite_hours=0;
	work_holiday_hours=0;
}

Time WorkDay::getBeginWorkDay()
{
	return begin_work_day;
}

Time WorkDay::getBeginBreak()
{
	return begin_break;
}

Time WorkDay::getEndBreak()
{
	return end_break;
}
Time WorkDay::getEndWorkDay()
{
	return end_work_day;
}

Time WorkDay::getEveningTime()
{
	return evening_time;
}

Time WorkDay::getNiteTime()
{
	return nite_time;
}

Time WorkDay::getEndNiteTime()
{
	return end_nite_time;
}

void WorkDay::setBeginWorkDay(int hour, int minute)
{
	bool control = 1;
	do
	{
		if ((hour > -1 && hour<25) && (minute>-1 && minute < 61))
		{
			begin_work_day.setHour(hour);
			begin_work_day.setMinute(minute);
			control = 0;
		}
		else if (hour < 0 || hour>24)
		{
			cout << "You entered uncorrect value!!! Try again.\n";
			cout << "-hour: ";
			cin >> hour;
		}
		else if (minute<0 || minute > 60)
		{
			cout << "You entered uncorrect value!!! Try again.\n";
			cout << "-minute: ";
			cin >> minute;
		}
	} while (control == 1);
}

void WorkDay::setBeginBreak(int hour, int minute)
{
	bool control = 1;
	do
	{
		if ((hour > -1 && hour<25) && (minute>-1 && minute < 61))
		{
			begin_break.setHour(hour);
			begin_break.setMinute(minute);
			control = 0;
		}
		else if (hour < 0 || hour>24)
		{
			cout << "You entered uncorrect value!!! Try again.\n";
			cout << "-hour: ";
			cin >> hour;
		}
		else if (minute<0 || minute > 60)
		{
			cout << "You entered uncorrect value!!! Try again.\n";
			cout << "-minute: ";
			cin >> minute;
		}
	} while (control == 1);
}

void WorkDay::setEndWorkDay(int hour, int minute)
{
	bool control = 1;
	do
	{
		if ((hour > -1 && hour<25) && (minute>-1 && minute < 61))
		{
			end_work_day.setHour(hour);
			end_work_day.setMinute(minute);
			control = 0;
		}
		else if (hour < 0 || hour>24)
		{
			cout << "You entered uncorrect value!!! Try again.\n";
			cout << "-hour: ";
			cin >> hour;
		}
		else if (minute<0 || minute > 60)
		{
			cout << "You entered uncorrect value!!! Try again.\n";
			cout << "-minute: ";
			cin >> minute;
		}
	} while (control == 1);
}

void WorkDay::setEndBreak(int hour, int minute)
{
	bool control = 1;
	do
	{
		if ((hour > -1 && hour<25) && (minute>-1 && minute < 61))
		{
			end_break.setHour(hour);
			end_break.setMinute(minute);
			control = 0;
		}
		else if (hour < 0 || hour>24)
		{
			cout << "You entered uncorrect value!!! Try again.\n";
			cout << "-hour: ";
			cin >> hour;
		}
		else if (minute<0 || minute > 60)
		{
			cout << "You entered uncorrect value!!! Try again.\n";
			cout << "-minute: ";
			cin >> minute;
		}
	} while (control == 1);
}

void WorkDay::setAll()
{
	bool control = 1; 
	char choice;
	cout << "Does the work day move on to the next day?(y/n)\n";
	do
	{
		choice = getchar();
		if (choice == 'y')
		{
			double_work_day =1;
			control = 0;
		}
		else if (choice == 'n')
		{
			double_work_day = 0;
			control = 0;
		}
		else
		{
			cout << "You entered uncorrect value!!! Try again.\n";
		}
		
	} while (control == 1);
	int adjustment = 1;  //переменная для контроля начала и окончания рабочей смены (не позволяет начало смены записать в конец и наоборот)
	if (double_work_day == 1)
	{
		adjustment = -1;
	}
	int hour, minute;
	cout << "Enter the begining of the work day:\n";
	cout << "-hour - ";
	cin >> hour;
	cout << "-minute - ";
	cin >> minute;
	setBeginWorkDay(hour, minute);
	control = 1;
	do
	{
		cout << "Enter the ending of the work day:\n";
		cout << "-hour - ";
		cin >> hour;
		cout << "-minute - ";
		cin >> minute;
		if (begin_work_day.convertInHour()*adjustment <= (hour + minute / 60.0) * adjustment)
		{
			control = 0;
			setEndWorkDay(hour, minute);
		}
		else
		{
			cout << "You entered uncorrect value!!! Try again.\n";
			cout << "1. Change the begining of the work day;\n";
			cout << "2. Change the ending of the work day;\n";
			int select;
			cin >> select;
			if (select == 1)
			{
				cout << "Enter the begining of the work day:\n";
				cout << "-hour - ";
				cin >> hour;
				cout << "-minute - ";
				cin >> minute;
				setBeginWorkDay(hour, minute);
			}
		}
	} while (control == 1);
	cout << "Does the work day have a break?(y/n)\n";
	control = 1;
	do
	{
		cin >> choice;
		if (choice == 'y')
		{
			do
			{
				cout << "Enter the begining of the break:\n";
				cout << "-hour - ";
				cin >> hour;
				cout << "-minute - ";
				cin >> minute;
				if ((double_work_day == 0 && (Time(hour, minute) > begin_work_day && Time(hour, minute) < end_work_day)) || (double_work_day == 1 && ((Time(hour, minute) > begin_work_day && Time(hour, minute)<=Time(24,0)) || (Time(hour, minute)>=Time(0, 0) && Time(hour, minute) < end_work_day))))
				{
					setBeginBreak(hour, minute);
					control = 0;
				}
				else
				{
					cout << "You entered uncorrect value!!! Try again.\n";
				}
			} while (control == 1);
			control = 1;
			do
			{
				cout << "Enter the ending of the break:\n";
				cout << "-hour - ";
				cin >> hour;
				cout << "-minute - ";
				cin >> minute;
				if ((double_work_day == 0 && (Time(hour, minute) > begin_break && Time(hour, minute) < end_work_day)) || (double_work_day == 1 && ((Time(hour, minute) > begin_break && Time(hour, minute)<=Time(24, 0)) || (Time(hour, minute)>=Time(0, 0) && Time(hour, minute) < end_work_day))))
				{
					control = 0;
					setEndBreak(hour, minute);
				}
				else
				{
					cout << "You entered uncorrect value!!! Try again.\n";
				}
			} while (control == 1);
		}
		else if (choice == 'n')
		{
			control = 0;
		}
		else
		{
			cout << "You entered uncorrect value!!! Try again.\n";
		}

	} while (control == 1);
	calculateAllTypeHours();
}

void WorkDay::setWorkDayBeforeHoliday(bool a)
{
	work_day_before_holiday = a;
}

void WorkDay::setWorkDayHoliday(bool a)
{
	work_day_holiday = a;
}

float WorkDay::timeInsideWorkDay(Time begin, Time begin_inside, Time end_inside, Time end)
{
	float tmp=0.0;
	for (int i = begin.getHour(); i <= end.getHour(); i++)
	{
		if (begin.getHour() <= begin_inside.getHour())
		{
			if (i > begin_inside.getHour() && i <= end_inside.getHour())
			{
				tmp++;
			}
		}
		else if (i > begin.getHour() && i <= end_inside.getHour())
		{
			tmp++;
		}
	}
	if (begin_inside <= begin && begin <= end_inside)
	{
		tmp -= (begin.getMinute() / 60.0);
	}
	if (begin_inside <= end && end <= end_inside)
	{
		tmp += (end.getMinute() / 60.0);
	}
	return tmp;
}

void WorkDay::calculateWorkHours()
{
	if (double_work_day == 0)
	{
		work_hours = (end_work_day - begin_work_day).convertInHour() - (end_break - begin_break).convertInHour();
	}
	else
	{
		if (begin_break<=end_break)
		{
			work_hours = (Time(24, 0) - begin_work_day + end_work_day).convertInHour() - (end_break - begin_break).convertInHour();
		}
		else
		{
			work_hours = (Time(24, 0) - begin_work_day + end_work_day).convertInHour() - (Time(24, 0) - begin_break+end_break).convertInHour();
		}
	}
}

void WorkDay::calculateWorkEveningHours()
{
	if (begin_work_day < end_work_day)
	{
		work_evening_hours = timeInsideWorkDay(begin_work_day, evening_time, nite_time, end_work_day) - timeInsideWorkDay(begin_break, evening_time, nite_time, end_break);
	}
	else if (begin_work_day >= end_work_day)
	{
		work_evening_hours = timeInsideWorkDay(begin_work_day, evening_time, nite_time, Time(24,0));
		if (begin_break < end_break)
		{
			work_evening_hours -= timeInsideWorkDay(begin_break, evening_time, nite_time, end_break);
		}
		else if (begin_break >= end_break)
		{
			work_evening_hours -= timeInsideWorkDay(begin_break, evening_time, nite_time, Time(24,0));
		}
	}
	/*if (double_work_day == 0 && begin_work_day<=nite_time && end_work_day>evening_time)
	{
		if (begin_work_day<=evening_time && end_work_day>=nite_time)
		{
			work_evening_hours = (nite_time - evening_time).convertInHour();
		}
		else if (begin_work_day >= evening_time && end_work_day >= nite_time)
		{
			work_evening_hours = (nite_time-begin_work_day).convertInHour();
		}
		else if (begin_work_day >= evening_time && end_work_day <= nite_time)
		{
			work_evening_hours = (end_work_day-begin_work_day).convertInHour();
		}
		else if (begin_work_day <= evening_time && end_work_day <= nite_time)
		{
			work_evening_hours = (end_work_day - evening_time).convertInHour();
		}
	}
	else if (double_work_day == 1)
	{
		if (begin_work_day <= evening_time)
		{
			work_evening_hours = (nite_time - evening_time).convertInHour();
		}
		else if (begin_work_day >= evening_time && begin_work_day <= nite_time)
		{
			work_evening_hours = (nite_time - begin_work_day).convertInHour();
		}
	}
	else
	{
		work_evening_hours = 0;
	}*/
}

void WorkDay::calculateWorkNiteHours()
{
	if (begin_work_day < end_work_day)
	{
		work_nite_hours = timeInsideWorkDay(begin_work_day, nite_time, Time(24, 0), end_work_day) - timeInsideWorkDay(begin_break, nite_time, Time(24, 0), end_break);
	}
	else if (begin_work_day >= end_work_day)
	{
		work_nite_hours = timeInsideWorkDay(begin_work_day, nite_time, Time(24, 0), Time(24, 0));
		work_nite_hours += timeInsideWorkDay(Time(0, 0), Time(0, 0), end_nite_time, end_work_day);
		if (begin_break < end_break)
		{
			work_nite_hours -= timeInsideWorkDay(begin_break, evening_time, Time(24, 0), end_break);
		}
		else if (begin_break >= end_break)
		{
			work_nite_hours -= timeInsideWorkDay(begin_break, nite_time, Time(24, 0), Time(24, 0));
			work_nite_hours -= timeInsideWorkDay(Time(0, 0), Time(0, 0), end_nite_time, end_break);
		}
	}
	/*if (double_work_day == 0 && end_work_day>=nite_time)
	{
		if (begin_work_day <= nite_time)
		{
			work_nite_hours = (end_work_day-nite_time).convertInHour();
		}
		else if (begin_work_day >= nite_time)
		{
			work_nite_hours = (end_work_day - begin_work_day).convertInHour();
		}
	}
	else if (double_work_day == 1)
	{
		if (begin_work_day <= nite_time && end_work_day <= end_nite_time)
		{
			work_nite_hours = (Time(24,0)-nite_time).convertInHour()+end_work_day.convertInHour();
		}
		else if (begin_work_day >= nite_time && end_work_day <= end_nite_time)
		{
			work_nite_hours = (Time(24, 0) - begin_work_day).convertInHour() + end_work_day.convertInHour();
		}
		else if (begin_work_day <= nite_time && end_work_day >= end_nite_time)
		{
			work_nite_hours = (Time(24, 0) - nite_time).convertInHour() + end_nite_time.convertInHour();
		}
		else if (begin_work_day >= nite_time && end_work_day >= end_nite_time)
		{
			work_nite_hours = (Time(24, 0) - begin_work_day).convertInHour() + end_nite_time.convertInHour();
		}
	}
	else
	{
		work_nite_hours = 0;
	}*/
}
void WorkDay::calculateWorkHolidayHours()
{
	if (double_work_day == 1)
	{
		if (work_day_holiday == 1)
		{
			work_holiday_hours = (Time(24, 0) - begin_work_day).convertInHour();
		}
		if (work_day_before_holiday == 1)
		{
			work_holiday_hours += end_work_day.convertInHour();
		}
	}
	else if (double_work_day == 0 && work_day_holiday == 1)
	{
		work_holiday_hours = (end_work_day-begin_work_day).convertInHour();
	}

}
void WorkDay::calculateAllTypeHours()
{
	calculateWorkHours();
	calculateWorkEveningHours();
	calculateWorkNiteHours(); 
	calculateWorkHolidayHours();
}

float WorkDay::getWorkHours()
{
	return work_hours;
}

float WorkDay::getWorkEveningHours(){
	return work_evening_hours;
}

float WorkDay::getWorkNiteHours()
{
	return work_nite_hours;
}

float WorkDay::getWorkHolidayHours()
{
	return work_holiday_hours;
}

void WorkDay::Print()
{
	char symbol = 37;
	begin_work_day.Print();
	cout << symbol;
	begin_break.Print();
	cout << " - ";
	end_break.Print(); 
	cout << symbol;
	end_work_day.Print();
	cout << "\nHours:\n";
	cout << "- work - " << work_hours << ";\n";
	cout << "- evening - " << work_evening_hours << ";\n";
	cout << "- nite - " << work_nite_hours << ";\n";
	cout << "- holiday - " << work_holiday_hours << ";\n";
}

WorkDay::~WorkDay(){}


Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}

Date::Date(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
}

void Date::setDay(int day)
{
	bool control = 1;
	do
	{
		if (day > 0 && day<(getDaysInMonth()+1))
		{
			this->day=day;
			control = 0;
		}
		else
		{
			cout << "You entered uncorrect value!!! Try again.\n";
			cout << "Day: ";
			cin >> day;
		}
	} while (control == 1);
}
void Date::setMonth(int month)
{
	bool control = 1;
	do
	{
		if (month > 0 && month<13)
		{
			this->month = month;
			control = 0;
		}
		else
		{
			cout << "You entered uncorrect value!!! Try again.\n";
			cout << "Month: ";
			cin >> month;
		}
	} while (control == 1);
}
void Date::setYear(int year)
{
	this->year = year;
}

void Date::setDate()
{
	int y, m, d;
	cout << "Enter the year: ";
	cin >> y;
	setYear(y);
	cout << "Enter the month: ";
	cin >> m;
	setMonth(m);
	cout << "Enter the day: ";
	cin >> d;
	setDay(d);
}

void Date::setDate(int y, int m, int d)
{
	setYear(y);
	setMonth(m);
	setDay(d);
}


void Date::Print()
{
	if (day < 10)
	{
		cout << "0" << day;
	}
	else
	{
		cout << day;
	}
	cout << ".";
	if (month < 10)
	{
		cout << "0" << month;
	}
	else
	{
		cout << month;
	}
	cout << "." << year;
}

int Date::getDay() const
{
	return day;
}

int Date::getMonth()
{
	return month;
}

int Date::getYear()
{
	return year;
}

int Date::getDaysInMonth()
{
	if ((year % 4 == 0 || year % 100 != 0 && year % 400 == 0) && month==2)
	{
		return days_in_month[month-1]+1;
	}
	else
	{
		return days_in_month[month - 1];
	}
}


int Date::operator-(const Date &a)
{
	int vis_years = 0;
	int mas_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (int i = (year<a.year ? year : a.year); i <= (year>a.year ? year : a.year); i++)
	{
		if (i % 4 == 0 || i % 100 != 0 && i % 400 == 0)
		{
			vis_years++;
		}
	}
	int days_in_years = abs(year - a.year) * 365 + vis_years;
	int days_in_month = 0;
	if (year<a.year ? month<a.month : a.month<month)
	{
		for (int i = ((year<a.year ? month : a.month) - 1); i<((year<a.year ? a.month : month) - 1); i++)
		{
			days_in_month += mas_month[i];
		}
	}
	if (year<a.year ? month>a.month:a.month>month)
	{
		for (int i = ((year<a.year ? a.month : month) - 1); i<((year<a.year ? month : a.month) - 1); i++)
		{
			days_in_month -= mas_month[i];
		}
	}
	int days = abs(day - a.day);
	int sum_days = days_in_years + days_in_month + days;
	return sum_days;
}

bool Date::operator==(const Date &obj)
{
	if (month == obj.month && day == obj.day && year == obj.year)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Date Date::operator+(int a)
{
	Date tmp=*this;
	int sum = 0;
	int mas_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	while (true)
	{
		while (tmp.month <= 12 && sum < a)
		{
			while (tmp.day <= mas_month[month - 1] && sum < a)
			{
				tmp.day++;
				sum++;
			}
			if (sum == a)
			{
				if (tmp.day>mas_month[month - 1])
				{
					tmp.day = 1;
					tmp.month++;
				}
				break;
			}
			tmp.day = 1;
			tmp.month++;
		}
		if (sum == a)
		{
			if (tmp.month > 12)
			{
				tmp.month = 1;
				tmp.year++;
			}
			break;
		}
		tmp.month = 1;
		tmp.year++;
	}
	return tmp;
}

Date::~Date(){}


Holiday::Holiday()
{
	size = 11;
	//mas = new Date[size]{Date(2017, 1, 1), Date(2017, 1, 7), Date(2017, 3, 8), Date(2017, 4, 16), Date(2017, 5, 1), Date(2017, 5, 2), Date(2017, 5, 9), Date(2017, 6, 4), Date(2017, 6, 28), Date(2017, 8, 24), Date(2017, 10, 14)};
	mas = new Date[size];
	mas[0] =  Date(2017, 1, 1);
	mas[1] = Date(2017, 1, 7);
	mas[2] = Date(2017, 3, 8);
	mas[3] = Date(2017, 4, 16);
	mas[4] = Date(2017, 5, 1);
	mas[5] = Date(2017, 5, 2);
	mas[6] = Date(2017, 5, 9);
	mas[7]= Date(2017, 6, 4);
	mas[8] = Date(2017, 6, 28);
	mas[9] = Date(2017, 8, 24);
	mas[10] = Date(2017, 10, 14);
}

Date Holiday::getHoliday(int i)
{
	if (i >= 0 && i < size)
	{
		return mas[i];
	}
	else
	{
		return Date(0, 0, 0);
	}
}

int Holiday::getSize()
{
	return size;
}

Holiday::~Holiday(){}


WorkShedule::WorkShedule()
{
	size_shedule=24;
	counter_size_shedule=0; 
	name_work_shedule = nullptr;
	//*date_shedule = nullptr;
	date_shedule = nullptr;
	//*shedule=nullptr;
	shedule = nullptr;
	template_shedule = nullptr;
	number_of_shift = 1;
	lenght_reiteration_work_day = nullptr;
	lenght_reiteration_rest_day = nullptr;
	memory[0]=0;
	memory[1] = 0;
	memory[2] = 0;
	number_of_brigades = 1;
}

void WorkShedule::setNumberOfShift(int number)
{
	number_of_shift = number;
}

void WorkShedule::setNumberOfBrigades(int number)
{
	number_of_brigades = number;
}

void WorkShedule::setMemory(int a, int b, int c)
{
	memory[0] = a;
	memory[1] = b;
	memory[2] = c;
}

int WorkShedule:: operator[](int position)
{
	return memory[position];
}

void WorkShedule::createTemplateShedule()
{
	int number;
	cout << "How much shifts do work day have?\n";
	cin>>number;
	setNumberOfShift(number);
	template_shedule = new WorkDay[number_of_shift];
	lenght_reiteration_work_day = new int[number_of_shift];
	lenght_reiteration_rest_day = new int[number_of_shift];
	for (int i = 0; i < number_of_shift; i++)
	{
		cout << i + 1 << "'st shift:\n";
		template_shedule[i].setAll();
		template_shedule[i].calculateAllTypeHours();
		cout << "Number reiterations this work day: ";
		cin >> lenght_reiteration_work_day[i];
		cout << "Number reiterations rest day after this work day: ";
		cin >> lenght_reiteration_rest_day[i];
	}
}

void WorkShedule::manualCreateShedule()
{
	int tmp;
	if (counter_size_shedule == 0)
	{
		cout << "Enter the name of this shedule: ";
		enterTheText(name_work_shedule);
		cin.ignore();
		cout << "Enter the current year: ";
		cin >> tmp;
		sample.setYear(tmp);
		cout << "Enter the current month: ";
		cin >> tmp;
		sample.setMonth(tmp);
		createTemplateShedule();
	}
	date_shedule = new Date*[size_shedule];
	shedule = new WorkDay*[size_shedule];
	date_shedule[counter_size_shedule] = new Date[sample.getDaysInMonth()];
	shedule[counter_size_shedule] = new WorkDay[sample.getDaysInMonth()];
	for (int i = 0; i < sample.getDaysInMonth(); i++)
	{
		date_shedule[counter_size_shedule][i].setDate(sample.getYear(), sample.getMonth(), i + 1);
		date_shedule[counter_size_shedule][i].Print();
		cout << "\n";
		bool control = 1;
		do
		{
			cout << "Enter a shift:";
			cin>>tmp; 
			if (tmp>=1 && tmp<=number_of_shift)
			{
				shedule[counter_size_shedule][i] = template_shedule[tmp - 1];
				shedule[counter_size_shedule][i].setWorkDayHoliday(search(date_shedule[counter_size_shedule][i]));
				shedule[counter_size_shedule][i].setWorkDayBeforeHoliday(search(date_shedule[counter_size_shedule][i] + 1));
				shedule[counter_size_shedule][i].calculateAllTypeHours();
				control = 0;
			}
			else if (tmp == 0)
			{
				shedule[counter_size_shedule][i] = WorkDay();
				control = 0;
			}
			else
			{
				cout << "You entered uncorrect value!!! Try again.\n";
			}
		} while (control == 1);
	}
}

void WorkShedule::autoCreateShedule()
{
	if (counter_size_shedule == 0)
	{
		cout << "Enter the name of this shedule: ";
		enterTheText(name_work_shedule);
		cin.ignore();
		int tmp;
		cout << "Enter the current year: ";
		cin >> tmp;
		sample.setYear(tmp);
		cout << "Enter the current month: ";
		cin >> tmp;
		sample.setMonth(tmp);
		createTemplateShedule();
	}
	int number_work_day = memory[0];
	int position_of_the_work_day_in_shelter = memory[1];
	date_shedule = new Date*[size_shedule];
	shedule = new WorkDay*[size_shedule];
	date_shedule[counter_size_shedule] = new Date[sample.getDaysInMonth()];
	shedule[counter_size_shedule] = new WorkDay[sample.getDaysInMonth()]; 
	for (int i = 0; i < sample.getDaysInMonth();)
	{
		date_shedule[counter_size_shedule][i].setDate(sample.getYear(), sample.getMonth(), i + 1);
		if (memory[2] == 0 || (memory[2] == 1 && (memory[1] + 1) == lenght_reiteration_rest_day[memory[0]])) //???????????????
		{
			for (; position_of_the_work_day_in_shelter < lenght_reiteration_work_day[number_work_day] && i < sample.getDaysInMonth(); position_of_the_work_day_in_shelter++)
			{
				shedule[counter_size_shedule][i] = template_shedule[number_work_day];
				shedule[counter_size_shedule][i].setWorkDayHoliday(search(date_shedule[counter_size_shedule][i]));
				shedule[counter_size_shedule][i].setWorkDayBeforeHoliday(search(date_shedule[counter_size_shedule][i] + 1));
				shedule[counter_size_shedule][i].calculateAllTypeHours();
				i++;
			}
			setMemory(number_work_day, position_of_the_work_day_in_shelter - 1, 0);
			position_of_the_work_day_in_shelter = 0;
		}
		if (memory[2] == 1 || (memory[2] == 0 && (memory[1] + 1) == lenght_reiteration_work_day[memory[0]]))
		{
			for (; position_of_the_work_day_in_shelter < lenght_reiteration_rest_day[number_work_day] && i < sample.getDaysInMonth(); position_of_the_work_day_in_shelter++)
			{
				shedule[counter_size_shedule][i] = WorkDay();
				shedule[counter_size_shedule][i].setWorkDayHoliday(search(date_shedule[counter_size_shedule][i]));
				shedule[counter_size_shedule][i].setWorkDayBeforeHoliday(search(date_shedule[counter_size_shedule][i] + 1));
				//shedule[counter_size_shedule][i].calculateAllTypeHours();
				shedule[counter_size_shedule][i].calculateWorkHolidayHours();
				i++;
			}
		}
		if ((number_work_day + 1) < number_of_shift)
		{
			number_work_day++;
		}
		else
		{
			number_work_day = 0;
		}
	}
	counter_size_shedule++;
}

bool WorkShedule::search(Date obj)
{
	for (int i = 0; i<holiday.getSize(); i++)
	{
		if (obj == holiday.getHoliday(i))
		{
			return true;
		}
	}
	return false;
}

void WorkShedule::Print()
{
	for (int i = 0; i < sample.getDaysInMonth(); i++)
	{
		date_shedule[counter_size_shedule][i].Print();
		cout << "\n";
		shedule[counter_size_shedule][i].Print();
		cout << "\n";
	}
	cout << "---------------------------------\n";
}
WorkShedule::~WorkShedule()
{
}

Worker::Worker()
{
}


Worker::~Worker()
{
}
