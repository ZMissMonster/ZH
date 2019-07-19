#define _CRT_SECURE_NO_WARNINGS 1
//链接：https://www.nowcoder.com/questionTerminal/5973a31d58234b068fa1fe34f7290855
//NowCoder每天要给许多客户写电子邮件。正如你所知，如果一封邮件中包含多个收件人，收件人姓名之间会用一个逗号和空格隔开；如果收件人姓名也包含空格或逗号，则姓名需要用双引号包含。
//现在给你一组收件人姓名，请你帮他生成相应的收件人列表。
//输入描述 :
//输入包含多组数据。
//
//每组数据的第一行是一个整数n(1≤n≤128)，表示后面有n个姓名。
//
//紧接着n行，每一行包含一个收件人的姓名。姓名长度不超过16个字符。
//输出描述 :
//对应每一组输入，输出一行收件人列表。
#include <iostream>
#include <string>
#include <cstdio>
int main()
{
	int n;
	while (std::cin >> n) //接收数字
	{
		std::cin.get(); //处理回车
		std::string name;
		for (int i = 0; i < n; i++) //名字分别处理
		{
			bool quote = false;
			std::getline(std::cin, name);
			if (name.find(',') != std::string::npos ||
				name.find(' ') != std::string::npos) //找到逗号或者空格，就要加双引号
			{
				quote = true;
			} 
			if(quote)
			{
					putchar('\"'); //putchar效率更高
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
				if (i == n - 1) //如果已经是最后一个字符串，那就补回车，否则加逗号和空格
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