#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//分别遍历两个链表，算出长度，长的先走差值步，再同步走，相等时就是交点
//https://leetcode-cn.com/problems/intersection-of-two-linked-lists/description/
 
struct ListNode {
		int val;
		struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	int lenA = 0, lenB = 0;
	struct ListNode* curA = headA;
	struct ListNode* curB = headB;
	while (curA)
	{
		++lenA;
		curA = curA->next;
	}	
	while (curB)
	{
		++lenB;
		curB = curB->next;
	}
	int sub = abs(lenA-lenB);//计算差值
	struct ListNode* LongList = headA,* ShortList = headB;//默认A是长的，B是短的
	
	if (lenA < lenB)//若A短，交换一下
	{
		LongList = headB;
		ShortList = headA;
	}
	while (sub--)//长的先走差值步
	{
		LongList = LongList->next;
	}
	while (LongList && ShortList)//一起走，相等则返回交点
	{
		if (LongList == ShortList)//这里不能比较结点的值，因为如果值相等但是下一个才相交就跑不过
		{
			return LongList;
		}
		else
		{
			LongList = LongList->next;
			ShortList = ShortList->next;
		}
	}
	return NULL;
}