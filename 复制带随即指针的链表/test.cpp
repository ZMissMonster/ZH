#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode-cn.com/problems/copy-list-with-random-pointer/
//����һ������ÿ���ڵ����һ���������ӵ����ָ�룬��ָ�����ָ�������е��κνڵ��սڵ㡣Ҫ�󷵻��������������
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
//��ÿ����㶼������������һ��λ�ã���ʱ���µ�random�Ǿɵ�random����һ�����ٽ��в�⣡
class Solution {
public:
	Node* copyRandomList(Node* head) {
		//1.���ƽ��
		class Node* cur = head;
		while (cur)//cur��Ϊ�վ��ҳ�������һ����㣬���м����cur�Ŀ���,����ÿһ�����
		{
			class Node* next = cur->next;
			class Node* copy = (class Node*)malloc(sizeof(class Node));
			copy->val = cur->val;
			cur->next = copy;
			copy->next = next;
			cur = next;
		}
			//2.��random:�µ�random�Ǿɵ�random����һ��
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
			//3.�������
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