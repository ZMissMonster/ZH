#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//�ֱ������������������ȣ��������߲�ֵ������ͬ���ߣ����ʱ���ǽ���
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
	int sub = abs(lenA-lenB);//�����ֵ
	struct ListNode* LongList = headA,* ShortList = headB;//Ĭ��A�ǳ��ģ�B�Ƕ̵�
	
	if (lenA < lenB)//��A�̣�����һ��
	{
		LongList = headB;
		ShortList = headA;
	}
	while (sub--)//�������߲�ֵ��
	{
		LongList = LongList->next;
	}
	while (LongList && ShortList)//һ���ߣ�����򷵻ؽ���
	{
		if (LongList == ShortList)//���ﲻ�ܱȽϽ���ֵ����Ϊ���ֵ��ȵ�����һ�����ཻ���ܲ���
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