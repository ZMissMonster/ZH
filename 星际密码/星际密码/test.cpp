#define _CRT_SECURE_NO_WARNINGS 1
//链接：https://www.nowcoder.com/questionTerminal/34f17d5f2a8240bea661a23ec095a062
//来源：牛客网
//星际战争开展了100年之后，NowCoder终于破译了外星人的密码！他们的密码是一串整数，通过一张表里的信息映射成最终4位密码。表的规则是：n对应的值是矩阵X的n次方的左上角，如果这个数不足4位则用0填充，如果大于4位的则只输出最后4位。
//| 1 1 | ^n = > | Xn .. |
//| 1 0 | | .. .. |
//例如n = 2时，
//| 1 1 | ^ 2 = > | 1 1 | *| 1 1 | = > | 2 1 |
//| 1 0 | | 1 0 | | 1 0 | | 1 1 |
//即2对应的数是“0002”。
//输入描述 :
//输入有多组数据。
//每组数据两行：第一行包含一个整数n(1≤n≤100)；第二行包含n个正整数Xi(1≤Xi≤10000)
//输出描述 :
//	 对应每一组输入，输出一行相应的密码。
#include <iostream>
#include <vector>
using namespace std;
vector<int> a = { 1, 1 };
void data_init()
{
	int i;
	for (i = 2; i < 10005; i++){
		a.push_back((a[i - 1] + a[i - 2]) % 10000);
	}
} 
int main()
{
	int n, t;
	data_init();
	while (cin >> n){
		while (n--){
			cin >> t;
			printf("%04d", a[t]);
		}
		cout<<endl;
	}
	return 0;
}