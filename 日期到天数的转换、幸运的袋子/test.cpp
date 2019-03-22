#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
using namespace std;

//幸运的袋子

int getLuckyPacket(int x[], int n, int pos, int sum, int multi)
{
	int count = 0;
	//循环，搜索以位置i开始所有可能的组合
	for (int i = pos; i<n; i++)
	{
		sum += x[i];
		multi *= x[i];
		if (sum > multi)
		{
			//找到符合要求的组合，加1，继续累加后续的值，看是否有符合要求的集合
			count += 1 + getLuckyPacket(x, n, i + 1, sum, multi);
		} 
		else if (x[i] == 1)
		{
			//如何不符合要求，且当前元素值为1，则继续向后搜索
			count += getLuckyPacket(x, n, i + 1, sum, multi);
		} 
		else
		{
			//如何sum大于multi,则后面就没有符合要求的组合了
			break;
		} // 要搜索下一个位置之前，首先恢复sum和multi
		sum -= x[i];
		multi /= x[i];
		//数字相同的球，没有什么区别，都只能算一个组合，所以直接跳过
		while (i < n - 1 && x[i] == x[i + 1])
		{
			i++;
		}
	} 
	return count;
} 
int main()
{
	int n;
	while (cin >> n)
	{
		int x[n];
		for (int i = 0; i < n; i++)
		{
			cin >> x[i];
		} 
		sort(x, x + n);
		//从第一个位置开始搜索
		cout << getLuckyPacket(x, n, 0, 0, 1) << endl;
	} 
	return 0;
}
//日期到天数的转换
//int main()
//{
//	int array1[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
//	int array2[13] = { 0, 31, 60,91,121,152,182,212,244,274,305,335,366 };
//	int year, month, day;
//	int sum = 0;
//	while (cin >> year >> month >> day)
//	{
//		if (year % 4 == 0 && year % 100 != 0
//			|| year % 400 == 0)//闰年
//		{
//			sum = 0;
//			sum += array2[month-1];
//			sum += day;
//		}
//		else//平年
//		{
//			sum = 0;
//			sum += array1[month-1];
//			sum += day;
//		}
//		cout << sum << endl;
//	}
//	system("pause");
//	return 0;
//}