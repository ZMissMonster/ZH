#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1);
	Date(const Date& d);
	Date& operator=(const Date& d);//��ֵ���������
	~Date();
	void Print();
	int GetMonthDay(int year, int month);
	
	Date operator+(int day);
	Date& operator+=(int day);

	Date operator-(int day);
	Date& operator-=(int day);

	int operator-(const Date& d);//���ڼ�����

	//++d ->d.operator++(&d)
	Date& operator++();
	//d++ ->d.operator++(&d,1) ǰ�ú����������ֹ�������
	Date operator++(int);

	Date& operator--();
	Date operator--(int);


	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
private:
	int _year;
	int _month;
	int _day;
};