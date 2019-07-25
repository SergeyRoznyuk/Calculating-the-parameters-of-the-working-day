#pragma once


class Time
{
	int hour;
	int minute;
public:
	Time();
	Time(int, int);
	int getHour();
	int getMinute();
	void setHour(int);
	void setMinute(int);
	Time operator+(const Time &);
	Time operator-(const Time &);
	bool operator>(const Time &);
	bool operator<(const Time &);
	bool operator==(const Time&);
	bool operator>=(const Time&);
	bool operator<=(const Time&);
	void Print();
	float convertInHour();
	~Time();
};



class WorkDay
{
	Time begin_work_day;
	Time begin_break;
	Time end_break;
	Time end_work_day;
	bool double_work_day; //если смена переходит на следующие сутки - необходимо ставить 1, иначе - 0
	bool work_day_before_holiday; //если смена накануне праздничного дня - необходимо ставить 1, иначе - 0
	bool work_day_holiday; //если смена приходится на праздничный день - необходимо ставить 1, иначе - 0
	float work_hours;
	float work_evening_hours;
	float work_nite_hours;
	float work_holiday_hours;
	Time evening_time = { 18, 0 };
	Time nite_time = { 22, 0 };
	Time end_nite_time = { 6, 0 };
public:
	WorkDay();
	Time getBeginWorkDay();
	Time getBeginBreak();
	Time getEndBreak();
	Time getEndWorkDay();
	Time getEveningTime();
	Time getNiteTime();
	Time getEndNiteTime();
	void setBeginWorkDay(int, int);
	void setBeginBreak(int, int);
	void setEndWorkDay(int, int);
	void setEndBreak(int, int);
	void setAll();
	void setWorkDayBeforeHoliday (bool);
	void setWorkDayHoliday (bool);
	float timeInsideWorkDay(Time, Time, Time, Time); //метод для нахождения часов определённого интервала времени внутри рабочей смены
	void calculateWorkHours();
	void calculateWorkEveningHours(); 
	void calculateWorkNiteHours(); 
	void calculateWorkHolidayHours(); //доработать с учётом перерыва на обед
	void calculateAllTypeHours();
	float getWorkHours();
	float getWorkEveningHours();
	float getWorkNiteHours();
	float getWorkHolidayHours();
	void Print();
	~WorkDay();
};


class Date
{
	int day;
	int month;
	int year;
	const int *days_in_month =new int [12] { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
public:
	Date();
	Date(int, int, int);
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	void setDate();
	void setDate(int, int, int);
	int getDay() const;
	int getMonth();
	int getYear();
	int getDaysInMonth();
	void Print();
	int operator- (const Date&);
	bool operator==(const Date&);
	Date operator+(int);
	~Date();
};


class Holiday
{
	Date *mas;
	int size;
public:
	Holiday();
	Date getHoliday(int);
	int getSize();
	~Holiday();
};

void enterTheText(char *&);

class WorkShedule
{
	char *name_work_shedule;
	int size_shedule;
	int counter_size_shedule;
	Date **date_shedule;
	WorkDay **shedule;
	Date sample; //объект для определения размера графика (в зависимости от года и месяца возвращает определённое кол-во дней)
	Holiday holiday;
	WorkDay *template_shedule;
	int number_of_shift;
	int *lenght_reiteration_work_day; //массив для хранения количества повторений рабочих смен
	int *lenght_reiteration_rest_day; //массив для хранения количества выходных после каждой рабочей смены
	int memory[3]; //массив для запоминания последнего дня месяца: номер смены, на каком повторении остановились и была ли это рабочая смена или выходной 
	int number_of_brigades;  //пока что не реализовано
public:
	WorkShedule();
	void setNumberOfShift(int);
	void setNumberOfBrigades(int);
	void setMemory(int, int, int);
	int operator[] (int);
	void createTemplateShedule();
	void manualCreateShedule();
	void autoCreateShedule();
	bool search(Date);
	void Print();
	~WorkShedule();
};


class Worker
{
public:
	Worker();
	~Worker();
};

