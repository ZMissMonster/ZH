#define _CRT_SECURE_NO_WARNINGS 1
//����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��

//Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� ��� pos �� - 1�����ڸ�������û�л���

//˵�����������޸ĸ���������
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
 };

struct ListNode *detectCycle(struct ListNode *head) {
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	struct ListNode* meet = NULL;
	while (fast&&fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;//fastʼ���ߵĲ�����slow��������slow=step��fast=2*step.
		//2(L+X)=L+X+nC   ->  L+X=nC  ->  L=nC-X
		if (fast == slow)
		{
			meet = slow;//��¼����λ��
			break;
		}
	}
	if (meet == NULL)
	{
		return NULL;//���meetû�䣬˵��û�л�
	}
	//L = nC - X  ����ͷ������λ��ͬʱ�ߣ��ٴ��������ǵ�һ�����
	while (meet&&head)
	{
		if (meet == head)
			return head;
		meet = meet->next;
		head = head->next;
	}
	return NULL;
}