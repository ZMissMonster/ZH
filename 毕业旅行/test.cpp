#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<vector<int> > vv(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> vv[i][j];
		}
	}
	int minsum1 = 0;
	int minsum2 = 0;
	int minsum3 = 0;
	int minsum4 = 0;
	int minsum5 = 0;
	int minsum = 0;
	int sum1 = 0;//12314
	int sum2 = 0;//12431
	int sum3 = 0;//13242
	int sum4 = 0;//13421
	int sum5 = 0;//14321
	int sum6 = 0;//14231
	sum1 = vv[0][1] + vv[1][2] + vv[2][3] + vv[3][0];
	sum2 = vv[0][1] + vv[1][3] + vv[3][2] + vv[2][0];
	sum3 = vv[0][2] + vv[2][1] + vv[3][1] + vv[3][0];
	sum4 = vv[0][2] + vv[3][2] + vv[3][1] + vv[1][0];
	sum5 = vv[0][3] + vv[3][1] + vv[2][1] + vv[2][0];
	sum6 = vv[0][3] + vv[2][3] + vv[2][1] + vv[1][0];
	minsum1 = min(sum1, sum2);
	minsum2 = min(sum3, sum4);
	minsum3 = min(sum5, sum6);
	minsum4 = min(minsum1, minsum2);
	minsum5 = min(minsum2, minsum3);
	minsum = min(minsum4, minsum5);
	cout <<minsum << endl;
	system("pause");
	return 0;
}