#include <iostream>
#include <assert.h>
using namespace std;

template<class T>
class Vector
{
public:
	Vector(size_t capacity=10)
		:_array(new T[capacity])
		, _size(0)
		, _capacity(capacity)
	{}
	~Vector()
	{
		if (_array)
		{
			delete[] _array;
			_array = nullptr;
			_size = _capacity = 0;
		}
	}
	void PushBack(const T& x)//void PushBack(Vector<int>*this,const T& x)
	{
		//但是不能自动增容
		_array[_size] = x;
		++_size;
	}
	size_t Size()
	{
		return _size;
	}
	T operator[](size_t pos)//数组[]运算符重载
	{
		assert(pos < _size);
		return _array[pos];
	}
private:
	T* _array;
	size_t _size;
	size_t _capacity;
};

int main()
{
	Vector<int> v1;//类模板一定要显示实例化，否则没办法推演
	v1.PushBack(1);
	v1.PushBack(2);
	v1.PushBack(3);
	v1.PushBack(4);

	for (size_t i = 0; i < v1.Size(); ++i)
	{
		cout << v1[i] << " ";
		//cout << v1.operator[](i) << " ";
	}
	cout << endl;

	Vector<char> v2;
	v2.PushBack('a');
	v2.PushBack('b');
	v2.PushBack('c');
	v2.PushBack('d');
	for (size_t i = 0; i < v2.Size(); ++i)
	{
		cout << v2[i] << " ";
		//cout << v2.operator[](i) << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}


//template<class T1, class T2, ..., class Tn>
//class 类模板名
//{
//	// 类内成员定义
//};

//// 专门处理int的加法函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//// 通用加法函数
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // 与非函数模板类型完全匹配，不需要函数模板实例化
//	Add(1, 2.0); // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
//}

//// 专门处理int的加法函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//// 通用加法函数
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // 与非模板函数匹配，编译器不需要特化
//	Add<int>(1, 2); // 调用编译器特化的Add版本
//}

//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//int main(void)
//{
//	int a = 10;
//	double b = 20.0;
//	// 显式实例化
//	Add<int>(a, b);
//	return 0;
//}
//int main()
//{
//	int a1 = 10, a2 = 10;
//	double b1 = 10.0, b2 = 20.0;
//	Add(a1, a2);
//	Add(b1, b2);
//	return 0;
//}
//template<typename T>
//void Swap(T& left, T& right)
//{
//	T temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(char& left, char& right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}
//int main()
//{
//	double d1 = 2.0;
//	double d2 = 5.0;
//	Swap(d1, d2);
//	int i1 = 10;
//	int i2 = 20;
//	Swap(i1, i2);
//	char a = '0';
//	char b = '9';
//	Swap(a, b);
//	return 0;
//}
//int main()
//{
//	int a = 1, b = 2;
//	char c = 10, d = 20;
//	cout << a << " " << b << " " << c << " " << d << endl;
//	Swap(a, b);
//	Swap(c, d);
//	cout << a << " " << b << " " << c << " " << d << endl;
//	system("pause");
//	return 0;
//}


//// 饿汉模式
//// 优点：简单
//// 缺点：可能会导致进程启动慢，且如果有多个单例类对象实例启动顺序不确定。
//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		return &m_instance;
//	}
//private:
//	// 构造函数私有
//	Singleton(){};
//	// C++98 防拷贝
//	Singleton(Singleton const&);
//	Singleton& operator=(Singleton const&);
//	// or
//	// C++11
//	Singleton(Singleton const&) = delete;
//	Singleton& operator=(Singleton const&) = delete;
//	static Singleton m_instance;
//};
//Singleton Singleton::m_instance; // 在程序入口之前就完成单例对象的初始化


//// 懒汉
//// 优点：第一次使用实例对象时，创建对象。进程启动无负载。多个单例实例启动顺序自由控制。
//// 缺点：复杂
//#include <iostream>
//#include <mutex>
//#include <thread>
//using namespace std;
//class Singleton
//{
//public:
//	static Singleton* GetInstance() {
//		// 注意这里一定要使用Double-Check的方式加锁，才能保证效率和线程安全
//		if (nullptr == m_pInstance) {
//			m_mtx.lock();
//			if (nullptr == m_pInstance) {
//				m_pInstance = new Singleton();
//			}
//			m_mtx.unlock();
//		}
//		return m_pInstance;
//	}
//	// 实现一个内嵌垃圾回收类
//	class CGarbo {
//	public:
//		~CGarbo(){
//			if (Singleton::m_pInstance)
//				delete Singleton::m_pInstance;
//		}
//	};
//	// 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
//	static CGarbo Garbo;
//private:
//	// 构造函数私有
//	Singleton(){};
//	// 防拷贝
//	Singleton(Singleton const&);
//	Singleton& operator=(Singleton const&);
//	static Singleton* m_pInstance; // 单例对象指针
//	static mutex m_mtx; //互斥锁
//};
//Singleton* Singleton::m_pInstance = nullptr;
//Singleton::CGarbo Garbo;
//mutex Singleton::m_mtx;
//void func(int n)
//{
//	cout << Singleton::GetInstance() << endl;
//}
//// 多线程环境下演示上面GetInstance()加锁和不加锁的区别。
//int main()
//{
//	thread t1(func, 10);
//	thread t2(func, 10);
//	t1.join();
//	t2.join();
//	cout << Singleton::GetInstance() << endl;
//	cout << Singleton::GetInstance() << endl;
//}