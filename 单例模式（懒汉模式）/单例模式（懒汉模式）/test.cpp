#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <mutex>
using namespace std;
class Configsingleton
{
public:
	static Configsingleton* GetInstance()
	{
		//双重检查
		if (_psinst == nullptr)
		{
			//加锁
			_mutex.lock();
			if (_psinst == nullptr)
			{
				_psinst = new Configsingleton;//第一次调用时，如果
			}
			_mutex.unlock();//解锁
		}
		return _psinst;
	}

private:
	//构造函数私有
	Configsingleton()
	{
		//进行初始化工作}
	}

	//析构函数
	~Configsingleton()
	{}


	//防拷贝
	Configsingleton(const Configsingleton&) = delete;//拷贝构造函数
	Configsingleton& operator=(const Configsingleton&) = delete;//赋值运算符重载

	//定义一个自己类型的对象（相当于全局的，但是此时受类域的限制）
	static Configsingleton* _psinst;
	static mutex _mutex;
};
//在类外初始化
Configsingleton* Configsingleton::_psinst;
mutex Configsingleton::_mutex;