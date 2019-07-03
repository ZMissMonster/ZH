#define _CRT_SECURE_NO_WARNINGS 1
//输入一个链表的头结点，从尾到头反过来打印链表的每个节点的值。
//这道题中，我们首先想到遍历链表，但是要求反向输出，所以可以连想到栈结构。也可以使用递归，每次打印该节点时先打印该节点的下一个节点。
#include <iostream>
#include <stack>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
};
//栈结构实现
void PrintListReverse1(ListNode *head)
{
	stack<ListNode*> nodes;
	ListNode* Node = head;
	//将链表节点依次放入栈
	while (Node != nullptr)
	{
		nodes.push(Node);
		Node = Node->next;
	}
	//依次出栈
	while (!nodes.empty())
	{
		Node = nodes.top();
		cout << Node->val<<endl;
		nodes.pop();
	}
}
//递归
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
