#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <mutex>
using namespace std;
class Configsingleton
{
public:
	static Configsingleton* GetInstance()
	{
		//˫�ؼ��
		if (_psinst == nullptr)
		{
			//����
			_mutex.lock();
			if (_psinst == nullptr)
			{
				_psinst = new Configsingleton;//��һ�ε���ʱ�����
			}
			_mutex.unlock();//����
		}
		return _psinst;
	}

private:
	//���캯��˽��
	Configsingleton()
	{
		//���г�ʼ������}
	}

	//��������
	~Configsingleton()
	{}


	//������
	Configsingleton(const Configsingleton&) = delete;//�������캯��
	Configsingleton& operator=(const Configsingleton&) = delete;//��ֵ���������

	//����һ���Լ����͵Ķ����൱��ȫ�ֵģ����Ǵ�ʱ����������ƣ�
	static Configsingleton* _psinst;
	static mutex _mutex;
};
//�������ʼ��
Configsingleton* Configsingleton::_psinst;
mutex Configsingleton::_mutex;