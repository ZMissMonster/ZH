#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <map>
#include <set>

void test_map()
{

}

void test_set()
{
	//插入
	set<int> s;
	s.insert(4);
	s.insert(5);
	s.insert(5);
	s.insert(1);
	s.insert(3);
	s.insert(5);
	s.insert(2);
	s.insert(5);
	s.insert(6);

	//迭代器遍历
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	//查找

	set<int>::iterator pos = s.find(3);// --- 时间复杂度：O(log(N))，底层是搜索树，建议使用
	//pos = find(s.begin(), s.end(), 3);// --- 时间复杂度：O(N)，需要遍历一遍不建议使用
	if (pos != s.end())
	{
		cout << "找到啦！" << endl;
	}

	//s.erase(it);       //该语句在循环外时，有3就删除，没有3就报错
	//s.erase(3);       //有3就删除，没有3就不删
	//新式for循环
	//for (auto e : s)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;


	s.clear();//清掉所有数据
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;


	set<int> s2;
	s2.insert(6);
	s2.insert(9);
	s2.insert(8);
	s2.insert(7);
	s2.insert(10);

	s2.swap(s);//交换根节点的指针，效率高
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}
void test_multiset()
{
	multiset<int> ms;
	ms.insert(3);
	ms.insert(4);
	ms.insert(5);
	ms.insert(2);
	ms.insert(1);
	ms.insert(5);
	ms.insert(4);
	ms.insert(3);
	//可以插入重复的相同的key值
	for (auto e : ms)
	{
		cout << e << " ";
	}
	cout << endl;

	auto mit = ms.find(3);
	if (mit != ms.end())//因为有多个3，所以找到的是中序遍历的第一个
	{
		cout << "找到啦~！" << endl;
		while (*mit == 3)//继续遍历输出所有的3
		{
			cout << *mit <<" ";
			++mit;
		}
		cout << endl;
	}
}
int main()
{
	//test_set();
	test_multiset();
	system("pause");
	return 0;
}

