#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/4284c8f466814870bae7799a07d49ec8?tpId=85&amp;&amp;tqId=29852&amp;rp=1&amp;ru
//小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3.......
//这条石板路要根据特殊的规则才能前进：对于小易当前所在的编号为K的 石板，小易单次只能往前跳K的一个约数(不含1和K)步，即跳到K + X(X为K的一个非1和本身的约数)的位置。 小易当前处在编号为N的石板，他想跳到编号恰好为M的石板去，小易想知道最少需要跳跃几次可以到达。
//例如：
//N = 4，M = 24：
//4->6->8->12->18->24
//于是小易最少需要跳跃5次，就可以从4号石板跳到24号石板
//输入描述 :
//	输入为一行，有两个整数N，M，以空格隔开。(4 ≤ N ≤ 100000) (N ≤ M ≤ 100000)
//输出描述 :
//	输出小易最少需要跳跃的步数, 如果不能到达输出 - 1
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
		for (int j = 0; j < yueshu.size(); ++j){  //记录从起点N到位置i的最小步数
			if (yueshu[j] + i <= M){
				if (steps[yueshu[j] + i] == 0)    //到达位置i的最小步数加1
					steps[yueshu[j] + i] = steps[i] + 1;
				else                         //其它点也能到达，比较大小，记录最小步数
					steps[yueshu[j] + i] = (steps[i] + 1) < steps[yueshu[j] + i] ? (steps[i] + 1) : steps[yueshu[j] + i];
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
