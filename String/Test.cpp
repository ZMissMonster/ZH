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
//	str.push_back(' '); // ��str�����ո�
//	str.append("hello"); // ��str��׷��һ���ַ�"hello"
//	str += 'w'; // ��str��׷��һ���ַ�'b'
//	str += "orld"; // ��str��׷��һ���ַ���"it"
//	cout << str << endl;
//	cout << str.c_str() << endl; // ��C���Եķ�ʽ��ӡ�ַ���
//// ��ȡfile�ĺ�׺
//	string file("string.cpp");
//	size_t pos = file.rfind('.');
//	string suffix(file.substr(pos, file.size() - pos));
//	cout << suffix << endl;
//// npos��string�����һ����̬��Ա����
//// static const size_t npos = -1;
//// ȡ��url�е�����
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
//// ɾ��url��Э��ǰ׺
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
//	// s2[0] = 'h'; �������ʧ�ܣ���Ϊconst���Ͷ������޸�
//}

//void test_string()
//{
//	string s1("hello,world");//�ȶ��Ÿ�Ϊ�Ǻ�
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
//// ��s����Ч�ַ��������ӵ�10�������λ����'a'�������
//// ��aaaaaaaaaa��
//	s.resize(10, 'a');
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//// ��s����Ч�ַ��������ӵ�15�������λ����ȱʡֵ'\0'�������
//// "aaaaaaaaaa\0\0\0\0\0"
//// ע���ʱs����Ч�ַ������Ѿ����ӵ�15��
//	s.resize(15);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//// ��s����Ч�ַ�������С��5��
//	s.resize(5);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	cout << s << endl;
//}
//====================================================================================
//void TestString2()
//{
//	string s;
//	// ����reserve�Ƿ��ı�string����ЧԪ�ظ���
//	s.reserve(100);
//	cout << s.size() << endl;
//	cout << s.capacity() << endl;
//	// ����reserve����С��string�ĵײ�ռ��Сʱ���Ƿ�Ὣ�ռ���С
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
// ע�⣺string�����֧��ֱ����cin��cout������������
//	string s1("hello");
//	cout << s1 << endl;
//	cout << s1.size() << endl;
//	cout << s1.length() << endl;
//	cout << s1.capacity() << endl;
//	cout << s1.max_size() << endl;
//	cout << endl;
//// ��s1�е��ַ�����գ�ע�����ʱֻ�ǽ�size��0�����ı�ײ�ռ�Ĵ�С
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

//"1234"�ַ���ת���Σ������ַ�����
//����һ
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
//��������������--���ƻ���װ�������ȥ��������
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
//	//��ʼ��
//	string s1("hello");
//	string s2(s1);
//	string s3 = "world";
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//
//	string file("file.cpp");
//	string suffix(file, 4, 4);//�ӵ��ĸ�λ�ÿ�ʼȡ4���ַ�
//	cout << suffix << endl;
//
//	string path("c:\\test.c", 3);
//	cout << path << endl;//��ǰn���ַ�����
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
//	string s1; // ����յ�string�����s1
//	string s2("hello bit"); // ��C��ʽ�ַ�������string�����s2
//	string s3(10, 'a'); // ��10���ַ�'a'����string�����s3
//	string s4(s2); // ��������s4
//	string s5(s3, 5); // ��s3��ǰ5���ַ�����string����s5
//	string s6("world");
//	s1 = s6;//��ֵ
//}
//int main()
//{
//	TestString();
//	system("pause");
//	return 0;
//}