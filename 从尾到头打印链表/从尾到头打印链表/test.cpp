#define _CRT_SECURE_NO_WARNINGS 1
//����һ�������ͷ��㣬��β��ͷ��������ӡ�����ÿ���ڵ��ֵ��
//������У����������뵽������������Ҫ������������Կ������뵽ջ�ṹ��Ҳ����ʹ�õݹ飬ÿ�δ�ӡ�ýڵ�ʱ�ȴ�ӡ�ýڵ����һ���ڵ㡣
#include <iostream>
#include <stack>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
};
//ջ�ṹʵ��
void PrintListReverse1(ListNode *head)
{
	stack<ListNode*> nodes;
	ListNode* Node = head;
	//������ڵ����η���ջ
	while (Node != nullptr)
	{
		nodes.push(Node);
		Node = Node->next;
	}
	//���γ�ջ
	while (!nodes.empty())
	{
		Node = nodes.top();
		cout << Node->val<<endl;
		nodes.pop();
	}
}
//�ݹ�
void PrintListReverse2(ListNode *head)
{
	if (head != nullptr)
	{
		if (head->next != nullptr)
		{
			PrintListReverse2(head->next);
		}
		cout << head->val << endl;
	}
	
}
