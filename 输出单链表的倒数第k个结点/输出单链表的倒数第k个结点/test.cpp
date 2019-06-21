#define _CRT_SECURE_NO_WARNINGS 1
//该题目是单链表，所以没办法从链表的尾部向前遍历，只能从前往后，那么
//方法一：
//遍历两次链表，第一次计算出链表有多少个结点，第二次输出链表的n-k+1位置的结点就是倒数第k个结点。
//方法二：
//遍历一次链表，定义两个指针，第一个指针先走k-1步，然后第二个指针再走，两个始终相差k-1，当前面的指针走到尾部时，第二个指针正好是倒数第k个。
#include <iostream>
using namespace std;

//定义一个链表
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int a) 
	{
		val = a;
		next = NULL;
	}
};
//实现函数
ListNode* FindK(ListNode* head, int k)
{
	//链表不存在或者k值无意义时
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