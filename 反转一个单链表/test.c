//��תһ��������
//https://leetcode-cn.com/problems/reverse-linked-list/description/

//˼·һ��ֱ�ӷ�תָ��
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* reverseList(struct ListNode* head) {
	if (head == NULL || head->next == NULL)
		return head;
	struct ListNode *n1, *n2, *n3;
	n1 = head;
	n2 = n1->next;
	n3 = n2->next;
	n1->next = NULL;
	while (n2)
	{
		n2->next = n1;
		n1 = n2;
		n2 = n3;
		if (n3)
			n3 = n3->next;
	}
	return n1;
}

//˼·��������һ���µ�����ͷ���Ϊ�գ��Ѿɵ�����ͷ����µģ������µ�����
// Definition for singly-linked list.
 struct ListNode {
   int val;
   struct ListNode *next;
 };

struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode *cur = head;
	struct ListNode *newhead = NULL;
	while (cur)
	{
		struct ListNode *next = cur->next;
		cur->next = newhead;
		newhead = cur;
		cur = next;
	}
	return newhead;
}