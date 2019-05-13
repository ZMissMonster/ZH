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
	//����
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

	//����������
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	//����

	set<int>::iterator pos = s.find(3);// --- ʱ�临�Ӷȣ�O(log(N))���ײ���������������ʹ��
	//pos = find(s.begin(), s.end(), 3);// --- ʱ�临�Ӷȣ�O(N)����Ҫ����һ�鲻����ʹ��
	if (pos != s.end())
	{
		cout << "�ҵ�����" << endl;
	}

	//s.erase(it);       //�������ѭ����ʱ����3��ɾ����û��3�ͱ���
	//s.erase(3);       //��3��ɾ����û��3�Ͳ�ɾ
	//��ʽforѭ��
	//for (auto e : s)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;


	s.clear();//�����������
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

	s2.swap(s);//�������ڵ��ָ�룬Ч�ʸ�
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
	//���Բ����ظ�����ͬ��keyֵ
	for (auto e : ms)
	{
		cout << e << " ";
	}
	cout << endl;

	auto mit = ms.find(3);
	if (mit != ms.end())//��Ϊ�ж��3�������ҵ�������������ĵ�һ��
	{
		cout << "�ҵ���~��" << endl;
		while (*mit == 3)//��������������е�3
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

