//计算糖果

#include <iostream>
using namespace std;
int main()
{
	int A, B, C;
	int y1, y2, y3, y4;
	while (cin >> y1 >> y2 >> y3 >> y4)
	{
		
		B = (y2 + y4)/2;
		A = B + y1;
		C = B - y2;
		//A = (y1 + y2) / 2;
		//C = (y4 - y2)/2;
		if (A - B == y1 && B - C == y2 && A + B == y3 && B + C == y4)
		{
			cout << A << " " << B << " " << C << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}

//进制转换

//#include <stdio.h>
//#include <stdlib.h>
//int cnt = 0;
//int fib(int n)
//{
//	cnt++;
//	if (n == 0)
//		return 1;
//	else if (n == 1)
//		return 2;
//	else
//		return fib(n - 1) + fib(n - 2);
//}
//int main()
//{
//	int a[5] = { 1, 3, 5, 7, 9 };
//	int *p = (int*)(&a + 1);
//	printf("%d%d", *(a + 1), *(p - 1));
//	//fib(5);
//	//printf("%d", cnt);
//	system("pause");
//	return 0;
//}