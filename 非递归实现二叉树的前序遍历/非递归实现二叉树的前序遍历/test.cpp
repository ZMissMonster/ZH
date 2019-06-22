#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode* left;//����
	struct TreeNode* right;//�Һ���
};

vector<int> preorderTraversal(TreeNode* root) 
{
	vector<int> res;//��Ž��
	//����ֱ�ӷ���
	if (!root){
		return;
	}
	stack<TreeNode*> bucket;//��ջ��ʱ�洢�Լ���֤˳��
	bucket.push(root);//�ȷŸ��ڵ�

	while (!bucket.empty())//��Ϊ�����ʾû�б�����
	{
		TreeNode* cur = bucket.top();//ָ��ָ��ջ��ջ��,��ʱֻ�и��ڵ�
		//�Ѹ����Ž�����
		res.push_back(cur->val);
		bucket.pop();

		//���η����Һ������ӣ���Ϊջ�ȳ����
		if (cur->right)
		{
			bucket.push(cur->left);
		}
		if (cur->left)
		{
			bucket.push(cur->left);
		}
	}
	return res;
}
