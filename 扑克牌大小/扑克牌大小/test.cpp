#define _CRT_SECURE_NO_WARNINGS 1
//扑克牌大小
//链接：https://www.nowcoder.com/practice/0a92c75f5d6b4db28fcfa3e65e5c9b3f?tpId=49&&tqId=29277 & rp = 1 & ru = / activity / oj&qru = / ta / 2016test / question - ranking
//“输入每手牌可能是个子，对子，顺子（连续5张），三个，炸弹（四个）和对王中的一种，
//不存在其他情况，由输入保证两手牌都是合法的，顺子已经从小到大排列“
//按照题意牌面类型的确定和大小的比较直接可以转换为牌个数的比较
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	string line;
	while (getline(cin, line)){
		//王炸最大，直接输出
		if (line.find("joker JOKER") != -1)
			cout << "joker JOKER" << endl;
		else{
			int dash = line.find('-');
			//分开两手牌
			string car1 = line.substr(0, dash);
			string car2 = line.substr(dash + 1);
			//获取空格的次数，牌数为c + 1
			int c1 = count(car1.begin(), car1.end(), ' ');
			int c2 = count(car2.begin(), car2.end(), ' ');
			//拿到第一张牌
			string first1 = car1.substr(0, car1.find(' '));
			string first2 = car2.substr(0, car2.find(' '));
			string str = "345678910JQKA2jokerJOKER";
			if (c1 == c2){
				//只要牌数相等，则第一张牌大的即为大
				if (str.find(first1) > str.find(first2))
					cout << car1 << endl;
				else
					cout << car2 << endl;
			}
			else
			{
				//牌数不相同，说明类型不同,只有炸弹可以和其它牌比较
				//其它类型都是错误的
				if (c1 == 3)
					cout << car1 << endl;
				else if (c2 == 3)
					cout << car2 << endl;
				else
					cout << "ERROR" << endl;
			}
		}
	}
}
