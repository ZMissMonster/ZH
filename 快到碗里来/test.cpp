#define _CRT_SECURE_NO_WARNINGS 1
//链接：https://www.nowcoder.com/questionTerminal/82424d93369649b98720743c25edc6ce
//小喵们很喜欢把自己装进容器里的（例如碗），但是要是碗的周长比喵的身长还短，它们就进不去了。现在告诉你它们的身长，和碗的半径，请判断一下能否到碗里去。
//输入描述 :
//输入有多组数据。
//每组数据包含两个整数n(1≤n≤2 ^ 128) 和r(1≤r≤2 ^ 128)，分别代表喵的身长和碗的半径。
//圆周率使用3.14。
//求圆的周长和身长比较即可
#include <iostream>
using namespace std;
int main(){
	double n, r;
	while (cin >> n >> r){
		if (n > (2 * r*3.1415))
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	} 
	return 0;
}