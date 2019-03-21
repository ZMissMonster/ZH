//�����һ�㲻֧�ֿ������죬��������һ�ݶ����൱������һ��ָ��ָ��������ڴ�أ������������ȥ����Ļ����õ�����ͬһ���ڴ棬�ǻ���������
#pragma once

//ע�⣺ģ�岻֧�ַ������
template<class T, size_t N_Obj = 20>
class ObjectPool
{
public:
	ObjectPool() = default;//�������Լ�����һ�����캯��
	//������
	ObjectPool(const ObjectPool<T>&) = delete;//��������
	ObjectPool<T>& operator=(const ObjectPool<T>&) = delete;//operator��ֵ

	template<class INIT_T>//��ģ���ģ���Ա����
	T* New(const INIT_T& x = INIT_T())//��new��ʱ��ͳ�ʼ��
	{
		T* obj = nullptr;
		if (_freelist != nullptr)//��Ϊ�������ڴ����ֱ����
		{
			//�ڴ���ͷ�ĸ��ֽڴ���һ��ĵ�ַ
			void* next = *((void**)_freelist);//���;�������������ǿתΪ(int*)
			obj = (T*)_freelist;
			_freelist = next;
		}
		else//û���ڴ棬��Ҫ����������
		{
			if (_start == _finish)//�����û���ڴ棬��ϵͳ����
			{
				_start = (char*)malloc(sizeof(T)*N_Obj);
				
				//newʧ�ܣ����쳣
				//_start = nullptr;
				/*if (_start == nullptr)
				{
					throw std::bad_alloc();
				}
				_finish = _start + sizeof(T)*N_Obj;
			}*/

			//�ڴ�����ڴ�,ֱ��������
			obj = (T*)_start;
			_start += sizeof(T);
		}
		new(obj)T(x);//new�Ķ�λ���ʽ�������пռ���г�ʼ��
		return obj;
	}
	void Delete(T* ptr)
	{
		ptr->~T();//��ʾ�������������������ڴ�й©
		*(void**)ptr= _freelist;
		_freelist = ptr;
	}

private:
	char* _start=nullptr;//�����һ��ʼʲôҲû�У�����ȱʡֵ�Զ���ʼ��
	char* _finish = nullptr;//char*���ͣ�1���ü�һ���ֽ�

	void* _freelist = nullptr;
};

void TestObjectPool()
{
	ObjectPool<std::string> pool;
	std::string* p1 = pool.New("111");
	std::string* p2 = pool.New("222");
	cout << p1 << endl;
	cout << p2 << endl;
	pool.Delete(p1);
	pool.Delete(p2);

	std::string* p3 = pool.New("333");
	std::string* p4 = pool.New("444");
	std::string* p5 = pool.New("555");
	cout << p3 << endl;
	cout << p4 << endl;
	cout << p5 << endl;
}
#include <vector>
#include <time.h>

void BenchMark()//��������(��Ч���)��release��
{
	size_t n = 10000;
	
	std::vector<std::string*> v1;
	v1.reserve(n);
	size_t begin1 = clock();
	for (size_t i = 0; i < n; ++i)
	{
		v1.push_back(new std::string);
	}
	for (size_t i = 0; i < n; ++i)
	{
		free(v1[i]);
	}
	size_t end1 = clock();


	std::vector<std::string*> v2;
	v2.reserve(n); 
	size_t begin2 = clock();
	ObjectPool<std::string> pool;
	for (size_t i = 0; i < n; ++i)
	{
		v2.push_back(pool.New(""));
	}
	for (size_t i = 0; i < n; ++i)
	{
		pool.Delete(v2[i]);
	}
	size_t end2 = clock();

	cout << end1 - begin1 << endl;
	cout << end2 - begin2 << endl;

}