#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
// Definition for singly-linked list.
 struct ListNode {
    int val;
    struct ListNode *next;
 };
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	//����һ��Ϊ�գ�ֱ�ӷ�����һ��  
	if (l1 == NULL)
		return l2;
	else if (l2 == NULL)
		return l1;
	// ��ȡһ��С�Ľڵ���ͷ
	struct ListNode* head, *tail;
	if (l1->val < l2->val)
	{
		head = l1;
		l1 = l1->next;
	}
	else
	{
		head = l2;
		l2 = l2->next;
	}
	// ȡС�Ľڵ����β��
	tail = head;
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->val < l2->val)
		{
			tail->next = l1;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			l2 = l2->next;
		}
		tail = tail->next;
	}
	if (l1 != NULL)
		tail->next = l1;
	if (l2 != NULL)
		tail->next = l2;
	return head;
}