#define _CRT_SECURE_NO_WARNINGS 1
//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

//为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 - 1，则在该链表中没有环。

//说明：不允许修改给定的链表。
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
 };

struct ListNode *detectCycle(struct ListNode *head) {
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	struct ListNode* meet = NULL;
	while (fast&&fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;//fast始终走的步数是slow的两倍，slow=step，fast=2*step.
		//2(L+X)=L+X+nC   ->  L+X=nC  ->  L=nC-X
		if (fast == slow)
		{
			meet = slow;//记录相遇位置
			break;
		}
	}
	if (meet == NULL)
	{
		return NULL;//如果meet没变，说明没有环
	}
	//L = nC - X  所以头和相遇位置同时走，再次相遇就是第一个结点
	while (meet&&head)
	{
		if (meet == head)
			return head;
		meet = meet->next;
		head = head->next;
	}
	return NULL;
}