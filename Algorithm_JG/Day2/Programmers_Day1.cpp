#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

////���ڿ� ������������ ��ġ�ϱ�
//string stringLower(string s)
//{
//	sort(s.begin(), s.end());
//	reverse(s.begin(), s.end());
//
//	return s;
//}

////������ȣ
//string Sizer(string s, int n)
//{
//	int iSize = s.size();
//	for (int i = 0; i < iSize; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			if (s[i] == ' ')
//				break;
//
//			if (s[i] == 'Z')
//			{
//				s[i] = 'A';
//				continue;
//			}
//			else if (s[i] == 'z')
//			{
//				s[i] = 'a';
//				continue;
//			}
//			s[i]++;
//		}
//	}
//	return s;
//}

/*
1-2-3- 4- 5- 6-7- 8- 9 -10-11-12-13 -14 -15  -16... ��
1-2-4-11-12-14-21-22-24-41-42-44-111-112-114-121...
�̷������� �̾����ȴ�.

1���ڸ����� 3���� ����� 
�������� 0�̸� 4
�������� 1�̸� 1
�������� 2�̸� 2

10���ڸ���
1-2-3 / 0
4-5-6 / 1
7-8-9 / 2
10-11-12 / 4

13-14-15 / 1
16-17-18 / 2
19-20-21 / 4

���� ��Ʈ�� 3������ 4��°�� 1�ڸ��� ���ϱ�
�̷��������ؾ��ϳ� �ƴѵ��ϴ�


-----
3���� ���������� �غ���
1-2-4 �̰� �� ����Ŭ, �ѽ���Ŭ���������� �ڸ��� +1

*/

////124������ ����
//int Add(int n)
//{
//	int answer = 0;
//	int iIndex = 0;
//
//	while (1)
//	{
//		int iAcc = 0;
//
//		if (n == iAcc)
//			break;
//
//		iAcc++;
//
//	}
//
//
//
//	return answer;
//}

/*
������ؼ� �� ���ϸ��
��� -> ����� ���������°�
*/
////�������
//int Add(int n) 
//{
//	int answer = 0;
//	
//	for (int i = 1; i <= n; i++)
//	{
//		if (n%i == 0)
//			answer += i;
//	}
//	
//	
//	return answer;
//}

//�ִ������� �ּҰ����
vector<int> solution(int n, int m) 
{
	vector<int> answer;
	return answer;
}

void main()
{
	

	system("Pause");
	return ;
}