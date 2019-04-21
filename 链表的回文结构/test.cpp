//链表的回文结构
//https://www.nowcoder.com/practice/d281619e4b3e4a60a2cc66ea32855bfa?tpId=49&&tqId=29370&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};

class PalindromeList {
public:
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
	bool chkPalindrome(ListNode* A) {
		int n = 0;
		struct ListNode* cur = A;
		while (cur)
		{
			cur = cur->next;
			++n;
		}
		cur = A;
		int mid = n / 2;
		while (mid--)
		{
			cur = cur->next;
		}
		struct ListNode* head1 = A;
		struct ListNode* head2 = reverseList(cur);
		mid = n / 2;
		while (mid--)
		{
			if (head1->val == head2->val)
			{
				head1 = head1->next;
				head2 = head2->next;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
};