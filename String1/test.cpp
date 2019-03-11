#include <iostream>
#include <string>
using namespace std;

//void test_string()
//{
//	string s1("hello");
//	string s2("world");
//	cout << s1 << "--" << s2 << endl;
//	s1.swap(s2);//单纯地成员变量的交换，指针交换，代价小
//	cout << s1 << "--" << s2 << endl;
//	swap(s1, s2); //产生了一个临时对象，拷贝构造，再赋值，再赋值，代价大，效率低
//	cout << s1 << "--" << s2 << endl;
//}
//void test_string1()
//{
//	string url = "https://blog.csdn.net/Miss_Monster";
//	cout << url << endl;
//	//从0开始的5个字符替换为"http"，但是代价较大。
//	//如果不是一等一替换，字符需要一个一个挪动一次位置
//	url.replace(0, 5, "http");
//	cout <<"替换后为："<< url << endl;
//	cout << endl;
//
//
//	url[5] = '\0';//将url的第五个字符改为'\0'
//	cout << url << endl;//cout遇到'\0'不会停止
//	cout <<"C形式的字符串输出为："<< url.c_str() << endl;
//	printf("printf输出%s\n", url.c_str());//C形式的字符串是以'\0'结束
//	cout << endl;
//}
//void test_string2()
//{
//	string file = "test.cpp";
//	/*硬编码(写死的生硬的编码)，从字符串的第4个位置开始取4个字符
//	一旦改变字符串，或者字符串很长，适用性就不普遍了，这样就不可取*/
//	string suffix(file, 4, 4);
//	cout << suffix << endl;
//
//	size_t pos = file.find('.');//如果找到了就返回第一次出现的位置
//	if (pos != string::npos)//否则返回npos（npos是它的一个静态成员的const变量，npos=-1）
//	{
//		string suffix(file, pos, file.size() - pos);
//		cout << suffix << endl;
//	}
//}
string getfilesuffix(const string& file)
{
	//size_t pos = file.find('.'); //返回第一次出现的位置
	size_t pos = file.rfind('.');  //返回最后一次出现的位置

	string suffix;
	if (pos != string::npos)
	{
		//suffix = file.substr(pos);	//取到最后
		suffix = file.substr(pos, file.size() - pos);//根据算出要取出的位数取
	}
	return suffix;
}
void test_string()
{
	cout << getfilesuffix("test.cpp") << endl;
	cout << getfilesuffix("test.c") << endl;

	cout << getfilesuffix("test.tar.zip") << endl;//若为这种形式，则用rfind找最后一个后缀

	//.zip
	const string file = "test.cpp.tar.zip";
	size_t pos = file.rfind('.'); //最后一次出现的位置
	string suffix;
	if (pos != string::npos)
	{
		suffix = file.substr(pos, file.size() - pos);
	}
	cout << suffix << endl;

	//.tar
	size_t prevpos = file.rfind('.', pos - 1);//从pos-1的位置上倒着找
	if (pos != string::npos)
	{
		suffix = file.substr(prevpos, pos - prevpos);
	}
	cout << suffix << endl;

	//找域名
	string url("https://blog.csdn.net/Miss_Monster");
	cout << url << endl;
	size_t start = url.find("://");//找字符串
	if (start == string::npos)
	{
		cout << "invalid url" << endl;
		return;
	}
	start += 3;
	size_t finish = url.find('/', start);
	string address = url.substr(start, finish - start);
	cout << address << endl;
}
int main()
{
	test_string();
	system("pause");
	return 0;
}
