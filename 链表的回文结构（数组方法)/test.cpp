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
		int a[900];//��Ŀ˵�����Ȳ�����900
		int n = 0;
		struct ListNode* cur = A;
		while (cur)
		{
			a[n++] = cur->val;//���������ֵ�Ž�������
			cur = cur->next;
		}
		int left = 0;
		int right = n - 1;
		while (left < right)//����ָ�뿪ʼ���м����
		{
			if (a[left] != a[right])
				return false;
			++left;
			--right;
		}
		return true;
	}
};