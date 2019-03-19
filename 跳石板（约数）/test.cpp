#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<vector>
#include<math.h>
using namespace std;
//跳石板

//求约数
void getYueshu(int n, vector<int> &yueshu){//求除了1和本身的约数
	for (int i = 2; i <= sqrt(n); ++i){
		if (n%i == 0){
			yueshu.push_back(i);
			if (n / i != i)//非平方数时还有另一个数也要加入
				yueshu.push_back(n / i);
		}
	}
}
int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> steps(M + 1, 0);
	steps[N] = 1;

	for (int i = N; i <= M; ++i){
		if (steps[i] == 0)continue;   //位置无法到达，跳过
		vector<int> yueshu;
		getYueshu(i, yueshu);
		for (int j = 0; j<yueshu.size(); ++j){  //记录从起点N到位置i的最小步数
			if (yueshu[j] + i <= M){
				if (steps[yueshu[j] + i] == 0)    //到达位置i的最小步数加1
					steps[yueshu[j] + i] = steps[i] + 1;
				else                         //其它点也能到达，比较大小，记录最小步数
					steps[yueshu[j] + i] = (steps[i] + 1)<steps[yueshu[j] + i] ? (steps[i] + 1) : steps[yueshu[j] + i];
			}
		}
	}

	if (steps[M] == 0)
		cout << -1 << endl;
	else
		cout << steps[M] - 1 << endl;
	system("pause");
	return 0;
}

//class A
//{
//public:
//	virtual void print()
//	{
//		cout << "A:print()" << "\n";
//	}
//};
//class B :public A
//{
//public:virtual void print()
//{
//		   cout << "B:print()" << "\n";
//}
//};
//class C :public A
//{
//public:virtual void print()
//{
//		   cout << "C:print()" << "\n";
//}
//};
//void print(A a)
//{
//	a.print();
//}
//int main()
//{
//	A a, *aa, *ab, *ac;
//	B b;
//	C c;
//	aa = &a;
//	ab = &b;
//	ac = &c;
//	a.print();
//	b.print();
//	c.print();
//	aa->print();
//	ab->print();
//	ac->print();
//	print(a);
//	print(b);
//	print(c);
//	system("pause");
//	return 0;
//}