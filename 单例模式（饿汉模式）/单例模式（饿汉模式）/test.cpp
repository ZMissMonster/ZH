#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Configsingleton
{
public:
	//���нӿڻ�ȡ����
	static Configsingleton& GetInstance()
	{
		return _sinst;
	}

private:
	//���캯��˽��
	Configsingleton(const char*ip, int port)
		:_ip(ip)
		,_port(port)
	{
		//���г�ʼ������
	}
	//Configsingleton()
	//{
	//	//���г�ʼ������
	//}
	//������
	Configsingleton(const Configsingleton&) = delete;//�������캯��
	Configsingleton& operator=(const Configsingleton&) = delete;//��ֵ���������
	//��Ա����,���Բ�Ҫ
	const char* _ip;
	int _port;
	//����һ���Լ����͵Ķ����൱��ȫ�ֵģ����Ǵ�ʱ����������ƣ�
	static Configsingleton _sinst;
};
//�������ʼ��������� _sinst
Configsingleton Configsingleton::_sinst("127.0.0.1", 80);
//Configsingleton Configsingleton::_sinst;