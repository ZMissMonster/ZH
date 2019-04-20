//https://www.nowcoder.com/practice/d281619e4b3e4a60a2cc66ea32855bfa?tpId=49&&tqId=29370&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking

#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) 
		: val(x)
		, next(NULL) 
	{}
};
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		int a[900];//题目说链表长度不超过900
		int n = 0;
		struct ListNode* cur = A;
		while (cur)
		{
			a[n++] = cur->val;//遍历链表把值放进数组中
			cur = cur->next;
		}
		int left = 0;
		int right = n - 1;
		while (left < right)//左右指针开始向中间遍历
		{
			if (a[left] != a[right])
				return false;
			++left;
			--right;
		}
		return true;
	}
};