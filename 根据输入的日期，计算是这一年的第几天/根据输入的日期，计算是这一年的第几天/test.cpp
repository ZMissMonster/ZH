#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
int main()
{
	int one2ndays[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
	int year, month, day;
	while (cin >> year >> month >> day)
	{
		int n = one2ndays[month - 1];
		n += day;
		if ((month > 2)
			&& ((year % 4 == 0 && year % 100 != 0)
			|| (year % 400 == 0)))
		{
			n += 1;
		}
		cout << n << endl;
	}
	return 0;
}