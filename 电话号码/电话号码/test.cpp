#define _CRT_SECURE_NO_WARNINGS 1
//���ӣ�https://www.nowcoder.com/questionTerminal/ceb89f19187b4de3997d9cdef2d551e8
//
//��ͼ��һ���绰�ľŹ�����������һ�����ֶ�ӦһЩ��ĸ������ڹ�����ҵϲ���ѵ绰������Ƴ����Լ���˾�������Ӧ�����繫˾��Help Desk������4357����Ϊ4��ӦH��3��ӦE��5��ӦL��7��ӦP�����4357����HELP��ͬ��TUT - GLOP�ʹ���888 - 4567��310 - GINO����310 - 4466��
//NowCoder�ս������󣬲���ϰ��������������ʽ�����ڸ���һ���绰�����б��������ת����������ʽ�ĺ��룬��ȥ���ظ��Ĳ��֡�
//�������� :
//��������������ݡ�
//ÿ�����ݵ�һ�а���һ��������n��1��n��1024����
//������n�У�ÿ�а���һ���绰���룬�绰����������ַ��� - �������ֺʹ�д��ĸ��ɡ�
//û���������ֵ����ַ��������ų����ַ��󳤶�ʼ��Ϊ7�������绰����ֻ��7λ����
//������� :
//��Ӧÿһ�����룬�����ֵ�˳��������ظ��ı�׼������ʽ�绰���룬����xxx - xxxx����ʽ��
//ÿ���绰����ռһ�У�ÿ������֮�����һ��������Ϊ�������
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <exception>
#include <iomanip>
#include <memory>
#include <sstream>
#define INF 1000000
using namespace std;
int main(int argc, char** argv)
{
	unordered_map<char, char> dic;
	dic.emplace('A', '2');
	dic.emplace('B', '2');
	dic.emplace('C', '2');
	dic.emplace('D', '3');
	dic.emplace('E', '3');
	dic.emplace('F', '3');
	dic.emplace('G', '4');
	dic.emplace('H', '4');
	dic.emplace('I', '4');
	dic.emplace('J', '5');
	dic.emplace('K', '5');
	dic.emplace('L', '5');
	dic.emplace('M', '6');
	dic.emplace('N', '6');
	dic.emplace('O', '6');
	dic.emplace('P', '7');
	dic.emplace('Q', '7');
	dic.emplace('R', '7');
	dic.emplace('S', '7');
	dic.emplace('T', '8');
	dic.emplace('U', '8');
	dic.emplace('V', '8');
	dic.emplace('W', '9');
	dic.emplace('X', '9');
	dic.emplace('Y', '9');
	dic.emplace('Z', '9');
	int n;
	while (cin >> n && n > 0)
	{
		set<string> hs;
		string s;
		for (int i = 0; i < n; ++i)
		{
			cin >> s;
			string p = "";
			for (auto& c : s)
			{
				if (isdigit(c)) p += c;
				else if (isupper(c)) p += dic[c];
			} 
			if(p.size() != 7) continue;
			p = p.substr(0, 3) + "-" + p.substr(3);
			hs.emplace(p);
		} 
		for(auto& phone : hs) cout << phone << endl;
		cout << endl;
	} 
	return 0;
}