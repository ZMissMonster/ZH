#define _CRT_SECURE_NO_WARNINGS 1
//���ӣ�https://www.nowcoder.com/questionTerminal/34f17d5f2a8240bea661a23ec095a062
//��Դ��ţ����
//�Ǽ�ս����չ��100��֮��NowCoder���������������˵����룡���ǵ�������һ��������ͨ��һ�ű������Ϣӳ�������4λ���롣��Ĺ����ǣ�n��Ӧ��ֵ�Ǿ���X��n�η������Ͻǣ�������������4λ����0��䣬�������4λ����ֻ������4λ��
//| 1 1 | ^n = > | Xn .. |
//| 1 0 | | .. .. |
//����n = 2ʱ��
//| 1 1 | ^ 2 = > | 1 1 | *| 1 1 | = > | 2 1 |
//| 1 0 | | 1 0 | | 1 0 | | 1 1 |
//��2��Ӧ�����ǡ�0002����
//�������� :
//�����ж������ݡ�
//ÿ���������У���һ�а���һ������n(1��n��100)���ڶ��а���n��������Xi(1��Xi��10000)
//������� :
//	 ��Ӧÿһ�����룬���һ����Ӧ�����롣
#include <iostream>
#include <vector>
using namespace std;
vector<int> a = { 1, 1 };
void data_init()
{
	int i;
	for (i = 2; i < 10005; i++){
		a.push_back((a[i - 1] + a[i - 2]) % 10000);
	}
} 
int main()
{
	int n, t;
	data_init();
	while (cin >> n){
		while (n--){
			cin >> t;
			printf("%04d", a[t]);
		}
		cout<<endl;
	}
	return 0;
}