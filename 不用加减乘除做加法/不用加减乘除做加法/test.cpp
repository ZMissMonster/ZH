#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/questionTerminal/59ac416b4b944300b617d4f7f111b215
//дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ��+��-��*��/����������š�

//���ֵ���ӿ���ת��Ϊ�����Ƶļӷ���ע��ÿһλ������λ����
// ����������൱��ÿһλ��ӣ��������ǽ�λ��
//���������룬������һλ���൱����ý�λ��
//�����������Ľ�����

class Solution {
public:
	int Add(int num1, int num2)
	{
		while (num2 != 0){
			int sum = num1 ^ num2;
			int carray = (num1 & num2) << 1;
			num1 = sum;
			num2 = carray;
		}
		return num1;
	}
};