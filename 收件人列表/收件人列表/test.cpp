#define _CRT_SECURE_NO_WARNINGS 1
//���ӣ�https://www.nowcoder.com/questionTerminal/5973a31d58234b068fa1fe34f7290855
//NowCoderÿ��Ҫ�����ͻ�д�����ʼ�����������֪�����һ���ʼ��а�������ռ��ˣ��ռ�������֮�����һ�����źͿո����������ռ�������Ҳ�����ո�򶺺ţ���������Ҫ��˫���Ű�����
//���ڸ���һ���ռ����������������������Ӧ���ռ����б�
//�������� :
//��������������ݡ�
//
//ÿ�����ݵĵ�һ����һ������n(1��n��128)����ʾ������n��������
//
//������n�У�ÿһ�а���һ���ռ��˵��������������Ȳ�����16���ַ���
//������� :
//��Ӧÿһ�����룬���һ���ռ����б�
#include <iostream>
#include <string>
#include <cstdio>
int main()
{
	int n;
	while (std::cin >> n) //��������
	{
		std::cin.get(); //����س�
		std::string name;
		for (int i = 0; i < n; i++) //���ֱַ���
		{
			bool quote = false;
			std::getline(std::cin, name);
			if (name.find(',') != std::string::npos ||
				name.find(' ') != std::string::npos) //�ҵ����Ż��߿ո񣬾�Ҫ��˫����
			{
				quote = true;
			} 
			if(quote)
			{
					putchar('\"'); //putcharЧ�ʸ���
				} 
			std::cout << name;
				if (quote)
				{
					putchar('\"');
				}
				std::cout << name;
				if (quote)
				{
					putchar('\"');
				}
				if (i == n - 1) //����Ѿ������һ���ַ������ǾͲ��س�������Ӷ��źͿո�
				{
					putchar('\n');
				} 
				else
				{
					putchar(',');
					putchar(' ');
				}
		}
	} 
	return 0;
}