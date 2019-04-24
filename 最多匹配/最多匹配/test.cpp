#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	char s[255];
	char t[255];
	char *s1, *s2, *tmp;
	cin >> s;
	cin >> t;
	s1 = s;
	s2 = t;
	int count = 0;
	if (s == NULL || t == NULL)
	{
		return false;
	}
	while (*s1 != '\0')
	{
		tmp = s1;
		if (*tmp == *s2)
		{
			while ((*tmp == *s2) && (*s2 != '\0') && (*tmp != '\0'))
			{
				tmp++;
				s2++;
			}
		}
		else if (*tmp == '?')
		{
			tmp = s2;
			while ((*tmp == *s2) && (*s2 != '\0') && (*tmp != '\0'))
			{
				tmp++;
				s2++;
			}
		}
		s1++;
		if (*s2 == '\0')
		{
			count = count + 1;
		}
		s2 = t;
	}
	cout << count << endl;
	system("pause");
	return 0;
}