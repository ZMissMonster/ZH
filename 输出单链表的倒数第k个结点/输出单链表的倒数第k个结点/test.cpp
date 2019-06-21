#define _CRT_SECURE_NO_WARNINGS 1
//����Ŀ�ǵ���������û�취�������β����ǰ������ֻ�ܴ�ǰ������ô
//����һ��
//��������������һ�μ���������ж��ٸ���㣬�ڶ�����������n-k+1λ�õĽ����ǵ�����k����㡣
//��������
//����һ��������������ָ�룬��һ��ָ������k-1����Ȼ��ڶ���ָ�����ߣ�����ʼ�����k-1����ǰ���ָ���ߵ�β��ʱ���ڶ���ָ�������ǵ�����k����
#include <iostream>
using namespace std;

//����һ������
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int a) 
	{
		val = a;
		next = NULL;
	}
};
//ʵ�ֺ���
ListNode* FindK(ListNode* head, int k)
{
	//�������ڻ���kֵ������ʱ
	if (head == nullptr || k == 0)
		return nullptr;
	ListNode* p1 = head;
	ListNode* p2 = nullptr;
	for (int i = 0; i < k - 1; ++i)
	{
		if (p1->next != nullptr)
			p1 = p1->next;
		else
			return nullptr;
	}
	p2 = head;
	while (p1->next != nullptr)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p2;
}
int main()
{
	int n;
	while (cin >> n) 
	{
		int val;
		ListNode *head = new ListNode(0);
		ListNode *p = head;
		for (int i = 0; i < n; i++) {
			cin >> val;
			ListNode *q = new ListNode(val);
			p->next = q;
			p = p->next;
		}
		int k;
		cin >> k;
		ListNode *temp = FindK(head, k);
		cout << temp->val << endl;
	}
	return 0;
}