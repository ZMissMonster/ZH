//https://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70?tpId=8&&tqId=11004&rp=2&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
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
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		if (pHead == NULL)
			return NULL;
		//��������������һ���洢����С�ģ�һ���洢������ģ���˳�����һ�飬����ã��ٺϲ�
		struct ListNode* lesshead, *lesstail, *greaterhead, *greatertail;
		//���ٿռ�
		lesshead = lesstail = (struct ListNode*)malloc(sizeof(struct ListNode));
		greaterhead = greatertail = (struct ListNode*)malloc(sizeof(struct ListNode));
		//��һ��ָ�����ԭ����
		struct ListNode* cur = pHead;
		while (cur)
		{
			if (cur->val < x)
			{
				//���cur��ֵС��x��������less����ĺ��
				lesstail->next = cur;
				lesstail = lesstail->next;
				}
			else
			{
				//���cur��ֵ����x��������greater����ĺ��
				greatertail->next = cur;
				greatertail = greatertail->next;
			}
			cur = cur->next;
		}
		//�ϲ��������ͷ�����ͷ���
		lesstail->next = greaterhead->next; 
		greatertail->next = NULL;

		pHead = lesshead->next;
		free(lesshead);
		free(greaterhead);

		return pHead;
	}
};