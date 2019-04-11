#define _CRT_SECURE_NO_WARNINGS 1
//����һ������ͷ��� head �ķǿյ���������������м��㡣����������м��㣬�򷵻صڶ����м��㡣
//https://leetcode-cn.com/problems/middle-of-the-linked-list/submissions/
//����ָ�뷨�������������������һ��������ߵ�β����������һ��
//Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };
struct ListNode* middleNode(struct ListNode* head) {
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	while (fast&&fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}