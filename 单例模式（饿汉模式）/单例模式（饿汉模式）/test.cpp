#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Configsingleton
{
public:
	//公有接口获取对象
	static Configsingleton& GetInstance()
	{
		return _sinst;
	}

private:
	//构造函数私有
	Configsingleton(const char*ip, int port)
		:_ip(ip)
		,_port(port)
	{
		//进行初始化工作
	}
	//Configsingleton()
	//{
	//	//进行初始化工作
	//}
	//防拷贝
	Configsingleton(const Configsingleton&) = delete;//拷贝构造函数
	Configsingleton& operator=(const Configsingleton&) = delete;//赋值运算符重载
	//成员变量,可以不要
	const char* _ip;
	int _port;
	//定义一个自己类型的对象（相当于全局的，但是此时受类域的限制）
	static Configsingleton _sinst;
};
//在类外初始化这个对象 _sinst
Configsingleton Configsingleton::_sinst("127.0.0.1", 80);
//Configsingleton Configsingleton::_sinst;