#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode-cn.com/problems/copy-list-with-random-pointer/
//给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。要求返回这个链表的深拷贝。
#include <stdio.h>
#include <iostream>
using namespace std;

class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node() 
	{}
	Node(int _val, Node* _next, Node* _random) {
		val = _val;
		next = _next;
		random = _random;
	}
};
//把每个结点都复制在它的下一个位置，此时，新的random是旧的random的下一个，再进行拆解！
class Solution {
public:
	Node* copyRandomList(Node* head) {
		//1.复制结点
		class Node* cur = head;
		while (cur)//cur不为空就找出它的下一个结点，在中间加入cur的拷贝,复制每一个结点
		{
			class Node* next = cur->next;
			class Node* copy = (class Node*)malloc(sizeof(class Node));
			copy->val = cur->val;
			cur->next = copy;
			copy->next = next;
			cur = next;
		}
			//2.置random:新的random是旧的random的下一个
		cur = head;
		while (cur)
		{
			class Node* copy = cur->next;
			if (cur->random)
			{
				copy->random = cur->random->next;
			}
			else
			{
				copy->random = nullptr;
			}
			cur = copy->next;
		}
			//3.拆解链表
		class Node* copyhead = nullptr, *copytail = nullptr;
		cur = head;
		while (cur)
		{
			class Node* copy = cur->next;
			class Node* next = copy->next;
			if (copytail == nullptr)
			{
				copyhead = copytail = copy;
			}
			else
			{
				copytail->next = copy;
				copytail = copytail->next;
			}
			cur->next = next;
			cur = next;
		}
		return copyhead;
	}
};