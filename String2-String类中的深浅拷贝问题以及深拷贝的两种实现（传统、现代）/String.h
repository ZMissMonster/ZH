#define _CRT_SECURE_NO_WARNINGS 
#include  <iostream>
using namespace std;
#pragma once



//浅拷贝
namespace CPP
{
	class String
	{
	public:
		//推荐使用全缺省的带参的构造函数初始化
		String(const char* str="")//不能给nullptr，因为strlen会崩溃
			:_str(new char[strlen(str)+1])
		{
			strcpy(_str, str);// while (*dst++ = *src++)'\0'已经拷贝过去了
		}

		//拷贝构造---浅拷贝
		String(const String& s)
			:_str(s._str)
		{}
		//赋值
		String& operator=(const String& s)
		{
			if (this != &s)
			{
				_str = s._str;
			}
			return *this;
		}
		//析构函数
		~String()
		{
			if (_str)
			{
				delete[] _str;
			}
		}
		//输出c形式的字符串
		char* c_str()
		{
			return _str;
		}
		//计算大小size
		size_t Size()
		{
			return strlen(_str);
		}
		char& operator[](size_t pos)//返回别名，除了可读还可写
		{
			return _str[pos];
		}
	private:
		char* _str;
	};
	void TestString1()
	{
		String s1("hello");
		String s2(s1);//未写拷贝构造函数时，使用默认的，为浅拷贝（值拷贝）
		cout << s2.c_str() << endl;

		String s3("world");
		s2 = s3;
		cout << s2.c_str() << endl;
	}
}

//深浅拷贝---传统写法
namespace CPP
{
	class String
	{
	public:
		////无参的构造函数
		//String()
		//	//:_str(nullptr)//不可取，会有空指针问题
		//	:_str(new char[1])
		//{
		//	_str[0] = '\0';
		//}

		////带参的构造函数
		//String(const char* str)
		//	:_str(new char[strlen(str)+1])
		//{
		//	strcpy(_str, str);// while (*dst++ = *src++)'\0'已经拷贝过去了
		//}

		//推荐使用全缺省的带参的构造函数初始化
		String(const char* str="")//不能给nullptr，因为strlen会崩溃
			:_str(new char[strlen(str)+1])
		{
			strcpy(_str, str);// while (*dst++ = *src++)'\0'已经拷贝过去了
		}

		//深拷贝 
		//s3(s2) s3是this指针，s2是s
		String(const String& s)
		{
			_str = new char[strlen(s._str) + 1];//_str是this指针，新开一个s2大小的空间
			strcpy(_str, s._str);//把s2中的各个字节拷贝给this(s3)
		}

		//赋值 s3=s2
		String& operator=(const String& s)
		{
			if (this != &s)//判断不要自己给自己赋值
			{
				delete[] _str;//因为不知道空间大小，为避免内存泄漏，先释放掉s3原来的空间
				_str = new char[strlen(s._str) + 1];
				strcpy(_str, s._str);
			}
			return *this;
		}

		//析构函数
		~String()
		{
			if (_str)
			{
				delete[] _str;
			}
		}

		//输出c形式的字符串
		char* c_str()
		{
			return _str;
		}
		//计算大小size
		size_t Size()
		{
			return strlen(_str);
		}

		char& operator[](size_t pos)//返回别名，除了可读还可写
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
		cout << s1.c_str() << endl;//s1是一个空对象，它的_str是一个空指针
		cout << s2.c_str() << endl;

		for (size_t i = 0; i < s2.Size(); ++i)
		{
			cout << s2[i]<<" ";
		}
		cout << endl;

		String s3(s2);//未写拷贝构造函数，使用默认的，即为浅拷贝（值拷贝）
		cout << s3.c_str() << endl;

		String s4("world");
		s3 = s4;
		cout << s3.c_str() << endl;
	}
}


//深浅拷贝---现代写法
namespace CPP
{
	class String
	{
	public:
		//推荐使用全缺省的带参的构造函数初始化
		String(const char* str="")//不能给nullptr，因为strlen会崩溃
			:_str(new char[strlen(str)+1])
		{
			strcpy(_str, str);// while (*dst++ = *src++)'\0'已经拷贝过去了
		}

		//深拷贝 
		//s3(s2) tmp开辟一个和s2相同的空间，拷过来，s2是s
		String(const String& s)
			:_str(nullptr)
		{
			String tmp(s._str);//调构造
			swap(_str, tmp._str);
		}

		////赋值 s3=s2
		//String& operator=(const String& s)
		//{
		//	if (this != &s)//判断不要自己给自己赋值
		//	{
		//		String tmp(s._str);
		//		strcpy(_str, tmp._str);
		//	}
		//	return *this;
		//}
		//更简单的赋值
		String& operator=(String s)
		{
			swap(_str, s._str);
			return *this;
		}

		//析构函数
		~String()
		{
			if (_str)
			{
				delete[] _str;
			}
		}

		//输出c形式的字符串
		char* c_str()
		{
			return _str;
		}
		//计算大小size
		size_t Size()
		{
			return strlen(_str);
		}

		char& operator[](size_t pos)//返回别名，除了可读还可写
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
		cout << s1.c_str() << endl;//s1是一个空对象，它的_str是一个空指针
		cout << s2.c_str() << endl;

		for (size_t i = 0; i < s2.Size(); ++i)
		{
			cout << s2[i]<<" ";
		}
		cout << endl;

		String s3(s2);//未写拷贝构造函数，使用默认的，即为浅拷贝（值拷贝）
		cout << s3.c_str() << endl;

		String s4("world");
		s3 = s4;
		cout << s3.c_str() << endl;
	}
}