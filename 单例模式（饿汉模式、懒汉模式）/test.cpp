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
		//���ǲ����Զ�����
		_array[_size] = x;
		++_size;
	}
	size_t Size()
	{
		return _size;
	}
	T operator[](size_t pos)//����[]���������
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
	Vector<int> v1;//��ģ��һ��Ҫ��ʾʵ����������û�취����
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
//class ��ģ����
//{
//	// ���ڳ�Ա����
//};

//// ר�Ŵ���int�ļӷ�����
//int Add(int left, int right)
//{
//	return left + right;
//}
//// ͨ�üӷ�����
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // ��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
//	Add(1, 2.0); // ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add����
//}

//// ר�Ŵ���int�ļӷ�����
//int Add(int left, int right)
//{
//	return left + right;
//}
//// ͨ�üӷ�����
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // ���ģ�庯��ƥ�䣬����������Ҫ�ػ�
//	Add<int>(1, 2); // ���ñ������ػ���Add�汾
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
//	// ��ʽʵ����
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


//// ����ģʽ
//// �ŵ㣺��
//// ȱ�㣺���ܻᵼ�½�����������������ж�����������ʵ������˳��ȷ����
//class Singleton
//{
//public:
//	static Singleton* GetInstance()
//	{
//		return &m_instance;
//	}
//private:
//	// ���캯��˽��
//	Singleton(){};
//	// C++98 ������
//	Singleton(Singleton const&);
//	Singleton& operator=(Singleton const&);
//	// or
//	// C++11
//	Singleton(Singleton const&) = delete;
//	Singleton& operator=(Singleton const&) = delete;
//	static Singleton m_instance;
//};
//Singleton Singleton::m_instance; // �ڳ������֮ǰ����ɵ�������ĳ�ʼ��


//// ����
//// �ŵ㣺��һ��ʹ��ʵ������ʱ���������󡣽��������޸��ء��������ʵ������˳�����ɿ��ơ�
//// ȱ�㣺����
//#include <iostream>
//#include <mutex>
//#include <thread>
//using namespace std;
//class Singleton
//{
//public:
//	static Singleton* GetInstance() {
//		// ע������һ��Ҫʹ��Double-Check�ķ�ʽ���������ܱ�֤Ч�ʺ��̰߳�ȫ
//		if (nullptr == m_pInstance) {
//			m_mtx.lock();
//			if (nullptr == m_pInstance) {
//				m_pInstance = new Singleton();
//			}
//			m_mtx.unlock();
//		}
//		return m_pInstance;
//	}
//	// ʵ��һ����Ƕ����������
//	class CGarbo {
//	public:
//		~CGarbo(){
//			if (Singleton::m_pInstance)
//				delete Singleton::m_pInstance;
//		}
//	};
//	// ����һ����̬��Ա�������������ʱ��ϵͳ���Զ������������������Ӷ��ͷŵ�������
//	static CGarbo Garbo;
//private:
//	// ���캯��˽��
//	Singleton(){};
//	// ������
//	Singleton(Singleton const&);
//	Singleton& operator=(Singleton const&);
//	static Singleton* m_pInstance; // ��������ָ��
//	static mutex m_mtx; //������
//};
//Singleton* Singleton::m_pInstance = nullptr;
//Singleton::CGarbo Garbo;
//mutex Singleton::m_mtx;
//void func(int n)
//{
//	cout << Singleton::GetInstance() << endl;
//}
//// ���̻߳�������ʾ����GetInstance()�����Ͳ�����������
//int main()
//{
//	thread t1(func, 10);
//	thread t2(func, 10);
//	t1.join();
//	t2.join();
//	cout << Singleton::GetInstance() << endl;
//	cout << Singleton::GetInstance() << endl;
//}