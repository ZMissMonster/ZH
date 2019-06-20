#define _CRT_SECURE_NO_WARNINGS 1
//atoi(表示 ascii to integer)是把字符串转换成整型数的一个函数.
//atoi()函数会扫描参数 nptr字符串，跳过前面的空白字符（例如空格，tab缩进等，可以通过isspace()函数来检测），直到遇上数字或正负符号才开始做转换，而再遇到非数字或字符串结束时('\0')才结束转换，并将结果返回。如果 nptr不能转换成 int 或者 nptr为空字符串，那么将返回0
//我们在模拟实现atoi函数时, 要注意以下几点:
//1.字符串之前的空白问题
//2.正负号
//3.字符串为空时
//4.被转换的数字过于大（正溢出、负溢出）
//5.其他, 无法转换的情况(全是字母....之类的)
#include <iostream>
#include <assert.h>
#include <stdlib.h>
using namespace std;

enum
{
	vaild,//有效=0
	invaild,//无效=1
};
int flag = vaild;//默认有效
int my_atoi(const char* ptr)
{
	long long ret = 0;
	int symbol = 1;//符号表示正负
	//断言ptr != NULL
	assert(ptr);
	//判断空字符
	if (*ptr == '\0')
	{
		flag = invaild;
		return 0;
	}
	//去掉空格、制表符
	while(isspace(*ptr))
	{
		ptr++;
	}
	//符号位判断
	if (*ptr == '-')
	{
		symbol = -1;
		ptr++;
	}
	else if (*ptr == '+')
	{
		ptr++;
	}
	else if (((*ptr <= '0') && (*ptr >= '9')))//非法字符
	{
		flag = invaild;
		return 0;
	}
	//各种异常处理完毕，开始转换
	while ((*ptr != '\0') && (*ptr >= '0') && (*ptr <= '9'))
	{
		ret = (ret * 10 + *ptr - '0');
		ptr++;
	}
	//加上符号
	ret *= symbol;
	//检测溢出情况
	//int 0111 1111 1111 1111 1111 1111 1111 1111 正溢出
	//     7    f    f    f    f    f    f    f
	//    1000 0000 0000 0000 0000 0000 0000 0000 负溢出
	//      8     0   0   0     0    0    0    0
	if (((ret > 0x7fffffff) && (1 == symbol)) ||
		(ret < (signed int)0x80000000) && (-1 == symbol)){
		flag = invaild;
		return 0;
	}
	//ret合法
	flag = vaild;
	cout << ret << endl;
}
//打印atoi函数状态
void PrintState(){
	if (flag){
		cout << "异常" << endl;
	}
	else{
		cout<< "正常" << endl;
	}
}
//测试函数
int main()
{
	my_atoi("1234");
	PrintState();
	my_atoi("-1234");
	PrintState();
	my_atoi("!!!");
	PrintState();
	my_atoi("");
	PrintState();
	my_atoi("   1234aaaa");
	PrintState();
	my_atoi("1234aaaa");
	PrintState();

	system("pause");
	return 0;
}