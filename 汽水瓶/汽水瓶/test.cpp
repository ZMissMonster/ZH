#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/fe298c55694f4ed39e256170ff2c205f?tpId=37&&tqId=21245&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
//������һ�������⣺��ĳ�̵�涨����������ˮƿ���Ի�һƿ��ˮ��С��������ʮ������ˮƿ���������Ի�����ƿ��ˮ�ȣ�������5ƿ���������£�����9����ƿ�ӻ�3ƿ��ˮ���ȵ�3ƿ���ģ������Ժ�4����ƿ�ӣ���3���ٻ�һƿ���ȵ���ƿ���ģ���ʱ��ʣ2����ƿ�ӡ�Ȼ�������ϰ��Ƚ����һƿ��ˮ���ȵ���ƿ���ģ������Ժ���3����ƿ�ӻ�һƿ���Ļ����ϰ塣���С��������n������ˮƿ�������Ի�����ƿ��ˮ�ȣ�
//�������� :
//�����ļ�������10��������ݣ�ÿ������ռһ�У�������һ��������n��1 <= n <= 100������ʾС�����ϵĿ���ˮƿ����n = 0��ʾ�����������ĳ���Ӧ��������һ�С�
//
//������� :
//����ÿ��������ݣ����һ�У���ʾ�����Ժȵ���ˮƿ�������һƿҲ�Ȳ��������0��
#include<iostream>
#include<string>
using namespace std;
int calculateNum(int num)
{
	//�ܶһ���
	int sum = 0;
	while (num > 1)
	{
		//ÿ��ƿ��һƿ
		int result = num / 3;
		//ʣ�಻����ƿ���ȱ���
		int reminder = num % 3;
		sum = sum + result;
		//��һ�ο��Զһ��Ŀ�ƿ
		num = result + reminder;
		if (num == 2)
		{
			++sum;
			break;
		}
	} 
	return sum;
} 
int main(){
	int number;
	while (cin >> number)
	{
		cout << calculateNum(number) << endl;
	} 
	return 0;
}