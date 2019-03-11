#include <iostream>
#include <string>
using namespace std;

//void test_string()
//{
//	string s1("hello");
//	string s2("world");
//	cout << s1 << "--" << s2 << endl;
//	s1.swap(s2);//�����س�Ա�����Ľ�����ָ�뽻��������С
//	cout << s1 << "--" << s2 << endl;
//	swap(s1, s2); //������һ����ʱ���󣬿������죬�ٸ�ֵ���ٸ�ֵ�����۴�Ч�ʵ�
//	cout << s1 << "--" << s2 << endl;
//}
//void test_string1()
//{
//	string url = "https://blog.csdn.net/Miss_Monster";
//	cout << url << endl;
//	//��0��ʼ��5���ַ��滻Ϊ"http"�����Ǵ��۽ϴ�
//	//�������һ��һ�滻���ַ���Ҫһ��һ��Ų��һ��λ��
//	url.replace(0, 5, "http");
//	cout <<"�滻��Ϊ��"<< url << endl;
//	cout << endl;
//
//
//	url[5] = '\0';//��url�ĵ�����ַ���Ϊ'\0'
//	cout << url << endl;//cout����'\0'����ֹͣ
//	cout <<"C��ʽ���ַ������Ϊ��"<< url.c_str() << endl;
//	printf("printf���%s\n", url.c_str());//C��ʽ���ַ�������'\0'����
//	cout << endl;
//}
//void test_string2()
//{
//	string file = "test.cpp";
//	/*Ӳ����(д������Ӳ�ı���)�����ַ����ĵ�4��λ�ÿ�ʼȡ4���ַ�
//	һ���ı��ַ����������ַ����ܳ��������ԾͲ��ձ��ˣ������Ͳ���ȡ*/
//	string suffix(file, 4, 4);
//	cout << suffix << endl;
//
//	size_t pos = file.find('.');//����ҵ��˾ͷ��ص�һ�γ��ֵ�λ��
//	if (pos != string::npos)//���򷵻�npos��npos������һ����̬��Ա��const������npos=-1��
//	{
//		string suffix(file, pos, file.size() - pos);
//		cout << suffix << endl;
//	}
//}
string getfilesuffix(const string& file)
{
	//size_t pos = file.find('.'); //���ص�һ�γ��ֵ�λ��
	size_t pos = file.rfind('.');  //�������һ�γ��ֵ�λ��

	string suffix;
	if (pos != string::npos)
	{
		//suffix = file.substr(pos);	//ȡ�����
		suffix = file.substr(pos, file.size() - pos);//�������Ҫȡ����λ��ȡ
	}
	return suffix;
}
void test_string()
{
	cout << getfilesuffix("test.cpp") << endl;
	cout << getfilesuffix("test.c") << endl;

	cout << getfilesuffix("test.tar.zip") << endl;//��Ϊ������ʽ������rfind�����һ����׺

	//.zip
	const string file = "test.cpp.tar.zip";
	size_t pos = file.rfind('.'); //���һ�γ��ֵ�λ��
	string suffix;
	if (pos != string::npos)
	{
		suffix = file.substr(pos, file.size() - pos);
	}
	cout << suffix << endl;

	//.tar
	size_t prevpos = file.rfind('.', pos - 1);//��pos-1��λ���ϵ�����
	if (pos != string::npos)
	{
		suffix = file.substr(prevpos, pos - prevpos);
	}
	cout << suffix << endl;

	//������
	string url("https://blog.csdn.net/Miss_Monster");
	cout << url << endl;
	size_t start = url.find("://");//���ַ���
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
