#define _CRT_SECURE_NO_WARNINGS 
#include  <iostream>
using namespace std;
#pragma once



//ǳ����
namespace CPP
{
	class String
	{
	public:
		//�Ƽ�ʹ��ȫȱʡ�Ĵ��εĹ��캯����ʼ��
		String(const char* str="")//���ܸ�nullptr����Ϊstrlen�����
			:_str(new char[strlen(str)+1])
		{
			strcpy(_str, str);// while (*dst++ = *src++)'\0'�Ѿ�������ȥ��
		}

		//��������---ǳ����
		String(const String& s)
			:_str(s._str)
		{}
		//��ֵ
		String& operator=(const String& s)
		{
			if (this != &s)
			{
				_str = s._str;
			}
			return *this;
		}
		//��������
		~String()
		{
			if (_str)
			{
				delete[] _str;
			}
		}
		//���c��ʽ���ַ���
		char* c_str()
		{
			return _str;
		}
		//�����Сsize
		size_t Size()
		{
			return strlen(_str);
		}
		char& operator[](size_t pos)//���ر��������˿ɶ�����д
		{
			return _str[pos];
		}
	private:
		char* _str;
	};
	void TestString1()
	{
		String s1("hello");
		String s2(s1);//δд�������캯��ʱ��ʹ��Ĭ�ϵģ�Ϊǳ������ֵ������
		cout << s2.c_str() << endl;

		String s3("world");
		s2 = s3;
		cout << s2.c_str() << endl;
	}
}

//��ǳ����---��ͳд��
namespace CPP
{
	class String
	{
	public:
		////�޲εĹ��캯��
		//String()
		//	//:_str(nullptr)//����ȡ�����п�ָ������
		//	:_str(new char[1])
		//{
		//	_str[0] = '\0';
		//}

		////���εĹ��캯��
		//String(const char* str)
		//	:_str(new char[strlen(str)+1])
		//{
		//	strcpy(_str, str);// while (*dst++ = *src++)'\0'�Ѿ�������ȥ��
		//}

		//�Ƽ�ʹ��ȫȱʡ�Ĵ��εĹ��캯����ʼ��
		String(const char* str="")//���ܸ�nullptr����Ϊstrlen�����
			:_str(new char[strlen(str)+1])
		{
			strcpy(_str, str);// while (*dst++ = *src++)'\0'�Ѿ�������ȥ��
		}

		//��� 
		//s3(s2) s3��thisָ�룬s2��s
		String(const String& s)
		{
			_str = new char[strlen(s._str) + 1];//_str��thisָ�룬�¿�һ��s2��С�Ŀռ�
			strcpy(_str, s._str);//��s2�еĸ����ֽڿ�����this(s3)
		}

		//��ֵ s3=s2
		String& operator=(const String& s)
		{
			if (this != &s)//�жϲ�Ҫ�Լ����Լ���ֵ
			{
				delete[] _str;//��Ϊ��֪���ռ��С��Ϊ�����ڴ�й©�����ͷŵ�s3ԭ���Ŀռ�
				_str = new char[strlen(s._str) + 1];
				strcpy(_str, s._str);
			}
			return *this;
		}

		//��������
		~String()
		{
			if (_str)
			{
				delete[] _str;
			}
		}

		//���c��ʽ���ַ���
		char* c_str()
		{
			return _str;
		}
		//�����Сsize
		size_t Size()
		{
			return strlen(_str);
		}

		char& operator[](size_t pos)//���ر��������˿ɶ�����д
		{
			return _str[pos];
		}
	private:
		char* _str;
	};
	void TestString1()
	{
		String s1;
		String s2("hello");
		cout << s1.c_str() << endl;//s1��һ���ն�������_str��һ����ָ��
		cout << s2.c_str() << endl;

		for (size_t i = 0; i < s2.Size(); ++i)
		{
			cout << s2[i]<<" ";
		}
		cout << endl;

		String s3(s2);//δд�������캯����ʹ��Ĭ�ϵģ���Ϊǳ������ֵ������
		cout << s3.c_str() << endl;

		String s4("world");
		s3 = s4;
		cout << s3.c_str() << endl;
	}
}


//��ǳ����---�ִ�д��
namespace CPP
{
	class String
	{
	public:
		//�Ƽ�ʹ��ȫȱʡ�Ĵ��εĹ��캯����ʼ��
		String(const char* str="")//���ܸ�nullptr����Ϊstrlen�����
			:_str(new char[strlen(str)+1])
		{
			strcpy(_str, str);// while (*dst++ = *src++)'\0'�Ѿ�������ȥ��
		}

		//��� 
		//s3(s2) tmp����һ����s2��ͬ�Ŀռ䣬��������s2��s
		String(const String& s)
			:_str(nullptr)
		{
			String tmp(s._str);//������
			swap(_str, tmp._str);
		}

		////��ֵ s3=s2
		//String& operator=(const String& s)
		//{
		//	if (this != &s)//�жϲ�Ҫ�Լ����Լ���ֵ
		//	{
		//		String tmp(s._str);
		//		strcpy(_str, tmp._str);
		//	}
		//	return *this;
		//}
		//���򵥵ĸ�ֵ
		String& operator=(String s)
		{
			swap(_str, s._str);
			return *this;
		}

		//��������
		~String()
		{
			if (_str)
			{
				delete[] _str;
			}
		}

		//���c��ʽ���ַ���
		char* c_str()
		{
			return _str;
		}
		//�����Сsize
		size_t Size()
		{
			return strlen(_str);
		}

		char& operator[](size_t pos)//���ر��������˿ɶ�����д
		{
			return _str[pos];
		}
	private:
		char* _str;
	};
	void TestString1()
	{
		String s1;
		String s2("hello");
		cout << s1.c_str() << endl;//s1��һ���ն�������_str��һ����ָ��
		cout << s2.c_str() << endl;

		for (size_t i = 0; i < s2.Size(); ++i)
		{
			cout << s2[i]<<" ";
		}
		cout << endl;

		String s3(s2);//δд�������캯����ʹ��Ĭ�ϵģ���Ϊǳ������ֵ������
		cout << s3.c_str() << endl;

		String s4("world");
		s3 = s4;
		cout << s3.c_str() << endl;
	}
}