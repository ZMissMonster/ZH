#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/d8acfa0619814b2d98f12c071aef20d4?tpId=8&&tqId=11039&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
//��Ŀ����
//����һ���ַ����������һ���㷨���ж����Ƿ�Ϊһ���Ϸ������Ŵ���
//����һ���ַ���A�����ĳ���n���뷵��һ��boolֵ�������Ƿ�Ϊһ���Ϸ������Ŵ���
//����������
//"(()())", 6
//���أ�true
//����������
//"()a()()", 7
//���أ�false
//����������
//"()(()()", 7
//���أ�false

class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		stack<char> brackets;
		for (auto e : A)
		{
			switch (e)
			{
			case '(':
			{
						brackets.push(e);
						break;
			}
			case ')':
			{
						if (brackets.empty() || brackets.top() != '(')
						{
							return false;
						}
						else
						{
							brackets.pop();
						}
						break;
			}
			default:
				return false;
				break;
			}
		}
		return true;
	}
};