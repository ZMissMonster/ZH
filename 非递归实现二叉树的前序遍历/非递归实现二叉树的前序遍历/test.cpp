#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode* left;//左孩子
	struct TreeNode* right;//右孩子
};

vector<int> preorderTraversal(TreeNode* root) 
{
	vector<int> res;//存放结果
	//空树直接返回
	if (!root){
		return;
	}
	stack<TreeNode*> bucket;//用栈暂时存储以及保证顺序
	bucket.push(root);//先放根节点

	while (!bucket.empty())//不为空则表示没有遍历完
	{
		TreeNode* cur = bucket.top();//指针指向栈的栈顶,此时只有根节点
		//把根结点放进数组
		res.push_back(cur->val);
		bucket.pop();

		//依次放入右孩子左孩子，因为栈先出后进
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
