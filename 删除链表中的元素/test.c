//ÒÆ³ıÁ´±íÔªËØ
//https://leetcode-cn.com/problems/remove-linked-list-elements/
//Definition for singly-linked list.
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
 struct ListNode {
     int val;
     struct ListNode *next;
 };

struct ListNode* removeElements(struct ListNode* head, int val) {
	if (head->val == NULL)
		return NULL;
	struct ListNode* cur = head;
	struct ListNode* prev = NULL;
	while (cur)
	{
		if (cur->val == val)
		{
			struct ListNode* next = cur->next;
			if (prev == NULL)
			{
				head = cur->next;
			}
			else
			{
				prev->next = cur->next;
			}
			free(cur);
			cur = next;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
		return head;
	}