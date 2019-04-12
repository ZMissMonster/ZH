#define _CRT_SECURE_NO_WARNINGS 1
//链表中倒数第k个结点
//https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&&tqId=11167&rp=2&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) 
		:val(x), next(NULL) 
	{}
};
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		struct ListNode* fast = pListHead;
		struct ListNode* slow = pListHead;
		while (k--)
		{
			if (fast)
			{
				fast = fast->next;//快指针先走k步
			}
			else
			{
				return NULL;
			}
		}
		while (fast)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
	}
};