#define _CRT_SECURE_NO_WARNINGS 1
//给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点。
//https://leetcode-cn.com/problems/middle-of-the-linked-list/submissions/
//快慢指针法，快的走两步，慢的走一步，快的走到尾，慢的走了一半
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