#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

void test_string()
{
	string s1("ello");
	s1.insert(0, 1,'h');
	cout << s1 << endl;
}
int main()
{
	test_string();
	system("pause");
	return 0;
}

//void TestString()
//{
//	string str;
//	str.push_back(' '); // 在str后插入空格
//	str.append("hello"); // 在str后追加一个字符"hello"
//	str += 'w'; // 在str后追加一个字符'b'
//	str += "orld"; // 在str后追加一个字符串"it"
//	cout << str << endl;
//	cout << str.c_str() << endl; // 以C语言的方式打印字符串
//// 获取file的后缀
//	string file("string.cpp");
//	size_t pos = file.rfind('.');
//	string suffix(file.substr(pos, file.size() - pos));
//	cout << suffix << endl;
//// npos是string里面的一个静态成员变量
//// static const size_t npos = -1;
//// 取出url中的域名
//	string url("http://www.cplusplus.com/reference/string/string/find/");
//	cout << url << endl;
//	size_t start = url.find("://");
//	if (start == string::npos)
//	{
//		cout << "invalid url" << endl;
//		return;
//	}
//	start += 3;
//	size_t finish = url.find('/', start);
//	string address = url.substr(start, finish - start);
//	cout << address << endl;
//// 删除url的协议前缀
//	pos = url.find("://");
//	url.erase(0, pos + 3);
//	cout << url << endl;
//}
//int main()
//{
//	TestString(); 
//	system("pause");
//	return 0;
//}

//void TestString()
//{
//	string s1("hello Bit");
//	const string s2("Hello Bit");
//	cout << s1 << " " << s2 << endl;
//	cout << s1[0] << " " << s2[0] << endl;
//	s1[0] = 'H';
//	cout << s1 << endl;
//	for (size_t i = 0; i < s1.size(); ++i)
//	{
//		cout << s1[i] << endl;
//	}
//	// s2[0] = 'h'; 代码编译失败，因为const类型对象不能修改
//}

//void test_string()
//{
//	string s1("hello,world");//叭逗号改为星号
//	//s1[5] = '*';
//	//cout << s1 << endl;
//	
//	//for (size_t i = 0; i < s1.size(); ++i)
//	//{
//	//	if (s1[i] == ',')
//	//	{
//	//		s1[i] = '*';
//	//	}
//	//}
//	//cout << s1 << endl;
//
//}
//int main()
//{
//	test_string();
//	system("pause");
//	return 0;
//}
//void test_string4()
//{
//	string s;
//// 将s中有效字符个数增加到10个，多出位置用'a'进行填充
//// “aaaaaaaaaa”
//	s.resize(10, 'a');
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//// 将s中有效字符个数增加到15个，多出位置用缺省值'\0'进行填充
//// "aaaaaaaaaa\0\0\0\0\0"
//// 注意此时s中有效字符个数已经增加到15个
//	s.resize(15);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//// 将s中有效字符个数缩小到5个
//	s.resize(5);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//}
//====================================================================================
//void TestString2()
//{
//	string s;
//	// 测试reserve是否会改变string中有效元素个数
//	s.reserve(100);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	// 测试reserve参数小于string的底层空间大小时，是否会将空间缩小
//	s.reserve(50);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;


	//string s("hello world");
	//cout << s<< endl;
	//cout << s.size() << endl;
	//cout << s.capacity() << endl;
	////s.resize(5);
	////s.resize(15, 'a');
	//cout << s << endl;
// 注意：string类对象支持直接用cin和cout进行输入和输出
//	string s1("hello");
//	cout << s1 << endl;
//	cout << s1.size() << endl;
//	cout << s1.length() << endl;
//	cout << s1.capacity() << endl;
//	cout << s1.max_size() << endl;
//	cout << endl;
//// 将s1中的字符串清空，注意清空时只是将size清0，不改变底层空间的大小
//	s1.clear();
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//	cout << endl;
//
//	string s;
////	size_t sz = 0;
//	cout << "making s grow:\n";
//	s.reserve(100);
//	size_t sz = s.capacity();
//	for (int i = 0; i < 100; ++i)
//	{
//		s.push_back('c');
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "capacity changed: " << sz << '\n';
//		}
//	}
//}


//int main()
//{
//	TestString2();
//	//test_string4();
//	system("pause");
//	return 0;
//}

//"1234"字符串转整形（遍历字符串）
//方法一
//int StrToInt1(string str)
//{
//	int value = 0;
//	for (size_t i = 0; i < str.size(); ++i)
//	{
//		value *= 10;
//		value += str[i]-'0';
//
//		/*cout << str[i] << " ";
//		cout << str.operator[](i) << " ";*/
//	}
//	//cout << endl;
//	//return 0;
//	return value;
//}
//void test_string3()
//{
//	cout << StrToInt1("1234") << endl;
//}
//int main()
//{
//	test_string3();
//	system("pause");
//	return 0;
//}
//方法二：迭代器--不破坏封装的情况下去访问容器
//int StrToInt2(string str)
//{
//	int value = 0;
//	
//	string::iterator it = str.begin();
//	while (it != str.end())
//	{
//		value *= 10;
//		value += (*it - '0');
//		++it;
//	}
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	vector<int>::iterator vit = v.begin();
//	while (vit != v.end())
//	{
//		cout << *vit << " ";
//		++vit;
//	}
//
//	list<int> l;
//	l.push_back(10);
//	l.push_back(20);
//	l.push_back(30);
//	list<int>::iterator lit = l.begin();
//	while (lit != l.end())
//	{
//		cout << *lit <<" ";
//		++lit;
//	}
//	return value;
//}
//void test_string4()
//{
//	cout << StrToInt2("1234") << endl;
//}
//int main()
//{
//	test_string4();
//	system("pause");
//	return 0;
//}



//void test_string1()
//{
//	//初始化
//	string s1("hello");
//	string s2(s1);
//	string s3 = "world";
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//
//	string file("file.cpp");
//	string suffix(file, 4, 4);//从第四个位置开始取4个字符
//	cout << suffix << endl;
//
//	string path("c:\\test.c", 3);
//	cout << path << endl;//用前n个字符构造
//}
//int main()
//{
//	test_string3();
//	//test_string1();
//	//TestString();
//	system("pause");
//	return 0;
//}




//void TestString()
//{
//	string s1; // 构造空的string类对象s1
//	string s2("hello bit"); // 用C格式字符串构造string类对象s2
//	string s3(10, 'a'); // 用10个字符'a'构造string类对象s3
//	string s4(s2); // 拷贝构造s4
//	string s5(s3, 5); // 用s3中前5个字符构造string对象s5
//	string s6("world");
//	s1 = s6;//赋值
//}
//int main()
//{
//	TestString();
//	system("pause");
//	return 0;
//}