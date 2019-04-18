//��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣 ���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL)
			return NULL;
		struct ListNode* n0 = NULL;
		struct ListNode* n1 = pHead;
		struct ListNode* n2 = n1->next;
		while (n2 != NULL)
		{
			if (n2->val != n1->val)
			{
				n0 = n1;
				n1 = n2;
				n2 = n2->next;
			}
			else
			{
				while (n2 && n2->val == n1->val)
				{
					n2 = n2->next;
				}
				if (n0)
				{
					n0->next = n2;
				}
				else
				{
					pHead = n2;
				}
				n1 = n2;
				if (n2)
				{
					n2 = n2->next;
				}
			}
		}		
		return pHead;
	}
};