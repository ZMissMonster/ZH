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
		//创建两个单链表，一个存储比他小的，一个存储比他大的，按顺序遍历一遍，分类好，再合并
		struct ListNode* lesshead, *lesstail, *greaterhead, *greatertail;
		//开辟空间
		lesshead = lesstail = (struct ListNode*)malloc(sizeof(struct ListNode));
		greaterhead = greatertail = (struct ListNode*)malloc(sizeof(struct ListNode));
		//用一个指针遍历原链表
		struct ListNode* cur = pHead;
		while (cur)
		{
			if (cur->val < x)
			{
				//如果cur的值小于x，就链到less链表的后边
				lesstail->next = cur;
				lesstail = lesstail->next;
				}
			else
			{
				//如果cur的值大于x，就链到greater链表的后边
				greatertail->next = cur;
				greatertail = greatertail->next;
			}
			cur = cur->next;
		}
		//合并链表，并释放两个头结点
		lesstail->next = greaterhead->next; 
		greatertail->next = NULL;

		pHead = lesshead->next;
		free(lesshead);
		free(greaterhead);

		return pHead;
	}
};