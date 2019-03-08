#include "Date.h"

int Date::GetMonthDay(int year, int month)
{
	static const int MonthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month==2 && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		return 29;
	}
	return MonthArray[month];
}

//构造函数
Date::Date(int year , int month, int day)
{
	if (year >= 0 &&
		month > 0 && month < 13 &&
		day > 0 && day <= GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}else
	{
		cout << "Date Invalid" << endl;
	}
}
//拷贝构造函数
//析构函数
Date::~Date()
{
}

void Date::Print()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

bool Date:: operator>(const Date& d)
{
	return (_year > d._year)
		|| (_year == d._year && _month > d._month)
		|| (_year == d._year && _month == d._month && _day > d._day);
}
//复用 运算符重载
bool Date::operator>=(const Date& d)
{
	return *this > d || *this == d;
}
bool Date::operator<(const Date& d)
{
	return !(*this >= d);
}
bool Date::operator<=(const Date& d)
{
	return !(*this >= d);
}
bool Date::operator==(const Date& d)
{
	return _year == d._year && _month > d._month && _day > d._day;
}
bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}

//赋值操作符重载
Date& Date::operator=(const Date& d)
{
	if (this != &d)//防止自己给自己赋值
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;//可以支持连续赋值
}
Date Date::operator+(int day)
{
	//Date ret(*this);
	//ret._day += day;
	//while (ret._day > GetMonthDay(ret._year, ret._month))
	//{
	//	ret._day -= GetMonthDay(ret._year, ret._month);
	//	ret._month++;
	//	if (ret._month == 13)
	//	{
	//		ret._year++;
	//		ret._month = 1;
	//	}
	//}
	//return ret;
	Date ret(*this);
	ret += day;
	return ret;
}

Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return*this -= -day;
	}
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}


Date Date::operator-(int day)
{
	//Date ret(*this);
	//ret._day -= day;
	//while (ret._day <= 0)
	//{
	//	--ret._month;
	//	if (ret._month == 0)
	//	{
	//		ret._year--;
	//		ret._month = 12;
	//	}
	//	ret._day += GetMonthDay(ret._year, ret._month);
	//}
	//return ret;
	Date ret(*this);
	ret -= day;
	return  ret;
}

Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += -day;
	}
	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}
//日期减日期
int Date::operator-(const Date& d)
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int n = 0;
	while (min != max)
	{

		++min;
		++n;
	}
	return n*flag;
}


//++d ->d.operator++(&d)
Date& Date::operator++()
{
	*this += 1;
	return *this;
}
//d++ ->d.operator++(&d,1) 前置后置这样区分构成重载
Date Date::operator++(int)
{
	Date tmp(*this);
	 *this += 1;
	return tmp;
}
//-> --d
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
//-> d--
Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}



int main()
{
	Date d1(2000, 2, 29);
	d1.Print();

	Date d2(d1);//拷贝构造
	d2.Print();

	Date d3;
	d1 = d3;//赋值
	d3.Print();

	Date d4 = d1;//拷贝构造
	d4.Print();

	Date(2018, 11, 18).Print();//匿名对象

	Date d5(2018, 1, 1);
	Date d6 = d5 + 20;
	d6.Print();

	Date d7(2018, 1, 1);
	Date d8 = d7 - 10;
	d7.Print();

	Date d9(2018,11,14);
	d9.Print();
	(++d9).Print();
	d9.Print();
	(d9++).Print();
	d9.Print();

	system("pause");
	return 0;
}